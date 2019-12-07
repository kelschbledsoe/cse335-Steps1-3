/**
 * \file Fish.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */


#pragma once
#include "Item.h"
class CItem;


/**
 * Class that implements a Fish
 */
class CFish : public CItem
{
public:
	/// Default constructor (disabled)
	CFish() = delete;

	virtual ~CFish();

	/// Copy constructor (disabled)
	CFish(const CFish&) = delete;

	void Update(double elapsed);

	/// Set the fish speed
	/// \param speedx Speed in x direction
	/// \param speedy Speed in y direction
	void SetSpeed(double speedx, double speedy) { mSpeedX = speedx; mSpeedY = speedy; }

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;

protected:
	CFish(CAquarium* aquarium, const std::wstring& filename);
	
};


