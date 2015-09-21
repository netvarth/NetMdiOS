//
//  ReferralDetails.h
//  NetMdBL
//
//  Created by Surendar Modugu on 3/17/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ReferralDetails : NSObject

@property (nonatomic, assign) int       Id;
@property (nonatomic, strong) NSString* firstName;
@property (nonatomic, strong) NSString* address;
@property (nonatomic, strong) NSString* mobile;
@property (nonatomic, strong) NSString* email;
@property (nonatomic, strong) NSString* lastName;
@property (nonatomic, strong) NSString* specialization;
@property (nonatomic, strong) NSString* qualification;


@end
