/**
 * \file FishSparty.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */

#include "pch.h"
#include <string>
#include "FishSparty.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename
const wstring FishSpartyImageName = L"images/Sparty-fish.png";

/// Max speed in X direction in pixels per second
const double MaxSpeedX = 225;
/// Max speed in Y direction in pixels per second
const double MaxSpeedY = 225;
/// Min speed in X direction in pixels per second
const double MinSpeedX = 175;
/// Min speed in Y direction in pixels per second
const double MinSpeedY = 175;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishSparty::CFishSparty(CAquarium* aquarium) :
	CFish(aquarium, FishSpartyImageName)
{
	CFish::SetSpeed(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX),
		MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
}


/**
 * Destructor
 */
CFishSparty::~CFishSparty()
{

}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns itemNode The XML node
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishSparty::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"sparty");
	return itemNode;
}