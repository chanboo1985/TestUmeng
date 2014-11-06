#include "HelloWorldScene.h"
#include "Cocos2dx/Common/CCUMSocialSDK.h"
//#include "Cocos2dx/ShareButton/UMShareButton.h"
#include <vector>
#include <map>

USING_NS_CC;
USING_NS_UM_SOCIAL;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

/*
 * 分享回调, 该回调不是某个类的成员函数， 而是一个普通的函数, 具体使用参考HelloWorldScene的例子
* @param platform 要分享到的目标平台
 * @param stCode 返回码, 200代表分享成功, 100代表开始分享
 * @param errorMsg 分享失败时的错误信息,android平台没有错误信息
 */
void shareCallback(int platform, int stCode, string &emsg)
{
	if (stCode == 100)
	{
		CCLog("-----------------开始分享");
	} 
	else if(stCode == 200)
	{
		CCLog("-----------------开始成功");
	}else
	{
		CCLog("-----------------开始出错");
	}

	CCLog("platform num is : %d.", platform);
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	/*UMShareButton *shareBtn = UMShareButton::create("shareNormal.png","shareSelected.png","54258b8afd98c5944700cfd9",share_selector(shareCallback));
	vector<int>* platforms = new vector<int>();
	platforms->push_back(SINA);
	platforms->push_back(RENREN);
	platforms->push_back(DOUBAN);
	platforms->push_back(QZONE);
	platforms->push_back(QQ);
	shareBtn->setPlatforms(platforms);
	shareBtn->setShareContent("umeng social cocos2dx sdk");
	shareBtn->setShareImage("/sdcard/header.jpeg");
	shareBtn->setPosition(ccp(150,180));
	CCMenu *pMenu = CCMenu::create(shareBtn, NULL);
	pMenu->setPosition(ccp(100,100));
	this->addChild(pMenu,1);*/

	// ********************** 设置平台信息 ***************************
	// CCUMSocialSDK *sdk = shareButton->getSocialSDK();
	// sdk->setQQAppIdAndAppKey("设置QQ的app id", "appkey");
	// sdk->setWeiXinAppId("设置微信和朋友圈的app id");
	// sdk->setYiXinAppKey("设置易信和易信朋友圈的app id");
	// sdk->setLaiwangAppInfo("设置来往和来往动态的app id", 
	//                  "设置来往和来往动态的app key", "我的应用名");
	// sdk->setFacebookAppId("你的facebook appid");
	// 设置用户点击一条图文分享时用户跳转到的目标页面, 一般为app主页或者下载页面
	// sdk->setTargetUrl("http://www.umeng.com/social");
	//     // 打开或者关闭log
	// sdk->setLogEnable(true) ;
	// **********************   END ***************************


    return true;
}


//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//    return;
//#endif
//
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}


// HelloWorld为cocos2d::CCLayer的子类, shareButtonClick为某个按钮点击事件的处理函数
void HelloWorld::menuCloseCallback(Ref* pSender)
{
	// 获取一个CCUMSocialSDK实例
	CCUMSocialSDK *sdk = CCUMSocialSDK::create("54258b8afd98c5944700cfd9");
	// 设置友盟appkey,如果create中设置了不用调用该函数
	// sdk->setAppKey("4eaee02c527015373b000003");
	// **********************   设置平台信息  ***************************
	// sdk->setQQAppIdAndAppKey("设置QQ的app id", "appkey");
	// sdk->setWeiXinAppId("设置微信和朋友圈的app id");
	// sdk->setYiXinAppKey("设置易信和易信朋友圈的app id");
	// sdk->setLaiwangAppInfo("设置来往和来往动态的app id", 
	//              "设置来往和来往动态的app key", "我的应用名");
	// sdk->setFacebookAppId("你的facebook appid");
	//     // 打开或者关闭log
	// sdk->setLogEnable(true) ;
	// **********************   END ***************************

	// 设置用户点击一条图文分享时用户跳转到的目标页面, 一般为app主页或者下载页面
	sdk->setTargetUrl("http://www.umeng.com/social");
	// 设置友盟分享面板上显示的平台
	vector<int>* platforms = new vector<int>();
	platforms->push_back(SINA);
	platforms->push_back(RENREN) ;
	platforms->push_back(DOUBAN) ;
	platforms->push_back(QZONE) ;
	platforms->push_back(QQ) ;
	// 设置平台, 在调用分享、授权相关的函数前必须设置SDK支持的平台
	sdk->setPlatforms(platforms) ;

	// 打开分享面板, 注册分享回调, 参数1为分享面板上的平台, 参数2为要分享的文字内容，
	// 参数3为要分享的图片路径(android和IOS的图片地址格式不一致，因此分平台设置), 参数4为分享回调.
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	sdk->openShare("Test Umeng Shared!!", "/sdcard/image.png", share_selector(shareCallback));
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	sdk->openShare("要分享的文字内容","share.png", share_selector(shareCallback));
#endif
}


//// HelloWorld为cocos2d::CCLayer的子类, shareButtonClick为某个按钮点击事件的处理函数
//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//	// 获取一个CCUMSocialSDK实例
//	CCUMSocialSDK *sdk = CCUMSocialSDK::create("54258b8afd98c5944700cfd9");
//	// 设置用户点击一条图文分享时用户跳转到的目标页面, 一般为app主页或者下载页面
//	sdk->setTargetUrl("http://www.umeng.com/social");   
//	// **********************   设置平台信息  ***************************
//	// sdk->setQQAppIdAndAppKey("设置QQ的app id", "appkey");
//	// sdk->setWeiXinAppId("设置微信和朋友圈的app id");
//	// sdk->setYiXinAppKey("设置易信和易信朋友圈的app id");
//	// sdk->setLaiwangAppInfo("设置来往和来往动态的app id", 
//	//              "设置来往和来往动态的app key", "我的应用名");
//	// sdk->setFacebookAppId("你的facebook appid");
//	//     // 打开或者关闭log
//	// sdk->setLogEnable(true) ;
//	// **********************   END ***************************
//	CCLog("----------------CCUMSocialSDK CLICK BTN----------------------------");
//	// 直接分享，参数1为要分享到的目标平台, 参数2为要分享的文字内容, 
//	// 参数3为要分享的图片路径(android和IOS的图片地址格式不一致，因此分平台设置), 参数4为分享回调.
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//	sdk->directShare(SINA, "fuck umeng!!!!!!!!!","/sdcard/image.png", share_selector(shareCallback));
//#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//	sdk->directShare(SINA, "要分享的文字内容","image.png", share_selector(shareCallback));
//#endif
//}
