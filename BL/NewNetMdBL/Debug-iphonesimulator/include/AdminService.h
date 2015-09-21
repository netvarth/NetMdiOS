//
//  AdminService.h
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 07/08/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdminDao.h"
#import "DoctorDetail.h"

@interface AdminService : NSObject
@property (nonatomic,strong) id<AdminDao>Admindaodelegate;
+ (AdminService*)sharedInstance;
- (int)getloginid:(DoctorDetail*)objDoctordetail;
- (LoginDTO*)getlogindata:(int)logId;
@end
