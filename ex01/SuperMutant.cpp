#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
: Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &_supermutant)
: Enemy(_supermutant)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaaargh" << std::endl;
}

SuperMutant &SuperMutant::operator=(const SuperMutant &_supermutant)
{
	if (this == &_supermutant)
		return (*this);
	this->Enemy::operator=(_supermutant);
	return (*this);	
}

void SuperMutant::takeDamage(int _damage)
{
	_damage -= 3;
	this->Enemy::takeDamage(_damage);
}