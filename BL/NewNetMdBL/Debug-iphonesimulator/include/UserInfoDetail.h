//
//  UserInfoDetail.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserInfoDetail : NSObject

@property (nonatomic, assign)int   Id;
@property (nonatomic, assign)int   globalId;
@property (nonatomic, strong) NSString* firstName;
@property (nonatomic, strong) NSString* lastName;
@property (nonatomic, strong) NSString* userType;
@property (nonatomic, strong) NSString* userName;
@property (nonatomic, strong) NSString* password;
@property (nonatomic, strong) NSString* mobile;
@property (nonatomic, strong) NSString* phone;
@property (nonatomic, strong) NSString* status;
@property (nonatomic, strong) NSString* email;
@property (nonatomic, strong) NSString* address;

@end
