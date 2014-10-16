/* 
 * File:   EnemyFishNode.cpp
 * Author: ly
 * 
 * Created on 2014年10月11日, 下午4:26
 */

#include "EnemyFishNode.h"
#include "FishData.h"
#include "GameConfig.h"

USING_NS_CC;

bool EnemyFishNode::init(EnemyFishType type) {
    if (BaseEnemyFishNode::init()) {
        this->m_type = type;
        this->m_moveTimeElapsed = 0;

        switch (this->m_type) {
            case EnemyFishType::Fish2:
                this->m_animSpriteList = FISH2;
                this->m_animKey = GAME_CONFIG_ANIMKEY_ENEMY_FISH2;
                break;

            case EnemyFishType::Fish3:
                this->m_animSpriteList = FISH3;
                this->m_animKey = GAME_CONFIG_ANIMKEY_ENEMY_FISH3;
                break;

            case EnemyFishType::Fish4:
                this->m_animSpriteList = FISH4;
                this->m_animKey = GAME_CONFIG_ANIMKEY_ENEMY_FISH4;
                break;
            case EnemyFishType::Fish5:
                this->m_animSpriteList = FISH5;
                this->m_animKey = GAME_CONFIG_ANIMKEY_ENEMY_FISH5;
                break;
            case EnemyFishType::Fish6:
                this->m_animSpriteList = FISH6;
                this->m_animKey = GAME_CONFIG_ANIMKEY_ENEMY_FISH6;
                break;

            default:
                this->m_animSpriteList = FISH1;
                this->m_animKey = GAME_CONFIG_ANIMKEY_ENEMY_FISH1;
                break;


        }

        Sprite* enemyFish = Sprite::createWithSpriteFrameName(this->m_animSpriteList.at(0).c_str());
        enemyFish->setAnchorPoint(Vec2::ZERO);
        enemyFish->setTag((int) BaseFishNode::ChildTag::FISH);
        enemyFish->setPosition(Vec2::ZERO);
        this->addChild(enemyFish);

        this->setAnchorPoint(Vec2(0.5, 0.5));
        this->setContentSize(enemyFish->getContentSize());

        Node* center = Node::create();
        center->setAnchorPoint(Vec2(0.5,0.5));
        center->setTag((int)ChildTag::CENTER_POINT);
        
        switch(this->m_type)
        {
            case EnemyFishType::Fish2:
                center->setPosition(Vec2(this->getContentSize().width / 2, 12));
                center->setContentSize(Size(16,16));
                break;
                
            case EnemyFishType::Fish3:
                center->setPosition(Vec2(this->getContentSize().width / 2, 30));
                center->setContentSize(Size(24,24));
                break;
                
            case EnemyFishType::Fish4:
                center->setPosition(Vec2(this->getContentSize().width / 2, 50));
                center->setContentSize(Size(40,40));
                break;
                
            case EnemyFishType::Fish5:
                center->setPosition(Vec2(this->getContentSize().width / 2, 105));
                center->setContentSize(Size(128,96));
                break;
                
            case EnemyFishType::Fish6:
                center->setPosition(Vec2(this->getContentSize().width / 2, 105));
                center->setContentSize(Size(128,96));
                break;
                
            default:
                center->setPosition(Vec2(this->getContentSize().width / 2, 12));
                center->setPosition(Size(16,16));
                break;
                
        }
        this->addChild(center);
        this->playAnim();
//        this->scheduleUpdate();
        
        return true;
    }
    return false;
}
EnemyFishNode* EnemyFishNode::create(EnemyFishType type)
{
    EnemyFishNode* obj = new EnemyFishNode();
    if(obj && obj->init(type))
    {
        obj->autorelease();
        return obj;
    }
    CC_SAFE_DELETE(obj);
    return NULL;
}