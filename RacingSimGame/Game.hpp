#ifndef MCHAN_GAME_HPP
#define MCHAN_GAME_HPP

#include <SFML/Graphics.hpp>


class Game : private sf::NonCopyable
{
public:
								Game();
		void					run();

private:
		void					processEvents();
		void					update(sf::Time deltaTime);
		void					render();

		void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
		static const float		PlayerSpeed;
		static const sf::Time	TimePerFrame;
		static const int		ScreenResolutionX;
		static const int		ScreenResolutionY;

		sf::RenderWindow		mWindow;
		sf::Texture				mTexture;
		sf::Sprite				mPlayer;

		bool					mIsAccelerating;
		bool					mIsBraking;
		bool					mIsTurningLeft;
		bool					mIsTurningRight;
};

#endif 
// MCHAN_GAME_HPP