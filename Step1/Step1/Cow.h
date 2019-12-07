/**
* \file Cow.h
*
* \author Gabriella Kelsch Bledsoe
*
* Class that describes a cow.
*/

#pragma once

#include <string>
#include "Animal.h"

/**
 * Describes a single cow.
 */
class CCow : public CAnimal
{
public:

	/// The types of cows can have on farm
	enum Type { Bull, BeefCow, MilkCow };

	/// Get the information of the cow
	void ObtainCowInformation();

	/// Show the information about the cow
	void DisplayAnimal();

	/**
	* Determine if an animal is female
	* \return bool true if the animal is female
	*/
	bool IsFemale();

private:
	/// The cow's name
	std::string mName;

	/// The type of code: Bull, BeefCow, or MilkCow
	Type mType = MilkCow;

	/// The milk production for a cow in gallons per day
	double mMilkProduction = 0;
};
