//
//  fileStudent.c
//  Cstudent
//
//  Created by 刘阳 on 15/12/1.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#include "fileStudent.h"

char* studentFilePath="/Users/liuyang/Documents/workspace/CTest/student.txt";


//
StudentList readStudentFile(StudentList L){
    FILE* fp;
    if ((fp=fopen(studentFilePath, "rb"))==NULL) {
        puts("ERROR");
        exit(0);
    }
    
    //因为feof总会多输出一个结果，所以手动算一下数据长度
    fseek(fp, 0, SEEK_END);
    int length=(int)ftell(fp)/getStructStudentSize();
    fseek(fp, 0, SEEK_SET);
    printf("TEST:数据长度:%d\n",length);
    for (int i=0;i<length; i++) {
        struct Student student;
        fread(&student,sizeof(struct Student), 1, fp);
        printf("TEST:读取:%s,%s\n",student.studentId,student.password);
        insertStudentAt(L, student.studentId, student.password,student.studentName,student.class,student.age,student.score_1,student.score_2,student.score_3);
    }
    fclose(fp);
    return L;
}


//
void writeStudentFile(StudentList L){
    FILE* fp;
    if ((fp=fopen(studentFilePath, "wb+"))==NULL) {
        puts("ERROR");
        exit(0);
    }
    //这里我没有去研究能否直接写入整个list，仍是以保存为单个结构体数据再写入的方法//估计是不行的，保存内存地址无意义
    int dataLength=getStudentListSize(L);//貌似也没什么用
    printf("TEST:写入student数据，长度：%d\n",dataLength);
    StudentList temPtr=L->next;
    
    while (temPtr!=NULL) {
        //        printf("%s,%s\n",temPtr->userName,temPtr->password);
        fwrite(temPtr,getStructStudentSize(), 1, fp);
        temPtr=temPtr->next;
    }
    
    fclose(fp);
}


