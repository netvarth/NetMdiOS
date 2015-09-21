//
//  AdminDao.h
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 07/08/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DoctorDetail.h"
#import "LoginDTO.h"

@protocol AdminDao <NSObject>
- (int)getloginid:(DoctorDetail*)objDoctordetail;
- (LoginDTO*)getlogindata:(int)logId;
@end
