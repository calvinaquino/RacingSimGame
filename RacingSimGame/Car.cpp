#include "Car.hpp"
#include "ResourceHolder.hpp"
#include "Category.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


Textures::ID toTextureID(Car::Type type)
{
	switch (type)
	{
	case Car::XRT:
		return Textures::XRT;

	case Car::XFR:
		return Textures::XFR;
	
	case Car::RB4:
		return Textures::RB4;
	
	case Car::MRT:
		return Textures::MRT;
	
	case Car::FZR:
		return Textures::FZR;
	
	case Car::FXO:
		return Textures::FXO;
	
	case Car::FOX:
		return Textures::FOX;
	
	case Car::BF1:
		return Textures::BF1;
	}
	return Textures::Tyre;
}

Car::Car(Type type, const TextureHolder& textures)
: mType(type)
, mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Car::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

unsigned int Car::getCategory() const
{
	switch (mType)
	{
	case XRT:
		return Category::PlayerCar;

		default:
		return Category::OpponentCar;
	}
}