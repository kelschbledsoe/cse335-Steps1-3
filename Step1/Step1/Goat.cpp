/**
 * \file Cow.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */

#include <iostream>
#include "Goat.h"

using namespace std;



/** Obtain information from the user about this goat.
 *
 * Asks the user for the information that describes a goat.
 */
void CGoat::ObtainGoatInformation()
{
	cout << endl;
	cout << "Input information about the goat" << endl;

	// Obtain the name. This is easy, since it's just a
	// string.
	cout << "Name: ";
	cin >> mName;

	// Obtain the type using a menu. We have a loop so
	// we can handle errors.
	bool valid = false;
	while (!valid)
	{
		cout << "1: Nanny" << endl;
		cout << "2: Billy" << endl;
		cout << "3: Wether" << endl;
		cout << "4: Male Kid" << endl;
		cout << "5: Female Kid" << endl;
		cout << "Enter selection and return: ";
		int option;
		cin >> option;
		if (!cin)
		{
			// We have an error. Clear the input and try again
			cin.clear();
			cin.ignore();
			continue;
		}

		switch (option)
		{
		case 1:
			mType = Nanny;
			valid = true;
			break;

		case 2:
			mType = Billy;
			valid = true;
			break;

		case 3:
			mType = Wether;
			valid = true;
			break;

		case 4:
			mType = MaleKid;
			valid = true;
			break;

		case 5:
			mType = FemaleKid;
			valid = true;
			break;
		}
	}
}

/**
 * Display information about this goat.
 */
void CGoat::DisplayAnimal()
{
	cout << mName << ": ";
	switch (mType)
	{
	case Nanny:
		cout << "Nanny" << endl;
		break;

	case Billy:
		cout << "Billy" << endl;
		break;

	case Wether:
		cout << "Wether" << endl;
		break;

	case MaleKid:
		cout << "Male Kid" << endl;
		break;

	case FemaleKid:
		cout << "Female Kid" << endl;
		break;
	}
}

/**
* Returns whether the specified goat is female or not.
*/
bool CGoat::IsFemale()
{
	switch (mType)
	{
	case Nanny:
		return true;

	case Billy:
		return false;

	case Wether:
		return false;

	case MaleKid:
		return false;

	case FemaleKid:
		return true;
	}
	return false;
}