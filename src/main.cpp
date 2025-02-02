#include <iostream>

#include "games/engine.hpp"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "The game cannot be started.\nYou need to enter the command: "
                 "make start-<debug|release> GAME_CODE=<LCM|GEOMPROG>\n";
    return EXIT_FAILURE;
  }
  games::Engine engine{argv[1]};
  engine.Start();
  return EXIT_SUCCESS;
}
