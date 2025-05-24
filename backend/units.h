#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

struct Option {
  std::string name;
  std::string type;
  int range;
  int strength;
  int armor_penetration;
  int damage;
};

struct Stats {
  int movement;
  int weapon_skill;
  int ballistic_skill;
  int strength;
  int toughness;
  int wounds;
  int attacks;
  int leadership;
  int save;
};

struct Unit {
  std::string faction;
  std::string chapter;
  std::string unit_name;
  int points;
  Stats stats;
  std::vector<Option> options;
};

// Declare from_json functions
void from_json(const nlohmann::json &j, Option &o);
void from_json(const nlohmann::json &j, Stats &s);
void from_json(const nlohmann::json &j, Unit &u);
// Declare to_json functions
void to_json(nlohmann::json &j, const Option &o);
void to_json(nlohmann::json &j, const Stats &s);
void to_json(nlohmann::json &j, const Unit &u);