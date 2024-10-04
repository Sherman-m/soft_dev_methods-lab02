#include "engine.hpp"

#include <format>
#include <iostream>

void GameEngine::Start() {
  std::cout << "Welcome to the Brain Games!\nMay I have your name? ";
  std::cin >> player_name_;
  std::cout << std::format("\nHello, {}!\n", player_name_);

  if (k_code_to_game_.find(game_code_) == k_code_to_game_.end()) {
    std::cout << std::format("The game_code={} does not exist.\n", game_code_);
    return;
  }

  auto game_ptr = k_code_to_game_.at(game_code_);
  std::string answer_to_player =
      (game_ptr->Play()) ? "Congratulations" : "Let's try again";
  std::cout << std::format("{}, {}!\n", answer_to_player, player_name_);
}
