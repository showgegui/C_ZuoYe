#include "GameMenuLayer.h"


GameMenuLayer::GameMenuLayer()
{
}


GameMenuLayer::~GameMenuLayer()
{
}

bool GameMenuLayer::init()
{
	if (!cocos2d::Layer::init())
	{
		return false;
	}
	auto WindowsSize = Director::getInstance()->getVisibleSize();


	/*创建一个精灵背景图*/
	auto *bgSprite = CCSprite::create("UI_GameStartMenuLayer-ipadhd.png");



	/*把精灵加到层的子节点*/
	this->addChild(bgSprite);


	/*设置背景图显示位置（精灵的位置在窗口的中心）*/
	bgSprite->setPosition(WindowsSize.width / 2, WindowsSize.height / 2);
	return true;
}
void GameMenuLayer::createMenu()
{
	auto *spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	spriteFrameCache->addSpriteFramesWithFile("UI_GameMenuText_cn-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("UI_GameStartMenuLayer-ipadhd.plist");
	auto *startNormalBackgoundSprite = CCSprite::createWithSpriteFrameName("ui_background_normal-ipadhd.png");
	CCSprite *startSelectedTextSprite = CCSprite::createWithSpriteFrameName("UI_GameMenuText_cn-ipadhd.png");
	startNormalBackgoundSprite->addChild(startSelectedTextSprite);

	auto starSpriteSize = startNormalBackgoundSprite->getContentSize();
	startSelectedTextSprite->setPosition(ccp(starSpriteSize.width / 2, starSpriteSize.height / 2+20));

	CCSprite *starSelectedBackgroundSprite = CCSprite::createWithSpriteFrameName("bj01_01-ipadhd.png");
	CCSprite *starSelectedTextSprite = CCSprite::createWithSpriteFrameName("bj02_01-ipadhd.png");
	starSelectedBackgroundSprite->addChild(starSelectedTextSprite);

	starSelectedTextSprite->setPosition(ccp(starSpriteSize.width / 2, starSpriteSize.height / 2 + 20));
	CCMenuItemSprite*startMenuItem = CCMenuItemSprite::create(startNormalBackgoundSprite,starSelectedBackgroundSprite,this);
	CCMenu *menu = CCMenu::create(startMenuItem,NULL);
	this->addChild(menu);
	menu->setPosition(ccp(1024, 800));

}
CCScene *GameMenuLayer::scene()
{
	CCScene *scene = CCScene::create();
	GameMenuLayer *layer = GameMenuLayer::create();
	scene->addChild(layer);
	return scene;

}
void GameMenuLayer::onStertGame(CCObject *sender)
{

}