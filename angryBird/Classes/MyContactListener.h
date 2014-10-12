/*
 * MyContactListener.h
 *
 *  Created on: 2014-9-1
 *      Author: ly
 */

#ifndef MYCONTACTLISTENER_H_
#define MYCONTACTLISTENER_H_

#include"Box2D/Box2D.h"
#include"cocos2d.h"
#include"SpriteBase.h"
#include"Bird.h"
#include"MyContactListener.h"

class MyContactListener :public b2ContactListener {

public:
	   MyContactListener(b2World *w, CCLayer *c);
	   virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	   b2World *_world;
	   CCLayer *_layer;
};

#endif /* MYCONTACTLISTENER_H_ */
