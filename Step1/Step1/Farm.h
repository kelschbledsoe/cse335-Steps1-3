/**
 * \file Farm.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class that describes a Farm.
 * 
 * This class holds a collection of animals that make
 * up the inventory of a farm.
 */

#pragma once
#include <vector>
#include "Cow.h"

 /**
  * Class that describes a farm.
  *
  * Holds a collection of animals that make up the farm
  * inventory.
  */
class CFarm
{
public:
	virtual ~CFarm();

	/// Adds animal to inventory
	/// param animal An animal to add to the inventory 
	void AddAnimal(CAnimal* animal);

	/// Shows animals in inventory
	void DisplayInventory();

	/**
	* Shows how many animals in inventory are female
	* \return int of number of female animals
	*/
	int CountFemale();

private:
	/// A list with the inventory of all animals on the farm
	std::vector<CAnimal*> mInventory;
};
