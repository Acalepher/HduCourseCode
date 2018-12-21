//
//  chainlist.h
//  ex3
//
//  Created by Acaleph ❦ on 2017/10/23.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#ifndef chainlist_h
#define chainlist_h

#include<iostream>
using namespace std;

struct form
{
    int xh;
    float cj;
};

typedef form DataType;

struct Node
{
    DataType data;
    struct Node * next;
};

//初始化单链表
int InitList(Node * &H);

//判表空
int ListEmpty(Node * H);

//求单链表中当前元素个数
int ListLength(Node * H);

//遍历单链表
void TraverseList(Node * H);

//返回第一个与指定值匹配的元素位置
int Find_item(Node * H, DataType item);

//获取单链表中指定位置上的数据元素
int Find_pos(Node * H, int pos, DataType * item);

//像线性表指定位置插入一个新元素
int ListInsert(Node * H, int pos, DataType item);

//从线性表中删除第一个能与指定值匹配的元素
int ListDelete(Node * H, int item);

//撤销单链表
void DestroyList(Node * &H);

//向递增有序的单链表H中插入新的元素item，插入后单链表仍然有序
//int ListInsert_order(Node * H, DataType item);

#endif /* chainlist_h */
