/**
 * \file FishSparty.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class that implements a Sparty fish
 */


#pragma once
#include <memory>
#include "Item.h"

 /**
  * Implements a Sparty fish
  */
class CFishSparty : public CItem
{
public:
	CFishSparty::CFishSparty(CAquarium* aquarium);
	virtual ~CFishSparty();

	/// Default constructor (disabled)
	CFishSparty() = delete;

	/// Copy constructor (disabled)
	CFishSparty(const CFishSparty&) = delete;

	virtual void Draw(Gdiplus::Graphics* graphics);

	virtual bool HitTest(int x, int y) override;

private:
	/// The image associated with the fish
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;

};

