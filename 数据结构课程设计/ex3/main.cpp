//
//  main.cpp
//  ex4
//
//  Created by Acaleph ❦ on 2017/10/30.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include <iostream>
#include "SqStack.hpp"
#include "SNode.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    SqStack my_stack1;
    SNode *my_stack2;
    DataType PopA;
    Push(my_stack1, 11);
    Push(my_stack1, 12);
    Push(my_stack1, 13);
    Push(my_stack1, 14);
    Push(my_stack1, 15);
    Push(my_stack1, 16);
    Push(my_stack1, 17);
    Push(my_stack1, 18);
    Push(my_stack1, 19);
    Push(my_stack1, 20);
    Pop(my_stack1, PopA);
    Pop(my_stack1, PopA);
    Pop(my_stack1, PopA);
    Pop(my_stack1, PopA);
    Pop(my_stack1, PopA);
    Pop(my_stack1, PopA);
    Pop(my_stack1, PopA);
    Pop(my_stack1, PopA);
    Pop(my_stack1, PopA);
    Pop(my_stack1, PopA);
    Push(my_stack2, 23333);
    Push(my_stack2, 12);
    Push(my_stack2, 13);
    Push(my_stack2, 14);
    Push(my_stack2, 15);
    Push(my_stack2, 16);
    Push(my_stack2, 17);
    Push(my_stack2, 18);
    Push(my_stack2, 19);
    Push(my_stack2, 20);
    Pop(my_stack2, PopA);
    Pop(my_stack2, PopA);
    Pop(my_stack2, PopA);
    Pop(my_stack2, PopA);
    Pop(my_stack2, PopA);
    Pop(my_stack2, PopA);
    Pop(my_stack2, PopA);
    Pop(my_stack2, PopA);
    Pop(my_stack2, PopA);
    Pop(my_stack2, PopA);
    return 0;
}
