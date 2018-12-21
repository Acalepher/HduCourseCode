//
//  BiTree.h
//  ex6
//
//  Created by Acaleph ❦ on 2017/11/20.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#ifndef BiTree_h
#define BiTree_h

#include <stdio.h>
#include <iostream>
using namespace std;

typedef char DataType;

typedef struct Node{
    DataType    data;    //数据域
    struct Node *lchild;
    struct Node *rchild; //结点的左右子树指针
}BTNode;//二叉树结点类型

//初始化空二叉树
void TreeInit(BTNode* &root);

//按照前序遍历序列建立二叉树
void CreateBTree_Pre(BTNode  *&root, DataType Array[]);

//释放二叉树中所有结点
void ClearBTree(BTNode* &root);

//计算叶子结点个数
int LeafCount(BTNode * root);

//计算二叉树双分支结点个数
int TwoDegreeCount(BTNode *root);

#endif /* BiTree_h */
