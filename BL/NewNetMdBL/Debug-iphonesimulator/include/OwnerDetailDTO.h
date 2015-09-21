//
//  OwnerDetail.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/29/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface OwnerDetailDTO : NSObject

@property (nonatomic, assign) int     Id;
@property (nonatomic, assign) int     globalId;
@property (nonatomic, strong) NSString*     firstName;
@property (nonatomic, strong) NSString*     lastName;
@property (nonatomic, strong) NSString*     dateOfBirth;
@property (nonatomic, strong) NSString*     gender;
@property (nonatomic, strong) NSString*     mobile;
@property (nonatomic, strong) NSString*     phone;
@property (nonatomic, strong) NSString*     email;
@property (nonatomic, strong) NSString*     address;
@property  int           loginId ;
@property (nonatomic, strong) NSString*     createDateTime;
@property (nonatomic, strong) NSString*     updateDateTime;
@property (nonatomic, strong) ErrorDTO*     error;
@property (nonatomic, assign) BOOL    success;

@end
