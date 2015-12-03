//
//  fileAdmin.c
//  Cstudent
//
//  Created by 刘阳 on 15/11/29.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#include "fileAdmin.h"

char* adminFilePath="/Users/liuyang/Documents/workspace/CTest/admin.txt";


//读取学生数据,返回链表,此代码应只用于读取全局缓存数据
AdminList readAdminFile(AdminList L){
    FILE* fp;
    if ((fp=fopen(adminFilePath, "rb"))==NULL) {//为何w+也ok的
        puts("Admin初始化");
        //        exit(0);
        //当文件不存在时保存一个admin默认值
        struct Admin* defaut = createEmptyAdminList();
        insertAdminAt(defaut, "admin", "pass");
        writeAdminFile(defaut);
        fp=fopen(adminFilePath, "rb");
    }
    
    //因为feof总会多输出一个结果，所以手动算一下数据长度
    fseek(fp, 0, SEEK_END);
    int length=(int)ftell(fp)/getStructAdminSize();
    fseek(fp, 0, SEEK_SET);
    printf("TEST CODE:数据长度:%d\n",length);
    for (int i=0;i<length; i++) {
        struct Admin admin;
        fread(&admin,sizeof(struct Admin), 1, fp);
        printf("TEST CODE:读取:%s,%s\n",admin.userName,admin.password);
        //        insertAdminNode(L, admin);//可能是这个直接传对象方法不行，用回老方法试试，TODO
        insertAdminAt(L, admin.userName, admin.password);
    }
    fclose(fp);
    return L;
}

//写入学生数据,此代码应只用于写入全局缓存数据
void writeAdminFile(AdminList L){
    FILE* fp;
    if ((fp=fopen(adminFilePath, "wb+"))==NULL) {
        puts("ERROR");
        exit(0);
    }
    //这里我没有去研究能否直接写入整个list，仍是以保存为单个结构体数据再写入的方法//估计是不行的，保存内存地址无意义
    int dataLength=getAdminListSize(L);//貌似也没什么用
    printf("TEST CODE:写入admin数据，长度：%d\n",dataLength);
    AdminList temPtr=L->next;
    
    while (temPtr!=NULL) {
        //        printf("%s,%s\n",temPtr->userName,temPtr->password);
        fwrite(temPtr,getStructAdminSize(), 1, fp);
        temPtr=temPtr->next;
    }
    
    fclose(fp);
}
