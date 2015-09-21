//
//  AppointmentService.m
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/30/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "AppointmentService.h"

@implementation AppointmentService
@synthesize appointmentdaodelegate;

+ (AppointmentService*)sharedInstance {
    static dispatch_once_t onceToken;
    static AppointmentService* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[AppointmentService alloc] init];
    });
    
    return sharedInstance;
}

- (BOOL)addAppointment:(AppointmentDTO*) appointmentDto
{
    [appointmentdaodelegate addAppointment:appointmentDto ] ;
    return YES;
}

- (NSMutableArray*)getAllAppointments
{
    return [appointmentdaodelegate getAllAppointments];
}

- (void)deleteAppointmentById:(int) AppointmentId
{
    [appointmentdaodelegate deleteAppointmentById:AppointmentId];
}

-(void) editAppointment:(AppointmentDTO*) AppointmentDto
{
    [appointmentdaodelegate editAppointmentById:AppointmentDto];
}
- (AppointmentDTO *) getAppointmentById:(int) AppointmentId
{
   return [appointmentdaodelegate getAppointmentById:AppointmentId];
}
- (NSMutableArray*) getAllAppointmentsByDoctorId:(int) doctorId
{
    return [appointmentdaodelegate getAllAppointmentsByDoctorId:doctorId];
}
@end

