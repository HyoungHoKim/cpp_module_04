#include "PowerFist.hpp"

PowerFist::PowerFist()
: AWeapon("Power Fist", 8, 50)
{ }

PowerFist::PowerFist(const PowerFist &_powerfist)
: AWeapon(_powerfist)
{ }

PowerFist::~PowerFist()
{ }

PowerFist &PowerFist::operator=(const PowerFist &_powerfist)
{
	if (this == &_powerfist)
		return (*this);
	this->AWeapon::operator=(_powerfist);
	return (*this);
}

void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}