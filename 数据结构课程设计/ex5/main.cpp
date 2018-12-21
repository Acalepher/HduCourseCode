//
//  main.cpp
//  ex6
//
//  Created by Acaleph ❦ on 2017/11/13.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include <iostream>
using namespace std;

void hanoi(int n, char x, char y, char z){
    if(n==1)
        cout<<x<<"->"<<z<<endl;
    else{
        hanoi(n-1,x,z,y);
        cout<<x<<"->"<<z<<endl;
        hanoi(n-1,y,x,z);
    }
}

int main()
{
    hanoi(3,'A','B','C');
    return 0;
}


/*// 本函数利用递归算法求n的阶乘
int counter=0;

int fac(int n)
{    // 断点
    counter++;
    cout<<"第"<<counter<<"次调用：n="<<n<<endl;
    
    if (n==1)
        return 1;
    else
    {
        return n * fac(n-1);
    }
}

int fac2(int n){
    int fac=1;
    while(n>0){
        fac*=n;
        n--;
    }
    return fac;
}

double Avg(int A[], int n){
    if(n>1)
        return (Avg(A, n-1)*(n-1)+A[n-1])/n;
    else
        return A[0];
}

int main()
{
    //cout<<"结果：fac(5)="<<fac2(5)<<endl;
    int A[5]={2,3,4,5,6};
    cout<<"Avg of A[] = "<<Avg(A,5)<<endl;
    
    return 0;
}*/
