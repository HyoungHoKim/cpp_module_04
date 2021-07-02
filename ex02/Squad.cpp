#include "Squad.hpp"

Squad::Squad()
{
	this->count = 0;
	this->army = NULL;
	this->army_old_ptr = NULL;
}

Squad::Squad(const Squad &_squad)
{
	if (this->army != NULL && this->count > 0)
	{
		for (int i = 0; i < this->count; i++)
			delete(this->army[i]);
		delete[] this->army;
		delete[] this->army_old_ptr;
		this->army = NULL;
		this->army_old_ptr = NULL;
	}
	this->count = _squad.getCount();
	if (this->count > 0)
	{
		this->army = new ISpaceMarine*[this->count];
		this->army_old_ptr = new ISpaceMarine*[this->count];
		for (int i = 0; i < this->count; i++)
		{
			this->army[i] = _squad.getUnit(i)->clone();
			this->army_old_ptr[i] = _squad.getUnit(i);
		}
	}
}

Squad::~Squad()
{
	if (this->army != NULL)
	{
		for (int i = 0; i < this->count; i++)
			delete(this->army[i]);
		delete[] this->army;
		delete[] this->army_old_ptr;
	}
}

Squad &Squad::operator=(const Squad &_squad)
{
	if (this == &_squad)
		return (*this);
	if (this->army != NULL && this->count > 0)
	{
		for (int i = 0; i < this->count; i++)
			delete(this->army[i]);
		delete[] this->army;
		delete[] this->army_old_ptr;
		this->army = NULL;
		this->army_old_ptr = NULL;
	}
	this->count = _squad.getCount();
	if (this->count > 0)
	{
		this->army = new ISpaceMarine*[this->count];
		this->army_old_ptr = new ISpaceMarine*[this->count];
		for (int i = 0; i < this->count; i++)
		{
			this->army[i] = _squad.getUnit(i)->clone();
			this->army_old_ptr[i] = _squad.getUnit(i);
		}
	}
	return (*this);
}

int Squad::getCount(void) const
{
	return (this->count);
}

ISpaceMarine* Squad::getUnit(int n) const
{
	if (this->count >= n && this->army)
		return (this->army[n]);
	else
		return (NULL);
}

int Squad::push(ISpaceMarine* soldier)
{
	if (soldier)
	{
		for (int i = 0; i < this->count; i++)
		{
			if (this->army_old_ptr[i] == soldier)
				return (this->count);
		}
		ISpaceMarine **temp = new ISpaceMarine*[this->count + 1];
		ISpaceMarine **temp_old = new ISpaceMarine*[this->count + 1];
		for (int i = 0; i < this->count; i++)
		{
			temp[i] = this->army[i];
			temp_old[i] = this->army_old_ptr[i];
		}
		delete[] this->army;
		delete[] this->army_old_ptr;
		this->army = temp;
		this->army_old_ptr = temp_old;
		this->army[this->count] = soldier->clone();
		this->army_old_ptr[this->count] = soldier;
		this->count++;
	}
	return (this->count);
}