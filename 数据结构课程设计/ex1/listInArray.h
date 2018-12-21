//
//  listInArray.h
//  class-1
//
//  Created by Cyris on 2017/10/16.
//  Copyright © 2017年 Cyris. All rights reserved.
//

#ifndef listInArray_h
#define listInArray_h

#include <iostream>
using namespace std;

#define LISTSIZE 100
typedef int DataType;
typedef struct Sqlist{
    DataType items[LISTSIZE];
    int length;
}LIST;

// 初始化空线性表
void InitList(LIST &L);

// 判断线性表是否为空
int ListEmpty(LIST &L);

// 求出线性表长度
int ListLength(LIST &L);

// 向线性表指定位置插入一个新元素
int ListInsert(LIST &L, int pos, DataType item);

// 从线性表中删除第一个与指定元值匹配的元素
int ListDelete(LIST &L, int pos, DataType * item);

// 获取顺序表中指定位置上的数据元素
int GetElem(LIST &L, int pos,DataType * item);

// 从线性表中查找元素，返回第一个与指定值匹配的元素
int Find(LIST &L,DataType item);

// 遍历输出线性表
int TraverseList(LIST &L);

//合并两个线性表
int MergeList(LIST&L1, LIST&L2);

//合并非递减列表为lc
void MergeList_Sq(LIST La, LIST Lb, LIST&Lc);


#endif /* listInArray_h */

