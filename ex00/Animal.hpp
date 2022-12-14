#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "colours.h"

using std::string;

class	Animal
{
	public:
		Animal(void);
		Animal(Animal const &tocopy);
		Animal	&operator=(Animal const &toassign);
		virtual ~Animal(void);

		virtual void	makeSound(void) const;

		string	const &getType(void) const;
	protected:
		string	_type;
};

#endif