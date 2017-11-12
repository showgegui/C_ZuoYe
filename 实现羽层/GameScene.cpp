#include "GameScene.h"


GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}
bool GameScene::init()
{
	/*do  {...}while(0)本身没有实际意义，但有很多好处：
	1、辅助定义复杂的宏，避免引用时出错（在引用宏时只是单单加{}话有可能会编译不过）
	2、避免使用goto对程序流进行统一的控制，（goto 标签：）运行到goto时会跳过中间的操作
		到标签：后的操作，进行跳过一些程序；但goto不符合软件工程结构尽量不用，do{..}while(0)
		通过break可以跳出，实现。
	3、避免空宏引起的warning
		内核中由于不同架构的限制，很多时候会用到空宏，在编译的时候，空宏会给出warning，为了避免
		这样的warning，就可以使用do{}while(0)来定义空宏
	4、定义一个单独的函数块来实现复杂的操作：
		当你的功能很复杂，变量很多你又不愿意增加一个函数的时候，使用do{}while(0);，将你的代码
		写在里面，里面可以定义变量而不用考虑变量名会同函数之前或者之后的重复。
	*/
	do
	{
		if (!CCScene::init())
		{
			break;
		}
		/*创建背景层*/
		preloadResources();
		backgroundLayer = BackgroundLayer::create();
		CC_BREAK_IF(!backgroundLayer);
		this->addChild(backgroundLayer);
		

		fishLayer = FishLayer::create();
		CC_BREAK_IF(!fishLayer);
		this->addChild(fishLayer);
		

		menuLayer = MenuLayer::create();
		CC_BREAK_IF(!menuLayer);
		CC_SAFE_RETAIN(menuLayer);
		return true;

	}
	while (0);
	return false;
}



void GameScene::preloadResources(void)
{
	/*CCSpriteFrameCache的对象从plist文件中导入精灵帧*/
	CCSpriteFrameCache *spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Large-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Marlin-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Shark-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Small-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Mid-ipadhd.plist");


	/*字符串数组存鱼*/
	char a[][50] = { "SmallFish","Croaker","AngelFish","Amphiprion","PufferS","Bream","Porgy","Chelonian",
	"Lantern","Ray","Shark","GoldenTrout","GShark","GMarlinsFish","GrouperFish","JadePerch","MarlinsFish","PufferB" };

	for (int i = 0; i < 18; i++)
	{
		CCArray *array = CCArray::createWithCapacity(10);
		for (int j = 0; j < 10; j++)
		{
			CCString  *spriteFrameName = CCString::createWithFormat("%s_actor_%03d.png",a[i],j+1);
			CCSpriteFrame *spriteFrame = spriteFrameCache->spriteFrameByName(spriteFrameName->getCString());
			if (spriteFrame == NULL)
			{
				break;
			}
			array->addObject(spriteFrame);
		}
		if (array->count() == 0)
		{
			continue;
		}
		CCAnimation *animation = CCAnimation::createWithSpriteFrames(array,0.15f);
		CCString *animationName = CCString::createWithFormat("fish_animation_%02d",i+1);
		CCAnimationCache::sharedAnimationCache()->addAnimation(animation,animationName->getCString());

	}

}