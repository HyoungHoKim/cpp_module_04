#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "MateriaSource.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria **inventory;
	int save_cnt;

public:
	Character(std::string _name);
	Character(const Character &_character);
	virtual ~Character();
	Character &operator=(const Character &_character);

	std::string const & getName() const;
	AMateria **getInventory(void) const;
	int	getSaveCnt(void) const;

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif