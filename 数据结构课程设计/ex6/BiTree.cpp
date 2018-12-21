//
//  BiTree.cpp
//  ex6
//
//  Created by Acaleph ❦ on 2017/11/20.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include <stdio.h>
#include "BiTree.h"
#include <iostream>
using namespace std;

//初始化空二叉树
void TreeInit(BTNode* &root)
{
    root=NULL;
}

//按照前序遍历序列建立二叉树
void CreateBTree_Pre(BTNode  *&root, DataType Array[])
{
    static int count=0;    //静态变量count
    char item=Array[count];//读取Array[]数组中的第count个元素
    count++;
    if(item == '#') //如果读入#字符，创建空树
    { root = NULL; return ;}
    else
    {
        root = new BTNode;
        root->data = item;
        CreateBTree_Pre (root->lchild,Array);    //建左子树
        CreateBTree_Pre (root->rchild,Array); //建右子树
    }
}

//释放二叉树中所有结点
void ClearBTree(BTNode* &root)
{
    if(root!=NULL)
    {
        ClearBTree( root->lchild );
        ClearBTree( root->rchild );
        delete root;
        root=NULL;
    }
}

//计算叶子结点个数
int LeafCount(BTNode *root){
    static int LFNum = 0;
    if(!root)
        return 0;
    if((!root->lchild)&&(!root->rchild))
        LFNum++;
    LeafCount(root->lchild);
    LeafCount(root->rchild);
    return LFNum;
}

//计算二叉树双分支结点个数
int TwoDegreeCount(BTNode *root){
    static int TDNum = 0;
    if(!root)
        return 0;
    if(root->lchild&&root->rchild)
        TDNum++;
    TwoDegreeCount(root->lchild);
    TwoDegreeCount(root->rchild);
    return TDNum;
}





