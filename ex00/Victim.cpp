#include "Victim.hpp"

Victim::Victim(std::string _name) : name(_name)
{
	std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &_victim)
{
	this->name = _victim.get_name();
	std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name << " just died for no apparent reason!" << std::endl;
}
	
Victim &Victim::operator=(const Victim &_victim)
{
	if (this == &_victim)
		return (*this);
	this->name = _victim.get_name();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Victim &_victim)
{
	os << "I'm " << _victim.get_name() << " and I like otters!" << std::endl;
	return (os);
}

std::string Victim::get_name(void) const
{
	return (this->name);
}

void Victim::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}