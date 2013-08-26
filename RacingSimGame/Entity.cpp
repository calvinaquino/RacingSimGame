#include "Entity.hpp"


void Entity::applyForce(sf::Vector2f force)
{
	mForce = force;
}

void Entity::applyForce(float vx, float vy)
{
	mForce.x = vx;
	mForce.y = vy;
}

void Entity::applyTorque(float torque)
{

}

sf::Vector2f Entity::getVelocity() const
{
	return mForce/mMass;
}

void Entity::setMass(float mass)
{
	mMass = mass;
}

float Entity::getMass() const
{
	return mMass;
}

void Entity::updateCurrent(sf::Time dt)
{	
	move(getVelocity() * dt.asSeconds());
}