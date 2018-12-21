//
//  main.cpp
//  class-1
//
//  Copid by Aca on 2017/10/16.
//  Copyright © 2017年 Cyris. All rights reserved.
//

#include <iostream>
#include "listInArray.h"
using namespace std;

int main(void){
    
    LIST my_List1, my_list2, Lc;
    DataType Array[] = {3, 5, 7, 10, 12};
    //DataType Array[] = "student";
    // 初始化线性表
    InitList(my_List1);
    InitList(my_list2);
    InitList(Lc);
    // 向线性表中指定位置插入数据
    ListInsert(my_List1, 1, 2);
    ListInsert(my_List1, 2, 4);
    ListInsert(my_List1, 3, 7);
    ListInsert(my_List1, 4, 9);
    for (int i=1; i<6; i++){
        ListInsert(my_list2, i, Array[i-1]);
    }
    //第（4）题
    cout << "线性表my_list1中有数据: "<<endl;
    TraverseList(my_List1);
    cout << "线性表my_list2中有数据: "<<endl;
    TraverseList(my_list2);
    MergeList_Sq(my_List1, my_list2, Lc);
    cout<<"合并后的线性表Lc中有数据："<<endl;
    TraverseList(Lc);
    return 0;
    /*//第六题
    for(int i=1;i<11;i++){
        ListInsert(my_list2, i, i);
        ListInsert(my_list2, i, i);
    }*/
    // 输出线性表元素
    /*cout << "线性表my_list1中有数据: "<<endl;
    TraverseList(my_List1);
    cout << "线性表my_list2中有数据: "<<endl;
    TraverseList(my_list2);
    MergeList(my_List1, my_list2);
    cout<<"合并后的线性表my_list1中有数据："<<endl;
    TraverseList(my_List1);
    return 0;//原main函数*/
    
    /*//新main函数
    LIST my_List;
    DataType item1='b',item2;
    DataType *item=&item2;
    
    InitList(my_List);
    ListInsert(my_List, 1, 'a');
    ListInsert(my_List, 2, 'b');
    ListInsert(my_List, 3, 'c');
    ListInsert(my_List, 4, 'd');
    ListInsert(my_List, 5, 'e');
    cout<<"列表长度："<<ListLength(my_List)<<endl;
    TraverseList(my_List);
    cout<<"列表为空？（1=yes，0=no）："<<ListEmpty(my_List)<<endl;
    ListInsert(my_List, 4, 'f');
    TraverseList(my_List);
    
    ListDelete(my_List, 3, item);
    TraverseList(my_List);
    cout<<"第二个元素："<<GetElem(my_List, 2, item)<<endl;
    
    cout<<"元素b的位置："<<Find(my_List, item1)<<endl;
    
    return 0;*/
}
