//
//  ExManage.hpp
//  ex10【17.6 考试报名管理】
//
//  Created by Acaleph ❦ on 2017/12/18.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#ifndef ExManage_hpp
#define ExManage_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct examinee{
    char examno[10];//准考证号
    char name[10];//姓名
    char sex;
    float age;
    char examtype[5];//成绩
}ElemType;

typedef struct ExNode{
    ElemType examer;
    ExNode *next;
}ExNode;

ExNode* Init();//初始化

void EnterEx(ExNode *p);//输入考生信息

void ShowEx(ExNode *h);//输出考生信息

void SearchEx(ExNode *h);//查询考生信息

void AddEx(ExNode *ptail);//添加考生

int CompareChar(char a[], char b[]);

void ChangeEx(ExNode *h);//修改考生信息

void DeleteEx(ExNode *h);//删除考生信息

#endif /* ExManage_hpp */
