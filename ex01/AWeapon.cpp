#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage)
{
	this->name = name;
	this->ap_cost = apcost;
	this->damage = damage;
}

AWeapon::AWeapon(const AWeapon &_aweapon)
{
	this->name = _aweapon.getName();
	this->ap_cost = _aweapon.getAPCost();
	this->damage = _aweapon.getDamage();
}

AWeapon::~AWeapon() {}

AWeapon &AWeapon::operator=(const AWeapon &_aweapon)
{
	if (this == &_aweapon)
		return (*this);
	this->name = _aweapon.getName();
	this->ap_cost = _aweapon.getAPCost();
	this->damage = _aweapon.getDamage();
	return (*this);
}

const std::string &AWeapon::getName(void) const
{
	return (this->name);
}

int AWeapon::getAPCost(void) const
{
	return (this->ap_cost);
}

int AWeapon::getDamage(void) const
{
	return (this->damage);
}