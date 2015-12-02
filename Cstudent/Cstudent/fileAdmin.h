//
//  fileAdmin.h
//  Cstudent
//
//  Created by 刘阳 on 15/11/29.
//  Copyright © 2015年 刘阳. All rights reserved.
//

#ifndef fileAdmin_h
#define fileAdmin_h

#include <stdlib.h>
#include <stdio.h>
#include "modeAdmin.h"


AdminList readAdminFile(AdminList L);
void writeAdminFile(AdminList L);

#endif /* fileAdmin_h */
