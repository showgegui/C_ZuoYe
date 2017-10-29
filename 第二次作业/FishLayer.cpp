#include "FishLayer.h"


FishLayer::FishLayer()
{
}


FishLayer::~FishLayer()
{
}

bool FishLayer::init()
{
	if (!cocos2d::Layer::init())
	{
		return false;
	}
	return true;
}