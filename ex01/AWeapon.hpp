#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon
{
private:
	std::string name;
	int ap_cost;
	int damage;

public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(const AWeapon &_aweapon);
	virtual ~AWeapon();
	AWeapon &operator=(const AWeapon &_aweapon);
	
	std::string getName(void) const;
	int getAPCost(void) const;
	int getDamage(void) const;
	
	virtual void attack(void) const = 0; 
};

#endif