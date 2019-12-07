/**
 * \file Chicken.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Declaration of the CChicken class.
 */

#pragma once

#include <string>
#include "Animal.h"

 /** Class that describes a chicken.
 */
class CChicken : public CAnimal
{
public:
	CChicken();
	virtual ~CChicken();

	/// Get the information of the chicken
	void ObtainChickenInformation();

	/// Show the information about the chicken
	void DisplayAnimal();

	/**
	* Determine if an animal is female
	* \return bool true if the animal is female
	*/
	bool IsFemale();

private:
	/// The chicken's ID
	std::string mId;
};