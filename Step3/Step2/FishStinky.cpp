/**
 * \file FishStinky.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */

#include "pch.h"
#include <string>
#include "FishStinky.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename
const wstring FishStinkyImageName = L"images/Stinky-fish.png";


/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishStinky::CFishStinky(CAquarium* aquarium) :
	CItem(aquarium, FishStinkyImageName)
{
}

/**
 * Destructor
 */
CFishStinky::~CFishStinky()
{
}