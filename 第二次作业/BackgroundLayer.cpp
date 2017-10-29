#include "BackgroundLayer.h"
USING_NS_CC;

BackgroundLayer::BackgroundLayer()
{
}


BackgroundLayer::~BackgroundLayer()
{
}

bool BackgroundLayer::init()
{
	if (!cocos2d::Layer::init())
	{
		return false;
	}
	/*获取窗口大小*/
	auto WindowsSize = Director::getInstance()->getVisibleSize();
	
	
	/*创建一个精灵背景图*/
	auto *bgSprite = Sprite::create("bj01_01-ipadhd.png");
	
	
	/*把精灵加到层的子节点*/
	this->addChild(bgSprite);
	
	
	/*设置背景图显示位置（精灵的位置在窗口的中心）*/
	bgSprite->setPosition(WindowsSize.width / 2, WindowsSize.height / 2);
	return true;
}