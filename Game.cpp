#include "Game.hpp"

Game::Game(): window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pillpopper") {}

void Game::update(sf::Time interpolation, sf::Time t, sf::Time dt) {
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        return;
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      exit(EXIT_SUCCESS);
    }
}

void Game::render(sf::Time interpolation) {
    window.clear();
    window.display();
}

void Game::run() {
  sf::Time startTime = gameClock.getElapsedTime();
  sf::Time accumulator = sf::Time();
  sf::Time dt = sf::seconds(0.01);
  sf::Time t = sf::seconds(0.0);
  sf::Time interpolation = sf::seconds(0.0);
  sf::Time previous_interpolation = interpolation;

  while (window.isOpen()) {
    processEvents();

    sf::Time currentTime = gameClock.getElapsedTime();
    sf::Time frameTime = currentTime - startTime;
    if (frameTime.asSeconds() > FRAME_TIME) {
      frameTime = sf::seconds(FRAME_TIME);
    }

    startTime = currentTime;
    accumulator += frameTime;

    while (accumulator >= dt) {
      previous_interpolation = interpolation;
      update(interpolation, t, dt);
      t += dt;
      accumulator -= dt;
    }

    auto alpha = accumulator / dt;

    interpolation = sf::seconds(interpolation.asSeconds() * alpha + previous_interpolation.asSeconds() *(1.0 - alpha));

    render(interpolation);
  }
}
