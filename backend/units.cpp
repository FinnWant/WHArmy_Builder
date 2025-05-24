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

void to_json(json &j, const Option &o) {
  j = json{{"name", o.name},
           {"type", o.type},
           {"range", o.range},
           {"strength", o.strength},
           {"armor_penetration", o.armor_penetration},
           {"damage", o.damage}};
}

// Define to_json for Stats
void to_json(json &j, const Stats &s) {
  j = json{{"movement", s.movement},
           {"weapon_skill", s.weapon_skill},
           {"ballistic_skill", s.ballistic_skill},
           {"strength", s.strength},
           {"toughness", s.toughness},
           {"wounds", s.wounds},
           {"attacks", s.attacks},
           {"leadership", s.leadership},
           {"save", s.save}};
}

// Define to_json for Unit
void to_json(json &j, const Unit &u) {
  j = json{{"faction", u.faction},     {"chapter", u.chapter},
           {"unit_name", u.unit_name}, {"points", u.points},
           {"stats", u.stats},         {"options", u.options}};
}