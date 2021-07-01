#include "BadGuy.hpp"

BadGuy::BadGuy()
: Enemy(110, "BadGuy")
{
	std::cout << "* Ha Ha Ha *" << std::endl;
}

BadGuy::BadGuy(const BadGuy &_BadGuy)
: Enemy(_BadGuy)
{
	std::cout << "* Ha Ha Ha *" << std::endl;
}

BadGuy::~BadGuy()
{
	std::cout << "* Kkkkk... *" << std::endl;
}

BadGuy &BadGuy::operator=(const BadGuy &_BadGuy)
{
	if (this == &_BadGuy)
		return (*this);
	this->Enemy::operator=(_BadGuy);
	return (*this);	
}