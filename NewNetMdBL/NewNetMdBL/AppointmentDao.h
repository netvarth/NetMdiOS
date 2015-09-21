//
//  AppointmentDao.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/30/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppointmentDTO.h"

@protocol AppointmentDao <NSObject>

- (BOOL)addAppointment:(AppointmentDTO*) appointmentDto;
- (NSMutableArray*)getAllAppointments;
- (void)deleteAppointmentById:(int) AppointmentId;
- (void)editAppointmentById:(AppointmentDTO *)AppointmentDao;
- (AppointmentDTO*) getAppointmentById:(int) AppointmentId;
- (NSMutableArray*) getAllAppointmentsByDoctorId:(int) doctorId;
@end
