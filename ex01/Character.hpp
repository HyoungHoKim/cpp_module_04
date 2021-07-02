#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
private:
	Character();
	std::string name;
	int ap;
	AWeapon *weaponPtr;

public:
	Character(std::string const &name);
	Character(const Character &_character);
	~Character();
	Character &operator=(const Character &_character);

	void recoverAP(void);
	void equip(AWeapon *_aweapon);
	void attack(Enemy *_enemy);

	std::string const &getName(void) const;
	int getAP(void) const;
	AWeapon *getAWeaponPtr(void) const;
};

std::ostream &operator<<(std::ostream &os, const Character &_character);

#endif