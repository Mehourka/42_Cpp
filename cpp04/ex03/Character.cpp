#include "Character.hpp"

Character::Character(): _name("Anon")
{
	Log("Character Def. Constr. called");
}

Character::Character(const std::string & name): _name(name)
{
	Log("Character Str. Constr. called");

}

Character::Character(const Character & other)
{
	Log("Character Copy Constr. called");

	*this = other;
}

Character & Character::operator=(const Character & other)
{
	Log("Character Assignation Constr. called");
	this->_name = other.getName();
	return *this;
}

Character::~Character()
{

}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if(!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
	std::cout << "Cannot Equipe: inventory full" << std::endl;
}

void Character::unequip(int idx)
{
	(void) idx;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	(void) idx;
	(void) target;
}

void Character::printInventory() const
{
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		std::cout << _inventory[i];
	}
}

std::ostream & operator << (std::ostream & o, const Character &character)
{
	o << character.getName();
	return (o);
}