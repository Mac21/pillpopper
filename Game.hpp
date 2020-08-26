#ifndef GAME_HPP_
#define GAME_HPP_

#include "Defs.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
public:
  Game();
  void run();
private:
  void processEvents();
  void update();
  void render();
  sf::RenderWindow mWindow;
};

#endif
