#ifndef PILL_HPP_
#define PILL_HPP_

#include "Defs.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

class Pill {
public:
  Pill();
  void move(float, float);
  void rotateClockwise();
  void rotateCounterClockwise();
  void update(sf::Time t, sf::Time dt);
  sf::Sprite getSprite();
private:
  sf::Sprite sprite;
  sf::Texture texture;
  float velocity = PILL_GRAVITY_VELOCITY;
};

#endif
