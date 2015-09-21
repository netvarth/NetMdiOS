//
//  DoctorMembership.h
//  NetMdBL
//
//  Created by Surendar Modugu on 3/15/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DoctorMembershipDTO : NSObject

@property (nonatomic, assign) int           Id;
@property (nonatomic, assign) int           doctorId;
@property (nonatomic, strong) NSString*     membership;
@property (nonatomic, strong) NSString*     actionName;

@end
