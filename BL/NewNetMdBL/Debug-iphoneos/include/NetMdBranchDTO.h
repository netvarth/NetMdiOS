//
//  NetMdBranchDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NetMdBranchDTO : NSObject

@property (nonatomic, assign) int       globalId;
@property (nonatomic, assign) int       Id;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* email;
@property (nonatomic, strong) NSString* phone;
@property (nonatomic, strong) NSString* mobile;
@property (nonatomic, strong) NSString* address;
@property (nonatomic, strong) NSString* status;
@property (nonatomic, assign) int netMdId;
@property (nonatomic, strong) NSString* macId;

@property (nonatomic, strong) NSArray* passPhrase;
@property (nonatomic, assign) int numberOfDevices;



@end
