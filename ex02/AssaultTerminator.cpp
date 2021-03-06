#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &_at)
{
	*this = _at;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator &AssaultTerminator::operator=(const AssaultTerminator &_at)
{
	if (this == &_at)
		return (*this);
	return (*this);
}

AssaultTerminator* AssaultTerminator::clone() const
{
	return (new AssaultTerminator(*this));
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfist *" << std::endl;
}