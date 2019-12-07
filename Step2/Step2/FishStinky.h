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
	CFishStinky::CFishStinky(CAquarium* aquarium);

	/// Default constructor (disabled)
	CFishStinky() = delete;

	/// Copy constructor (disabled)
	CFishStinky(const CFishStinky&) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics) override;

	bool HitTest(int x, int y);

	/// Set the item location
	void SetLocation(double x, double y) override;

private:
	/// The image associated with the fish
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};

