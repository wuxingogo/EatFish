/* 
 * File:   PlayerFishNode.cpp
 * Author: ly
 * 
 * Created on 2014年10月7日, 下午9:09
 */
#include "GameConfig.h"
#include "PlayerFishNode.h"
#include "FishData.h"

USING_NS_CC;
using namespace CocosDenshion;


bool PlayerFishNode::init()
{
    if(BaseFishNode::init())
    {
        this->m_animSpriteList = PLAYER_FISH;
        this->m_status = Status::SMALL;
        this->m_isInvincible = false;
        this->m_isMoving = false;
        
  
        Sprite* fish = Sprite::createWithSpriteFrameName(this->m_animSpriteList.at(0).c_str());
        fish->setPosition(Vec2::ZERO);
        fish->setAnchorPoint(Vec2::ZERO);
        fish->setTag((int)BaseFishNode::ChildTag::FISH);
        this->addChild(fish);
        
        this->setAnchorPoint(Vec2(0.5,0.5));
        this->setContentSize(fish->getContentSize());
        
        Node* center = Node::create();
        center->setAnchorPoint(Vec2(0.5,0.5));
        center->setPosition(Vec2(this->getContentSize().width / 2 ,21));
        center->setTag((int)BaseFishNode::ChildTag::CENTER_POINT);
        center->setContentSize(Size(16,16));
        this->addChild(center);
     
        
        return true;
    }
    return false;
}

void PlayerFishNode::invincible()
{
    this->m_isInvincible = true;
    Sprite* water = Sprite::createWithSpriteFrameName("water1.png");
    water->setPosition(Vec2(this->getContentSize().width / 2, this->getContentSize().height / 2));
    water->setScale(5.0);
    water->setTag((int)ChildTag::WATER);
    this->addChild(water);
    
    //自动取消无敌时间
    this->scheduleOnce(schedule_selector(PlayerFishNode::invincibleCallback),GAME_CONFIG_PLAYER_INVINCIBLE);
    
}
void PlayerFishNode::invincibleCallback(float delay)
{
    this->m_isInvincible = false;
    Sprite* water = (Sprite*)this->getChildByTag((int)ChildTag::WATER);
    if(water)
        water->removeFromParentAndCleanup(true);
}