#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>
#include <string>

class Victim
{
protected:
	std::string name;

public:
	Victim(std::string _name);
	Victim(const Victim &_victim);
	~Victim();
	Victim &operator=(const Victim &_victim);

	std::string get_name(void) const;

	virtual void getPolymorphed(void) const;
};

std::ostream &operator<<(std::ostream &os, const Victim &_victim);

#endif