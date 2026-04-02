/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <sabruma@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 01:32:37 by sabruma           #+#    #+#             */
/*   Updated: 2026/04/02 19:34:12 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl << "Creating AAnimal* array" << std::endl;
	AAnimal* animals[4];
	for (size_t i = 0; i < 4; i++)
	{
		(i & 1) == 0 ? animals[i] = new Cat() : animals[i] = new Dog();
	}

	std::cout << std::endl << "Test 1: regular constructions" << std::endl; 
	// const AAnimal* meta = new AAnimal();	//can't instantiate
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();
	// delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "Test 2: wrong constructions" << std::endl; 
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	std::cout << wmeta->getType() << " " << std::endl;
	std::cout << wi->getType() << " " << std::endl;
	wi->makeSound(); //will output the animal sound!
	wmeta->makeSound(); // segfaults because of static linking
	delete wmeta;
	delete wi;

	std::cout << std::endl << "Test 3: brain usage" << std::endl; 
	Dog* dog = new Dog();
	dog->setIdeaAt(0, "I want to bury some bones in the garden");
	std::cout << "(Dog) is thinking: " << dog->getIdeaAt(0) << std::endl;
	dog->makeSound();
	Dog* dog2 = new Dog(*dog);
	std::cout << "(Dog copy) is thinking: " << dog2->getIdeaAt(0) << std::endl;
	delete dog;
	delete dog2;

	Cat* cat = new Cat();
	cat->setIdeaAt(0, "I want to play with that yarn");
	std::cout << "(Cat) is thinking: " << cat->getIdeaAt(0) << std::endl;
	cat->makeSound();
	Cat* cat2 = new Cat(*cat);
	std::cout << "(Cat copy) is thinking: " << cat2->getIdeaAt(0) << std::endl;
	delete cat;
	delete cat2;
	
	std::cout << std::endl << "Freeing array of mixed types" << std::endl; 
	for (size_t i = 0; i < 4; i++)
	{
		delete animals[i];
	}

	return 0;
}