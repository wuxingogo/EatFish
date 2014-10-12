/*
 * SlingShot.cpp
 *
 *  Created on: 2014-8-19
 *      Author: ly
 */

#include "SlingShot.h"
bool SlingShot::init(void){
	return true;
}
void SlingShot::draw(void){
   
    glLineWidth(2.0f);
    ccDrawColor4B(20,20,20,125);
    ccDrawLine(_startPoint1,_endPoint);
    ccDrawLine(_startPoint2,_endPoint);
}
