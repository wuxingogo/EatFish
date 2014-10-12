/*
 * Loading.cpp
 *
 *  Created on: 2014-8-17
 *      Author: ly
 */

#include "Loading.h"
#include "StartScene.h"



void* Loading::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    Loading *layer = Loading::create();

    // add layer as a child to scene
    scene->addChild(layer);


    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool Loading::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCSize winSize =CCDirector::sharedDirector()->getVisibleSize();
    cout<<winSize.width<<endl;
    cout<<winSize.height<<endl;
   
    

    CCSprite * bgsprite = CCSprite::create("loading.png");
    bgsprite->setPosition(ccp(winSize.width/2,winSize.height/2));
    

    float wid = winSize.width/bgsprite->getTexture()->getPixelsWide();
    float height = winSize.height/bgsprite->getTexture()->getPixelsHigh();
    bgsprite->setScale(wid>height?height:wid);
    
    this->addChild(bgsprite);
    
    loading = new char[25];
    strcpy(loading,"Loading");
    loadingTitle = CCLabelTTF::create(loading,"Marker Felt.ttf",16);

    loadingTitle->setAnchorPoint(ccp(0.0f,0.0f));
    loadingTitle->setPosition(ccp(bgsprite->getContentSize().width-80.0f,10.0f));
    bgsprite->addChild(loadingTitle);

    this->schedule(schedule_selector(Loading::loadTick),1.0f);
    return true;
}

void Loading::loadTick(float dt){
	static int count;
	count++;
	if(count>2){
		this->unschedule(schedule_selector(Loading::loadTick));
		CCScene * sScene = StartScene::scene();
		CCTransitionScene *trans = CCTransitionFlipX::create(0.5f,sScene);

		CCDirector::sharedDirector()->replaceScene(trans);


	}
	strcat(loading,".");
	loadingTitle->setString(loading);
}
/*
Loading::~Loading(){
	loadingTitle->release();
	loading = NULL;
	CCLayer::release();
	printf("~call Loading\n");
}
*/



