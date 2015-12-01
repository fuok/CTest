//
//  menu.c
//  Cstudent
//
//  Created by 刘阳 on 15/11/27.
//  Copyright © 2015年 刘阳. All rights reserved.
//

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
int loginTypeAdmin(){
    
    //确认用户输入
    printf("请输入用户名:\n");
    char inputName[20];//不能用[]={}声明
    fscanf(stdin, "%s",inputName);
    fflush(stdin);
    
    printf("请输入密码:\n");
    char inputPass[20];
    fscanf(stdin, "%s",inputPass);
    fflush(stdin);
    
    printf("%s,%s\n",inputName,inputPass);
    
    struct Admin* L = createEmptyAdminList();
    readAdminFile(L);
    
    if (getByUserName(L, inputName)) {
        printf("找到了\n");
    }else{
        printf("没找到\n");
    }
    
    
    
    //返回输入结果
    return 0;
}


int loginTypeStudent(){
    return 0;
}


















void wrongInput(int (*funcPtr)()){
    printf("输入错误请重新输入:\n");
    (*funcPtr)();
}

void systemExit(){
    exit(0);
}

