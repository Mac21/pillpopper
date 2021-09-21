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
      default:
        break;
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      pill.move(-PILL_MOVEMENT_VELOCITY, 0.F);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      pill.move(PILL_MOVEMENT_VELOCITY, 0.F);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      pill.move(0.F, PILL_MOVEMENT_VELOCITY);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      pill.rotateClockwise();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      pill.rotateCounterClockwise();
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
  sf::Time dt = sf::seconds(DT);
  sf::Time t = sf::Time();

  while (window.isOpen()) {
    processEvents();
    frameCount++;

    sf::Time currentTime = gameClock.getElapsedTime();
    sf::Time frameTime = currentTime - startTime;
    if (frameTime.asSeconds() > MAX_FRAME_TIME) {
      frameCount = 0;
      frameTime = sf::seconds(MAX_FRAME_TIME);
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
