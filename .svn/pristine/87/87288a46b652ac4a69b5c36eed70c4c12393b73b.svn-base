//
//  DoctorDetail.m
//  NetMdBL
//
//  Created by Surendar Modugu on 3/15/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "DoctorDetail.h"

@implementation DoctorDetail

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
               login:(LoginDTO*)login
{
    
    self    = [super init];
    if (self != nil) {
        self.Id           = doctorId;
        self.globalId           = globalId;
        self.firstName          = firstName;
        self.lastName           = lastName;
        self.dateOfBirth        = dateOfBirth;
        self.gender             = gender;
        self.workHistory        = workHistory;
        self.mobile             = mobile;
        self.phone              = phone;
        self.email              = email;
        self.address            = address;
        self.workingPlaces      = workingPlaces;
        self.designation        = designation;
        self.consultationInterval   = consultationInterval;
        self.status             = status;
        self.createdDateTime        = createdTime;
        self.updatedDateTime        = updatedTime;
        self.doctorExperience         = experience;
        self.doctorQualifications     = qualifications;
        self.expertise          = expertise;
        self.membership         = membership;
        self.achievement        = achievement;
        self.error              = error;
        self.success            = success;
       login=[[LoginDTO alloc]init];
        self.login              = login;
    }
    
    return self;
}

@end
