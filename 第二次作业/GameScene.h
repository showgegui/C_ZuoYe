#pragma once
#include"cocos2d.h"
#include"BackgroundLayer.h"
#include"FishLayer.h"
#include"MenuLayer.h"
using namespace cocos2d;
/*游戏场景类*/
class GameScene :public cocos2d::CCScene
{
public:
	GameScene(void);
	CREATE_FUNC(GameScene)
	~GameScene();
	/*初始化函数，完成各个层的创建和加载*/
	virtual bool init(void);
protected:
	/*数据成员*/
	BackgroundLayer::Layer * backgroundLayer;/*背景层*/
	//CannonLayer *cannonLayer;/*炮台层*/
	FishLayer::Layer *fishLayer;/*鱼层*/
	//PaneLayer *paneLayer;/*功能层*/
	MenuLayer *menuLayer;/*菜单层*/
	

};

