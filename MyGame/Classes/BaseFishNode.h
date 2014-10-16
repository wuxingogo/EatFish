/* 
 * File:   BaseFishNode.h
 * Author: ly
 *
 * Created on 2014年10月7日, 下午9:01
 */

#ifndef BASEFISHNODE_H
#define	BASEFISHNODE_H
#include "cocos2d.h"

class BaseFishNode : public cocos2d::Node {
public:
    enum class ChildTag
    {
        FISH = 1,
        CENTER_POINT = 2,
        CUMP = 3
    };
    enum class Orientation
    {
        LEFT = 1,
        RIGHT = 2
    };
    Orientation m_orientation; //朝向
    virtual bool init();
    

    
    bool m_isMoving;            //是否移动
    cocos2d::Rect centerRect();
    
    void orientationRight();
    void orientationLeft();
    
    std::vector<std::string> m_animSpriteList;
    std::string m_animKey;

    void playAnim();               //播放动画
    
    
private:

};

#endif	/* BASEFISHNODE_H */

