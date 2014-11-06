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
 * ����ص�, �ûص�����ĳ����ĳ�Ա������ ����һ����ͨ�ĺ���, ����ʹ�òο�HelloWorldScene������
* @param platform Ҫ������Ŀ��ƽ̨
 * @param stCode ������, 200�������ɹ�, 100����ʼ����
 * @param errorMsg ����ʧ��ʱ�Ĵ�����Ϣ,androidƽ̨û�д�����Ϣ
 */
void shareCallback(int platform, int stCode, string &emsg)
{
	if (stCode == 100)
	{
		CCLog("-----------------��ʼ����");
	} 
	else if(stCode == 200)
	{
		CCLog("-----------------��ʼ�ɹ�");
	}else
	{
		CCLog("-----------------��ʼ����");
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

	// ********************** ����ƽ̨��Ϣ ***************************
	// CCUMSocialSDK *sdk = shareButton->getSocialSDK();
	// sdk->setQQAppIdAndAppKey("����QQ��app id", "appkey");
	// sdk->setWeiXinAppId("����΢�ź�����Ȧ��app id");
	// sdk->setYiXinAppKey("�������ź���������Ȧ��app id");
	// sdk->setLaiwangAppInfo("����������������̬��app id", 
	//                  "����������������̬��app key", "�ҵ�Ӧ����");
	// sdk->setFacebookAppId("���facebook appid");
	// �����û����һ��ͼ�ķ���ʱ�û���ת����Ŀ��ҳ��, һ��Ϊapp��ҳ��������ҳ��
	// sdk->setTargetUrl("http://www.umeng.com/social");
	//     // �򿪻��߹ر�log
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


// HelloWorldΪcocos2d::CCLayer������, shareButtonClickΪĳ����ť����¼��Ĵ�����
void HelloWorld::menuCloseCallback(Ref* pSender)
{
	// ��ȡһ��CCUMSocialSDKʵ��
	CCUMSocialSDK *sdk = CCUMSocialSDK::create("54258b8afd98c5944700cfd9");
	// ��������appkey,���create�������˲��õ��øú���
	// sdk->setAppKey("4eaee02c527015373b000003");
	// **********************   ����ƽ̨��Ϣ  ***************************
	// sdk->setQQAppIdAndAppKey("����QQ��app id", "appkey");
	// sdk->setWeiXinAppId("����΢�ź�����Ȧ��app id");
	// sdk->setYiXinAppKey("�������ź���������Ȧ��app id");
	// sdk->setLaiwangAppInfo("����������������̬��app id", 
	//              "����������������̬��app key", "�ҵ�Ӧ����");
	// sdk->setFacebookAppId("���facebook appid");
	//     // �򿪻��߹ر�log
	// sdk->setLogEnable(true) ;
	// **********************   END ***************************

	// �����û����һ��ͼ�ķ���ʱ�û���ת����Ŀ��ҳ��, һ��Ϊapp��ҳ��������ҳ��
	sdk->setTargetUrl("http://www.umeng.com/social");
	// �������˷����������ʾ��ƽ̨
	vector<int>* platforms = new vector<int>();
	platforms->push_back(SINA);
	platforms->push_back(RENREN) ;
	platforms->push_back(DOUBAN) ;
	platforms->push_back(QZONE) ;
	platforms->push_back(QQ) ;
	// ����ƽ̨, �ڵ��÷�����Ȩ��صĺ���ǰ��������SDK֧�ֵ�ƽ̨
	sdk->setPlatforms(platforms) ;

	// �򿪷������, ע�����ص�, ����1Ϊ��������ϵ�ƽ̨, ����2ΪҪ������������ݣ�
	// ����3ΪҪ�����ͼƬ·��(android��IOS��ͼƬ��ַ��ʽ��һ�£���˷�ƽ̨����), ����4Ϊ����ص�.
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	sdk->openShare("Test Umeng Shared!!", "/sdcard/image.png", share_selector(shareCallback));
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	sdk->openShare("Ҫ�������������","share.png", share_selector(shareCallback));
#endif
}


//// HelloWorldΪcocos2d::CCLayer������, shareButtonClickΪĳ����ť����¼��Ĵ�����
//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//	// ��ȡһ��CCUMSocialSDKʵ��
//	CCUMSocialSDK *sdk = CCUMSocialSDK::create("54258b8afd98c5944700cfd9");
//	// �����û����һ��ͼ�ķ���ʱ�û���ת����Ŀ��ҳ��, һ��Ϊapp��ҳ��������ҳ��
//	sdk->setTargetUrl("http://www.umeng.com/social");   
//	// **********************   ����ƽ̨��Ϣ  ***************************
//	// sdk->setQQAppIdAndAppKey("����QQ��app id", "appkey");
//	// sdk->setWeiXinAppId("����΢�ź�����Ȧ��app id");
//	// sdk->setYiXinAppKey("�������ź���������Ȧ��app id");
//	// sdk->setLaiwangAppInfo("����������������̬��app id", 
//	//              "����������������̬��app key", "�ҵ�Ӧ����");
//	// sdk->setFacebookAppId("���facebook appid");
//	//     // �򿪻��߹ر�log
//	// sdk->setLogEnable(true) ;
//	// **********************   END ***************************
//	CCLog("----------------CCUMSocialSDK CLICK BTN----------------------------");
//	// ֱ�ӷ�������1ΪҪ������Ŀ��ƽ̨, ����2ΪҪ�������������, 
//	// ����3ΪҪ�����ͼƬ·��(android��IOS��ͼƬ��ַ��ʽ��һ�£���˷�ƽ̨����), ����4Ϊ����ص�.
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//	sdk->directShare(SINA, "fuck umeng!!!!!!!!!","/sdcard/image.png", share_selector(shareCallback));
//#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//	sdk->directShare(SINA, "Ҫ�������������","image.png", share_selector(shareCallback));
//#endif
//}
