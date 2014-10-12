/*
 * Loading.h
 *
 *  Created on: 2014-8-17
 *      Author: ly
 */

#ifndef LOADING_H_
#define LOADING_H_

#include"cocos2d.h"
#include<iostream>
using namespace std;
USING_NS_CC;

#include<string.h>
class Loading: public cocos2d::CCLayer {

public:
	CCLabelTTF * loadingTitle;
	char * loading ;
	static void* scene();
	virtual bool init();
	void release();
	CREATE_FUNC(Loading);
	void loadTick(float dt);
            
	//~Loading();
};



#endif /* LOADING_H_ */
