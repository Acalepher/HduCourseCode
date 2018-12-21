//
//  main.cpp
//  ex3
//
//  Created by Acaleph ❦ on 2017/10/23.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include <iostream>
#include "chainlist.h"

int main(int argc, const char * argv[]) {
    /*Node * head;
    DataType  item3;
    DataType charToBeDeleted;
    
    InitList(head);
    
    ListInsert(head, 1, 'a');
    ListInsert(head, 1, 'b');
    ListInsert(head, 1, 'c');
    ListInsert(head, 1, 'd');
    
    if(head){
        cout<<"当前链表长是"<<ListLength(head)<<",表中元素为：";
        TraverseList(head);
    }
    
    Find_pos(head, 3, &item3);
    cout<<"第三个元素是"<<item3<<endl;
    
    cout<<"a在"<<Find_item(head, 'a')<<"号位置"<<endl;
    
    ListInsert(head, 3, 'f');
    cout<<"在三号位插入f后，表中元素为：";
    TraverseList(head);
    
    cout<<"输入你想删除的元素：";
    cin>>charToBeDeleted;
    if(ListDelete (head, charToBeDeleted)){
        cout<<"删除"<<charToBeDeleted<<"成功。表中元素为：";
        TraverseList(head);
    }
    else
        cout<<"删除失败!"<<endl;
    
    
    //ListInsert_order(head,'c');
    //TraverseList(head);
    
    DestroyList (head);
    
    return 0;*/
    
    Node * head;
    InitList(head);
    DataType A[]={{101,85},{103,90.5},{104,73},{105,55}};
    
    for(int i=0;i<4;i++)
        ListInsert(head, i+1, A[i]);
        
    cout<<"学号 成绩"<<endl;
    TraverseList(head);
    
    ListDelete(head, 103);
    
    cout<<"学号 成绩"<<endl;
    TraverseList(head);
    
    DestroyList(head);
    
    return 1;
    
    
    
    
}
