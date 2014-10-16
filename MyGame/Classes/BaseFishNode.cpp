/* 
 * File:   BaseFishNode.cpp
 * Author: ly
 * 
 * Created on 2014年10月7日, 下午9:01
 */

#include "BaseFishNode.h"
USING_NS_CC;

using namespace std;


bool BaseFishNode::init()
{
    if(Node::init())
    {
        this->m_orientation = Orientation::LEFT;
        return true;
    }
    return false;
}
Rect BaseFishNode::centerRect()
{
    Node* center = this->getChildByTag((int)ChildTag::CENTER_POINT);
    
    if(!center)
        return Rect::ZERO;
    Vec2 point = center->boundingBox().origin;
    point = this->convertToWorldSpace(point);
    
    return Rect(point.x,point.y,center->getContentSize().width,center->getContentSize().height);
}
void BaseFishNode::orientationRight()
{
    this->m_orientation = Orientation::RIGHT;
    
    Sprite* fish = (Sprite*)this->getChildByTag((int)ChildTag::FISH);
    fish->setFlippedX(true);
}
void BaseFishNode::orientationLeft()
{
    this->m_orientation = Orientation::LEFT;
    
    Sprite* fish = (Sprite*)this->getChildByTag((int)ChildTag::FISH);
    fish->setFlippedX(false);
}
void BaseFishNode::playAnim()
{
    Animation* anim = AnimationCache::getInstance()->getAnimation(this->m_animKey);
    
    Sprite* fish = (Sprite*)this->getChildByTag((int)ChildTag::FISH);
    
    if(!anim)
    {
        Vector<SpriteFrame*> frames;
        
        vector<string>::iterator it = this->m_animSpriteList.begin();
        //vector<string>::interator it = this->m_animSpriteList.begin();
        while(it != this->m_animSpriteList.end()){
            string item = *it;
            frames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(item.c_str()));
            it++;
            
        }
        anim = Animation::createWithSpriteFrames(frames);
        //设置切换速度
        anim->setDelayPerUnit(0.1);
        anim->setRestoreOriginalFrame(false);
        
        AnimationCache::getInstance()->addAnimation(anim, this->m_animKey);
        
        this->setContentSize(frames.at(0)->getOriginalSize());
        
        
    }
    fish->stopAllActions();
    
    RepeatForever* animate = RepeatForever::create(Animate::create(anim));
    fish->runAction(animate);
}