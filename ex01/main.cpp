#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "MachineGun.hpp"

#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "BadGuy.hpp"

#include "Character.hpp"

void my_test(void)
{
	std::cout << "------- My Test -------" << std::endl;
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	AWeapon* mg = new MachineGun();

	std::cout << pr->getName() << std::endl;
	std::cout << pf->getName() << std::endl;
	std::cout << mg->getName() << std::endl;

	pr->attack();
	pf->attack();
	mg->attack();

	Enemy* sm = new SuperMutant();
	Enemy* rs = new RadScorpion();
	Enemy* bg = new BadGuy();

	std::cout << sm->getType() << std::endl;
	std::cout << rs->getType() << std::endl;
	std::cout << bg->getType() << std::endl;
	
	sm->takeDamage(30);
	rs->takeDamage(26);
	bg->takeDamage(40);
	std::cout << sm->getHP() << std::endl;
	std::cout << rs->getHP() << std::endl;
	std::cout << bg->getHP() << std::endl;
	
	Character *me = new Character("me");
	me->recoverAP();
	std::cout << "Over Recovery Check : " << me->getAP() << std::endl;
	me->equip(mg);
	std::cout << *me;
	me->attack(bg);
	std::cout << "Loose AP Check : " << me->getAP() << std::endl;
	me->attack(bg);
	me->attack(bg);
	me->attack(bg);
	me->attack(bg);
	me->attack(bg);
	me->attack(bg);
	me->attack(bg);
	std::cout << "Recovery Empty : ";
	me->attack(bg);
	std::cout << "Recovery Check : " << me->getAP() << std::endl;
	me->recoverAP();
	std::cout << "Recovery Check : " << me->getAP() << std::endl;
	me->attack(bg);

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