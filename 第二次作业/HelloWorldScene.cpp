#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{

    if ( !Scene::init() )
    {
        return false;
    }
	/*getInstance获得实例 getVisiSize获得窗口大小*/
    auto visibleSize = Director::getInstance()->getVisibleSize();
	/*Vec2就是坐标 定义原点坐标*/
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/*MenuItemImage菜单按钮（图片菜单MenuITEMImage（“未点击图片”，“点击后图片”，“回调方法”）），创建一个按钮*/
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	/*设置closeItem的位置（getContentSize是图片的大小）*/
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
		origin.y + closeItem->getContentSize().height / 2));

	/*在布景上添加菜单项的方法：
			1、把菜单项(MenuItem)添加进菜单(Menu)
			2、把菜单(Menu)添加至相应层(Layer)*/
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);





    /*标签名字，字体，字体大小  auto 对象名称=Label::createWithTTF("需要显示的字", "Resources内的字体", 字体大小)*/
	auto label = Label::createWithTTF("fishingJon", "fonts/Marker Felt.ttf", 24);
	
	/*标签的位置*/
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	/*把标签添加到场景中*/
    this->addChild(label, 1);




	/*创建一个精灵背景图*/
    auto sprite = Sprite::create("bj01_01-ipadhd.png");

    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	//sprite->setPosition(Point(0, 0));
	sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    this->addChild(sprite, 0);
	
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
   
    
}
