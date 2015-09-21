//
//  DoctorDetail.h
//  NetMdBL
//
//  Created by Surendar Modugu on 3/15/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>


#import "ErrorDTO.h"
#import "LoginDTO.h"

@interface DoctorDetail : NSObject

@property (nonatomic, assign) int       Id;
@property (nonatomic, assign) int       globalId;
@property (nonatomic, strong) NSString* firstName;
@property (nonatomic, strong) NSString* lastName;
@property (nonatomic, strong) NSString* dateOfBirth;
@property (nonatomic, strong) NSString* gender;
@property (nonatomic, strong) NSString* workHistory;
@property (nonatomic, strong) NSString* mobile;
@property (nonatomic, strong) NSString* phone;
@property (nonatomic, strong) NSString* email;
@property (nonatomic, strong) NSString* address;
@property (nonatomic, strong) NSString* workingPlaces;
@property (nonatomic, strong) NSString* designation;
@property (nonatomic, strong) NSString* specialization;
@property (nonatomic, strong) NSString* consultationInterval;
@property (nonatomic, strong) NSString* status;
@property (nonatomic, strong) NSString* createdDateTime;
@property (nonatomic, strong) NSString* updatedDateTime;
@property (nonatomic, strong) NSArray*  doctorExperience;
@property (nonatomic, strong) NSArray*  doctorQualifications;
@property (nonatomic, strong) NSArray*  expertise;
@property (nonatomic, strong) NSArray*  membership;
@property (nonatomic, strong) NSArray*  achievement;
@property (nonatomic, strong) ErrorDTO*    error;
@property (nonatomic, assign) BOOL      success;
@property (nonatomic, strong) LoginDTO*    login;
@property (nonatomic, strong) NSString* uniqueId;

- (id)initWithDoctor:(int)doctorId
            globalId:(int)globalId
           firstName:(NSString*)firstName
            lastName:(NSString*)lastName
         dateOfBirth:(NSString*)dateOfBirth
              gender:(NSString*)gender
         workHistory:(NSString*)workHistory
              mobile:(NSString*)mobile
               phone:(NSString*)phone
               email:(NSString*)email
             address:(NSString*)address
       workingPlaces:(NSString*)workingPlaces
         designation:(NSString*)designation
consultationInterval:(NSString*)consultationInterval
              status:(NSString*)status
         createdTime:(NSString*)createdTime
         updatedTime:(NSString*)updatedTime
          experience:(NSArray*)experience
      qualifications:(NSArray*)qualifications
           expertise:(NSArray*)expertise
          membership:(NSArray*)membership
         achievement:(NSArray*)achievement
               error:(ErrorDTO*)error
             success:(BOOL)success
               login:(LoginDTO*)login;

@end
