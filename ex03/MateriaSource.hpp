#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria **am_save;
	int save_cnt;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &_ms);
	virtual ~MateriaSource();
	MateriaSource &operator=(const MateriaSource &_ms);

	AMateria **getSavePtr(void) const;
	int	getSaveCnt(void) const;

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif