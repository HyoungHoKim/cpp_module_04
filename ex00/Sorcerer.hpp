#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include <string>

#include "Victim.hpp"

class Sorcerer
{
private:
	Sorcerer();

	std::string name;
	std::string title;

public:
	Sorcerer(std::string _name, std::string _title);
	Sorcerer(const Sorcerer &_sorcerer);
	~Sorcerer();
	Sorcerer &operator=(const Sorcerer &_sorcerer);

	std::string get_name(void) const;
	std::string get_title(void) const;

	void polymorph(Victim const &) const;
};

std::ostream &operator<<(std::ostream &os, const Sorcerer &_sorcerer);

#endif 