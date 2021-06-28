#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion();
	RadScorpion(const RadScorpion &_radscorpion);
	~RadScorpion();
	RadScorpion &operator=(const RadScorpion &_radscorpion);
};

#endif