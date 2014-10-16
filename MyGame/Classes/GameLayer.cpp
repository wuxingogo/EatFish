/* 
 * File:   GameLayer.cpp
 * Author: ly
 * 
 * Created on 2014年10月5日, 下午8:55
 */

#include "GameLayer.h"
#include "GameConfig.h"
#include "Strings.h"
#include "PlayerFishNode.h"
#include "JellyfishNode.h"
#include "EnemyFishNode.h"
#include "StartLayer.h"


USING_NS_CC;

using namespace std;
using namespace CocosDenshion;

bool GameLayer::init()
{
    if(!Layer::init()){
        return false;
    }
    
    this->m_stageNum = 1;
    this->m_score = 0;
    this->m_playerLife = GAME_CONFIG_PLAYERS;
    this->m_eatFish = 0;
    this->m_eatFishTotal = 0;
    this->m_eatFishTotalType1And2 = 0;
    this->m_eatFishTotalType3 = 0;
    this->m_eatFishTotalType4 = 0;
    
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Fishtales.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Fishall.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("cump.plist");
    
    Size winSize = Director::getInstance()->getWinSize();
    vector<string> bgList;
    bgList.push_back("bg3.png");
    bgList.push_back("bg2.png");
    bgList.push_back("bg1.png");
    //bg
    int i = CCRANDOM_0_1() * (bgList.size()-1);
    this->m_bg = bgList.at(i);
    Sprite* bg = Sprite::create(m_bg);
    bg->setPosition(winSize.width / 2,winSize.height / 2);
    this->addChild(bg);

    //Bubble
    ParticleSystemQuad *blisterLeft = ParticleSystemQuad::create("particle_sys_blister.plist");
    blisterLeft->setPosition(Vec2(winSize.width / 2 - 300, 120));
    blisterLeft->setTag((int)ChildTag::BLISTER_LEFT);
    this->addChild(blisterLeft);
	
    ParticleSystemQuad *blisterRight = ParticleSystemQuad::create("particle_sys_blister.plist");
    blisterRight->setPosition(Vec2(winSize.width / 2 + 300, 120));
    blisterRight->setTag((int)ChildTag::BLISTER_RIGHT);
    this->addChild(blisterRight);
    //all fish in this fishNode
    auto fishNode = Node::create();
    fishNode->setAnchorPoint(Vec2::ZERO);
    fishNode->setPosition(Vec2::ZERO);
    fishNode->setTag((int)ChildTag::FISH_NODE);
    this->addChild(fishNode);

    //right top these thing
    //stageNum
    Label *stageNumLab = Label::create(StringUtils::format(STRINGS_GAME_SCENE_LAB_STAGE_NUM, this->m_stageNum).c_str(), GAME_CONFIG_GLOBAL_FONTNAME_01,
            30, Size(200, 40), TextHAlignment::LEFT, TextVAlignment::CENTER);
    stageNumLab->setPosition(Vec2(winSize.width - 100, winSize.height - 24));
    stageNumLab->enableOutline(Color4B::BLACK,2);
    stageNumLab->setTag((int)ChildTag::LAB_STAGE_NUM);
    this->addChild(stageNumLab);

    //scoreNum
    Label *scoreLab = Label::create(StringUtils::format(STRINGS_GAME_SCENE_LAB_SCORE,this->m_score).c_str(),
            GAME_CONFIG_GLOBAL_FONTNAME_02,30,Size(200,40),TextHAlignment::LEFT,TextVAlignment::CENTER);
    scoreLab->setTag((int)ChildTag::LAB_SCORE);
    scoreLab->setPosition(winSize.width - 100, winSize.height - 56);
    scoreLab->enableOutline(Color4B::BLACK,2);
    this->addChild(scoreLab);
    
    //left top
    //the Progress bg
    Sprite* progressBg = Sprite::createWithSpriteFrameName("progress.png");
    progressBg->setTag((int)ChildTag::PROGRESS_BG);
    progressBg->setPosition(Vec2(80,610));
    this->addChild(progressBg);
    //the Progress bar
    Sprite* progress = Sprite::create("progressk.png");
    progress->setTag((int)ChildTag::PROGRESS);
    progress->setPosition(Vec2(80, 594));
    progress->setAnchorPoint(Vec2(0,0.5));
    progress->setPosition(Vec2(progress->getPosition().x - (progress->getContentSize().width / 2 ),progress->getPosition().y));
    progress->setScaleX(0);
    this->addChild(progress);
    //fish life
    Sprite* fishLife = Sprite::createWithSpriteFrameName("fishlife.png");
    fishLife->setPosition(Vec2(70,550));
    fishLife->setTag((int)ChildTag::FISH_LIFE);
    this->addChild(fishLife);
    //fishLifeLab
    Label* fishLifeLab = Label::create(StringUtils::format("%i",this->m_playerLife).c_str(),GAME_CONFIG_GLOBAL_FONTNAME_01,30,Size(100,40),TextHAlignment::LEFT,TextVAlignment::CENTER);
    fishLifeLab->setPosition(Vec2(140,540));
    fishLifeLab->setTag((int)ChildTag::LAB_FISH_LIFE);
    fishLifeLab->enableOutline(Color4B::BLACK,2);
    this->addChild(fishLifeLab);
    
    this->enabledTouchEvent(false);
    
    
    
    //now 暂停和player没有实现
    
    
    //player
    PlayerFishNode *player = PlayerFishNode::create();
    player->setPosition(Vec2(winSize.width / 2, 800));
    player->setTag((int)ChildTag::FISH_PLAYER);
    fishNode->addChild(player,99999);
    player->invincible();
    player->playAnim();
    
    //配合过场时间,所以延迟进行
    this->scheduleOnce(schedule_selector(GameLayer::gameStart),GAME_CONFIG_TRANSITION);
    
    return true;    
}
Scene* GameLayer::createScene(){
    auto scene = Scene::create();
    auto layer = GameLayer::create();
    scene->addChild(layer);
    return scene;
}
void GameLayer::gameStart(float delay)
{
    Node* fishNode = this->getChildByTag((int)ChildTag::FISH_NODE);
    PlayerFishNode* player = (PlayerFishNode*)fishNode->getChildByTag((int)ChildTag::FISH_PLAYER);
    player->runAction(Sequence::createWithTwoActions(MoveBy::create(1.0,Vec2(0, -400)),
            CallFunc::create(CC_CALLBACK_0(GameLayer::gameStartCallback,this))));
    
}
void GameLayer::gameStartCallback()
{
    this->enabledTouchEvent(true);
    
    Node* fishNode = this->getChildByTag((int)ChildTag::FISH_NODE);
    PlayerFishNode* player = (PlayerFishNode*)fishNode->getChildByTag((int)ChildTag::FISH_PLAYER);
    player->m_isMoving = true;
    
    this->scheduleUpdate();
    //cocos2d-x里会隐式调用update的方法,所以你需要重写update方法
}
void GameLayer::enabledTouchEvent(bool enabled)
{
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    if(enabled)
    {
        auto listener = EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onLayerTouchBegan,this);
        listener->onTouchMoved = CC_CALLBACK_2(GameLayer::onLayerTouchMoved,this);
        listener->onTouchEnded = CC_CALLBACK_2(GameLayer::onLayerTouchEnded,this);
        dispatcher->addEventListenerWithSceneGraphPriority(listener,this);
        
        
    }
    else
        dispatcher->removeEventListenersForTarget(this);
    
}
bool GameLayer::onLayerTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    return true;
}
void GameLayer::onLayerTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
    
    Size winSize = Director::getInstance()->getWinSize();
    Node* fishNode = this->getChildByTag((int)ChildTag::FISH_NODE);
    
    PlayerFishNode* player = (PlayerFishNode*)fishNode->getChildByTag((int)ChildTag::FISH_PLAYER);
    if(player && player->m_isMoving)
    {
        
        Point beginPoint = touch->getLocation();
        Point endPoint = touch->getPreviousLocation();
        Point offSet = beginPoint - endPoint;
        Point toPoint = player->getPosition() + offSet;
        float toX = player->getPosition().x;
        float toY = player->getPosition().y;
        
        Rect rect = player->centerRect();
        Rect moveRect = Rect(rect.size.width /2, rect.size.height / 2, winSize.width - (rect.size.width / 2), winSize.height - (rect.size.height / 2));
        
        //如果toPoint的X存在moveRect的宽度翻胃里面则X可移动,y的情况一样
        if(toPoint.x >= moveRect.origin.x && toPoint.x <= moveRect.size.width)
            toX = toPoint.x;
        if(toPoint.y >= moveRect.origin.y && toPoint.y <= moveRect.size.height)
            toY = toPoint.y;
        player->setPosition(Vec2(toX,toY));
        
        if(offSet.x > 0)
            player->orientationRight();
        else if(offSet.x < 0)
            player->orientationLeft();
        
    }
    
    
}
void GameLayer::onLayerTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    
}

