#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"


int main (void)
{

	// Character *steve = new Character("Steve");
	// std::cout << *steve << " Has joined the party" <<std::endl;

	// Character *bob = new Character("Bob");
	// std::cout << *bob << " Has joined the party" << std::endl;

	Ice *m_ice = new Ice();
	std::cout << *m_ice;
	// m_ice->use(*steve);

	// Cure m_cure = Cure();
	// std::cout << m_cure;

	// // Ice *m_ice2 = m_ice->clone();
	// // std::cout << *m_ice2;

	// steve->printInventory();

	AMateria::printMateriaList();

	// delete steve;
	// delete bob;
	delete m_ice;
	// // delete m_ice2;
}