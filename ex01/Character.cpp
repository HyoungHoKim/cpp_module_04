#include "Character.hpp"

Character::Character(std::string const &name)
{
	this->name = name;
	this->ap = 40;
	this->weaponPtr = NULL;
}

Character::Character(const Character &_character)
{
	this->name = _character.getName();
	this->ap = _character.getAP();
	this->weaponPtr = _character.getAWeaponPtr();
}

Character::~Character()
{ }

Character &Character::operator=(const Character &_character)
{
	if (this == &_character)
		return (*this);
	this->name = _character.getName();
	this->ap = _character.getAP();
	this->weaponPtr = _character.getAWeaponPtr();
	return (*this);
}

void Character::recoverAP(void)
{
	this->ap += 10;
	if (this->ap > 40)
		this->ap = 40;
}

void Character::equip(AWeapon *_aweapon)
{
	this->weaponPtr = _aweapon;
}

void Character::attack(Enemy *_enemy)
{
	if (this->weaponPtr == NULL)
		std::cout << this->name << " has " << this->ap << " AP and is unarmed" << std::endl;
	else if (this->ap < this->weaponPtr->getAPCost())
		std::cout << "Not Enough AP!!!" << std::endl;
	else if (!_enemy || _enemy->getHP() <= 0)
		std::cout << "The enemy is already Dead!!!" << std::endl;
	else
	{
		this->ap -= this->weaponPtr->getAPCost();
		std::cout << this->name << " attack " << _enemy->getType() 
		<< " with a " << this->weaponPtr->getName() << std::endl;
		this->weaponPtr->attack();
		_enemy->takeDamage(this->weaponPtr->getDamage());
		if (_enemy->getHP() <= 0)
			delete _enemy;
	}
}

std::string Character::getName(void) const
{
	return (this->name);
}

int Character::getAP(void) const
{
	return (this->ap);
}

AWeapon *Character::getAWeaponPtr(void) const
{
	return (this->weaponPtr);
}

std::ostream &operator<<(std::ostream &os, const Character &_character)
{
	if (_character.getAWeaponPtr() == NULL)
	{
		os << _character.getName() << " has " << _character.getAP() 
		<< " AP and is unarmed" << std::endl;
	}
	else
	{
		os << _character.getName() << " has " << _character.getAP() 
		<< " AP and wields a " << _character.getAWeaponPtr()->getName()
		<< std::endl;
	}
	return (os);
}