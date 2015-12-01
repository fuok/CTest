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
  
    
    
    systemTest();
    
//    systemStart();
   
    
    
    return 0;
}


//程序启动
void systemStart(){
    int selection;
    selection=loginTypeSelect();
    
    
    
    
}


//测试数据
void systemTest(){
    
    //建立测试数据
    struct Admin* head = createEmptyAdminList();
    insertAdminAt(head, "admin1", "pass1");
    insertAdminAt(head, "admin2", "pass2");
//    getLastAdminNode(head);//正确
    
    //写入测试数据
    writeAdminFile(head);
    
    //读取测试数据
    struct Admin* head2 = createEmptyAdminList();
    readAdminFile(head2);
    getLastAdminNode(head2);
    
    //缓存测试数据//要不先不做缓存了吧😄
}