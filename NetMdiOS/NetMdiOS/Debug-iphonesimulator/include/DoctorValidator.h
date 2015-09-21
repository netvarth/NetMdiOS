//
//  DoctorValidator.h
//  NetMdBL
//
//  Created by Surendar Modugu on 3/17/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Errors.h"
#import "DoctorDetail.h"
#import "Filter.h"

@interface DoctorValidator : NSObject

- (Errors*)validateCreateDoctor:(DoctorDetail*)doctor;
- (Errors*)validateUpdateDoctor:(DoctorDetail*)doctor;
- (Errors*)ValidateCreateUser:(LoginDTO*)user;
- (BOOL)isValidName:(NSString*)name;
- (Errors*)validateDoctorFilter:(Filter*)filter;

@end
