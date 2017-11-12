#pragma once
#include"cocos2d.h"
using namespace cocos2d;
/*背景层类*/
class BackgroundLayer :public CCLayer
{
public:
	BackgroundLayer(void);
	/*static BackgroundLayer *create(){
		BackgroundLayer *layer = new BackgroundLayer();
		if (layer &&layer->init()){
			return layer;
		}
		else{
			delete layer;
		}
	}*/

	/*目的就是提供创建对象的静态方法，以便进行内存管理，当然可以自己写一个create函数 pRet->autorelease();
	就是加入到内存管理池，pRet->init()就是为什么有时候继承Sprite或者其他类时，要进行重载以便初始化自己的一些数据*/
	CREATE_FUNC(BackgroundLayer);
	
	virtual bool init();
	~BackgroundLayer(void);
};





