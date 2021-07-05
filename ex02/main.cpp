#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

void copy_and_oper_test(Squad &squad)
{
	std::cout << "========================= copy and operator= test ======================" << std::endl;

	Squad squad_copy(squad);
	Squad squad_oper;
	squad_oper = squad;

	for(int i = 0; i < squad_copy.getCount(); i++)
	{
		int r = (rand() % 100);
		std::cout << i << ": ";
		if (r > 66)
			squad_copy.getUnit(i)->battleCry();
		else if (r > 33)
			squad_copy.getUnit(i)->rangedAttack();
		else
			squad_copy.getUnit(i)->meleeAttack();
	}

	for(int i=0; i<squad_oper.getCount(); i++)
	{
		int r = (rand() % 100);
		std::cout << i << ": ";
		if (r > 66)
			squad_oper.getUnit(i)->battleCry();
		else if (r > 33)
			squad_oper.getUnit(i)->rangedAttack();
		else
			squad_oper.getUnit(i)->meleeAttack();
	}

	std::cout << "========================= copy and operator= test end ======================" << std::endl;
}


void my_test(void)
{
	std::cout << "------- My Test -------" << std::endl;
	ISpaceMarine* a = new TacticalMarine;
	ISpaceMarine* b = new AssaultTerminator;
	ISpaceMarine* c = new TacticalMarine;
	ISpaceMarine* d = new AssaultTerminator;
	ISpaceMarine* e = new TacticalMarine;

	Squad* vlc = new Squad;
	std::cout << "--- Empty_case ---" << std::endl;
	std::cout << vlc->getCount() << std::endl;
	std::cout << vlc->getUnit(0) << std::endl;
	std::cout << vlc->getUnit(5) << std::endl;
	std::cout << vlc->push(NULL) << std::endl;

	std::cout << "--- Same_Unit ---" << std::endl;
	vlc->push(a);
	vlc->push(a);
	vlc->push(b);
	std::cout << vlc->getCount() << std::endl;
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	copy_and_oper_test(*vlc);

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