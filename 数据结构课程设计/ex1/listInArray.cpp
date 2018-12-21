//
//  listInArray.cpp
//  class-1
//
//  Created by Cyris on 2017/10/16.
//  Copyright © 2017年 Cyris. All rights reserved.
//

#include "listInArray.h"
#include <iostream>
using namespace std;

// 初始化空线性表
void InitList(LIST &L){
    L.length=0;
}

// 判断线性表是否空
int ListEmpty(LIST &L){
    if (L.length<0)
        return 1;
    else
        return 0;
}

// 求出线性表长度
int ListLength(LIST &L){
    return L.length;
}

// 向线性表指定位置插入一个新元素
int ListInsert(LIST &L, int pos, DataType item){
    // pos为插入的（逻辑）位置，item为待插入的数据元素
    int i=0;
    if (L.length >= LISTSIZE){                 // 判表满
        cout << "顺序表满，无法插入！" << endl;
        return 0;
    }
    if (pos<=0 || pos>L.length+1){             // 判位置
        cout << "插入位置无效！" << endl;
        return 0;
    }
    for (i=L.length-1; i>=pos-1; i--)          // 向后移动元素
        L.items[i+1]=L.items[i];
    L.items[pos-1]=item;
    L.length++;
    return 1;
}

// 从线性表中删除第一个与指定值匹配的元素
int ListDelete(LIST &L, int pos, DataType * item){
    // pos为删除的（逻辑）位置，用item返回被删元素
    int i = 0;
    if (ListEmpty(L)){
        cout << "顺序表为空表，无法删除！" << endl;
        return 0;
    }
    if (pos<1 || pos>L.length){
        cout << "删除位置无效！" << endl;
        return 0;
    }
    *item = L.items[pos-1];                 // 删除元素前，把元素的值通过指针传递给外部，备用
    for (i=pos; i<L.length; i++)            // 向前移动元素
        L.items[i-1]=L.items[i];
    L.length--;                             // 表长减1
    return 1;
    
}

// 获取顺序表中指定位置上的数据元素
int  GetElem(LIST &L, int pos, DataType * item){
    if (ListEmpty(L)) return 0;
    if (pos<=0 || pos>L.length){
        cout << "位置无效" << endl;
        return 0;
    }
    * item=L.items[pos-1];              // 把元素的值通过指针传递给外部
    return 1;
}

// 从线性表中查找元素，返回第一个与指定值匹配元素位置
int Find(LIST &L, DataType item){
    // item 为待查找的数据元素
    int i = 0;          // i表示当前查找的位置，从头开始
    if (ListEmpty(L)){
        cout << "顺序表为空表，无法查找！" << endl;
        return 0;
    }
    // 从头到尾比较线性表中的元素，当未超出线性表的末尾且未找到时，i向后移
    while (i<L.length && L.items[i]!=item)
        i++;
    if (i<L.length)                    // 如果未超出线性表末尾，说明找到
        return i+1;                    // 返回逻辑位置
    else
        return 0;                      // 超出线性表的末尾，则说明找不到
    
}

// 遍历输出线性表
int TraverseList(LIST &L){
    int i = 0;
    for (i=0; i<L.length; i++)
        cout << L.items[i] << "  ";
    cout << endl;
    return 1;
}
    
//合并两个线性表
int MergeList(LIST&L1, LIST&L2){
    int i;
    for(i=1; i<=L2.length; i++)
        ListInsert(L1, L1.length+1, L2.items[i-1]);
    if(L1.items[L1.length+L2.length-1]==L2.items[L2.length-1])
        return 1;
    else
        return 0;
}

//合并非递减列表为lc
void MergeList_Sq(LIST La, LIST Lb, LIST&Lc){
    int i=0,j=0,n=1;
    while(La.items[i]&&Lb.items[j]){
        if(La.items[i]>=Lb.items[j]){
            ListInsert(Lc, n, Lb.items[j]);
            j++;n++;
        }
        else{
            ListInsert(Lc, n, La.items[i]);
            i++;n++;
        }
    }
    while(La.items[i]){
        for(;i<La.length;i++,n++)
            ListInsert(Lc, n, La.items[i]);
    }
    while(Lb.items[j]){
        for(;j<Lb.length;j++,n++)
            ListInsert(Lc, n, Lb.items[j]);
    }
}
