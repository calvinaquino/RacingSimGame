#include "World.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window)
: mWindow(window)
, mWorldView(window.getDefaultView())
, mTextures() 
, mSceneGraph()
, mSceneLayers()
, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
, mScrollSpeed(-50.f)
, mPlayerCar(nullptr)
{
	loadTextures();
	buildScene();

	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	//moving here

	// Apply movements
	mSceneGraph.update(dt);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
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
	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	// Prepare the tiled background
	sf::Texture& texture = mTextures.get(Textures::Carpark);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	// Add the background sprite to the scene
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Ground]->attachChild(std::move(backgroundSprite));

	// Add player's aircraft
	std::unique_ptr<Car> leader(new Car(Car::XRT, mTextures));
	mPlayerCar = leader.get();
	mPlayerCar->setPosition(mSpawnPosition);
	mSceneLayers[AboveGround]->attachChild(std::move(leader));
}

void World::adaptPlayerPosition()
{
	// Keep player's position inside the screen bounds, at least borderDistance units from the border
	sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
	const float borderDistance = 40.f;

	sf::Vector2f position = mPlayerCar->getPosition();
	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
	mPlayerCar->setPosition(position);
}

void World::adaptPlayerVelocity()
{
	sf::Vector2f velocity = mPlayerCar->getVelocity();
}