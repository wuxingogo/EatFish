/*
 * GameScene.cpp
 *
 *  Created on: 2014-8-19
 *      Author: ly
 */

#include "GameScene.h"
#include "Box2D/Box2D.h"
#include <iostream>
#include "GameData.h"


#define SLINGSHOT_POS CCPointMake(85, 125)
//int GameScene::current = 0;
CCScene* GameScene::sceneWithLevel(int level){
	CCScene *sc = CCScene::create();
	CCLayer* layer = GameScene::nodeWithLevel(level);
	sc->addChild(layer);
	return sc;
}
cocos2d::CCLayer* GameScene::nodeWithLevel(int level){
	GameScene *layer = GameScene::create();
	//GameScene::current = level;
	return layer;
}

bool GameScene::init(){
	//printf("%d\n",GameScene::current);

    CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();
	//CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    bgSprite = CCSprite::create("bg.png");
    bgSprite->setPosition(ccp(winSize.width/2,winSize.height/2));
    //bgSprite->setContentSize(winSize);
    
     float wid = winSize.width/bgSprite->getTexture()->getPixelsWide();
                 float height = winSize.height/bgSprite->getTexture()->getPixelsHigh();
                 bgSprite->setScale(wid>height?height:wid);
    
    this->addChild(bgSprite);

    CCSprite * leftShot = CCSprite::create("leftshot.png");
    leftShot->setPosition(ccp(85,110));
    bgSprite->addChild(leftShot);

    CCSprite * rightShot = CCSprite::create("rightshot.png");
    rightShot->setPosition(ccp(85,110));
    bgSprite->addChild(rightShot);

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(GameScene::menuCloseCallback));

    pCloseItem->setPosition(ccp(
			winSize.width -pCloseItem->getContentSize().width*2 ,
			winSize.height -pCloseItem->getContentSize().height*2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    bgSprite->addChild(pMenu);



    slingshot = new SlingShot();
    slingshot->_startPoint1 = ccp(82, 130);
    slingshot->_startPoint2 = ccp(92, 128);
    slingshot->_endPoint = ccp(85,125);
	//slingshot->_endPoint = SLINGSHOT_POS;
	
    slingshot->setContentSize(CCSizeMake(480, 320)) ;
    slingshot->setPosition(ccp(0,0));

    bgSprite->addChild(slingshot);

    
    
    this->createWorld();
    this->createLevel();

    this->setTouchEnabled(true);
    if(isTouchEnabled()){
        printf("isTouched\n");
    }
    return true;
}
void GameScene::createWorld(){
	CCSize winSize = CCDirector::sharedDirector()->getVisibleSize();

	b2Vec2 gravity = b2Vec2(0.0f,-5.0f);

	world = new b2World(gravity);

	contactListener = new MyContactListener(world,this);
	world->SetContactListener(contactListener);

	b2BodyDef groundBodyDef ;
	groundBodyDef.position.Set(0,(88.5f/PTM_RATIO/2));

	b2PolygonShape polygonShape;
	//b2Vec2 vec2 = b2Vec2(winSize.width/PTM_RATIO,87/PTM_RATIO);

	polygonShape.SetAsBox(winSize.width/PTM_RATIO,(88.5f/PTM_RATIO/2));
	//polygonShape.SetAsBox((winSize.width/PTM_RATIO),(87/PTM_RATIO));


	b2Body * groundBody = world->CreateBody(&groundBodyDef);

	groundBody->CreateFixture(&polygonShape,0);

	this->schedule(schedule_selector(GameScene::tick));

}
void GameScene::tick(float dt){
    int32 velocityIterations = 8;
    int32 positionIterations = 1;
    world->Step(dt, velocityIterations, positionIterations);
    world->ClearForces();
    for(b2Body *b = world->GetBodyList(); b; b = b->GetNext()){
        if(b->GetUserData() != NULL){
                                                                        
        SpriteBase *oneSprite = (SpriteBase *)b->GetUserData();
        if(oneSprite->sprite!=NULL){
            oneSprite->sprite->setPosition(ccp( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO));
            oneSprite->sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));

				 //如果小鸟停止运动删除小鸟
                if (oneSprite->sprite->getTag() == BIRD_ID) {
                    bgSprite->addChild(streak);
                    streak->setPosition(oneSprite->sprite->getPosition());
                    if (!b->IsAwake()) {
                        
                        if(oneSprite->sprite!=NULL){
                            //oneSprite->sprite->removeFromParent();
                            //oneSprite->destory();
                        }
                        world->DestroyBody(b); 
                        oneSprite->destory();
                        birds->removeObject(birds->objectAtIndex(0));
                        this->jump();
                        break;
                       
                    }
                    else if(oneSprite->sprite->getPosition().x >480 || oneSprite->sprite->getPosition().y<84){
                        world->DestroyBody(b);               
                        oneSprite->destory();
                        birds->removeObject(birds->objectAtIndex(0));
                        printf("bird is far\n");
                        this->jump();
                    }
                }
                else{
                    if(oneSprite->HP <=0 || oneSprite->sprite->getPosition().x >480 || oneSprite->sprite->getPosition().y<84){
                        world->DestroyBody(b);
                        oneSprite->destory();
                        printf("Destroy Body!\n");
                    }
                }
            }
        }
    }
