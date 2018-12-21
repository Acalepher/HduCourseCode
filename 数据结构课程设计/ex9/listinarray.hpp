//
//  listinarray.hpp
//  ex9
//
//  Created by Acaleph ❦ on 2017/12/11.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#ifndef listinarray_hpp
#define listinarray_hpp

#include <iostream>
using namespace std;

#define LISTSIZE 10

typedef int DataType;//声明DataType类型

typedef struct SqList{
    DataType items[LISTSIZE]; //存放线性表数据
    int length;
}LIST;// LIST为用户定义的线性表类型

//初始化空线性表
void InitList(LIST &L);

//判断线性表是否为空
int ListEmpty(LIST &L);

//求出线性表长度
int ListLength(LIST &L);

//向线性表指定位置插入一个新元素
int ListInsert(LIST &L, int pos, DataType item);

//遍历输出线性表
int TraverseList(LIST &L);

//获取顺序表中指定位置上的数据元素
int GetElem(LIST &L,int pos,DataType *item);

//从线性表中查找元素，返回第一个与指定值匹配元素位置
int Find(LIST &L,DataType item);

//从线性表中删除第一个与指定值匹配的元素
int ListDelete(LIST &L, int pos, DataType *item);

void InsertSort(LIST &L);

void SelectSort(LIST &L);

#endif /* listinarray_hpp */
