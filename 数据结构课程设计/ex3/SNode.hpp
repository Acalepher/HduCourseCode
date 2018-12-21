//
//  SNode.hpp
//  ex4
//
//  Created by Acaleph ❦ on 2017/10/30.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#ifndef SNode_hpp
#define SNode_hpp

#include <stdio.h>
using namespace std;

typedef int DataType;
struct SNode{
    DataType item;
    SNode * next;
};

int Push(SNode *top, DataType item);

int Pop(SNode *top, DataType &item);



#endif /* SNode_hpp */
