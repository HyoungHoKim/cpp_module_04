#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad
{
private:
	int count;
	ISpaceMarine **army;
	ISpaceMarine **army_old_ptr;

public:
	Squad();
	Squad(const Squad &_squad);
	virtual ~Squad();
	Squad &operator=(const Squad &_squad);

	int getCount(void) const;
	ISpaceMarine* getUnit(int idx) const;
	int push(ISpaceMarine* soldier);
};

#endif