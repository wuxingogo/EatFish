/*
 * Ice.cpp
 *
 *  Created on: 2014-8-23
 *      Author: ly
 */

#include "Ice.h"
Ice* Ice::init(float x,float y,b2World* world,CCLayer* layer){
	Ice * ice = new Ice();
	ice->sprite =CCSprite::create("ice1.png");
	ice->layer = layer;
	ice->world = world;
	ice->sprite->setTag(ICE_ID);
	ice->sprite->setPosition(ccp(x,y));
	ice->HP = 27;
	ice->fullHP =ice->HP;
	ice->sprite->setScale(2.0f/10);
	ice->create2D(x,y);
	return ice;
}
void Ice::create2D(float x,float y){
	 b2BodyDef ballBodyDef;
	    ballBodyDef.type = b2_dynamicBody;
	    ballBodyDef.position.Set(x/PTM_RATIO, y/PTM_RATIO);
	    ballBodyDef.userData = this;

	    b2Body * ballBody = world->CreateBody(&ballBodyDef);

	    //    // Create block shape
	    b2PolygonShape blockShape;
	    blockShape.SetAsBox(this->sprite->getContentSize().width/11/PTM_RATIO,this->sprite->getContentSize().height/11/PTM_RATIO);

	    // Create shape definition and add to body
	    b2FixtureDef ballShapeDef;
	    ballShapeDef.shape = &blockShape;
	    ballShapeDef.density = 10.0f;
	    ballShapeDef.friction = 1.0f; // We don't want the ball to have friction!
	    ballShapeDef.restitution = 0;
	    ballBody->CreateFixture(&ballShapeDef);
}
