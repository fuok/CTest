//
//  menu.c
//  Cstudent
//
//  Created by 刘阳 on 15/11/27.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#include "menu.h"

AdminList cacheAdminList;
StudentList cacheStudentList;


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

//管理员登陆，登录函数应该是menu方法中唯一（还有学生登陆）返回指针的，返回的指针作为修改密码的参数
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
    //printf("%s,%s\n",inputName,inputPass);
    
    //缓存管理员数据
    cacheAdminList = createEmptyAdminList();
    readAdminFile(cacheAdminList);
    
    AdminList currentPtr=getByUserName(cacheAdminList, inputName);//判断登录名是否存在
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
    int a=1,b=2,c=3;
    printf("选择功能:\n%d,密码修改\n%d,学生管理\n%d,退出登录\n",a,b,c);
    int key;
    scanf("%d",&key);
    if (a!=key&&b!=key&&c!=key) {
        wrongInput(menuAdminMain);
    }
    //返回输入结果
    return key;
}

//admin修改密码
int menuAdminPassword(AdminList currentPtr){
    //确认用户输入
    printf("请输入旧密码:\n");
    char inputOld[20];
    fscanf(stdin, "%s",inputOld);
    fflush(stdin);
    
    printf("请输入新密码:\n");
    char inputNew[20];
    fscanf(stdin, "%s",inputNew);
    fflush(stdin);
    printf("TEST CODE:%s,%s\n",inputOld,currentPtr->password);
    if (strcmp(inputOld, currentPtr->password)==0) {
        strcpy(currentPtr->password, inputNew);
        //currentPtr->password=inputNew;
        printf("TEST CODE:new=%s\n",currentPtr->password);
        writeAdminFile(cacheAdminList);
        printf("修改成功\n");
        return 1;
    }else{
        printf("密码错误\n");
        return 0;
    }
}

//admin学生管理
int menuAdminManagement(){
    //确认用户输入
    int a=1,b=2,c=3,d=4,e=5;
    printf("选择操作:\n%d,学生浏览\n%d,添加学生\n%d,删除学生\n%d,修改学生\n%d,返回上级\n",a,b,c,d,e);
    int key;
    scanf("%d",&key);
    if (a!=key&&b!=key&&c!=key&&d!=key&&e!=key) {
        wrongInput(menuAdminManagement);
    }
    
    //缓存学生数据
    cacheStudentList = createEmptyStudentList();
    readStudentFile(cacheStudentList);
    
    //返回输入结果
    return key;
}

//选择学生排序方式
int menuSelectStudentListType(){
    //确认用户输入
    int a=1;
    printf("选择排序方式:\n%d,按姓名\n",a);
    int key;
    scanf("%d",&key);
    if (a!=key) {
        wrongInput(menuSelectStudentListType);
    }
    //返回输入结果
    return key;
}

//显示学生列表
void menuShowStudentListByName(){
    printf("-----学生信息-----\n");
    printf("学号 姓名 班级 年龄 成绩1 成绩2 成绩3 名次\n");
    
    //声明数组
    int length=getStudentListSize(cacheStudentList);
    StudentNode nodeArray[length];
    
    //遍历链表
    StudentList temPtr=cacheStudentList->next;
    int i=0;
    while (temPtr!=NULL) {
        nodeArray[i]=*temPtr;
        temPtr=temPtr->next;
        i++;
    }
    
    //数组排序
    for (int i=0; i<length-1; i++) {
        for (int j=i+1; j<length; j++) {
            if ((*(nodeArray[i].studentName))>(*(nodeArray[j].studentName))) {//根据姓名ASCII排序
                StudentNode tempNode = nodeArray[i];
                nodeArray[i]=nodeArray[j];
                nodeArray[j]=tempNode;
            }
        }
    }
    
    //输出
    for (int i=0; i<length; i++) {
        printf("%s,%s,%s,%d,%d,%d,%d,%d\n",nodeArray[i].studentId,nodeArray[i].studentName,nodeArray[i].class,nodeArray[i].age,nodeArray[i].score_1,nodeArray[i].score_2,nodeArray[i].score_3,nodeArray[i].rank);
//        printf("TEST CODE:%d\n",*(nodeArray[i].studentName));//检查ASCII
    }
    printf("-----------------\n");
}

//添加学生
void menuAddStudent(){
    char studentName[20],class[20];
    int age,score_1,score_2,score_3;
    printf("输入学生资料:\n");
    printf("依次输入:姓名 班级 年龄 成绩1 成绩2 成绩3\n");
    fscanf(stdin,"%s %s %d %d %d %d",studentName,class,&age,&score_1,&score_2,&score_3);
    fflush(stdin);
    //自动生成学号和初始密码
    char* studentId=getNewStudentId(cacheStudentList,class);
    char* defautPassword="123";
    insertStudentAt(cacheStudentList,studentId,defautPassword,studentName,class,age,score_1,score_2,score_3);
    writeStudentFile(cacheStudentList);
    printf("Done!\n");
    //getLastStudentNode(cacheStudentList);
}

