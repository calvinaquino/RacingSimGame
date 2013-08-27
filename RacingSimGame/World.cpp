#include "World.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window)
: mWindow(window)
, mWorldView(window.getDefaultView())
{
	loadTextures();
	buildScene();

	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
}

void World::draw()
{
	mWindow.setView(mWorldView);
}

void World::loadTextures()
{
	mTextures.load(Textures::BF1, "Resources/car/bf1car.bmp");
	mTextures.load(Textures::FOX, "Resources/car/foxcar.bmp");
	mTextures.load(Textures::FXO, "Resources/car/fxocar.bmp");
	mTextures.load(Textures::FZR, "Resources/car/fzrcar.bmp");
	mTextures.load(Textures::MRT, "Resources/car/mrtcar.bmp");
	mTextures.load(Textures::RB4, "Resources/car/rb4car.bmp");
	mTextures.load(Textures::XFR, "Resources/car/xfrcar.bmp");
	mTextures.load(Textures::XRT, "Resources/car/xrtcar.bmp");
	mTextures.load(Textures::Tyre, "Resources/tire.bmp");
	mTextures.load(Textures::G25, "Resources/g25small.bmp");
	mTextures.load(Textures::Carpark, "Resources/carpark2.bmp");
}

void World::buildScene()
{
}

void World::adaptPlayerPosition()
{

}

void World::adaptPlayerVelocity()
{
	sf::Vector2f velocity = mPlayerCar->getVelocity();
}