/*
 * GameScene.h
 *
 *  Created on: 2014-8-19
 *      Author: ly
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"
#include "SlingShot.h"
#include "SpriteBase.h"
#include "Box2D/Box2D.h"
#include "MyContactListener.h"
#include "Bird.h"
#include "Pig.h"
#include "Ice.h"
USING_NS_CC;

class GameScene: public cocos2d::CCLayer {


public:
	//static int current;
	static cocos2d::CCScene* sceneWithLevel(int level);
	static cocos2d::CCLayer* nodeWithLevel(int level);
	CREATE_FUNC(GameScene);
	void createWorld();
	void createLevel();
	virtual bool init();
	b2World* world;
	void jump();
	//CCArray * birds;
	void finishJump();
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
   //~GameScene();
   void tick(float dt);
   void menuCloseCallback(CCObject* pSender);
   MyContactListener *contactListener;
private:
	SlingShot *slingshot;
	bool gameFinish;
	bool gameStart;
	CCArray *  birds;
	int touchStatus;
	Bird * bird1;
	Bird * bird2;
	Bird * bird3;
	Bird * currentBird;
        CCMotionStreak * streak;
        CCSprite *bgSprite;
};




#endif /* GAMESCENE_H_ */
