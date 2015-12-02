//
//  main.c
//  Cstudent
//
//  Created by 刘阳 on 15/11/27.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "modeAdmin.h"
#include "modeStudent.h"
#include "fileAdmin.h"
#include "fileStudent.h"


void systemStart();
void systemTest();
void printAdminInfo();
void printStudentInfo();
void addTestAdmin();
void addTestStudent();


int main(int argc, const char * argv[]) {
    
    if (/* DISABLES CODE */ (1)) {
        
        addTestAdmin();
        addTestStudent();
        systemStart();
    }else{
        systemTest();
    }
    
    
    
    return 0;
}


//程序启动
void systemStart(){
    int selection=loginTypeSelect();
    //    printf("%d\n",selection);
    if (1==selection) {//管理员登录
        AdminList currentPtr=loginTypeAdmin();
        if (currentPtr) {//登录成功
            selection=menuAdminMain();
            if (1==selection) {//修改密码
                menuAdminPassword(currentPtr);
            }else{//学生管理
                selection=menuAdminManagement();
                switch (selection) {
                    case 1://学生浏览
                        
                        break;
                    case 2://添加
                        break;
                    case 3://删除
                        break;
                    case 4://修改
                        break;
                }
            }
        }else{//登录失败
            
        }
    }else{//学生登陆
        loginTypeStudent();
    }
    
    
    
}


//测试数据区域－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
void systemTest(){
    
    //缓存测试数据//要不先不做缓存了吧😄
    //直接做查询
    //    if (getByUserName(head2, "admin2")) {
    //        printf("找到了\n");
    //    }else{
    //        printf("没找到\n");
    //    }
    //不行，好像还是需要缓存的😭，至少要缓存当前用户的登录名吧
    
}


//添加admin测试数据
void addTestAdmin(){
    //建立测试数据
    //    char str1[]={'a','d','m','i','n','1','\0'};
    //    char str2[]={'p','a','s','s','1','\0'};
    struct Admin* head = createEmptyAdminList();
    insertAdminAt(head, "admin1","pass1");
    insertAdminAt(head, "admin2", "pass2");
    
    //写入测试数据
    writeAdminFile(head);
    
    //读取测试数据
    struct Admin* head2 = createEmptyAdminList();
    readAdminFile(head2);
}


//添加student测试数据
void addTestStudent(){
    //建立测试数据，添加10条测试数据
    struct Student* head = createEmptyStudentList();
    insertStudentAt(head,"C0101","pass1","Tom","C01",21,65,80,100);
    insertStudentAt(head,"C0105","pass1","John","C01",19,60,81,90);
    insertStudentAt(head,"C0120","pass1","Jimy","C01",21,75,60,98);
    insertStudentAt(head,"C0122","pass1","Frank","C01",17,90,80,100);
    insertStudentAt(head,"C0201","pass2","Larry","C02",20,65,80,100);
    insertStudentAt(head,"C0205","pass2","Kenney","C02",15,65,80,100);
    insertStudentAt(head,"C0209","pass2","Brown","C02",21,65,80,100);
    insertStudentAt(head,"C0214","pass2","Lily","C02",21,65,80,100);
    insertStudentAt(head,"C0301","pass3","Lucy","C03",21,65,80,100);
    insertStudentAt(head,"C0302","pass3","Emma","C03",21,65,80,100);

    //写入测试数据
    
    //读取测试数据
    
}

//读取admin数据，用于检验
void printAdminInfo(){
    struct Admin* head = createEmptyAdminList();
    readAdminFile(head);
}

//同上
void printStudentInfo(){
    //TODO
}