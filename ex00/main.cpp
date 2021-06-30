#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Peom.hpp"

void my_test(void)
{
	std::cout << "------- My Test -------" << std::endl;
	Sorcerer robert("Robert", "the Magnificent");

	Peon jim("Jimmy");
	Peom joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);
	return ;
}

void basic_test(void)
{
	std::cout << "------- Basic Test -------" << std::endl;
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);
	return ;
}

int main()
{
	basic_test();
	my_test();
	return 0;
}