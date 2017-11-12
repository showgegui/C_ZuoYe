#include "FishLayer.h"
#include "Fish.h"
#define FISH_MAX_COUNT 50


FishLayer::FishLayer(void)
{
}


FishLayer::~FishLayer(void)
{
	CC_SAFE_RELEASE_NULL(_fishes);
}

bool FishLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	/*测试*/
	/*Fish *fish = Fish::create((FishType)1);
	addChild(fish);
	fish->setPosition(ccp(1024,800));*/

	_fishes = CCArray::createWithCapacity(FISH_MAX_COUNT);//_fishes指针指向容量为50的鱼的数组
	CC_SAFE_RETAIN(_fishes);//数组创建完成后，需要通过CC_SAFE_RETAIN(_fishes)将其保存下来，不然会被回收池给回收掉
	for (int i=0; i < FISH_MAX_COUNT; i++)
	{
		int type = CCRANDOM_0_1() *k_Fish_Type_Count -1;//得到某种鱼的某种类别
		CCLOG("FishLayer type=%d", type);
		//type = (FishType)100;
		/*type只能1鱼只加载进一种？？在Fish的init有问题*/
		Fish *fish = Fish::create((FishType)type);//生成对应种类的鱼
		_fishes->addObject(fish);
	}
	this->schedule(schedule_selector(FishLayer::addFish), 3.0);//每隔3秒就会调用一次addFish函数
	return true;
}



void FishLayer::addFish(float delta)
{
	int addToCount = CCRANDOM_0_1() * 10 + 1;//生成随机数，表示此次要生成的鱼的数量
	int count = 0;
	CCObject *obj;
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();//得到窗口大小

	/*CCARRAY_FOREACH对数组的遍历*/
	CCARRAY_FOREACH(_fishes, obj)
	{
		Fish *fish = (Fish *)obj;
		if (fish->isRunning())
		{
			continue;
		}
		count++;

		/*随机生成x坐标和y坐标，设置fish的位置*/
		fish->setPosition(ccp(CCRANDOM_0_1()*winSize.width, CCRANDOM_0_1()*winSize.height));
		this->addChild(fish);
		if (count == addToCount)
		{
			break;
		}
	}
}