#include "Game.hpp"

Game::Game(): window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pillpopper") {}

void Game::update(sf::Time t, sf::Time dt) {
  framerateHud.setText(std::to_string(frameCount));
  pill.update(t, dt);
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      pill.move(-3.5f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      pill.move(3.5f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      pill.move(0.f, 3.5f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      pill.move(0.f, 3.5f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      pill.move(0.f, 3.5f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      exit(EXIT_SUCCESS);
    }
}

void Game::render() {
    window.clear();
    window.draw(framerateHud.getText());
    window.draw(pill.getSprite());
    window.display();
}

void Game::run() {
  sf::Time startTime = gameClock.getElapsedTime();
  sf::Time accumulator = sf::Time();
  sf::Time dt = sf::seconds(0.01);
  sf::Time t = sf::seconds(0.0);

  while (window.isOpen()) {
    processEvents();
    frameCount++;

    sf::Time currentTime = gameClock.getElapsedTime();
    sf::Time frameTime = currentTime - startTime;
    if (frameTime.asSeconds() > FRAME_TIME) {
      frameCount = 0;
      frameTime = sf::seconds(FRAME_TIME);
      startTime = currentTime;
    }

    accumulator += frameTime;

    while (accumulator >= dt) {
      update(t, dt);
      t += dt;
      accumulator -= dt;
    }

    render();
  }
}
