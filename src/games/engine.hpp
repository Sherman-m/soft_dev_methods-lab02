#pragma once

#include <memory>
#include <random>
#include <string>
#include <unordered_map>

#include "geom_prog_game.hpp"
#include "lcm_game.hpp"

// Engine
class GameEngine {
 public:
  explicit GameEngine(std::string game_code)
      : game_code_(std::move(game_code)) {
  }

  void Start();

 private:
  using CodeToGame =
      std::unordered_map<std::string, std::shared_ptr<CommonGame>>;

  const CodeToGame k_code_to_game_{
      {"LCM", std::make_shared<LcmGame>(gen_)},
      {"GEOMPROG", std::make_shared<GeometricProgressionGame>(gen_)}};

  std::string player_name_;
  std::string game_code_;
  std::mt19937 gen_{std::random_device{}()};
};
