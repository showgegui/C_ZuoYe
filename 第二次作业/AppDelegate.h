#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"


class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual void initGLContextAttrs();//设置 OpenGL环境


    virtual bool applicationDidFinishLaunching();//逻辑初始化


    virtual void applicationDidEnterBackground();//切换到后台


    virtual void applicationWillEnterForeground();//切换到前台
};

#endif // _APP_DELEGATE_H_

