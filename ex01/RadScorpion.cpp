#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
: Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &_radscorpion)
: Enemy(_radscorpion)
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion &RadScorpion::operator=(const RadScorpion &_radscorpion)
{
	if (this == &_radscorpion)
		return (*this);
	this->Enemy::operator=(_radscorpion);
	return (*this);	
}