#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type)
{
	this->hp = hp;
	this->type = type;
}

Enemy::Enemy(const Enemy &_enemy)
{
	this->hp = _enemy.getHP();
	this->type = _enemy.getType();
}

Enemy::~Enemy()
{ }

Enemy &Enemy::operator=(const Enemy &_enemy)
{
	if (this == &_enemy)
		return (*this);
	this->hp = _enemy.getHP();
	this->type = _enemy.getType();
	return (*this);
}

std::string Enemy::getType(void) const
{
	return (this->type);
}

int Enemy::getHP(void) const
{
	return (this->hp);
}

void Enemy::takeDamage(int _damage)
{
	if (_damage >= 0)
	{
		if (this->hp - _damage <= 0)
			_damage = this->hp;
		this->hp -= _damage;
	}
}