//
//  SNode.cpp
//  ex4
//
//  Created by Acaleph ❦ on 2017/10/30.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include "SNode.hpp"
#include <iostream>

int Push(SNode * top, DataType item){
    SNode *p = new SNode;
    p->next = top->next;
    top->next = p;
    top->next->item = item;
    return 1;
}

int Pop(SNode *top, DataType &item){
    if(!top) return 0;
    SNode *p = top->next;
    item = p->item;
    top->next = p->next;
    free(p);
    return 1;
}
