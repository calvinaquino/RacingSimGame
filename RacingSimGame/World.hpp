#ifndef RACE_WORLD_HPP
#define RACE_WORLD_HPP

#include "Car.hpp"

#include <SFML/System/NonCopyable.hpp"
#include <SFML/Graphics/View.hpp"
#include <SFML/Graphics/Texture.hpp"

#include <array>


// Forward declaration
namespace sf
{
	class RenderWindow;
}

class World : private sf::NonCopyable
{
	public:
		explicit							World(sf::RenderWindow& window);
		void								update(sf::Time dt);
		void								draw();


	private:
		void								loadTextures();
		void								buildScene();


	private:
		enum Layer
		{
			Background,
			Air,
			LayerCount
		};


	private:
		sf::RenderWindow&					mWindow;
		sf::View							mWorldView;

};

#endif // BOOK_WORLD_HPP