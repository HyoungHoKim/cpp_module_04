#include "Peom.hpp"

Peom::Peom(std::string _name)
: Victim(_name) 
{
	std::cout << "Jog Jog." << std::endl;
}

Peom::Peom(const Peom &_Peom)
: Victim(_Peom)
{
	std::cout << "Jog Jog." << std::endl;
}

Peom::~Peom()
{
	std::cout << "Dleuark..." << std::endl;
}

Peom &Peom::operator=(const Peom &_Peom)
{
	if (this == &_Peom)
		return (*this);
	this->Victim::operator=(_Peom);
	return (*this);
}
std::ostream &operator<<(std::ostream &os, const Peom &_Peom)
{
	os << "I'm " << _Peom.get_name() << " and I like pony!" << std::endl;
	return (os);
}

void Peom::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a pink otters!" << std::endl;
}