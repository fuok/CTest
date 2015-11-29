//
//  menu.c
//  Cstudent
//
//  Created by 刘阳 on 15/11/27.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#include <stdlib.h>
#include "menu.h"



//选择登陆方式
int loginTypeSelect(){
    //确认用户输入
    int a=1,b=2;
    printf("选择登陆类型:\n%d,管理员\n%d,学生\n",a,b);
    int key;
    scanf("%d",&key);
    if (a!=key&&b!=key) {
        wrongInput(loginTypeSelect);
    }
    
    //返回输入结果
    return key;
}


//






















void wrongInput(int (*funcPtr)()){
    printf("输入错误请重新输入:\n");
    (*funcPtr)();
}

void systemExit(){
    exit(0);
}