//删除学生
void menuDeleteStudent(){
    char studentId[20];
    printf("输入待删除的学生学号:\n");
    fscanf(stdin, "%s",studentId);
    fflush(stdin);
    printf("删除ing...:%s\n",studentId);
    deleteByStudentId(cacheStudentList,studentId);
    writeStudentFile(cacheStudentList);
    //getLastStudentNode(cacheStudentList);
}

//修改学生
void menuEditStudent(){
    char studentIdOld[20];
    printf("输入待修改的学生学号:\n");
    fscanf(stdin, "%s",studentIdOld);
    fflush(stdin);
    StudentList temPtr=getByStudentId(cacheStudentList,studentIdOld);
    char studentIdNew[20],password[20],studentName[20],class[20];
    int age,score_1,score_2,score_3;
    printf("输入学生资料:\n");
    printf("依次输入学号 密码 姓名 班级 年龄 成绩1 成绩2 成绩3\n");
    fscanf(stdin,"%s %s %s %s %d %d %d %d",studentIdNew,password,studentName,class,&age,&score_1,&score_2,&score_3);
    fflush(stdin);
    editStudent(temPtr,studentIdNew,password,studentName,class,age,score_1,score_2,score_3);
    writeStudentFile(cacheStudentList);
    //getLastStudentNode(cacheStudentList);
}

//学生登陆
StudentList loginTypeStudent(){
    //确认用户输入
    printf("请输入学号:\n");
    char inputName[20];//不能用[]={}声明
    fscanf(stdin, "%s",inputName);
    fflush(stdin);
    
    printf("请输入密码:\n");
    char inputPass[20];
    fscanf(stdin, "%s",inputPass);
    fflush(stdin);
    //printf("%s,%s\n",inputName,inputPass);
    
    //缓存学生数据
    cacheStudentList = createEmptyStudentList();
    readStudentFile(cacheStudentList);
    
    StudentList currentPtr=getByStudentId(cacheStudentList, inputName);//判断登录名是否存在
    if (currentPtr) {
        if (strcmp(inputPass, currentPtr->password)==0) {//判断密码是否正确
            printf("学生登录成功\n");
            return currentPtr;
        }else{
            printf("密码错误\n");
        }
    }else{
        printf("学号不存在\n");
    }
    //返回输入结果
    return NULL;
}

//学生主选项
int menuStudentMain(){
    //确认用户输入
    int a=1,b=2,c=3;
    printf("选择功能:\n%d,密码修改\n%d,查看个人信息\n%d,退出登录\n",a,b,c);
    int key;
    scanf("%d",&key);
    if (a!=key&&b!=key&&c!=key) {
        wrongInput(menuAdminMain);
    }
    //返回输入结果
    return key;
}

//学生修改密码
int menuStudentPassword(StudentList currentPtr){
    //确认用户输入
    printf("请输入旧密码:\n");
    char inputOld[20];
    fscanf(stdin, "%s",inputOld);
    fflush(stdin);
    
    printf("请输入新密码:\n");
    char inputNew[20];
    fscanf(stdin, "%s",inputNew);
    fflush(stdin);
    printf("TEST CODE:%s,%s\n",inputOld,currentPtr->password);
    if (strcmp(inputOld, currentPtr->password)==0) {
        strcpy(currentPtr->password, inputNew);
        //currentPtr->password=inputNew;
        printf("TEST CODE:new=%s\n",currentPtr->password);
        writeStudentFile(cacheStudentList);
        printf("修改成功\n");
        return 1;
    }else{
        printf("密码错误\n");
        return 0;
    }
}

//查看当前学生信息
void menuShowCurrentStudentInfo(StudentList currentPtr){
    printf("-----学生信息-----\n");
    printf("学号 姓名 班级 年龄 成绩1 成绩2 成绩3 名次\n");
    printf("%s,%s,%s,%d,%d,%d,%d,%d\n",currentPtr->studentId,currentPtr->studentName,currentPtr->class,currentPtr->age,currentPtr->score_1,currentPtr->score_2,currentPtr->score_3,currentPtr->rank);
    printf("-----------------\n");
}

//这个方法是当输入选项序号错误时，直接再次调用原方法以重新输入
void wrongInput(int (*funcPtr)()){
    printf("输入错误请重新输入:\n");
    (*funcPtr)();
}

//退出程序，暂时没用到
void systemExit(){
    exit(0);
}

