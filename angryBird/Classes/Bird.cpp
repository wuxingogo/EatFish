/*
 * Bird.cpp
 *
 *  Created on: 2014-8-19
 *      Author: ly
 */

#include "Bird.h"

Bird* Bird::init(float x,float y,b2World* world,CCLayer * layer){


	Bird *bird  = new Bird();
	bird->sprite =CCSprite::create("bird1.png");
	bird->layer = layer;
	bird->world = world;
	bird->sprite->setTag(BIRD_ID);
	bird->sprite->setPosition(ccp(x,y));
	bird->HP = 1000;
	bird->sprite->setScale(0.3f);

	return bird;
}
void Bird::setSpeed(float x, float y,b2World * world){
	b2BodyDef bodyDef;
	bodyDef.type =b2_dynamicBody;
	bodyDef.position.Set(this->sprite->getPosition().x/PTM_RATIO,this->sprite->getPosition().y/PTM_RATIO);
	//printf("%f,%f\n",this->sprite->getPosition().x,this->sprite->getPosition().y);
	bodyDef.userData = this;

	 float size = 0.06f;
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

	 b2PolygonShape blockShape;
	 blockShape.Set(vertices,8);
	//circleShape.m_p = 5 / PTM_RATIO;

	b2FixtureDef  fixtrueDef;
	fixtrueDef.shape = &blockShape;
	fixtrueDef.density = 80.0f;
	fixtrueDef.friction = 1.0f;
	fixtrueDef.restitution = 0.5f;

	b2Body * body = world->CreateBody(&bodyDef);
	body->CreateFixture(&fixtrueDef);

	b2Vec2 force = b2Vec2(x,y);
	body->ApplyLinearImpulse(force,bodyDef.position);
	printf("Apply force \n");
}
