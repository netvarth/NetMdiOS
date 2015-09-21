//
//  NetMdDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NetMdDTO : NSObject

@property (nonatomic, assign) int       globalId;
@property (nonatomic, assign) int       Id;
@property (nonatomic, assign) int       netMdId;
@property (nonatomic, assign) int       netMdBranchId;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* ownerFirstName;
@property (nonatomic, strong) NSString* ownerLastName;
@property (nonatomic, strong) NSString* ownerAddress;
@property (nonatomic, strong) NSString* ownerEmail;
@property (nonatomic, strong) NSString* ownerPhone;
@property (nonatomic, strong) NSString* ownerMobile;
@property (nonatomic, strong) NSString* status;
@property (nonatomic, strong) NSString* headOfficeName;
@property (nonatomic, strong) NSString* headOfficeEmail;
@property (nonatomic, strong) NSString* headOfficePhone;
@property (nonatomic, strong) NSString* headOfficeMobile;
@property (nonatomic, strong) NSString* headOfficeAddress;
@property (nonatomic, strong) NSString* userName;
@property (nonatomic, strong) NSString* password;
@property (nonatomic, strong) NSString* userType;
//@property(nonatomic,strong) NSString* logo;
@end
