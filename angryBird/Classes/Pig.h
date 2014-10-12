/*
 * Pig.h
 *
 *  Created on: 2014-8-23
 *      Author: ly
 */

#ifndef PIG_H_
#define PIG_H_

#include "SpriteBase.h"

class Pig: public SpriteBase {
public:
	static Pig* init(float x,float y,b2World* world,CCLayer* layer);
	void create2D(float x,float y);
};

#endif /* PIG_H_ */
