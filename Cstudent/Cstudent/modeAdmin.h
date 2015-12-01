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
//定义结构体
struct Admin {
    int index;
    char* userName;
    char* password;
    struct Admin* previous;
    struct Admin* next;
};
//typedef
typedef struct Admin AdminNode;
typedef struct Admin* AdminList;
//函数原型
AdminList createNewAdminNode(char* userName,char* password);
AdminList createEmptyAdminList();
AdminList insertAdminAt(AdminList L,char* userName,char* password);
int getAdminListSize(AdminList L);
int getStructAdminSize();
AdminList insertAdminNode(AdminList L,AdminNode node);
AdminList getLastAdminNode(AdminList L);


#endif /* modeAdmin_h */
