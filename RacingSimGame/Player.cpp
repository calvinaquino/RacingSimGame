#include "Player.hpp"
#include "CommandQueue.hpp"
#include "Car.hpp"
#include "Foreach.hpp"

#include <map>
#include <string>
#include <algorithm>


struct CarMover
{
	CarMover(float vx, float vy)
	: velocity(vx, vy)
	{
	}

	void operator() (Car& car, sf::Time) const
	{
		car.accelerate(velocity);
	}

	sf::Vector2f velocity;
};

Player::Player()
{
	// Set initial key bindings
	mKeyBinding[sf::Keyboard::Left] = TurnLeft;
	mKeyBinding[sf::Keyboard::Right] = TurnRight;
	mKeyBinding[sf::Keyboard::Up] = Accelerate;
	mKeyBinding[sf::Keyboard::Down] = Brake;
	mKeyBinding[sf::Keyboard::A]= ShiftUp;
	mKeyBinding[sf::Keyboard::Z] = ShiftDown;
	mKeyBinding[sf::Keyboard::X]= Clutch;


	// Set initial action bindings
	initializeActions();	

	// Assign all categories to player's aircraft
	FOREACH(auto& pair, mActionBinding)
		pair.second.category = Category::PlayerCar;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		// Check if pressed key appears in key binding, trigger command if so
		auto found = mKeyBinding.find(event.key.code);
		if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
			commands.push(mActionBinding[found->second]);
	}
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	// Traverse all assigned keys and check if they are pressed
	FOREACH(auto pair, mKeyBinding)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	FOREACH(auto pair, mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{
	const float playerSpeed = 200.f;

	mActionBinding[TurnLeft].action	 = derivedAction<Car>(CarMover(-playerSpeed, 0.f));
	mActionBinding[TurnRight].action = derivedAction<Car>(CarMover(+playerSpeed, 0.f));
	mActionBinding[Accelerate].action    = derivedAction<Car>(CarMover(0.f, -playerSpeed));
	mActionBinding[Brake].action  = derivedAction<Car>(CarMover(0.f, +playerSpeed));
	mActionBinding[ShiftUp].action = derivedAction<Car>(CarMover(+playerSpeed, 0.f));
	mActionBinding[ShiftDown].action    = derivedAction<Car>(CarMover(0.f, -playerSpeed));
	mActionBinding[Clutch].action  = derivedAction<Car>(CarMover(0.f, +playerSpeed));
}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
	case TurnLeft:
	case TurnRight:
	case Accelerate:
	case Brake:
	case ShiftUp:
	case ShiftDown:
	case Clutch:
			return true;

		default:
			return false;
	}
}