#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string _name, std::string _title)
: name(_name), title(_title)
{
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &_sorcerer)
{
	this->name = _sorcerer.get_name();
	this->title = _sorcerer.get_title();
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title 
	<< ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &_sorcerer)
{
	if (this == &_sorcerer)
		return (*this);
	this->name = _sorcerer.get_name();
	this->title = _sorcerer.get_title();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Sorcerer &_sorcerer)
{
	os << "I am " << _sorcerer.get_name() << ", " << _sorcerer.get_title()
	<< ", and I like ponies!" << std::endl; 
	return (os);
}

std::string Sorcerer::get_name(void) const
{
	return (this->name);
}

std::string Sorcerer::get_title(void) const
{
	return (this->title);
}

void Sorcerer::polymorph(Victim const &_victim) const
{
	_victim.getPolymorphed();
}