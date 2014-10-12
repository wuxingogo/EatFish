/*
 * StartScene.h
 *
 *  Created on: 2014-8-18
 *      Author: ly
 */

#ifndef STARTSCENE_H_
#define STARTSCENE_H_

#include"cocos2d.h"
USING_NS_CC;

class StartScene : public cocos2d::CCLayer {
public:
	static cocos2d::CCScene* scene();
	void createOneBird();
	void beginGame();
	virtual bool init();
	void actionFinish(CCNode * node);
                  CCSprite *bgSprite;
	CREATE_FUNC(StartScene);
};



#endif /* STARTSCENE_H_ */
