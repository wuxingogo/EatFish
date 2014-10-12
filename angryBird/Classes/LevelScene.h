/*
 * LevelScene.h
 *
 *  Created on: 2014-8-19
 *      Author: ly
 */

#ifndef LEVELSCENE_H_
#define LEVELSCENE_H_

#include "cocos2d.h"
USING_NS_CC;


class LevelScene: public cocos2d::CCLayer {
public:
	static cocos2d::CCScene * scene();
	virtual bool init();
	int successLevel; // 当前成功的通关数 1-14
	virtual void ccTouchesEnded(CCSet *touches, CCEvent *pEvent);
	CREATE_FUNC(LevelScene);
        CCSprite * spritebg;

};


#endif /* LEVELSCENE_H_ */
