/**
 * \file FishStinky.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class the implements a Stinky fish
 */


#pragma once
#include <memory>
#include "Item.h"

 /**
  * Implements a Stinky fish
  */
class CFishStinky : public CItem
{
public:
	CFishStinky(CAquarium* aquarium);
	virtual ~CFishStinky();

	/// Default constructor (disabled)
	CFishStinky() = delete;

	/// Copy constructor (disabled)
	CFishStinky(const CFishStinky&) = delete;

};