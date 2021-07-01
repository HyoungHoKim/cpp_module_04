#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &_ice);
	virtual ~Ice();
	Ice &operator=(const Ice &_ice);

	Ice* clone(void) const;
	void use(ICharacter& target);
};

#endif