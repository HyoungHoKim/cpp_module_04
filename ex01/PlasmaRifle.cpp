#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
: AWeapon("Plasma Rifle", 5, 21)
{ }

PlasmaRifle::PlasmaRifle(const PlasmaRifle &_plasmarifle)
: AWeapon(_plasmarifle)
{ }

PlasmaRifle::~PlasmaRifle()
{ }

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &_plasmarifle)
{
	if (this == &_plasmarifle)
		return (*this);
	this->AWeapon::operator=(_plasmarifle);
	return (*this);
}

void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}