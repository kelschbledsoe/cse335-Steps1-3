/**
 * \file FishMagikarp.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class that implements a Magikarp fish
 */


#pragma once
#include <memory>
#include "Fish.h"

/**
 * Implements a Magikarp fish
 */
class CFishMagikarp : public CFish
{
public:
	CFishMagikarp(CAquarium* aquarium);
	virtual ~CFishMagikarp();

	/// Default constructor (disabled)
	CFishMagikarp() = delete;

	/// Copy constructor (disabled)
	CFishMagikarp(const CFishMagikarp&) = delete;

	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};

