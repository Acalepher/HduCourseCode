//
//  main.cpp
//  ex5-2
//
//  Created by Acaleph ❦ on 2017/11/6.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include "SqQueue.hpp"
#include "LinkQueue.hpp"
#include "SqStack.h"
#include "LinkStack.h"

void Reverse(LinkQueue &Q)
 {
 DataType t;
 SNode *S;
 InitStack(S);
 while(QueueEmpty(Q)!=1)
 {
 DeQueue(Q, t);
 Push(S,t);
 }
 while(StackEmpty(S)!=1)
 {
 Pop(S, t);
 EnQueue(Q,t);
 }
 }

int Palindrome_Test(char str[]){
    int i=0,len;
    char t;
    SNode *S;
    InitStack(S);
    while(str[i]){
        Push(S,str[i]);
        i++;
    }
    len=i;
    i=0;
    while(str[i]){
        Pop(S, t);
        if(str[i]!=t) break;
        i++;
    }
    if(i==len)
        return 1;
    else
        return 0;
}

int main()
{
    char str[20];
    cout<<"input a str:"<<endl;
    cin>>str;
    
    if(Palindrome_Test(str)==1)
        cout<<str<<"是回文"<<endl;
    else
        cout<<str<<"不是回文"<<endl;
    
    
    /*//链式队列实验 开始
    DataType temp;
    LinkQueue Q1;
    InitQueue(Q1);
    
    EnQueue(Q1,'a');//断点①
    EnQueue(Q1,'b');
    EnQueue(Q1,'c');
    
    DeQueue(Q1, temp);//断点②
    DeQueue(Q1, temp);
    DeQueue(Q1, temp);
    //链式队列实验 结束
    
    //循环队列实验 开始
    SqQueue Q2;
    InitQueue(Q2);
    
    EnQueue(Q2,'a');//断点③
    EnQueue(Q2,'b');
    EnQueue(Q2,'c');
    EnQueue(Q2,'d');
    
    EnQueue(Q2,'e');//此处入队是否成功？
    
    DeQueue(Q2, temp);//断点④
    DeQueue(Q2, temp);
    DeQueue(Q2, temp);
    DeQueue(Q2, temp);
    
    for(int i=0; i<4; i++)
        EnQueue(Q2,'f'+i);
    EnQueue(Q2,'j');//断点⑤ 此处入队是否成功？
    //循环队列实验 结束
    */
    
     /*LinkQueue Q;
     InitQueue(Q);
     for(int i=0;i<4;i++)
     EnQueue(Q,'a'+i);
     TraverseQueue(Q);
     Reverse(Q);
     TraverseQueue(Q);
     */
    
    return 1;
}


