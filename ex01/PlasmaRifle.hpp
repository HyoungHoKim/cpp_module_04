#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &_plasmarifle);
	virtual ~PlasmaRifle();
	PlasmaRifle &operator=(const PlasmaRifle &_plasmarifle);

	void attack(void) const;
};

#endif 