#include "Ice.hpp"

Ice::Ice()
: AMateria("ice")
{ }

Ice::Ice(const Ice &_ice)
{
	*this = _ice;
}

Ice::~Ice()
{ }

Ice &Ice::operator=(const Ice &_ice)
{
	if (this == &_ice)
		return (*this);
	this->setType(_ice.getType());
	this->setXP(_ice.getXP());
	return (*this);
}

Ice* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	this->AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}