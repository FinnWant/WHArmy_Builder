#include "units.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Define from_json for Option
void from_json(const json &j, Option &o) {
  j.at("name").get_to(o.name);
  j.at("type").get_to(o.type);
  j.at("range").get_to(o.range);
  j.at("strength").get_to(o.strength);
  j.at("armor_penetration").get_to(o.armor_penetration);
  j.at("damage").get_to(o.damage);
}

// Define from_json for Stats
void from_json(const json &j, Stats &s) {
  j.at("movement").get_to(s.movement);
  j.at("weapon_skill").get_to(s.weapon_skill);
  j.at("ballistic_skill").get_to(s.ballistic_skill);
  j.at("strength").get_to(s.strength);
  j.at("toughness").get_to(s.toughness);
  j.at("wounds").get_to(s.wounds);
  j.at("attacks").get_to(s.attacks);
  j.at("leadership").get_to(s.leadership);
  j.at("save").get_to(s.save);
}

// Define from_json for Unit
void from_json(const json &j, Unit &u) {
  j.at("faction").get_to(u.faction);
  j.at("chapter").get_to(u.chapter);
  j.at("unit_name").get_to(u.unit_name);
  j.at("points").get_to(u.points);
  j.at("stats").get_to(u.stats);
  j.at("options").get_to(u.options);
}