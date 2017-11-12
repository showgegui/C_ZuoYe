#pragma once
#include"cocos2d.h"
#include "Fish.h"
using namespace cocos2d;
class FishLayer :public CCLayer
{
public:
	FishLayer(void);
	CREATE_FUNC(FishLayer);
	virtual bool init();
	virtual ~FishLayer(void);
protected:
	/*从数组中挑选若干条鱼出来，并随机摆放到场景中的某个位置*/
	void addFish(float delta);
	CCArray* _fishes;
};


