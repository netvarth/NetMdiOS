//
//  ServerService.m
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 14/05/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import "ServerService.h"
#import "DoctorResponse.h"

@implementation ServerService
@synthesize servicedaodelegate;



+ (ServerService*)sharedInstance {
    static dispatch_once_t onceToken;
    static ServerService* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[ServerService alloc] init];
    });
    
    return sharedInstance;
}

-(NSString*)getSynctable
{
 return [servicedaodelegate getSynctable];
  
    
}
-(void)updateUploadedTimeSyncTable:(NSString*)lastSyncTime
{
    return[servicedaodelegate updateUploadedTimeSyncTable:lastSyncTime];
    
}
-(void)updateDownloadedTimeSyncTable:(NSString*)lastportalSyncTime
{
    return[servicedaodelegate updateDownloadedTimeSyncTable:lastportalSyncTime];
}

-(void)addGlobalIdToCreatedDoctors:(DoctorResponse*)doctorResDAO
{
    return[servicedaodelegate addGlobalIdToCreatedDoctors:doctorResDAO];
}
- (NSMutableArray*)getAllUnsynchedDoctorDeatilsWithGlobalId{
    
    
    return [servicedaodelegate getAllUnsynchedDoctorDeatilsWithGlobalId];
    
}
- (NSMutableArray*)getAllDoctorExperienceByGlobalId:(int)doctorId
{
    return [servicedaodelegate getAllDoctorExperienceByGlobalId:doctorId];
}
- (NSMutableArray*)getAllDoctorQualificationsByGlobalId:(int)doctorId
{
    return [servicedaodelegate getAllDoctorQualificationsByGlobalId:doctorId];
}
- (NSMutableArray*)getAllDoctorAchievementsByGlobalId:(int)doctorId
{
    return [servicedaodelegate getAllDoctorAchievementsByGlobalId:doctorId];
}
- (NSMutableArray*)getAllDoctorMembershipsByGlobalId:(int)doctorId
{
    return [servicedaodelegate getAllDoctorMembershipsByGlobalId:doctorId];
}

- (NSMutableArray*)getAllDoctorExpertiseByGlobalId:(int)doctorId
{
    return [servicedaodelegate getAllDoctorExpertiseByGlobalId:doctorId];
    
}
- (NSMutableArray*) getAllUpdatedDoctorDeatilsWithGlobalId
{
return [servicedaodelegate getAllUpdatedDoctorDeatilsWithGlobalId];
}

- (NSMutableArray*)getAllUpdatedDoctorExperienceByGlobalId:(int)doctorId
{
    return [servicedaodelegate getAllUpdatedDoctorExperienceByGlobalId:doctorId];
}
- (NSMutableArray*)getAllUpdatedDoctorQualificationsByGlobalId:(int)doctorId
{
    return [servicedaodelegate getAllUpdatedDoctorQualificationsByGlobalId:doctorId];
}
- (NSMutableArray*)getAllUpdatedDoctorAchievementsByGlobalId:(int)doctorId
{
    return [servicedaodelegate getAllUpdatedDoctorAchievementsByGlobalId:doctorId];
}
- (NSMutableArray*)getAllUpdatedDoctorMembershipsByGlobalId:(int)doctorId
{
    return [servicedaodelegate getAllUpdatedDoctorMembershipsByGlobalId:doctorId];
}

- (NSMutableArray*)getAllUpdatedDoctorExpertiseByGlobalId:(int)doctorId
{
    return [servicedaodelegate getAllUpdatedDoctorExpertiseByGlobalId:doctorId];
}
- (NSMutableArray*)getAllschedulesByGlobalId
{
    return [servicedaodelegate getAllschedulesByGlobalId];
}
- (SeriesDTO*)getSeriesBySeriesId:(int)seriesId{
    return [servicedaodelegate getSeriesBySeriesId:seriesId];
}
- (void)addGlobalIdTocreatedSchedules:(ScheduleResponse*)scheduleResDAO;
{
    [servicedaodelegate addGlobalIdTocreatedSchedules:scheduleResDAO];
  }
- (void)addGlobalIdTocreatedSeries:(ScheduleResponse*)scheduleResDAO
{
    [servicedaodelegate addGlobalIdTocreatedSeries:scheduleResDAO];
}
- (NSMutableArray*)getAllDeletedschedulesByGlobalId
{
    return [servicedaodelegate getAllDeletedschedulesByGlobalId];
}
- (void)deleteschedule:(ScheduleResponse*)scheduleResDAO
{
    return [servicedaodelegate deleteschedule:scheduleResDAO];
}
- (void)deleteseries:(ScheduleResponse*)scheduleResDAO
{
    return [servicedaodelegate deleteseries:scheduleResDAO];
}
- (NSMutableArray*)getallpatientsWithGlobalId
{
    return [servicedaodelegate getallpatientsWithGlobalId];
}
- (NSMutableArray*)getallUpdatedPatientsWithGlobalId
{
    return [servicedaodelegate getallUpdatedPatientsWithGlobalId];
}
-(void)addGlobalIdTocreatedPatients:(PatientResponse*)patientResDAO
{
    return[servicedaodelegate addGlobalIdTocreatedPatients:patientResDAO];
}
-(NSMutableArray*)getallAppointmentsByGlobalId
{
    return [servicedaodelegate getallAppointmentsByGlobalId];
}
-(NSMutableArray*)getallupdatedAppointmentsByGlobalId
{
    return [servicedaodelegate getallupdatedAppointmentsByGlobalId];
}
-(void)addGlobalIdTocreatedAppointments:(AppointmentResponseDTO*)appointmentResDAO
{
    return [servicedaodelegate addGlobalIdTocreatedAppointments:appointmentResDAO];
}
- (NSMutableArray*)getAllDeletedappointmentsByGlobalId
{
    return [servicedaodelegate getAllDeletedappointmentsByGlobalId];
}
- (void)deleteAppointmentByGlobalId:(AppointmentResponseDTO*)appointmentResDAO
{
    return [servicedaodelegate deleteAppointmentByGlobalId:appointmentResDAO];
}
- (NSMutableArray*)getAllCasesByGlobalId
{
    return [servicedaodelegate getAllCasesByGlobalId];
}
- (int)getlogindetails:(DoctorDetail*)objDoctordetail
{
    return [servicedaodelegate getlogindetails:objDoctordetail];
}
-(void)updatefirstDownloadedTimeSyncTable:(NSString*)lastportalSyncTime
{
    return[servicedaodelegate updatefirstDownloadedTimeSyncTable:lastportalSyncTime];
}
-(void) addDocLoginPassword:(DoctorLoginDTO*)doctorLoginDto
{
    return [servicedaodelegate addDocLoginPassword:doctorLoginDto];
}

@end
