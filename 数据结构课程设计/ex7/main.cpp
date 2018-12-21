//
//  main.cpp
//  ex7
//
//  Created by Acaleph ❦ on 2017/11/27.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include <iostream>
#include "BiTree.hpp"

int main()
{
    BTNode *root;
    DataType A[]="ABD#G###CEH###FI##J##";//以"#"补充空分支后的某个遍历序列
    
    TreeInit(root);//初始化空二叉树
    CreateBTree_Pre(root,A);//以前序遍历序列建立二叉树
    
    cout<<"前序遍历序列：";
    PreOrder(root);//输出前序遍历序列
    cout<<endl;
    
     cout<<"中序遍历序列：";
     InOrder(root);//输出中序遍历序列
     cout<<endl;
     cout<<"后序遍历序列：";
     PostOrder(root);//输出后序遍历序列
     cout<<endl;
    
    cout<<"深度："<<BTreeDepth(root)<<endl;//计算二叉树深度
    return 0;
}
