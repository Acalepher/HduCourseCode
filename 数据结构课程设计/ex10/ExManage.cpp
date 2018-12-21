//
//  ExManage.cpp
//  ex10【17.6 考试报名管理】
//
//  Created by Acaleph ❦ on 2017/12/18.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include <iostream>
#include "ExManage.hpp"

/*char newno[10], newnm[10], newtp[5];
  char newsx;
  float newag;
  char examno[10];//准考证号
  char name[10];//姓名
  char sex;
  float age;
  char examtype[5];//成绩*/
ExNode* Init(){
    ExNode *head = new ExNode;
    head->next = NULL;
    
    return head;
}
//初始化

void EnterEx(ExNode *p){
    AddEx(p);
    
    int end;
    cout<<"Add Examer Finished? Enter 1 if yes, 0 if no.";
    cin>>end;
    cout<<endl;
    
    while(!end){
        AddEx(p);
        cout<<"Add Examer Finished? Enter 1 if yes, 0 if no.";
        cin>>end;
        cout<<endl;
     }
    cout<<"EnterEx() Finished!"<<endl;
}
//输入考生信息

void ShowEx(ExNode *h){
    ExNode *p = h;
    p = p->next;
    while(p){
        cout<<"Exam Number: "<< p->examer.examno << endl;

        cout<<"Stu Name: "<< p->examer.name << endl;

        cout<<"Stu Sex (F or M): "<< p->examer.sex <<endl;

        cout<<"Stu Age: "<< p->examer.age <<endl;

        cout<<"Stu Exam Type: "<< p->examer.examtype <<endl;

        cout<<endl;
        p = p->next;
    }
}
//输出考生信息



void SearchEx(ExNode *h){
    h=h->next;
    char Snm[10];
    int flag=0;
    cout<<"Enter the Exam Number you want to search: ";
    cin>>Snm;
    cout<<endl;
    while(h){
if(CompareChar(h->examer.examno,Snm)){
    flag = 1;
    cout<<"Exam Number: "<< h->examer.examno << endl;
    cout<<"Stu Name: "<< h->examer.name << endl;
    cout<<"Stu Sex (F or M): "<< h->examer.sex <<endl;
    cout<<"Stu Age: "<< h->examer.age <<endl;
    cout<<"Stu Exam Type: "<< h->examer.examtype <<endl;
}
    h = h->next;
    }
    if(!flag)
        cout<<"Search Failed."<<endl;
}
//查询考生信息

void AddEx(ExNode *h){
    ExNode *p = new ExNode;
    while (h->next) {
        h = h->next;
    }
    h->next = p;
    
    cout<<"Enter Exam Number: ";
    cin>>p->examer.examno;
    cout<<endl;
    cout<<"Enter Stu Name: ";
    cin>>p->examer.name;
    cout<<endl;
    cout<<"Enter Stu Sex (F or M): ";
    cin>>p->examer.sex;
    cout<<endl;
    cout<<"Enter Stu Age: ";
    cin>>p->examer.age;
    cout<<endl;
    cout<<"Enter Stu Exam Type: ";
    cin>>p->examer.examtype;
    cout<<endl;
    p->next = NULL;
}
//添加考生

int CompareChar(char a[], char b[]){
    for(int i=0;b[i]&&i<=10;i++)
        if(a[i]!=b[i])
            return 0;
    return 1;
}


void ChangeEx(ExNode *h){
    int flag=0, choi;
    char Snm[10];
    cout<<"Enter the Exam Number you want to change: ";
    cin>>Snm;
    cout<<endl;
    h=h->next;
    while(h){
        if(CompareChar(h->examer.examno,Snm)){
            flag = 1;
            cout<<"Change exam num(1),stu name(2),stu sex(3),stu age(4),stu exam type(5). Please input a number to choose a item to change:";
            cin>>choi;
            switch (choi) {
                case 1:{
                    cin>>h->examer.examno;
                    break;
                }
                case 2:{
                    cin>>h->examer.name;
                    break;
                }
                case 3:{
                    cin>>h->examer.sex;
                    break;
                }
                case 4:{
                    cin>>h->examer.age;
                    break;
                }
                case 5:{
                    cin>>h->examer.examtype;
                    break;
                }
                default:
                    break;
            }
        }
        h = h->next;
    }
    if(!flag)
        cout<<"Not Found."<<endl;
}
//修改考生信息

void DeleteEx(ExNode *h){
    ExNode *p = h;
    int flag=0;
    char Snm[10];
    cout<<"Enter the Exam Number you want to delete: ";
    cin>>Snm;
    cout<<endl;
    while(h && h->next){
        if(CompareChar(h->next->examer.examno,Snm)){
            flag = 1;
            p=h->next;
            h->next = p->next;
            free(p);
            cout<<"Delete Succeed!"<<endl;
        }
        h = h->next;
    }
    if(!flag)
        cout<<"Not Found."<<endl;
}
//删除考生信息
