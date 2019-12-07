/**
 * \file FishBeta.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class the implements a Beta fish
 */


#pragma once
#include <memory>
#include "Fish.h"


/**
 * Implements a Beta fish
 */
class CFishBeta : public CFish
{
public:
	CFishBeta::CFishBeta(CAquarium* aquarium);
	virtual ~CFishBeta();
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta&) = delete;
};

