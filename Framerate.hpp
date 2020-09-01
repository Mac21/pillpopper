#ifndef FRAMERATE_HPP_
#define FRAMERATE_HPP_

#include <string>
#include <iostream>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>

class Framerate {
public:
  Framerate();
  void update(sf::Time interpolation, sf::Time t, sf::Time dt);
  void setText(std::string s);
  sf::Text getText();
private:
  sf::Font font;
  sf::Text fontText;
};

#endif
