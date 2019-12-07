/**
 * \file Aquarium.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */

#include <algorithm>

#include "pch.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "Item.h"

using namespace std;
using namespace Gdiplus;


/**
 * Aquarium constructor
 */
CAquarium::CAquarium()
{
	mBackground = unique_ptr<Gdiplus::Bitmap>(
		Bitmap::FromFile(L"images/background1.png"));
	if (mBackground->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/background1.png");
	}

}

/**
 * Destructor
 */
CAquarium::~CAquarium()
{
}

 /** Draw the aquarium
 * \param graphics The GDI+ graphics context to draw on
 */
void CAquarium::OnDraw(Gdiplus::Graphics* graphics)
{
	graphics->DrawImage(mBackground.get(), 0, 0,
		mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the Sea!", -1, &font, PointF(2, 2), &green);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
}

/**
 * Add an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}

/** Moves an item to the back of mItems
 * Called when something is grabbed
 *
 * \param item the item to be moved to the end of mItems
 */
void CAquarium::MoveItemToEnd(shared_ptr<CItem> item)
{
	auto loc = find(begin(mItems), end(mItems), item);

	if (loc != end(mItems))
	{
		mItems.erase(loc);
		mItems.push_back(item);
	}
}

void CAquarium::CheckFishPosition(double stinkyX, double stinkyY)
{
	for (auto item : mItems)
	{
		// pass stinkyx and stinkyy into nudge
		item->CItem::Nudge(stinkyX, stinkyY);	
	}
}