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
		if (!Scene::init())
		{
			break;
		}
		/*创建背景层*/
		backgroundLayer = BackgroundLayer::create();
		/*检查是否创建成功*/
		CC_BREAK_IF(!backgroundLayer);
		/*将背景层导入场景*/
		this->addChild(backgroundLayer);
		/*创建鱼层*/
		fishLayer = FishLayer::create();
		/*检查鱼层是否创建成功*/
		CC_BREAK_IF(!fishLayer);
		/*将鱼层导入场景*/
		this->addChild(fishLayer);
		return true;

	}
	while (0);
	return false;
}