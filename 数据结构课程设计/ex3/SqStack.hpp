//
//  SqStack.hpp
//  ex4
//
//  Created by Acaleph ❦ on 2017/10/30.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#ifndef SqStack_hpp
#define SqStack_hpp

#include <stdio.h>
#define MAXSIZE 20

typedef int DataType;

struct SqStack{
    DataType items[MAXSIZE];
    int top=-1;
};


int Push(SqStack & S, DataType item);

int Pop(SqStack & S, DataType &item);


#endif /* SqStack_hpp */
