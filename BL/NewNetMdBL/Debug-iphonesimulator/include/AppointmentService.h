//
//  AppointmentService.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/30/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppointmentDao.h"
#import "AppointmentDTO.h"

@interface AppointmentService : NSObject

@property (nonatomic, strong) id<AppointmentDao> appointmentdaodelegate;

+ (AppointmentService*)sharedInstance;

- (BOOL)addAppointment:(AppointmentDTO*) appointmentDto;
- (NSMutableArray*)getAllAppointments;
- (void)deleteAppointmentById:(int) AppointmentId;
- (void) editAppointment:(AppointmentDTO*) AppointmentDto;
- (AppointmentDTO*) getAppointmentById:(int) AppointmentId;
- (NSMutableArray*) getAllAppointmentsByDoctorId:(int) doctorId;
@end
