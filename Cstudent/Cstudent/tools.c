//
//  tools.c
//  Cstudent
//
//  Created by 刘阳 on 15/12/4.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#include "tools.h"

//学号生成规则,'C'+班级＋序号
char* getNewStudentId(StudentList L,char* class){
    assert(L!=NULL);
    int max=1;
    StudentList temPtr=L->next;
    while (temPtr!=NULL) {
        char* srcStr=temPtr->studentId;
        //比较学号前半段
        char indexStr[10];//⚠️声明方式
        subString(srcStr, indexStr, 0, 3);
        if (strcmp(class, indexStr)==0) {
            //截取比较后半段
            char lastStr[10];
            subString(srcStr, lastStr, 3, 5);
            int num=stringToInteger(lastStr);
            if (num>=max) {
                max=num+1;//最大学号始终+1
            }
        }
        temPtr=temPtr->next;
    }
    char finalStr[10];
//    printf("TEST CODE:学号是%s\n",strcat(class,integerToString(max,finalStr)));
    return strcat(class,integerToString(max,finalStr));//class+序号,这里还有问题的，没有考虑十位数的0
}

//截取子串
char* subString(char* srcStr,char* tarStr,int index,int length){
    if (index<0||length<0) {
        return  NULL;
    }
    //    puts(srcStr);
    //    puts(tarStr);
    int j=0;
    for (int i=index; i<index+length; i++,j++) {//这里的思路是两行指针同时移动完成对比
        tarStr[j]=srcStr[i];
    }
    tarStr[j]='\0';
    return tarStr;
}

//字符串转换为数字
int stringToInteger(char* str){
    int num_int;
    double num_double;
//    char str_int[30] = "435";//将要被转换为整型的字符串
//    char str_double[30] = "436.55";//将要被转换为浮点型的字符串
    
    num_int = atoi(str);//转换为整型值
    num_double = atof(str);//转换为浮点型值
    
//    printf("num_int: %d\n", num_int);
//    printf("num_double: %lf\n", num_double);
    
    return num_int;
}

//数字转换为字符串
char* integerToString(int a,char* str){
    gcvt(a, 8, str);
    return str;
}
