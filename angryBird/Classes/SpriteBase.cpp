/*
 * SpriteBase.cpp
 *
 *  Created on: 2014-8-19
 *      Author: ly
 */

#include "SpriteBase.h"




 void SpriteBase::destory(){

//layer->removeChild(sprite,true);
     if(sprite)
         this->sprite->removeFromParent();

 }
