#include "CannonLayer.h"


CannonLayer::CannonLayer(void)
{
}


CannonLayer::~CannonLayer(void)
{
}
bool CannonLayer::init(){
	if(!CCLayer::init()){
		return false;
	}
	return true;
}
