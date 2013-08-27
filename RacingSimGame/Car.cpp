#include "Car.hpp"

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



