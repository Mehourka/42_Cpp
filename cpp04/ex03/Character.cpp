#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Anon")
{
	Log("Character Def. Constr. called");
	for (int i = 0; i < Character::_inventory_size; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
	Log("Character Str. Constr. called");
	for (int i = 0; i < Character::_inventory_size; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	Log("Character Copy Constr. called");
	for (int i = 0; i < Character::_inventory_size; i++)
		_inventory[i] = NULL;
	*this = other;
}

Character &Character::operator=(const Character &other)
{

	AMateria *otherItem;

	this->deleteInventory();
	this->_name = getName() + " (" + other.getName() + "'s copy)";
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		otherItem = other._inventory[i];
		if (otherItem)
			equip(otherItem->clone());
	}
	Log("Character Assignation Constr. called");
	return *this;
}

Character::~Character()
{
	Log("Character Destructor Called");
	deleteInventory();
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;

	if (m->getOwner() != NULL)
	{
		std::cout << "Cannot Equipe another Character's item" << std::endl;
		return;
	}

	for (int i = 0; i < Character::_inventory_size; i++)
	{
		if (!_inventory[i])
		{
			std::cout << getName() << " equiped " << m->getType() << std::endl;
			m->setOwner(this);
			_inventory[i] = m;
			return;
		}
	}
	std::cout << "Cannot Equipe: inventory full" << std::endl;
}

void Character::unequip(int idx)
{
	AMateria *m;

	m = _inventory[idx];
	if (m != NULL)
	{
		std::cout << getName() << " droped " << m->getType() << std::endl;
		_inventory[idx]->setOwner(NULL);
	}
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	AMateria *materia;

	if (idx < 0 && idx > Character::_inventory_size)
		return;

	materia = _inventory[idx];
	if (materia)
		materia->use(target);
}

void Character::printInventory() const
{
	AMateria *item;
	std::cout << getName() << "'s Inventory: " << std::endl;
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		item = _inventory[i];
		if (item)
			std::cout << " - " << _inventory[i]->getType() << "\n";
	}
	std::cout << std::endl;
}

void Character::deleteInventory()
{
	AMateria *item;
	for (int i = 0; i < Character::_inventory_size; i++)
	{
		item = _inventory[i];
		if (item) delete item;
		_inventory[i] = NULL;
	}
}

std::ostream &operator<<(std::ostream &o, const Character &character)
{
	o << character.getName();
	return (o);
}
