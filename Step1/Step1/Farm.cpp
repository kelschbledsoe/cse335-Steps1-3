/**
 * \file Farm.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */

#include "Farm.h"


 /**
  * Destructor.
  */
CFarm::~CFarm()
{
	// Iterate over all of the animals, destroying 
	// each one.
	for (auto animal : mInventory)
	{
		delete animal;
	}

	// And clear the list
	mInventory.clear();
}


/** Add an animal to the farm inventory.
*
* \param animal An animal to add to the inventory
*/
void CFarm::AddAnimal(CAnimal* animal)
{
	mInventory.push_back(animal);
}

/**
* Display the farm inventory.
*/
void CFarm::DisplayInventory()
{
	for (auto animal : mInventory)
	{
		animal->DisplayAnimal();
	}
}

/**
* Shows how many animals in inventory are female.
*/
int CFarm::CountFemale()
{
	int FemaleCount = 0;
	for (auto animal : mInventory)
	{
		if (animal->IsFemale())
		{
			FemaleCount++;
		}
	}
	return FemaleCount;
}