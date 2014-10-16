/* 
 * File:   JellyfishNode.h
 * Author: ly
 *
 * Created on 2014年10月9日, 下午3:09
 */

#ifndef JELLYFISHNODE_H
#define	JELLYFISHNODE_H

#include "BaseEnemyFishNode.h"
/*水母类*/
class JellyfishNode : public BaseEnemyFishNode{
public:
  virtual bool init();
  CREATE_FUNC(JellyfishNode);
private:

};

#endif	/* JELLYFISHNODE_H */

