/*
 * Ice.h
 *
 *  Created on: 2014-8-23
 *      Author: ly
 */

#ifndef ICE_H_
#define ICE_H_

#include "SpriteBase.h"

class Ice: public SpriteBase {
public:
	static Ice* init(float x,float y,b2World* world,CCLayer* layer);
	void create2D(float x,float y);
};

#endif /* ICE_H_ */
