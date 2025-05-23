#include "units.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;

int main() {
  std::ifstream file("/home/student/PROJECTS/resources/units.json");
  if (!file.is_open()) {
    std::cerr << "Failed to open units.json" << std::endl;
    return 1;
  }

  json unitData;
  try {
    file >> unitData;
    std::cout << "JSON loaded successfully: " << unitData.dump(4) << std::endl;
  } catch (const json::parse_error &e) {
    std::cerr << "JSON parsing error: " << e.what() << std::endl;
    return 1;
  }

  std::vector<Unit> units;
  try {
    units = unitData.get<std::vector<Unit>>();
    std::cout << "Units deserialized successfully!" << std::endl;
  } catch (const json::type_error &e) {
    std::cerr << "JSON type error: " << e.what() << std::endl;
    return 1;
  }

  for (const auto &unit : units) {
    std::cout << "Faction: " << unit.faction << "\n"
              << "Unit: " << unit.unit_name << "\n"
              << "Points: " << unit.points << "\n"
              << "Weapon Skill: " << unit.stats.weapon_skill << "\n"
              << "Options:\n";
    for (const auto &opt : unit.options) {
      std::cout << "  - " << opt.name << " (" << opt.type << ", Str "
                << opt.strength << ")\n";
    }
    std::cout << "-----------------------------\n";
  }

  return 0;
}
