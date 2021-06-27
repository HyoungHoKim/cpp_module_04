#include "Peon.hpp"

Peon::Peon(std::string _name)
: Victim(_name) 
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &_peon)
: Victim(_peon)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator=(const Peon &_peon)
{
	if (this == &_peon)
		return (*this);
	this->Victim::operator=(_peon);
	return (*this);
}
std::ostream &operator<<(std::ostream &os, const Peon &_peon)
{
	os << "I'm " << _peon.get_name() << " and I like otters!" << std::endl;
	return (os);
}

void Peon::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a pink pony!" << std::endl;
}