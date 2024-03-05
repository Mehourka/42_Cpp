#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	// Test the copy constructor
	MateriaSource *tmp_src = new MateriaSource();
	tmp_src->learnMateria(new Ice());
	tmp_src->learnMateria(new Cure());

	IMateriaSource *src = new MateriaSource(*tmp_src);
	delete tmp_src;

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	AMateria::deleteUnequipedMaterias();

	return 0;
}

// int main(void)
// {

// 	// Creating Characters
// 	Character *steve = new Character("Steve");
// 	std::cout << *steve << " Has joined the party" << std::endl;
// 	Character *bob = new Character("Bob");
// 	std::cout << *bob << " Has joined the party" << std::endl;
// 	std::cout << std::endl;

// 	// Creating AMaterias
// 	AMateria *m_ice = new Ice();
// 	AMateria *m_cure = new Cure();
// 	AMateria *tmp_ice = new Ice();
// 	std::cout << std::endl;

// 	// Equipe materias
// 	steve->equip(m_ice);
// 	steve->equip(m_cure);
// 	bob->equip(tmp_ice);
// 	std::cout << std::endl;

// 	AMateria::printMateriaList();

// 	// Copy character name and items
// 	*bob = *steve;
// 	steve->unequip(1); // Item dropped but not destroyed
// 	std::cout << std::endl;

// 	// print inventories
// 	steve->printInventory(); // Ice
// 	bob->printInventory();	 // Ice, Cure

// 	// Use all item slots
// 	for (int i = 0; i < 4; i++)
// 	{
// 		steve->use(i, *bob);
// 		bob->use(i, *steve);
// 	}

// 	AMateria::printMateriaList();

// 	// Delete all items
// 	delete steve;
// 	delete bob;
// 	AMateria::deleteUnequipedMaterias();

// 	AMateria::printMateriaList();
// }
