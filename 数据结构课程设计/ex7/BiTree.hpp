//
//  BiTree.hpp
//  ex7
//
//  Created by Acaleph ❦ on 2017/11/27.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#ifndef BiTree_hpp
#define BiTree_hpp

#include <iostream>
using namespace std;

typedef char DataType;

typedef struct Node{
    DataType    data;    //数据域
    struct Node        *left,*right; //结点的左右子树指针
}BTNode;//二叉树结点类型

//初始化空二叉树
void TreeInit(BTNode* &root);

//按照前序遍历序列建立二叉树
void CreateBTree_Pre(BTNode  *&root, DataType Array[]);

//前序遍历二叉树
void PreOrder(BTNode *root);

//计算二叉树深度
int BTreeDepth(BTNode *root);

//释放二叉树中所有结点
void ClearBTree(BTNode* &root);

//中序遍历
void InOrder (BTNode * root);

//后序遍历
void PostOrder (BTNode * root);

#endif /* BiTree_hpp */
