#include "BackgroundLayer.h"
USING_NS_CC;

BackgroundLayer::BackgroundLayer(void)
{
}


BackgroundLayer::~BackgroundLayer(void)
{
}

bool BackgroundLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	CCSprite *bgSprite = CCSprite::create("bj01_01-ipadhd.png");

/*把精灵加到层的子节点*/
	this->addChild(bgSprite);
	
	
	
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	
	
	/*设置背景图显示位置（精灵的位置在窗口的中心）*/
	//bgSprite->setPosition(CCPoint(winSize.width / 2, winSize.height / 2));
	bgSprite->setPosition(this->getAnchorPointInPoints());



	//CCLabelTTF* pLabel = CCLabelTTF::create("FishingJon","fonts/Marker Felt.ttf",70);

	// position the label on the center of the screen
	//pLabel->setPosition(CCPoint(winSize.width / 2, winSize.height-50));

	// add the label as a child to this layer
	//this->addChild(pLabel);

	return true;
}