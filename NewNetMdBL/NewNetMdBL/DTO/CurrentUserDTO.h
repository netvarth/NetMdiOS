//
//  CurrentUserDTO.h
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 16/01/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CurrentUserDTO : NSObject <NSCoding>

@property (nonatomic, assign) int  Id;
@property (nonatomic, assign) int   globalId;
@property (nonatomic, assign) int  selectedDoctorId;
@property (nonatomic, assign) int  loginId;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* userName;
@property (nonatomic, strong) NSString* userType;
@property (nonatomic, strong) NSString* password;
@property (nonatomic, strong) NSString* gender;
@property (nonatomic, strong) NSString* email;
@property (nonatomic, strong) NSString* address;
@property (nonatomic, strong) NSString* phone;
@property (nonatomic, strong) NSString* mobile;
@property (nonatomic, strong) NSString* dateOfBirth;

@end
