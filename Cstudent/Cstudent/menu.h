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


int loginTypeSelect();
AdminList loginTypeAdmin();
int menuAdminMain();
void menuAdminPassword();
int loginTypeStudent();

void wrongInput(int (*funcPtr)());

#endif /* menu_h */
