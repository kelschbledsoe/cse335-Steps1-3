/**
 * \file FishMagikarp.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class that implements a Magikarp fish
 */


#pragma once
#include <memory>
#include "Item.h"

/**
 * Implements a Magikarp fish
 */
class CFishMagikarp : public CItem
{
public:
	CFishMagikarp::CFishMagikarp(CAquarium* aquarium);
	virtual ~CFishMagikarp();

	/// Default constructor (disabled)
	CFishMagikarp() = delete;

	/// Copy constructor (disabled)
	CFishMagikarp(const CFishMagikarp&) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics);

	virtual bool HitTest(int x, int y) override;

private:
	/// The image associated with the fish
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;

};

