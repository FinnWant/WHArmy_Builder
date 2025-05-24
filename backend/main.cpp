#include "crow_all.h"
#include "units.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <vector>

using json = nlohmann::json;

// In-memory storage for builds
std::unordered_map<int, json> builds;
int nextBuildId = 1;

// Load units from JSON file
std::vector<Unit> loadUnits(const std::string &filePath) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open units.json");
  }

  json unitData;
  file >> unitData;
  return unitData.get<std::vector<Unit>>();
}

int main() {
  crow::SimpleApp app;

  // Load units
  std::vector<Unit> units;
  try {
    units = loadUnits("/home/student/PROJECTS/resources/units.json");
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  // GET /units: Serve unit and faction data
  CROW_ROUTE(app, "/units").methods(crow::HTTPMethod::GET)([&units]() {
    json response = units;
    return crow::response(response.dump());
  });

  // POST /builds: Accept army builds
  CROW_ROUTE(app, "/builds")
      .methods(crow::HTTPMethod::POST)([](const crow::request &req) {
        auto build = json::parse(req.body);
        int buildId = nextBuildId++;
        builds[buildId] = build;
        return crow::response(json{{"build_id", buildId}}.dump());
      });

  // GET /builds/{id}: Retrieve a specific build
  CROW_ROUTE(app, "/builds/<int>")
      .methods(crow::HTTPMethod::GET)([](int buildId) {
        if (builds.find(buildId) == builds.end()) {
          return crow::response(404, "Build not found");
        }
        return crow::response(builds[buildId].dump());
      });

  // POST /validate: Validate and calculate total points
  CROW_ROUTE(app, "/validate")
      .methods(crow::HTTPMethod::POST)([&units](const crow::request &req) {
        auto build = json::parse(req.body);
        int totalPoints = 0;
        for (const auto &entry : build) {
          std::string unitName = entry["unit_name"];
          int count = entry["count"];
          auto it = std::find_if(
              units.begin(), units.end(),
              [&unitName](const Unit &u) { return u.unit_name == unitName; });
          if (it == units.end()) {
            return crow::response(400, "Invalid unit: " + unitName);
          }
          totalPoints += it->points * count;
        }
        return crow::response(json{{"total_points", totalPoints}}.dump());
      });

  // Start the server
  app.port(8080).multithreaded().run();
}
