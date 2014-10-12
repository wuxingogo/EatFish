/*
 * MyContactListener.cpp
 *
 *  Created on: 2014-9-1
 *      Author: ly
 */

#include "MyContactListener.h"

MyContactListener :: MyContactListener(b2World *w, CCLayer *c) {

    _world = w;
    _layer = c;
}


void MyContactListener:: PostSolve(b2Contact *contact, const b2ContactImpulse *impulse) {
	 // solver计算完成后调用的函数
	 float force = impulse->normalImpulses[0];
	 //得到冲力
	 if(force > 2){
		 SpriteBase *spriteA = (SpriteBase *)contact->GetFixtureA()->GetBody()->GetUserData();
		 SpriteBase *spriteB = (SpriteBase *)contact->GetFixtureB()->GetBody()->GetUserData();
		 if( spriteA && spriteB){
			 printf("sprite A Tag is %d\n",spriteA->sprite->getTag());
			 printf("sprite B Tag is %d\n",spriteB->sprite->getTag());
			 if(spriteA->sprite->getTag() == BIRD_ID){
				 //CCSprite * sprite = spriteA->sprite;
				 //spriteB->sprite->setAnchorPoint(ccp(spriteB->sprite->getPosition().x,spriteB->sprite->getPosition().y));
			 }else{
				 spriteA->HP -=force;
				 printf("BIRD HP is %f\n",spriteA->HP);
			 }
			 if(spriteB->sprite->getTag() == BIRD_ID){
			 	 //CCSprite * sprite = spriteB->sprite;
			 	//spriteB->sprite->setAnchorPoint(ccp(spriteB->sprite->getPosition().x,spriteB->sprite->getPosition().y));
			 }else{
			 	 spriteB->HP -=force;
			 	printf("BIRD HP is %f\n",spriteB->HP);
			 }

		 }
	 }
}
