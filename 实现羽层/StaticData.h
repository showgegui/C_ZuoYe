#pragma once
#ifndef STATICDATA_H_
#define STATICDATA_H_
#include "D:\colos\cocos2d-x-2.2.5\cocos2dx\cocoa\CCObject.h"
#include "cocos2d.h"
#include <string>
class StaticData :
	public cocos2d::CCObject
{
private:
	StaticData(void);
	virtual ~StaticData(void);
	
protected:
	cocos2d::CCDictionary* _dictionary;
	std::string _staticFileName;
	bool StaticData::init();
	
public:
	
	static StaticData* sharedStaticData();
	const char* stringFromKey(std::string key);
	int intFromKey(std::string key);
	int floatFromKey(std::string key);
	bool booleanFromKey(std::string key);
	cocos2d::CCPoint pointFromKey(std::string key);
	cocos2d::CCRect rectFromKey(std::string key);
	cocos2d::CCSize sizeFromKey(std::string key);
	void purge();

	CC_SYNTHESIZE_READONLY(std::string,_staticDataPath,StaticDataPath);
};
#endif

