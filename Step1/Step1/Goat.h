/**
* \file Goat.h
*
* \author Gabriella Kelsch Bledsoe
*
* Class that describes a goat.
*/

#pragma once

#include <string>
#include "Animal.h"

/**
 * Describes a single goat.
 */
class CGoat : public CAnimal
{
public:

	/// The types of goats can have on farm
	enum Type { Nanny, Billy, Wether, MaleKid, FemaleKid };

	/// Get the information of the goat
	void ObtainGoatInformation();
	
	/// Show the information about the goat
	void DisplayAnimal();
	
	/**
	* Determine if an animal is female
	* \return bool true if the animal is female
	*/
	bool IsFemale();

private:
	/// The goat's name
	std::string mName;

	/// The type of goat: Nanny, Billy, Wether, MaleKid, FemaleKid
	Type mType;
};
