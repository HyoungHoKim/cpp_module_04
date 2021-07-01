#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void my_test(void)
{
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria *tmp = new Ice();
	src->learnMateria(tmp);
	delete tmp;
	tmp = new Cure();
	src->learnMateria(tmp);
	delete tmp;
	std::cout <<src->getSaveCnt() << std::endl;
	
	MateriaSource* src1 = new MateriaSource();
	*src1 = *src;
	std::cout << src1->getSaveCnt() << std::endl;

	Character* me = new Character("me");
	tmp = src1->createMateria("ice");
	me->equip(tmp);
	tmp = src1->createMateria("cure");
	me->equip(tmp);
	tmp = src1->createMateria("ice");
	me->equip(tmp);
	tmp = src1->createMateria("cure");
	me->equip(tmp);
	tmp = src1->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	tmp = src1->createMateria("cure");
	me->equip(tmp);
	delete tmp;
	std::cout << me->getSaveCnt() << std::endl;

	me->unequip(0);
	me->unequip(1);
	me->use(-1, *me);
	me->use(0, *me);
	me->use(1, *me);
	me->use(2, *me);
	me->use(3, *me);
	me->use(4, *me);

	delete src;
	delete src1;
	delete me;
}

void basic_test(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main()
{
	basic_test();
	my_test();

	system("leaks ex03");
	return 0;
}