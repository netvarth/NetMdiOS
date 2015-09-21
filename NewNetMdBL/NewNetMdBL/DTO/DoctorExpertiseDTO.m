//
//  DoctorExpertise.m
//  NetMdBL
//
//  Created by Surendar Modugu on 3/15/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "DoctorExpertiseDTO.h"

@implementation DoctorExpertiseDTO

- (id)initWithExpertise:(int)expertiseId
              doctorId :(int)doctorId
              expertise:(NSString*)expertise
             actionName:(NSString*)actionName {
    
    self    = [super init];
    if (self != nil) {
        self.Id    = expertiseId;
        self.doctorId       = doctorId;
        self.expertise      = expertise;
        self.actionName     = actionName;
    }
    
    return self;
}

@end
