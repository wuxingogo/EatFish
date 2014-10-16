/* 
 * File:   MyLayer.h
 * Author: ly
 *
 * Created on 2014年9月26日, 上午9:37
 */

#ifndef STARTLAYER_H
#define	STARTLAYER_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class StartLayer :public cocos2d::Layer{
public:
    
    enum class ChildTag
    {
        BG      =   99,
        TITLE   =   100,
        BTN_HELP    =   101,
        BTN_START   =   102,
        HELP    =   103,
        HELP_TITLE   =   104,
        HELP_LAB1   =   105,
        HELP_LAB2   =   106,
        HELP_LAB3   =   107,
        HELP_BTN_BACK   =   108
    };
    
    virtual bool init();
    CREATE_FUNC(StartLayer);
    static cocos2d::Scene* createScene();
    void onButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eventType);
private:

};

#endif	/* MYLAYER_H */

