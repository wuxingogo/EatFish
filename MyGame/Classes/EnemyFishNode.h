/* 
 * File:   EnemyFishNode.h
 * Author: ly
 *
 * Created on 2014年10月11日, 下午4:26
 */

#ifndef ENEMYFISHNODE_H
#define	ENEMYFISHNODE_H

#include "BaseEnemyFishNode.h"

class EnemyFishNode : public BaseEnemyFishNode {
public:
    enum class EnemyFishType
    {
        Fish1 = 1,
        Fish2 = 2,
        Fish3 = 3,
        Fish4 = 4,
        Fish5 = 5,
        Fish6 = 6
    };
    EnemyFishType m_type;
    virtual bool init(EnemyFishType type);
    static EnemyFishNode* create(EnemyFishType type);
private:

};

#endif	/* ENEMYFISHNODE_H */

