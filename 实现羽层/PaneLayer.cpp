#include "PaneLayer.h"


PaneLayer::PaneLayer(void)
{
}


PaneLayer::~PaneLayer(void)
{
}
bool PaneLayer::init(){
	if(!CCLayer::init()){
		return false;
	}
	return true;
}