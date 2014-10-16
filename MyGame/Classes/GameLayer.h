/* 
 * File:   GameLayer.h
 * Author: ly
 *
 * Created on 2014年10月5日, 下午8:55
 */

#ifndef GAMELAYER_H
#define	GAMELAYER_H

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"

#include "BaseFishNode.h"

class GameLayer : cocos2d::Layer{
public:
    int m_stageNum; //关卡
    int m_score; //分数

    int m_eatFish; //吃了鱼的分数，用来判断变大的，player死了会清0
    int m_eatFishTotal; //吃了鱼的总数
    int m_eatFishTotalType1And2; //吃了Type1和2的鱼的总数
    int m_eatFishTotalType3; //吃了Type3的鱼的总数
    int m_eatFishTotalType4; //吃了Type4的鱼的总数

    int m_playerLife; //玩家生命周期
    
    enum class ChildTag
    {
        BG = 1,
        BLISTER_LEFT = 2,
        BLISTER_RIGHT = 3,
        LAB_STAGE_NUM = 4,
        LAB_SCORE = 5,
        LAB_FISH_LIFE = 6,
        BTN_PAUSE = 7,
        PROGRESS_BG = 8,
        PROGRESS = 9,
        FISH_LIFE = 10,
        FISH_NODE = 11,
        FISH_PLAYER = 20,
        PAUSE_NODE = 21,
        BTN_RESUME = 22,
        BTN_SOUND = 23,
        BTN_EFFECT = 24,
        BTN_EXIT = 25,
        MASK = 26,
        CLEAR_NODE = 27,
        BTN_NEXT = 28,
        GAMEOVER_NODE = 29,
        BTN_RESTART = 30
    };
    
    CREATE_FUNC(GameLayer);
    virtual bool init();
    static cocos2d::Scene* createScene();
    
    void gameStart(float delay);
    void gameStartCallback();
    
    void enabledTouchEvent(bool enabled);
    void update(float delay);
    
    void enemyFishMoveEnd(cocos2d::Node* sender);
    
    bool onLayerTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onLayerTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onLayerTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    

    
private:
    //bg img
    std::string m_bg;
    
    //创建敌人的过程
    void enemyFishEmergence(BaseFishNode* enemyFishNode);
    
    //创建从左边还是右边出现的敌人
    cocos2d::Vec2 enemyFishRandomLeftPoint(BaseFishNode* enemyFishNode);
    cocos2d::Vec2 enemyFishRandomRightPoint(BaseFishNode* enemyFishNode);
    
};

#endif	/* GAMELAYER_H */

