#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
	std::string type;
	unsigned int _xp;

public:
	AMateria();
	AMateria(std::string _type);
	AMateria(const AMateria &_amateria);
	virtual ~AMateria();
	AMateria &operator=(const AMateria &_amateria);
	
	std::string const &getType(void) const;
	unsigned int getXP(void) const;

	void setType(std::string _type);
	void setXP(int xp);

	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);
};

#endif