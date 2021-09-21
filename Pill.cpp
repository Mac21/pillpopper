#include "Pill.hpp"

Pill::Pill() {
  if (!texture.loadFromFile("assets/blue_yellow_pill.png")) {
    std::cout << "Failed to load pill image\n";
    exit(EXIT_FAILURE);
  }

  sf::Sprite s(texture);
  auto rec = s.getTextureRect();
  s.setPosition(WINDOW_WIDTH / 2.F, 75);
  s.setOrigin(rec.width / 2.0F, rec.height / 2.0F);

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
  if (pos.y <= 0 || pos.y >= BOARD_HEIGHT_BOUNDRY || pos.x <= 0 || pos.x >= BOARD_WIDTH_BOUNDRY) {
    return;
  }
  sprite.setPosition(pos);
}

void Pill::rotateClockwise() {
  sprite.rotate(-90.0F);
}

void Pill::rotateCounterClockwise() {
  sprite.rotate(90.0F);
}

void Pill::update(sf::Time t, sf::Time dt) {
  move(0, velocity * dt.asMilliseconds());
}

sf::Sprite Pill::getSprite() {
  return sprite;
}
