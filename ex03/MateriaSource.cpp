#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->am_save = new AMateria*[4]; 
	for (int i = 0; i < 4; i++)
		this->am_save[i] = 0;
	this->save_cnt = 0;
}

MateriaSource::MateriaSource(const MateriaSource &_ms)
{
	*this = _ms;
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->save_cnt; i++)
		delete this->am_save[i];
	delete[] this->am_save;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &_ms)
{
	if (this == &_ms)
		return (*this);
	for (int i = 0; i < this->save_cnt; i++)
		delete this->am_save[i];
	this->save_cnt = _ms.getSaveCnt();
	for (int i = 0; i < this->save_cnt; i++)
		this->am_save[i] = _ms.getSavePtr()[i]->clone(); 
	return (*this);
}

AMateria **MateriaSource::getSavePtr(void) const
{
	return (this->am_save);
}

int	MateriaSource::getSaveCnt(void) const
{
	return (this->save_cnt);
}

void MateriaSource::learnMateria(AMateria* _am)
{
	if (!_am || this->save_cnt == 4)
		return ;
	for (int i = 0; i < this->save_cnt; i++)
		if (this->am_save[i] == _am)
			return ;
	this->am_save[this->save_cnt] = _am;
	this->save_cnt++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->save_cnt; i++)
		if (this->am_save[i]->getType() == type)
			return (this->am_save[i]->clone());
	return (nullptr);
}
