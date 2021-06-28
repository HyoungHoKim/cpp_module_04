#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy 
{
private:
	int hp;
	std::string type;

public:
	Enemy(int hp, std::string const &type);
	Enemy(const Enemy &_enemy);
	virtual ~Enemy();
	Enemy &operator=(const Enemy &_enemy);

	std::string getType(void) const;
	int getHP(void) const;
	
	virtual void takeDamage(int _damage);
};

#endif