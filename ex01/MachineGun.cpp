#include "MachineGun.hpp"

MachineGun::MachineGun()
: AWeapon("Machine Gun", 15, 20)
{ }

MachineGun::MachineGun(const MachineGun &_MachineGun)
: AWeapon(_MachineGun)
{ }

MachineGun::~MachineGun()
{ }

MachineGun &MachineGun::operator=(const MachineGun &_MachineGun)
{
	if (this == &_MachineGun)
		return (*this);
	this->AWeapon::operator=(_MachineGun);
	return (*this);
}

void MachineGun::attack(void) const
{
	std::cout << "* Udaaaaaa.... *" << std::endl;
}