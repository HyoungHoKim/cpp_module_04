#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	PowerFist(const PowerFist &_powerfist);
	~PowerFist();
	PowerFist &operator=(const PowerFist &_powerfist);

	void attack(void) const;
};

#endif