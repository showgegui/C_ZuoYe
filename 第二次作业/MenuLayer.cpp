#include "MenuLayer.h"


MenuLayer::MenuLayer()
{
}


MenuLayer::~MenuLayer()
{
}
bool MenuLayer::init()
{
	if (!cocos2d::Layer::init())
	{
		return false;
	}
	return true;
}