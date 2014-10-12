/*
 * Bird.h
 *
 *  Created on: 2014-8-19
 *      Author: ly
 */

#ifndef BIRD_H_
#define BIRD_H_

#include "SpriteBase.h"

class Bird: public SpriteBase {
public :
	static Bird* init(float x,float y,b2World* world,CCLayer* layer);
	bool isReady;
	bool isFly;
	void setSpeed(float x, float y,b2World * world);

};

#endif /* BIRD_H_ */
