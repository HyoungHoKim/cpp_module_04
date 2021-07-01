#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "unknown";
	this->_xp = 0;
}

AMateria::AMateria(std::string _type)
: type(_type)
{
	this->_xp = 0;
}

AMateria::AMateria(const AMateria &_amateria)
{
	*this = _amateria;
}

AMateria::~AMateria()
{ }

AMateria &AMateria::operator=(const AMateria &_amateria)
{
	if (this == &_amateria)
		return (*this);
	this->type = _amateria.getType();
	this->_xp = _amateria.getXP();
	return (*this);
}

std::string const &AMateria::getType(void) const
{
	return (this->type);
}

unsigned int AMateria::getXP(void) const
{
	return (this->_xp);
}

void AMateria::setType(std::string _type)
{
	this->type = _type;
}

void AMateria::setXP(int xp)
{
	this->_xp = xp;
}

AMateria* AMateria::clone(void) const
{
	return (new AMateria(*this));
}

void AMateria::use(ICharacter& target)
{
	this->_xp += 10;
}