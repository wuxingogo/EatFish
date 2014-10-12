/*
 * SlingShot.h
 *
 *  Created on: 2014-8-19
 *      Author: ly
 */

#ifndef SLINGSHOT_H_
#define SLINGSHOT_H_

#include"cocos2d.h"
USING_NS_CC;
class SlingShot: public cocos2d::CCSprite {
public:
    CCPoint _startPoint1;
    CCPoint _startPoint2;
    CCPoint _endPoint;
    virtual bool init(void);

    virtual void draw(void);
};

#endif /* SLINGSHOT_H_ */
