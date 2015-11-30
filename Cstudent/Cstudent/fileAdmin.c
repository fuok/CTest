//
//  fileAdmin.c
//  Cstudent
//
//  Created by 刘阳 on 15/11/29.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#include "fileAdmin.h"

char* adminFilePath="/Users/liuyang/Documents/workspace/CTest/admin.txt";


//
AdminList readAdminFile(){
    FILE* fp;
    if ((fp=fopen(adminFilePath, "rb+"))==NULL) {//为何w+也ok的
        puts("ERROR");
        exit(0);
    }
    fseek(fp, 0, SEEK_SET);//如果要直接跳到输出第二个学生，offset可以输入sizeof(struct Student)
    for (int i=0; i<3; i++) {
        struct Admin admin;
        fread(&admin,getStructAdminSize(), 1, fp);
        printf("%s,%s\n",admin.userName,admin.password);
    }
    fclose(fp);
    
    return NULL;
}


//
void writeAdminFile(AdminList list){
    FILE* fp;
    if ((fp=fopen(adminFilePath, "wb+"))==NULL) {//为何w+也ok的
        puts("ERROR");
        exit(0);
    }
    for (int i=0; i<3; i++) {//此处需要倒入获取链表长度方法
        fwrite(list,getStructAdminSize(), 1, fp);//我日
    }
    fclose(fp);
}


//FILE *fp;
//if ((fp=fopen("/Users/liuyang/Documents/The9课程/Ctest18文件操作/student.txt", "wb+"))==NULL) {//为何w+也ok的
//    puts("ERROR");
//    exit(0);
//}
//for (int i=0; i<3; i++) {
//    fwrite(stu+i, sizeof(struct Student), 1, fp);
//}
////    frewind();//不好使
//fseek(fp, 0, SEEK_SET);//如果要直接跳到输出第二个学生，offset可以输入sizeof(struct Student)
//printf("归位:%ld\n",ftell(fp));
//for (int i=0; i<3; i++) {
//    struct Student stu;
//    fread(&stu,sizeof(struct Student), 1, fp);
//    printf("%s,%d\n",stu.name,stu.age);
//}
//fclose(fp);