#include "Pill.hpp"

Pill::Pill() {
  sf::Texture t;
  if (!t.loadFromFile("assets/blue_pill.png")) {
    std::cout << "Failed to load pill image\n";
    exit(EXIT_FAILURE);
  }
  texture = t;

  sf::Sprite s(texture);
  s.setPosition(WINDOW_WIDTH / 2.f, 75);
  sprite = s;
}

void Pill::move(float x, float y) {
  sf::Vector2f pos = sprite.getPosition();
  if (x != 0) {
    pos.x += x;
  }
  if (y != 0) {
    pos.y += y;
  }
  if (pos.y <= 0 || pos.y >= WINDOW_HEIGHT || pos.x <= 0 || pos.x >= (WINDOW_WIDTH - 50)) {
    return;
  }
  sprite.setPosition(pos);
}

void Pill::update(sf::Time t, sf::Time dt) {
  move(0, velocity * dt.asMilliseconds());
}

sf::Sprite Pill::getSprite() {
  return sprite;
}
