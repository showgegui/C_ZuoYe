#pragma once
#include"cocos2d.h"
using namespace cocos2d;
/*”Œœ∑≤Àµ•≤„*/
class GameMenuLayer :public CCLayer
{
public:
	GameMenuLayer(void);
	~GameMenuLayer(void);
	CREATE_FUNC(GameMenuLayer);
	virtual bool init(void);
	static cocos2d::CCScene* scene();
protected:
	void createMenu(void);
	void onStertGame(CCObject *sender);
	void onSelectScene(CCObject *sender);

};

