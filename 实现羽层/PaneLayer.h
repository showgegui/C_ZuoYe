#pragma once
#include "cocos2d.h"
using namespace cocos2d;
/*¹¦ÄÜ²ã*/
class PaneLayer :
	public CCLayer
{
public:
	PaneLayer(void);
	CREATE_FUNC(PaneLayer);
	virtual bool init();
	virtual ~PaneLayer(void);
};

