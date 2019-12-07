/**
 * \file Aquarium.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class that represents an aquarium.
 */


#pragma once
#include <memory>
#include <vector>

class CItem;

/**
 * Represents an aquarium
 */
class CAquarium
{
public:
	CAquarium();
	virtual ~CAquarium();

	void OnDraw(Gdiplus::Graphics* graphics);

	void Add(std::shared_ptr<CItem> item);

	std::shared_ptr<CItem> HitTest(int x, int y);

	/// Function to move the grabbed item to the end of mItems
	void CAquarium::MoveItemToEnd(std::shared_ptr<CItem> item);

	/// Function to check the position of each fish
	/// \param stinkyX X location of stinky fish
	/// \param stinkyY Y location of stinky fish
	void CAquarium::CheckFishPosition(double stinkyX, double stinkyY);

private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;
};

