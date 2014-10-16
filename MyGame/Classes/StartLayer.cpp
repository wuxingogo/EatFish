/* 
 * File:   MyLayer.cpp
 * Author: ly
 * 
 * Created on 2014年9月26日, 上午9:37
 */


#include "StartLayer.h"
#include <iostream>
#include "Strings.h"
#include "GameConfig.h"
#include "ui/CocosGUI.h"
#include "GameLayer.h"
USING_NS_CC;
using namespace ui;

//USING_NS_CC; 
//USING_NS_CC_EXT; 
//using namespace cocostudio;  

using namespace CocosDenshion;
Scene* StartLayer::createScene(){
    auto scene = Scene::create();
    auto layer = StartLayer::create();
    scene->addChild(layer);
    return scene;
}
bool StartLayer::init(){
    if(!Layer::init()){
        return false;
    }
    Size winSize = Director::getInstance()->getWinSize();
    //bg img
    auto bg = Sprite::create("bg1.png");
    bg->setPosition(Vec2(winSize.width / 2,winSize.height / 2));
    bg->setTag((int)ChildTag::BG);
    this->addChild(bg);
    
    //title
    auto title = Sprite::create("scene_start_title.png");
    title->setPosition(Vec2(winSize.width / 2, 510));
    title->setTag((int)ChildTag::TITLE);
    this->addChild(title);
    
    //start button
    auto btnStart = Button::create();
    btnStart->loadTextureNormal("btn1_up.png");
    btnStart->loadTexturePressed("btn1_dw.png");
    btnStart->setPosition(Vec2(winSize.width / 2, 210));
    btnStart->addTouchEventListener(CC_CALLBACK_2(StartLayer::onButton,this));
    btnStart->setTag((int)ChildTag::BTN_START);
    btnStart->setTitleFontName(GAME_CONFIG_GLOBAL_FONTNAME_01);
    btnStart->setTitleFontSize(32.0f);
    btnStart->setTitleText(STRINGS_START_SCENE_BTN_START);
    this->addChild(btnStart);
    
    //help button
    Button *btnHelp = Button::create();
    btnHelp->loadTextureNormal("btn1_up.png");
    btnHelp->loadTexturePressed("btn1_dw.png");
    btnHelp->setPosition(Vec2(winSize.width/2,130));
    btnHelp->addTouchEventListener(CC_CALLBACK_2(StartLayer::onButton,this));
    btnHelp->setTag((int)ChildTag::BTN_HELP);
    btnHelp->setTitleText(STRINGS_START_SCENE_BTN_HELP);
    btnHelp->setTitleFontName(GAME_CONFIG_GLOBAL_FONTNAME_01);
    btnHelp->setTitleFontSize(32.0f);
    this->addChild(btnHelp);
    
    return true;
}
void StartLayer::onButton(Ref* pSender, ui::Widget::TouchEventType eventType){
    //if touch type is ended
    if(eventType == ui::Widget::TouchEventType::ENDED){
        switch(((Button*)pSender)->getTag())
        {
            
            case (int)ChildTag::BTN_START:
            {
                auto scene = GameLayer::createScene();
                auto trans = TransitionFade::create(GAME_CONFIG_TRANSITION,scene);
                Director::getInstance()->replaceScene(trans);
                break;
            }
            case (int)ChildTag::BTN_HELP:
            {
              
                break;
            }
        }
    }
}

