//
//  AdminService.m
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 07/08/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import "AdminService.h"

@implementation AdminService
@synthesize Admindaodelegate;
+ (AdminService*)sharedInstance {
    static dispatch_once_t onceToken;
    static AdminService* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[AdminService alloc] init];
    });
    
    return sharedInstance;
}
- (int)getloginid:(DoctorDetail*)objDoctordetail
{
    return [Admindaodelegate getloginid:objDoctordetail];
}
- (LoginDTO*)getlogindata:(int)logId
{
    return [Admindaodelegate getlogindata:logId];
}

@end
