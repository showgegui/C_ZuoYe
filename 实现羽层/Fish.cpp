#include "Fish.h"
//#include"StatiData.h"

Fish::Fish(void)
{
}


Fish::~Fish(void)
{
}

Fish *Fish::create(FishType type)
{
	Fish *fish = new Fish;
	if (fish && fish->init(type))
	{
		fish->autorelease();
		return fish;
	}
	else
	{
		CC_SAFE_DELETE(fish);
		return NULL;
	}
}




bool Fish::init(FishType type)
{
	
	if (!CCNode::init())
	{
		return false;
	}

	/*运行就出错？？*/
	if (type <=k_Fish_Type_SmallFish || type >= k_Fish_Type_Count)
	{
		type = (FishType)1;
	}//type = (FishType)1;
	setType(type);
	CCString *animationName = CCString::createWithFormat("fish_animation_%02d", _type);
	CCAnimation *animation = CCAnimationCache::sharedAnimationCache()->animationByName(animationName->getCString());
	CCAnimate *animate = CCAnimate::create(animation);
	_fishSprite = CCSprite::create();
	_fishSprite->runAction(CCRepeatForever::create(animate));
	this->addChild(_fishSprite);
	return true;
}




int Fish::getScore()
{
	return 0;
}



int Fish::getSpeed()
{
	return 200;
}

/*bool Fish::init(FishType type)
{
	if (!CCNode::init())
	{
		return false;
	}
	if (type < k_Fish_Type_SmallFish || type >= k_Fish_Type_Count)
	{
		type = k_Fish_Type_SmallFish;
	}
	setType(type);
	CCString *animationName = CCString::createWithFormat("fish_animation_%02d",_type);
	CCAnimation *animation = CCAnimationCache::sharedAnimationCache()->animationByName(animationName->getCString());
	CCAnimate *animate = CCAnimate::create(animation);
	fishSprite = CCSprite::create();
	fishSprite->runAction(CCRepeatForever::create(animate));
	this->addChild(fishSprite);
	return true;

}*/