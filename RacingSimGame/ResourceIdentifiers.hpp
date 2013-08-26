#ifndef RACE_RESOURCEIDENTIFIERS_HPP
#define RACE_RESOURCEIDENTIFIERS_HPP


// Forward declaration of SFML classes
namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		XRT,
		XFR,
		RB4,
		MRT,
		FZR,
		FXO,
		FOX,
		BF1,
		G25,
		Tyre,
		Carpark,
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif // RACE_RESOURCEIDENTIFIERS_HPP