//printf("count is %d\n",world->GetBodyCount());
}
void GameScene::createLevel(){
	//printf("createLevel\n");

	 bird1 = Bird::init(160,93,world,this);

	bgSprite->addChild(bird1->sprite);

	 bird2 = Bird::init(140,93,world,this);

	bgSprite->addChild(bird2->sprite);

	 bird3 = Bird::init(120,93,world,this);

	bgSprite->addChild(bird3->sprite);


        birds = new CCArray();

        birds->addObject(bird1);
        birds->addObject(bird2);
        birds->addObject(bird3);

	Pig* pig = Pig::init(350.0f,95.1f,world,this);
	this->addChild(pig->sprite);
	Ice * ice1 = Ice::init(313.997803f,129.077576f,world,this);
	bgSprite->addChild(ice1->sprite);
	Ice * ice2 = Ice::init(313.997803f,129.077576f,world,this);
	this->addChild(ice2->sprite);
	Ice * ice3 = Ice::init(313.997803f,129.077576f,world,this);
	this->addChild(ice3->sprite);
	Ice * ice4 = Ice::init(313.997803f,129.077576f,world,this);
	bgSprite->addChild(ice4->sprite);
	Ice * ice5 = Ice::init(313.997803f,129.077576f,world,this);
	bgSprite->addChild(ice5->sprite);

	this->jump();

	printf("world Body Count is %d\n",world->GetBodyCount());
        streak = CCMotionStreak::create(0.1f,0.01f,10,ccWHITE,"bird1.png");
        streak->setFastMode(true);
    //args time 

}
void GameScene::jump(){
	printf("jump\n");
	gameFinish = false;
	//if(!gameFinish){
	if(birds->count() > 0 && !gameFinish){
		currentBird = (Bird*)birds->objectAtIndex(0);
		//currentBird =  bird1;
		printf("%f\n",currentBird->sprite->getPosition().x);
		CCJumpTo * jump = CCJumpTo::create(2.0f,SLINGSHOT_POS,50.0f,1);
		CCCallFunc * jumpFinish = CCCallFunc::create(this,callfunc_selector(GameScene::finishJump));
		CCSequence *allActions = CCSequence::create(jump,jumpFinish,NULL);
                if(currentBird->sprite!=NULL)
	currentBird->sprite->runAction(allActions);

	}
}
void GameScene::finishJump(){
	printf("finishJump\n");
	gameStart = true;
	currentBird->isReady = true;
}
#define TOUCH_UNKNOW 0
#define TOUCH_SHOTBIRD 1

void GameScene::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent){
	touchStatus = TOUCH_UNKNOW;
	CCTouch * oneTouch =(CCTouch * )pTouches->anyObject();
	CCPoint location = oneTouch->getLocationInView();
                 
	CCPoint worldGlPoint = CCDirector::sharedDirector()->convertToGL(location);
        
         slingshot->_endPoint = worldGlPoint;
	printf("ccTouchesBegan\n");
	if(currentBird->sprite == NULL){
                        printf("none\n");
                        return ;

	}
	CCRect birdRect =  currentBird->sprite->boundingBox();
	printf("hava a bird\n");
	if(birdRect.containsPoint(worldGlPoint)){
		touchStatus = TOUCH_SHOTBIRD;
		printf("yeah\n");

	}
}

void GameScene::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent){

	if (touchStatus == TOUCH_SHOTBIRD) {

		CCTouch * oneTouch =(CCTouch * )pTouches->anyObject();
		CCPoint location = oneTouch->getLocationInView();
		CCPoint worldGlPoint = CCDirector::sharedDirector()->convertToGL(location);
               
		CCPoint nodePoint = this->convertToNodeSpace(worldGlPoint);
                 
		printf("Move::%f,%f\n",nodePoint.x,nodePoint.y);
		slingshot->_endPoint = worldGlPoint;
		currentBird->sprite->setPosition(nodePoint) ;
	}
}
void GameScene::ccTouchesEnded(CCSet *touches, CCEvent *pEvent){
	printf("Touch Ended\n");
	if (touchStatus == TOUCH_SHOTBIRD) {
		CCTouch * oneTouch =(CCTouch * )touches->anyObject();
		CCPoint location = oneTouch->getLocationInView();
		CCPoint worldGlPoint = CCDirector::sharedDirector()->convertToGL(location);
		CCPoint nodePoint = this->convertToNodeSpace(worldGlPoint);
		//slingshot->_endPoint = SLINGSHOT_POS;
                slingshot->_endPoint = nodePoint;
		float x = (85.0f-nodePoint.x)*50/70.0f;
		float y = (125.0f-nodePoint.y  )*50/70.0f;
		printf("%f,%f\n",x,y);
		currentBird->setSpeed(x, y,world);
		

	}
}
/*
GameScene::~GameScene(){
	currentBird->sprite->release();
	currentBird->sprite->release();
	currentBird->sprite->release();
	//birds->release();
	CCLayer::release();
	printf("call ~gameScene");

}
*/
void GameScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
/*
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
*/
}

