#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "colours.h"
#include <iostream>
#include <stdlib.h> // to use system leaks

using std::string;
using std::cout;
using std::endl;


// main() to test AMateria
// int	main(void)
// {
// 	cout << BYEL "Testing AMateria..." RESET << endl << endl;;
// 	cout << UWHT "Constructing an Ice Materia.." RESET << endl;
// 	Ice a;
// 	cout << endl;
	
// 	cout << UWHT "Getting the type..." RESET << endl;
// 	cout << a.getType() << endl << endl;

// 	cout << BYEL "Testing copy constructor..." RESET << endl << endl;
// 	Ice b(a);
// 	cout << endl;

// 	cout << UWHT "Getting the type..." RESET << endl;
// 	cout << b.getType() << endl << endl;

// 	cout << BYEL "Testing assignment operator..." RESET << endl << endl;
// 	Ice c;
// 	c = a;
// 	cout << endl;

// 	cout << UWHT "Getting the type..." RESET << endl;
// 	cout << c.getType() << endl << endl;

// }

// main() to test Character
void	test(void)
{
	cout << BYEL "TESTING CHARACTERS" RESET << endl;
	cout << UWHT "Creating a character (a) named Alpha..." RESET << endl;
	ICharacter *a = new Character("Alpha");
	cout << endl;

	cout << UWHT "Creating 3 Materias using MateriaSource..." RESET << endl;
	IMateriaSource *ms = new MateriaSource();
	ms->learnMateria(new Cure());
	ms->learnMateria(new Cure());
	ms->learnMateria(new Ice());
	cout << endl;

	cout << UWHT "Character (a) equipping Materias..." RESET << endl;
	AMateria *tmp;
	tmp = ms->createMateria("cure");
	a->equip(tmp);
	tmp = ms->createMateria("cure");
	a->equip(tmp);
	tmp = ms->createMateria("cure");
	a->equip(tmp);
	tmp = ms->createMateria("ice");
	a->equip(tmp);
	cout << endl;

	cout << UWHT "Printing (a) the inventory..." RESET << endl;
	a->showInventory();
	cout << endl;

	cout << UWHT "Creating another character (b) named Bravo..." RESET << endl;
	ICharacter *b = new Character("Bravo");
	cout << endl;

	cout << UWHT "Printing Bravo's inventory..." RESET << endl;
	b->showInventory();
	cout << endl;

	int idx = 3; // change this value to test
	cout << UWHT "Making Alpha unequip inventory at index " << idx << RESET << endl;
	a->unequip(idx);
	cout << endl;

	cout << UWHT "Printing Alpha's inventory..." RESET << endl;
	a->showInventory();
	cout << UWHT "Printing Bravo's inventory..." RESET << endl;
	b->showInventory();
	cout << endl;

	int idx2 = 3; // change this value to test
	cout << UWHT "Making Alpha use item at idx " << idx2 << " towards Bravo" RESET << endl;
	a->use(idx2, *b);
	cout << endl;

	cout << BYEL "ENDING PROGRAMME" RESET << endl;
	delete a;
	delete b;
	delete ms;

}

void	test2(void)
{
	ICharacter *a = new Character("alpha");
	IMateriaSource *ms = new MateriaSource();
	AMateria	*temp;

	ms->learnMateria(new Ice());
	ms->learnMateria(new Cure());
	ms->learnMateria(new Ice());
	temp = ms->createMateria("cure");
	a->equip(temp);
	temp = ms->createMateria("ice");
	a->equip(temp);
	temp = ms->createMateria("ice");
	a->equip(temp);
	temp = ms->createMateria("ice");
	a->equip(temp);
	a->showInventory();

	delete a;
	delete ms;
}


// Creating this function specifically to test if instantiating a 2nd
// character object will reset the Character::hold attribute back to NULL
// Answer is; no it won't
void	test3(void)
{
	Character a("a");
	AMateria *c = new Cure();
	a.equip(c);
	cout << "1" << endl;
	a.showInventory();
	a.unequip(0);
	cout << "2" << endl;
	a.showInventory();
	Character b("b");
	// (void)b;
}

int	main(void)
{
	test3();
	// system("leaks finalfantasy");
	return (0);
}