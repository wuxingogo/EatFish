/*
 * SpriteBase.h
 *
 *  Created on: 2014-8-19
 *      Author: ly
 */

#ifndef SPRITEBASE_H_
#define SPRITEBASE_H_

#include "cocos2d.h"
#include "Box2D/Box2D.h"
USING_NS_CC;


#define PTM_RATIO 32
//  小鸟
#define BIRD_ID 1
// 小猪
#define PIG_ID 2
#define ICE_ID 3

class SpriteBase : public CCObject{
public:
	//virtual static SpriteBase * init(float x,float y,b2World world,CCLayer layer) = 0;
	void destory();
	float HP;
	int fullHP;
	char * imageUrl;
	CCLayer * layer;
	b2World *world;
	b2Body  *myBody;
	CCSprite *sprite;

};

#endif /* SPRITEBASE_H_ */
