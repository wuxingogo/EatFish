/* 
 * File:   PlayerFishNode.h
 * Author: ly
 *
 * Created on 2014年10月7日, 下午9:09
 */

#ifndef PLAYERFISHNODE_H
#define	PLAYERFISHNODE_H

#include "BaseFishNode.h"


class PlayerFishNode : public BaseFishNode {
public:
    enum class Status
    {
        SMALL = 1,
        NORMAL = 2,
        BIG = 3
    };
    enum class ChildTag
    {
        WATER = 10,
        FLOWER = 11
    };
    virtual bool init();
    CREATE_FUNC(PlayerFishNode);
    Status m_status;    
    bool m_isInvincible; //是否正在无敌状态
    void invincible();      //设置无敌
    void invincibleCallback(float delay);   //自动取消无敌
private:

};

#endif	/* PLAYERFISHNODE_H */

