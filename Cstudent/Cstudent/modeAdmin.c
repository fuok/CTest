//
//  modeAdmin.c
//  Cstudent
//
//  Created by 刘阳 on 15/11/27.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#include "modeAdmin.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Admin {
    int index;
    char* userName;
    char* password;
    struct Admin* previous;
    struct Admin* next;
};


//创建一个空链表，空链表仅包含头节点而且头节点指针为NULL
AdminList createEmptyAdminList(){
    return createNewAdminNode("","");
}


//添加节点，头插法
AdminList insertAdminAt(AdminList L,char* userName,char* password){
    assert(L!=NULL);//断言
    AdminNode *newNode=createNewAdminNode(userName,password);
    if (newNode!=NULL) {
        //先把插入节点指向前序节点的指向
        newNode->next=L->next;
        //再把前序节点指向新节点，实现插入功能
        L->next=newNode;
    }
    
    //保存前一
    AdminList LP=newNode->next;
    if (LP!=NULL) {
//        printf("im in");
        LP->previous=newNode;
    }
    newNode->previous=L;
    
    return newNode;
}


//遍历链表,返回长度
int getAdminListSize(AdminList L){
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


//创建节点函数,不显式引用
AdminList createNewAdminNode(char* userName,char* password){
    AdminNode *newNode=NULL;//创建链表的第一步是创建节点
    newNode=(AdminNode*)calloc(1, sizeof(AdminNode));//这里的参数1怎么回事
    if (newNode==NULL) {
        return NULL;
    }
    newNode->previous=NULL;
    newNode->next=NULL;
    newNode->index=-1;
    newNode->userName=userName;
    newNode->password=password;
    return newNode;
}


//获取结构体占用的内存大小,不知道为什么在main函数不能使用这边头文件的typedef，所以定义这个
int getStructAdminSize(){
    return sizeof(struct Admin);
}