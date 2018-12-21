//
//  main.cpp
//  ex10【17.6 考试报名管理】
//
//  Created by Acaleph ❦ on 2017/12/18.
//  Copyright © 2017年 Acaleph ❦. All rights reserved.
//

#include <iostream>
#include "ExManage.hpp"

int main(int argc, const char * argv[]) {

    ExNode * Ehead = Init();
    int choice;
    cout<<"*******MENU*******"<<endl;
    cout<<"0.退出"<<endl;
    cout<<"1.输入数据"<<endl;
    cout<<"2.输出数据"<<endl;
    cout<<"3.添加数据"<<endl;
    cout<<"4.依据准考证号查找数据"<<endl;
    cout<<"5.删除数据"<<endl;
    cout<<"6.修改数据"<<endl;
    cout<<"******************"<<endl;
    cin>>choice;
    while(choice != 0)
    {
        switch (choice) {
            case 1: EnterEx(Ehead);break;
            case 2: ShowEx(Ehead);break;
            case 3: AddEx(Ehead);break;
            case 4: SearchEx(Ehead);break;
            case 5: DeleteEx(Ehead);break;
            case 6: ChangeEx(Ehead);break;
            
            default:
                break;
        }
        cout<<"*******MENU*******"<<endl;
        cout<<"0.退出"<<endl;
        cout<<"1.输入数据"<<endl;
        cout<<"2.输出数据"<<endl;
        cout<<"3.添加数据"<<endl;
        cout<<"4.依据准考证号查找数据"<<endl;
        cout<<"5.删除数据"<<endl;
        cout<<"6.修改数据"<<endl;
        cout<<"******************"<<endl;
        cin>>choice;
    }

    return 0;
}
