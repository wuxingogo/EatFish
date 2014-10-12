/*
 * LevelScene.cpp
 *
 *  Created on: 2014-8-19
 *      Author: ly
 */

#include "LevelScene.h"
#include "StartScene.h"
#include "GameScene.h"
using namespace std;

cocos2d::CCScene * LevelScene::scene(){
	CCScene * pscene = CCScene::create();
	LevelScene * layer = LevelScene::create();
	pscene->addChild(layer);
	return pscene;
}
bool LevelScene::init(){
	if(!CCLayer::init()){
		return false;
	}
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	spritebg = CCSprite::create("selectlevel.png");
	
        
        
                 float wid = winSize.width/spritebg->getTexture()->getPixelsWide();
                 float height = winSize.height/spritebg->getTexture()->getPixelsHigh();
                 spritebg->setScale(wid>height?height:wid);
                 spritebg->setPosition(ccp(winSize.width/2,winSize.height/2));
                 this->addChild(spritebg);

     
	CCSprite * backSprite = CCSprite::create("backarrow.png");
	backSprite->setPosition(ccp(40.0f,40.0f));
	backSprite->setScale(0.5f);
	backSprite->setTag(100);
	this->addChild(backSprite);
  

	successLevel = 2;
	char * imgPath = new char[255];
	char * num = new char;
	for(int i = 0 ; i < 14; i++){
		if(i<successLevel){
			strcpy(imgPath,"level.png");
			sprintf(num,"%d",i+1);
                                                      //CCNode *node = CCNode::create();
			CCLabelTTF * numLabel = CCLabelTTF::create(num,"Arial",30,CCSizeMake(0.0f,0.0f),kCCTextAlignmentCenter);

			numLabel->setPosition(ccp(60+i%7*60,320-75-i/7*80));
			this->addChild(numLabel,2);
                                                      
                                                      //spritebg->addChild(node);
		}else{
			strcpy(imgPath,"level.png");
		}
		CCSprite * levelSprite = CCSprite::create(imgPath);
		levelSprite->setTag(i+1);
		float x = 60+i%7*60;
		float y = 320-60-i/7*80;
		levelSprite->setPosition(ccp(x,y));
		levelSprite->setScale(0.6f);
		this->addChild(levelSprite,1);
	}


	this->setTouchEnabled(true);
     
	return true;
}
void LevelScene::ccTouchesEnded(CCSet *touches, CCEvent *pEvent){

	printf("touches\n");
	CCTouch * oneTouch =(CCTouch * )touches->anyObject();
	CCPoint location = oneTouch->getLocationInView();
	CCPoint worldGlPoint = CCDirector::sharedDirector()->convertToGL(location);

	CCPoint nodePoint = this->convertToNodeSpace(worldGlPoint);
	 for (int i = 0; i < 14; i++) {
		 CCSprite *oneSprite = (CCSprite *)this->getChildren()->objectAtIndex(i);
		 CCRect oneBox =  oneSprite->boundingBox();
		 if(oneBox.containsPoint(nodePoint)&&oneSprite->getTag() ==100){
			 //返回菜单得点击
			 CCScene *sc = StartScene:: scene();
			 CCTransitionScene *tran = CCTransitionFlipX::create(2.0f,sc);
			 CCDirector::sharedDirector()->replaceScene(tran);
		 }else if(oneBox.containsPoint(nodePoint) && oneSprite->getTag() < successLevel+1 && oneSprite->getTag() > 0){
			 CCScene * scene = GameScene::sceneWithLevel(oneSprite->getTag());
			 CCTransitionScene *tran = CCTransitionZoomFlipAngular::create(2.0f,scene);
			 CCDirector::sharedDirector()->replaceScene(tran);
		 }

	 }
  


}

