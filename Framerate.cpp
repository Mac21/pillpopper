#include "Framerate.hpp"

Framerate::Framerate() {
  sf::Font f;
  if (!f.loadFromFile("assets/Ubuntu-R.ttf")) {
    std::cout << "Failed to load font file\n";
    exit(EXIT_FAILURE);
  }

    font = f;

    sf::Text t;
    t.setFont(font);
    t.setString("Framerate: 0");
    fontText = t;
}

void Framerate::update(sf::Time interpolation, sf::Time t, sf::Time dt) {
}

void Framerate::setText(std::string s) {
  fontText.setString("Framerate: "+s);
}

sf::Text Framerate::getText() {
  return fontText;
}
