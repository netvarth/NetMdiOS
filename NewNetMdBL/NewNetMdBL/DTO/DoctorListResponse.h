//
//  DoctorResponse.h
//  NetMdBL
//
//  Created by Surendar Modugu on 3/17/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ErrorDTO.h"
#import "ReferralDetails.h"

@interface DoctorListResponse : NSObject

@property (nonatomic, strong) NSArray*  referral;
@property (nonatomic, strong) ErrorDTO*    error;
@property (nonatomic, assign) BOOL      success;
@property (nonatomic, assign) long      count;

@end
