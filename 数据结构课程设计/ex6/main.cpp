//
//  main.cpp
//  ex6
//
//  Created by Acaleph ❦ on 2017/11/20.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include <iostream>
#include "BiTree.h"
using namespace std;

int main()
{
    BTNode *root;
    DataType A[]="ABD#G###CEH###FI##J##";//以"#"补充空分支后的某个遍历序列
    
    TreeInit(root);//初始化空二叉树
    CreateBTree_Pre(root,A);//以前序遍历序列建立二叉树
    
    cout<<"叶子结点个数："<<LeafCount(root)<<endl;
    cout<<"双分支结点个数："<<TwoDegreeCount(root)<<endl;
    ClearBTree(root);  //取消注释以验证二叉树结点的释放
    return 0;
}