void GameLayer::update(float delay)
{
    Size winSize = Director::getInstance()->getWinSize();
    Node* fishNode = this->getChildByTag((int)ChildTag::FISH_NODE);
    
    if(!fishNode)//如果没有鱼 直接返回
        return ;
    //产生水母
    
    //CCRANDOM_0_1会产生一个随机数0-1
    
    if(CCRANDOM_0_1() <= GAME_CONFIG_ENEMY_JELLYFISH)
    {
        CCLog("产生了一只水母");
        JellyfishNode* enemyFishNode = JellyfishNode::create();
        
        float minVal = enemyFishNode->getContentSize().width /2;
        float maxVal = winSize.width - (enemyFishNode->getContentSize().width / 2);
        
        float srcX = maxVal - minVal;
        srcX = minVal + (srcX * CCRANDOM_0_1());
        
        enemyFishNode->setPosition(Vec2(srcX, -enemyFishNode->getContentSize().height / 2));
        fishNode->addChild(enemyFishNode);
        
        float moveTime = 15.0 - 10.0;
        moveTime = 10.0 + (moveTime * CCRANDOM_0_1());
        
        enemyFishNode->runAction(Sequence::createWithTwoActions(MoveTo::create(moveTime,Vec2(srcX,winSize.height + (enemyFishNode->getContentSize().height / 2))),CallFuncN::create(CC_CALLBACK_1(GameLayer::enemyFishMoveEnd,this))));
    
    }
    
    //fishi 1
    if(CCRANDOM_0_1() <= GAME_CONFIG_ENEMY_FISH1)
    {
        EnemyFishNode* enemyFishNode = EnemyFishNode::create(EnemyFishNode::EnemyFishType::Fish1);
        this->enemyFishEmergence(enemyFishNode);
    }
    //fishi 2
    if(CCRANDOM_0_1() <= GAME_CONFIG_ENEMY_FISH2)
    {
        EnemyFishNode* enemyFishNode = EnemyFishNode::create(EnemyFishNode::EnemyFishType::Fish2);
        this->enemyFishEmergence(enemyFishNode);
    }
    //fishi 3
    if(CCRANDOM_0_1() <= GAME_CONFIG_ENEMY_FISH3)
    {
        EnemyFishNode* enemyFishNode = EnemyFishNode::create(EnemyFishNode::EnemyFishType::Fish3);
        this->enemyFishEmergence(enemyFishNode);
    }//fishi 4
    if(CCRANDOM_0_1() <= GAME_CONFIG_ENEMY_FISH4)
    {
        EnemyFishNode* enemyFishNode = EnemyFishNode::create(EnemyFishNode::EnemyFishType::Fish4);
        this->enemyFishEmergence(enemyFishNode);
    }
    //fishi 5
    if(CCRANDOM_0_1() <= GAME_CONFIG_ENEMY_FISH5)
    {
        EnemyFishNode* enemyFishNode = EnemyFishNode::create(EnemyFishNode::EnemyFishType::Fish5);
        this->enemyFishEmergence(enemyFishNode);
    }
    

    
}
//鱼移动完了该干什么
void GameLayer::enemyFishMoveEnd(cocos2d::Node* sender)
{
    
}
void GameLayer::enemyFishEmergence(BaseFishNode* enemyFishNode)
{
    Vec2 startPoint;
    Vec2 endPoint;
    
    Node* fishNode = this->getChildByTag((int)ChildTag::FISH_NODE);
    
    //左右两边各为50%
    
    if(CCRANDOM_0_1() <= 0.5)
    {
        //左边出现
        startPoint = this->enemyFishRandomLeftPoint(enemyFishNode);
        endPoint = this->enemyFishRandomRightPoint(enemyFishNode); 
        //左边出现朝向右边
        enemyFishNode->orientationRight();
    }
    else
    {
        startPoint = this->enemyFishRandomRightPoint(enemyFishNode);
        endPoint = this->enemyFishRandomLeftPoint(enemyFishNode);
        //右边出现朝向左边
        enemyFishNode->orientationLeft();
    }
    enemyFishNode->setPosition(startPoint);
    fishNode->addChild(enemyFishNode);
    float moveTime = 20.0 - 10.0;
    moveTime = 10 + (moveTime * CCRANDOM_0_1());
    
    //执行动作需要强制设置成YES
    ((BaseEnemyFishNode*)enemyFishNode)->m_isMoving = true;
    ((BaseEnemyFishNode*)enemyFishNode)->m_moveTime =  moveTime;
    ((BaseEnemyFishNode*)enemyFishNode)->m_moveStartPoint = startPoint;
    ((BaseEnemyFishNode*)enemyFishNode)->m_moveEndPoint = endPoint;
    
    enemyFishNode->runAction(Sequence::createWithTwoActions(MoveTo::create(moveTime,endPoint),CallFuncN::create(CC_CALLBACK_1(GameLayer::enemyFishMoveEnd,this))));
}
//鱼从左边出现
Vec2 GameLayer::enemyFishRandomLeftPoint(BaseFishNode* enemyFishNode)
{
    Size winSize = Director::getInstance()->getWinSize();
    float x = -enemyFishNode->getContentSize().width / 2;
    float minY = enemyFishNode->centerRect().size.height / 2;
    float maxY = winSize.height - minY;
    
    float val = maxY - minY;
    float y = minY + (val * CCRANDOM_0_1());
    
    return Vec2(x,y);
}
//鱼从右边出现
Vec2 GameLayer::enemyFishRandomRightPoint(BaseFishNode* enemyFishNode)
{
    Size winSize = Director::getInstance()->getWinSize();
    float x = winSize.width + (enemyFishNode->getContentSize().width / 2);
    float minY = enemyFishNode->centerRect().size.height / 2;
    float maxY = winSize.height - minY;
    
    float val = maxY - minY;
    float y = minY + (val * CCRANDOM_0_1());
    return Vec2(x,y);
    
}
