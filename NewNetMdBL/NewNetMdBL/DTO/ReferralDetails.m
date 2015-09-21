//
//  ReferralDetails.m
//  NetMdBL
//
//  Created by Surendar Modugu on 3/17/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "ReferralDetails.h"

@implementation ReferralDetails

- (id)initWithReferralDetails:(int)referralId
                    firstName:(NSString*)firstName
                      address:(NSString*)address
                      mobile:(NSString*)mobile
                        email:(NSString*)email
                     lastName:(NSString*)lastName
               specialization: (NSString*) specialization
                qualification: (NSString*)qualification{
    
    self    = [super init];
    if (self != nil) {
        self.Id     = referralId;
        self.firstName      = firstName;
        self.address        = address;
        self.mobile         = mobile;
        self.email          = email;
        self.lastName       = lastName;
        self.specialization = specialization;
        self.qualification  =qualification;
    }
    
    return self;
}

@end
