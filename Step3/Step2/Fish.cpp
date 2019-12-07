/**
 * \file Fish.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */

#include "pch.h"
#include "Fish.h"
#include "Aquarium.h"


/**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */
CFish::CFish(CAquarium* aquarium, const std::wstring& filename) :
	CItem(aquarium, filename)
{
}

/**
 * Destructor
 */
CFish::~CFish()
{
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

	if ((mSpeedX > 0 && GetX() >= GetAquarium()->GetWidth() - 10 - GetImageWidth() / 2) || 
		(mSpeedX < 0 && GetX() <= GetImageWidth() /2))
	{
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}
	if ((mSpeedY > 0 && GetY() >= GetAquarium()->GetHeight() - 10 - GetImageHeight() / 2) || 
		(mSpeedY < 0 && GetY() <= GetImageHeight() / 2))
	{
		mSpeedY = -mSpeedY;
	}
	
}


/**
 * Save fish as an XML node
 * \param node Node going to be a child of
 * \returns XML node fish is being saved to
 */
std::shared_ptr<xmlnode::CXmlNode>
CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"speedx", mSpeedX);
	itemNode->SetAttribute(L"speedy", mSpeedY);
	return itemNode;
}


/**
 * Load the attributes for an item node.
 * This is the base class version that loads the attributes
 * common to all items. Override this to laod custom attributes
 * for specific items.
 *
 * \param node Xml node loading the item from
 */
void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	CItem::XmlLoad(node);
	mSpeedX = node->GetAttributeDoubleValue(L"speedx", 0);
	mSpeedY = node->GetAttributeDoubleValue(L"speedy", 0);
	SetMirror(mSpeedX < 0);
}
