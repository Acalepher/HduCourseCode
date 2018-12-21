//
//  BiTree.cpp
//  ex7
//
//  Created by Acaleph ❦ on 2017/11/27.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include "BiTree.hpp"

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
        CreateBTree_Pre (root->left,Array);    //建左子树
        CreateBTree_Pre (root->right,Array); //建右子树
    }
}

//前序遍历二叉树
void PreOrder(BTNode *root)
{
    if(root!=NULL){
        cout<<root->data;  //访问根
        PreOrder( root->left );     //前序遍历左子树
        PreOrder( root->right );     //前序遍历右子树
    }
}

//计算二叉树深度
int BTreeDepth(BTNode *root)
{
    if(root==NULL)        return 0;
    else{
        int depl=BTreeDepth( root->left );
        int depr=BTreeDepth( root->right );
        if(depl>depr)       return depl+1;
        else            return depr+1;
    }
}

//释放二叉树中所有结点
void ClearBTree(BTNode* &root)
{
    if(root!=NULL)
    {
        ClearBTree( root->left );
        ClearBTree( root->right );
        delete root;
        root=NULL;
    }
}

//中序遍历
void InOrder (BTNode * root){
    if(root!=NULL){
        InOrder( root->left );
        cout<<root->data;
        InOrder( root->right );
    }
}

//后序遍历
void PostOrder (BTNode * root){
    if(root!=NULL){
        PostOrder( root->left );
        PostOrder( root->right );
        cout<<root->data;
    }
}
