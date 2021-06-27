#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>
#include <string>

#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string _name);
	Peon(const Peon &_peon);
	~Peon();
	Peon &operator=(const Peon &_peon);

	void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &os, const Peon &_peon);

#endif