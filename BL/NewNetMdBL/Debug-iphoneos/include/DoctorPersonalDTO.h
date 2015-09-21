//
//  DoctorPersonalDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"
#import "LoginDTO.h"

@interface DoctorPersonalDTO : NSObject

@property (nonatomic, assign) int       Id;
@property (nonatomic, assign) int       globalId;
@property (nonatomic, strong) NSString* firstName;
@property (nonatomic, strong) NSString* lastName;
@property (nonatomic, strong) NSString* dateOfBirth;
@property (nonatomic, strong) NSString* gender;
@property (nonatomic, strong) NSString* workHistory;
@property (nonatomic, strong) NSString* mobile;
@property (nonatomic, strong) NSString* phone;
@property (nonatomic, strong) NSString* email;
@property (nonatomic, strong) NSString* address;
@property (nonatomic, strong) NSString* workingPlaces;
@property (nonatomic, strong) NSString* designation;
@property (nonatomic, strong) NSString* specialization;
@property (nonatomic, strong) NSString* consultationInterval;
@property (nonatomic, strong) NSArray*  achievement;
@property (nonatomic, strong) ErrorDTO*    error;
@property (nonatomic, assign) BOOL      success;
@property (nonatomic, strong) LoginDTO*    login;

@end
