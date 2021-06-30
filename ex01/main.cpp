#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

#include "Character.hpp"

void my_test(void)
{
	std::cout << "------- My Test -------" << std::endl;
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	std::cout << pr->getName() << std::endl;
	std::cout << pf->getName() << std::endl;

	pr->attack();
	pf->attack();

	Enemy* sm = new SuperMutant();
	Enemy* rs = new RadScorpion();

	std::cout << sm->getType() << std::endl;
	std::cout << rs->getType() << std::endl;
	
	sm->takeDamage(30);
	rs->takeDamage(26);
	std::cout << sm->getHP() << std::endl;
	std::cout << rs->getHP() << std::endl;
	
	Character *me = new Character("me");
	me->equip(pr);
	std::cout << *me;
	me->attack(sm);
	me->attack(sm);
	me->attack(sm);
	me->attack(sm);
	me->attack(sm);
	me->attack(sm);
	me->attack(sm);
	me->attack(sm);
	me->attack(sm);
	me->recoverAP();
	me->attack(sm);

	return ;
}

void basic_test(void)
{
	std::cout << "------- Basic Test -------" << std::endl;
	Character* me = new Character("me");

	std::cout << *me;

	Enemy* b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	return ;
}

int main(void)
{
	basic_test();
	my_test();
	return 0;
}