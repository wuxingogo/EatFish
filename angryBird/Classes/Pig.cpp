/*
 * Pig.cpp
 *
 *  Created on: 2014-8-23
 *      Author: ly
 */

#include "Pig.h"

Pig* Pig::init(float x,float y,b2World* world,CCLayer * layer){
	Pig * pig = new Pig();
	pig->sprite =CCSprite::create("pig1.png");
	pig->layer = layer;
	pig->world = world;
	pig->sprite->setTag(PIG_ID);
	pig->sprite->setPosition(ccp(x,y));
	pig->HP = 1;
	pig->sprite->setScale(2.0f/10);
	pig->create2D(x,y);



	return pig;
}
void Pig::create2D(float x,float y){
	b2BodyDef ballBodyDef;
	    ballBodyDef.type = b2_dynamicBody;
	    ballBodyDef.position.Set(x/PTM_RATIO, y/PTM_RATIO);
	    ballBodyDef.userData = this;

	    b2Body * ballBody = world->CreateBody(&ballBodyDef);

	    myBody = ballBody;

	    float size = 0.12f;
	    b2PolygonShape blockShape;
	    b2Vec2 vertices[] = {
	        b2Vec2(size ,-2*size),
	        b2Vec2(2*size,-size),
	        b2Vec2(2*size,size),

	        b2Vec2(size,2*size),
	        b2Vec2(-size,2*size),
	        b2Vec2(-2*size,size),
	        b2Vec2(-2*size,-size),
	        b2Vec2(-size,-2*size)
	    };
	    blockShape.Set(vertices, 8);

	    // Create shape definition and add to body
	    b2FixtureDef ballShapeDef;
	    ballShapeDef.shape = &blockShape;
	    ballShapeDef.density = 80.0f;
	    ballShapeDef.friction = 80.0f; // We don't want the ball to have friction!
	    ballShapeDef.restitution = 0.15f;
	    ballBody->CreateFixture(&ballShapeDef);

}
