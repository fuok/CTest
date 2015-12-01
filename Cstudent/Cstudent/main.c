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
#include "fileAdmin.h"


void systemStart();
void systemTest();

int main(int argc, const char * argv[]) {
  
    
    
    if (/* DISABLES CODE */ (1)) {
        systemStart();
    }else{
        systemTest();
    }
   
    
    
    return 0;
}


//程序启动
void systemStart(){
    int selection=loginTypeSelect();
    printf("%d\n",selection);
    if (1==selection) {
        loginTypeAdmin();
    }else{
        loginTypeStudent();
    }
    
    
    
}


//测试数据
void systemTest(){
    
    //建立测试数据
    char str1[]={'a','d','m','i','n','1','\0'};
    char str2[]={'p','a','s','s','1','\0'};
    struct Admin* head = createEmptyAdminList();
    insertAdminAt(head, "admin1","pass1");
    insertAdminAt(head, "admin2", "pass2");
//    getLastAdminNode(head);//正确
    
    //写入测试数据
    writeAdminFile(head);
    
    //读取测试数据
    struct Admin* head2 = createEmptyAdminList();
    readAdminFile(head2);
//    getLastAdminNode(head2);//正确
    
    //缓存测试数据//要不先不做缓存了吧😄
    //直接做查询
    if (getByUserName(head2, "admin2")) {
        printf("找到了\n");
    }else{
        printf("没找到\n");
    }
    
    //不行，好像还是需要缓存的😭，至少要缓存当前用户的登录名吧
    
}