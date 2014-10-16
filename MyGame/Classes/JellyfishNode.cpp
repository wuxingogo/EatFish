/* 
 * File:   JellyfishNode.cpp
 * Author: ly
 * 
 * Created on 2014年10月9日, 下午3:09
 */

#include "JellyfishNode.h"
#include "GameConfig.h"
#include "FishData.h"

USING_NS_CC;

bool JellyfishNode::init()
{
    if(!BaseEnemyFishNode::init())
    {
        return false;
    }
    
    this->m_animSpriteList = JELLYFISH;
    this->m_animKey = GAME_CONFIG_ANIMKEY_JELLY_FISH;
    this->m_moveTimeElapsed = 0;
    
    Sprite* jellyfish = Sprite::createWithSpriteFrameName(this->m_animSpriteList.at(0).c_str());
    jellyfish->setAnchorPoint(Vec2::ZERO);
    jellyfish->setPosition(Vec2::ZERO);
    jellyfish->setTag((int)BaseFishNode::ChildTag::FISH);
    
    this->addChild(jellyfish);
    this->setAnchorPoint(Vec2(0.5,0.5));
    this->setContentSize(jellyfish->getContentSize());
    
    Node* center = Node::create();
    center->setAnchorPoint(Vec2(0.5,0.5));
    center->setPosition(Vec2(this->getContentSize().width / 2, 110));
    center->setTag((int)ChildTag::CENTER_POINT);
    center->setContentSize(Size(56,64));
    this->addChild(center);
    
    
    return true;
    
}
