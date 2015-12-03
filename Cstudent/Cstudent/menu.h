//
//  menu.h
//  Cstudent
//
//  Created by 刘阳 on 15/11/27.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "modeAdmin.h"
#include "fileAdmin.h"
#include "modeStudent.h"
#include "fileStudent.h"


int loginTypeSelect();
AdminList loginTypeAdmin();//⚠️返回指针
int menuAdminMain();
int menuAdminPassword();
int menuAdminManagement();
void menuLoadAndShowStudentList();
void menuAddStudent();
void menuDeleteStudent();
void menuEditStudent();

StudentList loginTypeStudent();//⚠️返回指针
int menuStudentMain();
int menuStudentPassword();
void menuShowCurrentStudentInfo();

void wrongInput(int (*funcPtr)());
void systemExit();
#endif /* menu_h */
