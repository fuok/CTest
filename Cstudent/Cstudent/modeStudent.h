//
//  modeStudent.h
//  Cstudent
//
//  Created by 刘阳 on 15/11/27.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#ifndef modeStudent_h
#define modeStudent_h

#include <stdio.h>
//定义结构体
struct Student {
    int index;
    char studentId[20];
    char password[20];
    char studentName[20];
    char class[20];
    int age;
    int score_1;
    int score_2;
    int score_3;
    int rank;
    
    struct Student* previous;
    struct Student* next;
};
//typedef
typedef struct Student StudentNode;
typedef struct Student* StudentList;
//函数原型
StudentList createNewStudentNode();
StudentList createEmptyStudentList();
StudentList insertStudentAt();
StudentList getByStudentId();
StudentList deleteByStudentId();
StudentList editStudent();

int getStudentListSize();
StudentList getLastStudentNode();
StudentList getStudentArray();
int getStructStudentSize();


#endif /* modeStudent_h */
