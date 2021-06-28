#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

int main(void)
{
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

	sm->takeDamage(1000);
	rs->takeDamage(1000);
	std::cout << sm->getHP() << std::endl;
	std::cout << rs->getHP() << std::endl;
	
	delete sm;
	delete rs;
	return 0;
}