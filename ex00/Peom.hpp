#ifndef PEOM_HPP
# define PEOM_HPP

#include <iostream>
#include <string>

#include "Victim.hpp"

class Peom : public Victim
{
public:
	Peom(std::string _name);
	Peom(const Peom &_peom);
	virtual ~Peom();
	Peom &operator=(const Peom &_peom);

	void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &os, const Peom &_peon);

#endif