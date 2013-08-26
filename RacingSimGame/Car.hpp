#ifndef RACE_CAR_HPP
#define RACE_CAR_HPP

#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics/Sprite.hpp>


class Car : public Entity
{
	public:
		enum Type
		{
			XRT,
			XFR,
			RB4,
			MRT,
			FZR,
			FXO,
			FOX,
			BF1
		};


	public:
							Car(Type type, const TextureHolder& textures);

		virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual unsigned int	getCategory() const;


	private:
		Type				mType;
		sf::Sprite			mSprite;
};

#endif // RACE_CAR_CPP