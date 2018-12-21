//
//  SqQueue.hpp
//  ex5-2
//
//  Created by Acaleph ❦ on 2017/11/6.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#ifndef SqQueue_hpp
#define SqQueue_hpp

#include <iostream>
using namespace std;

#define QUEUESIZE 5

typedef char DataType;

typedef struct
{
    DataType items[QUEUESIZE];
    int    front;
    int rear;
}SqQueue;

//初始化空循环队列
int InitQueue(SqQueue &Q);

//求循环队列长度
int QueueLength(SqQueue &Q);

//判循环队列空
int QueueEmpty(SqQueue &Q);

//循环队列入队
int EnQueue(SqQueue &Q, DataType item );

//循环队列出队
int DeQueue(SqQueue &Q, DataType &item );

//取队头
int GetFront(SqQueue &Q, DataType &item );

//遍历队列
void TraverseQueue(SqQueue &Q);

// SqQueue.h


#endif /* SqQueue_hpp */
