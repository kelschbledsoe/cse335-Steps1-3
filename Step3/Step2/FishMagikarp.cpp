/**
 * \file FishMagikarp.cpp
 *
 * \author Gabriella Kelsch Bledsoe
 */

#include "pch.h"
#include <string>
#include "FishMagikarp.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename
const wstring FishMagikarpImageName = L"images/magikarp.png";

/// Max speed in X direction in pixels per second
const double MaxSpeedX = 75;
/// Max speed in Y direction in pixels per second
const double MaxSpeedY = 75;
/// Min speed in X direction in pixels per second
const double MinSpeedX = 25;
/// Min speed in Y direction in pixels per second
const double MinSpeedY = 25;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishMagikarp::CFishMagikarp(CAquarium* aquarium) :
	CFish(aquarium, FishMagikarpImageName)
{
	CFish::SetSpeed(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX),
		MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
}


/**
 * Destructor
 */
CFishMagikarp::~CFishMagikarp()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns itemNode The XML node
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishMagikarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"magikarp");
	return itemNode;
}