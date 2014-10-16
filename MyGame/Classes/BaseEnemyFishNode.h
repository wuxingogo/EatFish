/* 
 * File:   BaseEnemyFishNode.h
 * Author: ly
 *
 * Created on 2014年10月9日, 下午3:10
 */

#ifndef BASEENEMYFISHNODE_H
#define	BASEENEMYFISHNODE_H

#include "BaseFishNode.h"
class BaseEnemyFishNode : public BaseFishNode{
public:
    float m_moveTimeElapsed;
    
    float m_moveTime;//游动时间(其实就是速度))
    
    //游动的位置
    cocos2d::Vec2 m_moveStartPoint;
    cocos2d::Vec2 m_moveEndPoint;

private:

};

#endif	/* BASEENEMYFISHNODE_H */

