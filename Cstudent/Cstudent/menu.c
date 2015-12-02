//
//  menu.c
//  Cstudent
//
//  Created by 刘阳 on 15/11/27.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#include "menu.h"

AdminList cacheAdminList;


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


//管理员登陆，登录函数应该是menu方法中唯一（还有学生登陆）返回指针的，返回的指针作为缓存
AdminList loginTypeAdmin(){
    //确认用户输入
    printf("请输入用户名:\n");
    char inputName[20];//不能用[]={}声明
    fscanf(stdin, "%s",inputName);
    fflush(stdin);
    
    printf("请输入密码:\n");
    char inputPass[20];
    fscanf(stdin, "%s",inputPass);
    fflush(stdin);
    
//    printf("%s,%s\n",inputName,inputPass);
    
    //缓存admin数据
    struct Admin* L = createEmptyAdminList();
    readAdminFile(L);
    cacheAdminList=L;//缓存
    
    AdminList currentPtr=getByUserName(L, inputName);//判断登录名是否存在
    if (currentPtr) {
        if (strcmp(inputPass, currentPtr->password)==0) {//判断密码是否正确
            printf("管理员登录成功\n");
            return currentPtr;
        }else{
            printf("密码错误\n");
        }
    }else{
        printf("用户不存在\n");
    }
    //返回输入结果
    return NULL;
}


//admin主选项
int menuAdminMain(){
    //确认用户输入
    int a=1,b=2;
    printf("选择功能:\n%d,密码修改\n%d,学生管理\n",a,b);
    int key;
    scanf("%d",&key);
    if (a!=key&&b!=key) {
        wrongInput(loginTypeSelect);
    }
    //返回输入结果
    return key;
}


//admin修改密码
void menuAdminPassword(AdminList currentPtr){
    //确认用户输入
    printf("请输入旧密码:\n");
    char inputOld[20];
    fscanf(stdin, "%s",inputOld);
    fflush(stdin);
    
    printf("请输入新密码:\n");
    char inputNew[20];
    fscanf(stdin, "%s",inputNew);
    fflush(stdin);
    printf("%s,%s\n",inputOld,currentPtr->password);
    if (strcmp(inputOld, currentPtr->password)==0) {
        strcpy(currentPtr->password, inputNew);
//        currentPtr->password=inputNew;
        printf("new=%s\n",currentPtr->password);
        writeAdminFile(cacheAdminList);
        printf("修改成功\n");
    }else{
        printf("密码错误\n");
    }
}




//学生登陆
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

