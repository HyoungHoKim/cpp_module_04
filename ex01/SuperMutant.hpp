#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant();
	SuperMutant(const SuperMutant &_supermutant);
	virtual ~SuperMutant();
	SuperMutant &operator=(const SuperMutant &_supermutant);

	void takeDamage(int _damage);
};

#endif