//
//  DoctorResponse.m
//  NetMdBL
//
//  Created by Surendar Modugu on 3/17/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "DoctorListResponse.h"

@implementation DoctorListResponse

- (id)initWithReferral:(NSArray*)referral
                 error:(ErrorDTO*)error
               success:(BOOL)success
                 count:(long)count {
    
    self    = [super init];
    if (self != nil) {
        self.referral   = referral;
        self.error      = error;
        self.success    = success;
        self.count      = count;
    }
    
    return self;
}

@end
