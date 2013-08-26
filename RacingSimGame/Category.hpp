#ifndef RACE_CATEGORY_HPP
#define RACE_CATEGORY_HPP


// Entity/scene node category, used to dispatch commands
namespace Category
{
	enum Type
	{
		None				= 0,
		Scene				= 1 << 0,
		PlayerCar			= 1 << 1,
		OpponentCar			= 1 << 2,
		Tyre				= 1 << 3,
	};
}

#endif // RACE_CATEGORY_HPP