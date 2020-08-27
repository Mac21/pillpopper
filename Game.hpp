#ifndef GAME_HPP_
#define GAME_HPP_

#include "Defs.hpp"

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
public:
  Game();
  void run();
private:
  void processEvents();
  void update(sf::Time interpolation, sf::Time t, sf::Time dt);
  void render(sf::Time interpolation);

  sf::Clock gameClock;
  sf::RenderWindow window;
};

#endif
