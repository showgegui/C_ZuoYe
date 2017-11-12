#pragma once
#include"cocos2d.h"
#include"BackgroundLayer.h"
#include"FishLayer.h"
#include"MenuLayer.h"
#include"CannonLayer.h"
#include"PaneLayer.h"

using namespace cocos2d;
/*游戏场景类*/
class GameScene :public CCScene
{
public:
	GameScene(void);
	CREATE_FUNC(GameScene)
	virtual~GameScene(void);
	/*初始化函数，完成各个层的创建和加载*/
	virtual bool init();
protected:
	/*数据成员*/
	BackgroundLayer *backgroundLayer;/*背景层*/
	CannonLayer *cannonLayer;/*炮台层*/
	FishLayer *fishLayer;/*鱼层*/
	PaneLayer *paneLayer;/*功能层*/
	MenuLayer *menuLayer;/*菜单层*/
	void preloadResources(void);
	

};

