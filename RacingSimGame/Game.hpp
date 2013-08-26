#ifndef RACE_GAME_HPP
#define RACE_GAME_HPP

#include "World.hpp"
#include "Player.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Game : private sf::NonCopyable
{
public:
								Game();
		void					run();

private:
		void					processEvents();
		void					update(sf::Time deltaTime);
		void					render();
		
		void					updateStatistics(sf::Time elapsedTime);	
		void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
		static const float		PlayerSpeed;
		static const sf::Time	TimePerFrame;
		static const int		ScreenResolutionX;
		static const int		ScreenResolutionY;

		sf::RenderWindow		mWindow;
		World					mWorld;
		Player					mPlayer;
		
	  	sf::Font				mFont;
		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;
		std::size_t				mStatisticsNumFrames;
};

#endif 
// RACE_GAME_HPP