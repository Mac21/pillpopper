#include "Game.hpp"

Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pillpopper") {
  mWindow.setFramerateLimit(60);
}

void Game::update() {
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        mWindow.close();
        return;
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      exit(EXIT_SUCCESS);
    }
}

void Game::render() {
    mWindow.clear();
    mWindow.display();
}

void Game::run() {
  while (mWindow.isOpen()) {
    processEvents();
    update();
    render();
  }
}
