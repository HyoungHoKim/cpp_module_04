#include "Cure.hpp"

Cure::Cure()
: AMateria("cure")
{ }

Cure::Cure(const Cure &_cure)
{
	*this = _cure;
}

Cure::~Cure()
{ }

Cure &Cure::operator=(const Cure &_cure)
{
	if (this == &_cure)
		return (*this);
	this->setType(_cure.getType());
	this->setXP(_cure.getXP());
	return (*this);
}

Cure* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	this->AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s " << "wounds *" << std::endl;
}
