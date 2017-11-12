#include "StaticData.h"
USING_NS_CC;
#define STATIC_DATA_PATH "static_data.plist"  
static StaticData *g_sharedStaticData = NULL;
StaticData::StaticData(void)
{
	_staticDataPath = STATIC_DATA_PATH;
}
StaticData::~StaticData(void)
{
	CC_SAFE_RELEASE_NULL(_dictionary);
}
StaticData *StaticData::sharedStaticData()
{
	 if (g_sharedStaticData == NULL) {
		g_sharedStaticData = new StaticData();
		g_sharedStaticData->init();
	}
	return g_sharedStaticData;
}

bool StaticData::init() {
	_dictionary = CCDictionary::createWithContentsOfFile(_staticDataPath.c_str());
	CC_SAFE_RETAIN(_dictionary);
	return true;
}

const char* StaticData::stringFromKey(std::string key) {
	return _dictionary->valueForKey(key)->getCString();
}

int StaticData::intFromKey(std::string key) {
	return _dictionary->valueForKey(key)->intValue();
}

int StaticData::floatFromKey(std::string key) {
	return _dictionary->valueForKey(key)->floatValue();
}

bool StaticData::booleanFromKey(std::string key) {
	return _dictionary->valueForKey(key)->boolValue();
}

cocos2d::CCPoint StaticData::pointFromKey(std::string key) {
	return CCPointFromString(_dictionary->valueForKey(key)->getCString());
}

cocos2d::CCRect StaticData::rectFromKey(std::string key) {
	return CCRectFromString(_dictionary->valueForKey(key)->getCString());
}

cocos2d::CCSize  StaticData::sizeFromKey(std::string key) {
	return CCSizeFromString(_dictionary->valueForKey(key)->getCString());
}

void purge() {
	CC_SAFE_RELEASE_NULL(g_sharedStaticData);
}