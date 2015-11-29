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

void systemTest(){
    
    int size=getStructAdminSize();
    printf("Admin结构大小:%d\n",size);
    
}