//
//  modeAdmin.h
//  Cstudent
//
//  Created by 刘阳 on 15/11/27.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#ifndef modeAdmin_h
#define modeAdmin_h

#include <stdio.h>

struct Admin;

typedef struct Admin AdminNode;
typedef struct Admin* AdminList;

AdminList createNewAdminNode(char* userName,char* password);
AdminList createEmptyAdminList();
AdminList insertAdminAt(AdminList L,char* userName,char* password);
int getStructAdminSize();

//struct Admin {
//    int index;
//    char* userName;
//    char* password;
//    struct Admin* previous;
//    struct Admin* next;
//};
//
//typedef struct Admin AdminNode;//节点定义
//typedef struct Admin* AdminList;//链表指针定义
//
//int getAdminListSize(AdminList L);
//
//AdminList cacheAdminList;

#endif /* modeAdmin_h */
