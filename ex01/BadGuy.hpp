#ifndef BADGUY_HPP
# define BADGUY_HPP

#include "Enemy.hpp"

class BadGuy : public Enemy
{
public:
	BadGuy();
	BadGuy(const BadGuy &_BadGuy);
	virtual ~BadGuy();
	BadGuy &operator=(const BadGuy &_BadGuy);
};

#endif