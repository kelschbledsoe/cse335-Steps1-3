/**
 * \file DecorCastle.h
 *
 * \author Gabriella Kelsch Bledsoe
 *
 * Class the implements a Decor Castle
 */


#pragma once
#include <memory>
#include "Item.h"


 /**
  * Implements a Decor Castle
  */
class CDecorCastle : public CItem
{
public:
	CDecorCastle::CDecorCastle(CAquarium* aquarium);
	virtual ~CDecorCastle();

	/// Default constructor (disabled)
	CDecorCastle() = delete;

	/// Copy constructor (disabled)
	CDecorCastle(const CDecorCastle&) = delete;

	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};

