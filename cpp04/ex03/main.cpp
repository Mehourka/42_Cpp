#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"


int main (void)
{

	// Creating Characters
	Character *steve = new Character("Steve");
	std::cout << *steve << " Has joined the party" <<std::endl;
	Character *bob = new Character("Bob");
	std::cout << *bob << " Has joined the party" << std::endl;
	std::cout << std::endl;

	// Creating AMaterias
	AMateria *m_ice = new Ice();
	AMateria *m_cure = new Cure();
	AMateria *tmp_ice = new Ice();
	std::cout << std::endl;

	// Equipe materias
	steve->equip(m_ice);
	steve->equip(m_cure);
	bob->equip(tmp_ice);
	std::cout << std::endl;

	AMateria::printMateriaList();

	// Copy character name and items
	*bob = *steve;
	steve->unequip(1); // Item dropped but not destroyed
	std::cout << std::endl;

	// print inventories
	steve->printInventory(); // Ice
	bob->printInventory(); // Ice, Cure

	// Use all item slots
	for (int i = 0; i < 4; i++)
	{
		steve->use(i, *bob);
		bob->use(i, *steve);
	}

	AMateria::printMateriaList();

	// Delete all items
	delete steve;
	delete bob;
	AMateria::deleteUnequipedMaterias();

	AMateria::printMateriaList();
}