//
//  listinarray.cpp
//  ex9
//
//  Created by Acaleph ❦ on 2017/12/11.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include "listinarray.hpp"

//初始化空线性表
void InitList(LIST &L)
{
    L.length=0;
}

//判断线性表是否为空
int ListEmpty(LIST &L)
{
    if(L.length<=0)    return 1;
    else    return 0;
}

//求出线性表长度
int ListLength(LIST &L)
{
    return L.length;
}

//向线性表指定位置插入一个新元素
int ListInsert(LIST &L, int pos, DataType item)
{//pos为插入的（逻辑）位置,item为待插入的数据元素
    int i;
    if(L.length>=LISTSIZE){                  //判表满
        cout<<"顺序表满，无法插入！"<<endl;
        return 0;}
    if(pos<=0 || pos>L.length+1){           //判位置
        cout<<"插入位置无效！"<<endl;
        return 0;}
    for(i=L.length-1;  i>=pos-1;  i--)     //向后移动元素
        L.items[i+1]=L.items[i];
    L.items[pos-1]=item;                    //插入
    L.length++;                        //表长增一
    return 1;
}

//遍历输出线性表
int TraverseList(LIST &L)
{
    int i;
    for(i=0;i<L.length;i++)
        cout<<L.items[i]<<"  ";
    cout<<endl;
    return 1;
}

//获取顺序表中指定位置上的数据元素
int GetElem(LIST &L,int pos,DataType *item)
{//pos为指定位置,item用于返回找到的数据元素if(ListEmpty(L))    return 0;
    if(pos<=0 || pos>L.length){
        cout<<"位置无效"<<endl;
        return 0;}
    *item=L.items[pos-1];
    return 1;
}


//从线性表中查找元素，返回第一个与指定值匹配元素位置
int Find(LIST &L,DataType item)
{//item为待查找的数据元素
    int pos=0;
    if(ListEmpty(L)){
        cout<<"顺序表为空表，无法查找！"<<endl;
        return 0;
    }
    while(pos<L.length && L.items[pos]!=item) pos++;
    if(pos<L.length)    return pos+1;
    else                return 0;
}

//从线性表中删除第一个与指定值匹配的元素
int ListDelete(LIST &L, int pos, DataType *item)
{//pos为删除的（逻辑）位置,用item返回被删元素
    int i;
    if(ListEmpty(L)){                     //判表空
        cout<<"顺序表为空表，无法删除！"<<endl;
        return 0; }
    if(pos<1 || pos>L.length){       //判位置
        cout<<"删除位置无效！"<<endl;
        return 0; }
    *item=L.items[pos-1];
    for(i=pos;i<L.length;i++)      //向前移动元素
        L.items[i-1]=L.items[i];
    L.length--;                   //表长减一
    return 1;
}

void InsertSort(LIST &L){
    int i,j;
    int tmp;
    for(i = 1;i < L.length; i++)
    {
        tmp = L.items[i];//取出无序表的第一个元素插入到有序表
        for(j=i-1; j >= 0; j--)//有序表排序 断点①
        {
            if(tmp<L.items[j])
                L.items[j+1] = L.items[j];//位置j的元素向后移动
            else
                break;
        }
        L.items[j+1] = tmp;
        TraverseList(L);
    }
}

void SelectSort(LIST &L){
    int i,j,min;
    int tmp;
    for(i=0; i<L.length-1; i++)
    {
        min=i; //默认无序表的第一个元素Array[i]为最小值
        for(j=i+1; j<L.length; j++) //查找最小值下标 断点③
            if(L.items[j] < L.items[min])
                min = j;
        if(min != i) //找到了比i位置更小的元素且min与i的值不同
        {
            tmp = L.items[i];
            L.items[i] = L.items[min];
            L.items[min] = tmp;
        }
        TraverseList(L);
    }
}

