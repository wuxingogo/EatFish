/*
 * StartScene.cpp
 *
 *  Created on: 2014-8-18
 *      Author: ly
 */

#include "StartScene.h"
#include "LevelScene.h"
#include "GameScene.h"
#include "stdlib.h"
CCScene* StartScene::scene()
{
    // 'scene' is an autorelease object
    CCScene * scene = CCScene::create();

    // 'layer' is an autorelease object

    StartScene *slayer = StartScene::create();

    // add layer as a child to scene
    scene->addChild(slayer);

    // return the scene
    return scene;
}
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize winSize =CCDirector::sharedDirector()->getVisibleSize();
    bgSprite = CCSprite::create("startbg.png");
    bgSprite->setPosition(ccp(winSize.width/2,winSize.height/2));
    
    float wid = winSize.width/bgSprite->getTexture()->getPixelsWide();
    float height = winSize.height/bgSprite->getTexture()->getPixelsHigh();
    bgSprite->setScale(wid>height?height:wid);
    
    
    this->addChild(bgSprite);

    CCSprite * titleSprite = CCSprite::create("angrybird.png");
    titleSprite->setPosition(ccp(240.0f,250.0f));
    bgSprite->addChild(titleSprite);

    CCSprite * beginSprite = CCSprite::create("start.png");

    CCMenuItemSprite *beginMenuItem  = CCMenuItemSprite::create(beginSprite,NULL,NULL,this,menu_selector(StartScene::beginGame));
    CCMenu* pMenu = CCMenu::create(beginMenuItem, NULL);
    pMenu->setPosition(ccp(240.0f, 130.0f));
    bgSprite->addChild(pMenu);

    this->schedule(schedule_selector(StartScene::createOneBird),1.0f);

    return true;
}
void StartScene::createOneBird(){
	CCSprite * bird = CCSprite::create("bird1.png");
	bird->setScale(rand()%5/5.0f);
	bird->setPosition(ccp(50.0f+rand()%50,70.0f));

	CCPoint endPoint = ccp(360+rand()%50,70.0f);
	float height = rand()%100+50.0f;
	float time = 2.0f;

	CCActionInterval *actionJump = CCJumpTo::create(time,endPoint,height,1);
	CCCallFuncN * actionFinish = CCCallFuncN::create(this,callfuncN_selector(StartScene::actionFinish));
	CCSequence * allAction = CCSequence::create(actionJump,actionFinish,NULL);

	bird->runAction(allAction);

	bgSprite->addChild(bird);

	//bird->release();
}
void StartScene::actionFinish(CCNode * node){
	node->removeFromParentAndCleanup(true);

}
void StartScene::beginGame(){
	this->unschedule(schedule_selector(StartScene::createOneBird));
	CCScene * scene = LevelScene::scene();
	CCTransitionScene *trans = CCTransitionSplitRows::create(2.0f,scene);

	CCDirector::sharedDirector()->replaceScene(trans);


}
