/**
 * \file Animal.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class that describes an Animal.
 */

#pragma once

 /**
  * Class that describes an Animal.
  */
class CAnimal
{
public:
	virtual ~CAnimal();
	/// Display an animal.
	virtual void DisplayAnimal() {}
	/**
	* Determine if an animal is female
	* \return bool true if the animal is female
	*/
	virtual bool IsFemale() { return false; }
};

