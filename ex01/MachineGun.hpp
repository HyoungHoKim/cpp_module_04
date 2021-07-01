#ifndef MACHINEGUN_HPP
# define MACHINEGUN_HPP

#include "AWeapon.hpp"

class MachineGun : public AWeapon
{
public:
	MachineGun();
	MachineGun(const MachineGun &_MachineGun);
	virtual ~MachineGun();
	MachineGun &operator=(const MachineGun &_MachineGun);

	void attack(void) const;
};

#endif 