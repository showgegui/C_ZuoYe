#include "AppDelegate.h"
#include "HelloWorldScene.h"

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

//设置默认分辨率及三种尺寸分辨率，用于适配 

static cocos2d::Size designResolutionSize = cocos2d::Size(900,600);
/*设置*/
static cocos2d::Size smallResolutionSize = cocos2d::Size(900,600);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(3048,2538);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

//设置 OpenGL环境，这个设置对所有平台都有效 
void AppDelegate::initGLContextAttrs()
{
	//设置OpenGL context 属性,目前只能设置6个属性  
	//red,green,blue,alpha,depth,stencil 
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}


static int register_all_packages()
{
    return 0; 
}

//当应用程序启动时执行,游戏程序启动入口  
//在这里我们启动了第一个scen
bool AppDelegate::applicationDidFinishLaunching() {
  
	auto director = Director::getInstance();
	/*glview就是创建弹出框的大小view*/
	auto glview = director->getOpenGLView();

    if(!glview) {
		/*GLViewImpl::createWithRect设置屏幕大小*/
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("fishingJone", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("fishingJone");
#endif
        director->setOpenGLView(glview);
    }
	/*是否显示帧*/
    director->setDisplayStats(true);
	/*帧的大小*/
    director->setAnimationInterval(1.0f / 60);

	//分辨率适配 
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();
	
   if (frameSize.height > mediumResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }

    else if (frameSize.height > smallResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
  
    else
    {        
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }

    register_all_packages();

	//创建一个HelloWorld的scene，程序运行的第一个场景  
    auto scene = HelloWorld::createScene();

    director->runWithScene(scene);

    return true;
}

// 切换到后台 
void AppDelegate::applicationDidEnterBackground() {
	//暂停游戏  
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// 切换到前台
void AppDelegate::applicationWillEnterForeground() {

	//继续游戏
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
