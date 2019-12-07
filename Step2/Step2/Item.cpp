/**
 * \file Item.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */


#include "pch.h"
#include "Item.h"
#include "Aquarium.h"


 /// Maximum allowed X value
const double MaxX = 950;

/// Minimum allowed X value
const double MinX = 100;

/// Maximum allowed Y value
const double MaxY = 750;

/// Minimum allowed Y value
const double MinY = 50;

/// Minimum distance from a nudging fish
const double MinDistance = 200;

 /**
  * Constructor
  * \param aquarium The aquarium this item is a member of
  */
CItem::CItem(CAquarium* aquarium) : mAquarium(aquarium)
{
}

 /**
  * Destructor
  */
CItem::~CItem()
{
}


/**
 * Nudges the fish to a new location based on the stinky fish location
 * \param stinkyX 
 * \param stinkyY 
 */
void CItem::Nudge(double stinkyX, double stinkyY)
{
	// fishX, fishY is the position of a fish
	// stinkyX, stinkyY is the position of the stinky 
	double fishX = mX;
	double fishY = mY;

	// Create a vector in the direction we are from the nudger
	double dx = fishX - stinkyX;
	double dy = fishY - stinkyY;

	// Determine how far away we are
	double distance = sqrt(dx * dx + dy * dy);
	if (distance > 0 && distance < MinDistance)
	{
		// Distance is less than our minimum
		dx *= MinDistance / distance;
		dy *= MinDistance / distance;

		fishX = stinkyX + dx;
		fishY = stinkyY + dy;

		// Ensure fishX, fishY remain in the specified bounds

		if (fishX > MaxX)
		{
			fishX = MaxX;
		}

		if (fishX < MinX)
		{
			fishX = MinX;
		}

		if (fishY > MaxY)
		{
			fishY = MaxY;
		}

		if (fishY < MinY)
		{
			fishY = MinY;
		}
	}
	/// Set the new location
	mX = fishX;
	mY = fishY;
}
