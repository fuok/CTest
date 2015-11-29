//
//  modeAdmin.c
//  Cstudent
//
//  Created by 刘阳 on 15/11/27.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#include "modeAdmin.h"


struct Admin {
    int index;
    char* userName;
    char* password;
    struct Admin* previous;
    struct Admin* next;
};

//定义在这里貌似不行,还是只放函数吧


//遍历链表,返回长度
int getAdminListSize(struct Admin* L){
    //    printf("遍历链表:\n");
    int index=0;
    struct Admin* temp=L->next;//通过一个临时指针遍历，不能操作原指针//这里的遍历没算头指针
    while (temp!=NULL) {
//        printf("%d\n",temp->data);
        temp=temp->next;
        index++;//如果需要获取链表长度，在此进行处理
    }
    return index;
}


int getStructAdminSize(){
    return sizeof(struct Admin);
}