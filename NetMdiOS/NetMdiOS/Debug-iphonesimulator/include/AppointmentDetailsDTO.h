//
//  AppointmentDetailsDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/29/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppointmentDetailsDTO : NSObject

@property (nonatomic, assign) int       Id;
@property (nonatomic, assign) int       globalId;
@property (nonatomic, assign) int       patientId;
@property (nonatomic, assign) int       doctorId;
@property (nonatomic, assign) int       scheduleId;
@property (nonatomic, strong) NSString* startDate;
@property (nonatomic, strong) NSString* startTime;
@property (nonatomic, strong) NSString* patientName;
@property (nonatomic, strong) NSString* emailid;

@end
