#include "Character.hpp"

Character::Character(std::string _name)
: name(_name)
{
	this->save_cnt = 0;
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(const Character &_character)
{
	*this = _character;
}

Character::~Character()
{
	for (int i = 0; i < this->save_cnt; i++)
		delete this->inventory[i];
	delete[] this->inventory;
}

Character &Character::operator=(const Character &_character)
{
	if (this == &_character)
		return (*this);
	for (int i = 0; i < this->save_cnt; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = _character.getInventory()[i]->clone(); 
	}
	this->save_cnt = _character.getSaveCnt();
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->name);
}

AMateria **Character::getInventory(void) const
{
	return (this->inventory);
}

int	Character::getSaveCnt(void) const
{
	return (this->save_cnt);
}

void Character::equip(AMateria* m)
{
	if (!m || this->save_cnt > 3)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			this->save_cnt++;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (this->inventory[idx] == 0)
		std::cout << "It's empty!" << std::endl;
	else if (idx < 0 || idx > 3)
		std::cout << "Wrond Index" << std::endl;
	else
	{
		for (int i = idx; i < 3; i++)
		{
			this->inventory[i] = this->inventory[i + 1];
			this->inventory[i + 1] = 0;
		}
		this->save_cnt--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < this->save_cnt)
		this->inventory[idx]->use(target);
}