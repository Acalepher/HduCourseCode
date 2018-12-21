//
//  SqStack.cpp
//  ex4
//
//  Created by Acaleph ❦ on 2017/10/30.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//
#include <iostream>
#include "SqStack.hpp"

using namespace std;

int Push(SqStack & S, DataType item){
    if(S.top+1 == MAXSIZE){
        cout<<"数据溢出"<<endl;
        return 0;
    }
    S.items[++S.top] = item;
    return 1;
}

int Pop(SqStack & S, DataType &item){
    if(S.top==-1){
        cout<<"栈空"<<endl;
        return 0;
    }
    item = S.items[S.top];
    S.items[S.top] = 0;
    S.top--;
    return 1;
}
