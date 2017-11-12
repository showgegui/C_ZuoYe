#include "GameMenuLayer.h"


GameMenuLayer::GameMenuLayer()
{
}


GameMenuLayer::~GameMenuLayer()
{
}

bool GameMenuLayer::init()
{
	if (CCLayer::init())
	{
		return false;
	}
	CCSprite *bgSprite = CCSprite::create("ui_background_normal-ipadhd.png");

	this->addChild(bgSprite);
	
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	bgSprite->setPosition(CCPoint(winSize.width / 2, winSize.height / 2));


	//this->createMenu();


	return true;
}
void GameMenuLayer::createMenu()
{
	CCSpriteFrameCache *spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	spriteFrameCache->addSpriteFramesWithFile("UI_GameMenuText_cn-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("UI_GameStartMenuLayer-ipadhd.plist");

	CCSprite *startNormalBackgroundSprite = CCSprite::createWithSpriteFrameName("ui_button_box02_02.png");
	CCSprite *startNormalTextSprite = CCSprite::createWithSpriteFrameName("ui_2p_010.png");
	startNormalBackgroundSprite->addChild(startNormalTextSprite);

	CCSize startSpriteSize = startNormalBackgroundSprite->getContentSize();
	startNormalTextSprite->setPosition(ccp(startSpriteSize.width/2,startSpriteSize.height/2+20));

	CCSprite *startSelectedBackgroundSprite = CCSprite::createWithSpriteFrameName("ui_button_box02_01.png");
	CCSprite *startSelectedTextSprite = CCSprite::createWithSpriteFrameName("ui_2p_010.png");
	startSelectedBackgroundSprite->addChild(startSelectedTextSprite);

	startNormalTextSprite->setPosition(ccp(startSpriteSize.width / 2, startSpriteSize.height / 2 + 20));

	CCMenuItemSprite *startMenuItem = CCMenuItemSprite::create(startNormalBackgroundSprite, startSelectedBackgroundSprite
		, this,menu_selector(GameMenuLayer::onStertGame));
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