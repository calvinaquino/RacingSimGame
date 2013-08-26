#ifndef RACE_ENTITY_HPP
#define RACE_ENTITY_HPP

#include "SceneNode.hpp"


class Entity : public SceneNode
{
	public:
		void				setMass(float mass);
		float				getMass() const;
		void				applyForce(sf::Vector2f force);
		void				applyForce(float vx, float vy);
		void				applyTorque(float torque);

		sf::Vector2f		getVelocity() const;


	private:
		virtual void		updateCurrent(sf::Time dt);


	private:
		float				mDirection;
		sf::Vector2f		mForce;
		float				mMass;
};

#endif // RACE_ENTITY_HPP