#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

void my_test(void)
{
	std::cout << "------- My Test -------" << std::endl;
	ISpaceMarine* a = new TacticalMarine;
	ISpaceMarine* b = new AssaultTerminator;
	ISpaceMarine* c = new TacticalMarine;
	ISpaceMarine* d = new AssaultTerminator;
	ISpaceMarine* e = new TacticalMarine;

	ISquad* vlc = new Squad;
	std::cout << "--- Empty_case ---" << std::endl;
	std::cout << vlc->getCount() << std::endl;
	std::cout << vlc->getUnit(0) << std::endl;
	std::cout << vlc->getUnit(5) << std::endl;
	std::cout << vlc->push(NULL) << std::endl;

	std::cout << "--- Same_Unit ---" << std::endl;
	vlc->push(a);
	vlc->push(a);
	std::cout << vlc->getCount() << std::endl;
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
}

void basic_test(void)
{
	std::cout << "------- Basic Test -------" << std::endl;
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;
	delete bob;
	delete jim;
}

int main()
{

	basic_test();
	my_test();
	system("leaks a");
	return 0;
}