#include "Game.hpp"

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
const int Game::ScreenResolutionX = 800;
const int Game::ScreenResolutionY = 600;

Game::Game()
	: mWindow(sf::VideoMode(ScreenResolutionX, ScreenResolutionY), "Racing Sim Game", sf::Style::Close)
, mPlayer()
, mTexture()
, mIsAccelerating(false)
, mIsBraking(false)
, mIsTurningLeft(false)
, mIsTurningRight(false)
{
	if (!mTexture.loadFromFile("Resources/car/xrtcar.bmp"))
	{
		//handle error
		mWindow.close();
	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(ScreenResolutionX/2.f, ScreenResolutionY/2.f);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsAccelerating)
		movement.y -= PlayerSpeed;
	if (mIsAccelerating)
		movement.y += PlayerSpeed;
	if (mIsTurningLeft)
		movement.x -= PlayerSpeed;
	if (mIsTurningRight)
		movement.x += PlayerSpeed;

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsAccelerating = isPressed;
	if (key == sf::Keyboard::S)
		mIsBraking = isPressed;
	if (key == sf::Keyboard::A)
		mIsTurningLeft = isPressed;
	if (key == sf::Keyboard::D)
		mIsTurningRight = isPressed;
}

void Game::render()
{
	mWindow.clear();	
	mWindow.draw(mPlayer);
	mWindow.display();
}