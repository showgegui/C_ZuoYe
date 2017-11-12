#include "MenuLayer.h"


MenuLayer::MenuLayer()
{
}


MenuLayer::~MenuLayer()
{
}
bool MenuLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	return true;
}