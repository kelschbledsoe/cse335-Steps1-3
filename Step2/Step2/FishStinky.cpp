/**
 * \file FishStinky.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */

#include "pch.h"
#include <string>
#include "Aquarium.h"
#include "FishStinky.h"


using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishStinkyImageName = L"images/Stinky.png";

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CFishStinky::CFishStinky(CAquarium* aquarium) : CItem(aquarium)
{
	mFishImage = unique_ptr<Bitmap>(Bitmap::FromFile(FishStinkyImageName.c_str()));
	if (mFishImage->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += FishStinkyImageName;
		AfxMessageBox(msg.c_str());
	}
}

/**
 * Draw our fish
 * \param graphics Graphics device to draw on
 */
void CFishStinky::Draw(Gdiplus::Graphics* graphics)
{
	double wid = mFishImage->GetWidth();
	double hit = mFishImage->GetHeight();
	graphics->DrawImage(mFishImage.get(),
		float(GetX() - wid / 2), float(GetY() - hit / 2),
		(float)mFishImage->GetWidth(), (float)mFishImage->GetHeight());
}

/**
 * Test to see if we hit this object with a mouse.
 * \param x X position to test
 * \param y Y position to test
 * \return true if hit.
 */
bool CFishStinky::HitTest(int x, int y)
{
	double wid = mFishImage->GetWidth();
	double hit = mFishImage->GetHeight();

	// Make x and y relative to the top-left corner of the bitmap image
	// Subtracting the center makes x, y relative to the image center
	// Adding half the size makes x, y relative to theimage top corner
	double testX = x - GetX() + wid / 2;
	double testY = y - GetY() + hit / 2;

	// Test to see if x, y are in the image
	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
	{
		// We are outside the image
		return false;
	}

	// Test to see if x, y are in the drawn part of the image
	auto format = mFishImage->GetPixelFormat();
	if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
	{
		// This image has an alpha map, which implements the 
		// transparency. If so, we should check to see if we
		// clicked on a pixel where alpha is not zero, meaning
		// the pixel shows on the screen.
		Color color;
		mFishImage->GetPixel((int)testX, (int)testY, &color);
		return color.GetAlpha() != 0;
	}
	else {
		return true;
	}
}

/**
 * Set location of the fish
 * \param x X position set
 * \param y Y position set
 */
void CFishStinky::SetLocation(double x, double y)
{
	/// Upcall to set location in CItem
	CItem::SetLocation(x, y);
	mAquarium->CheckFishPosition(x, y);
}

