//
//  ServerService.h
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 14/05/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ServiceDao.h"
#import "DoctorDao.h"
#import "SeriesDTO.h"
#import "DoctorResponse.h"
#import "ScheduleResponse.h"
#import "PatientResponse.h"
#import "AppointmentResponseDTO.h"
#import "DoctorLoginDTO.h"

@interface ServerService : NSObject

@property (nonatomic,strong) id<ServiceDaoDelegate> servicedaodelegate;
+ (ServerService*)sharedInstance;


-(NSString*)getSynctable;
-(void)updateUploadedTimeSyncTable:(NSString*)lastSyncTime;
-(void)updateDownloadedTimeSyncTable:(NSString*)lastportalSyncTime;
-(void)addGlobalIdToCreatedDoctors:(DoctorResponse*)doctorResDAO;
- (NSMutableArray*) getAllUnsynchedDoctorDeatilsWithGlobalId;
- (NSMutableArray*)getAllDoctorExperienceByGlobalId:(int)doctorId;
- (NSMutableArray*)getAllDoctorQualificationsByGlobalId:(int)doctorId;
- (NSMutableArray*)getAllDoctorAchievementsByGlobalId:(int)doctorId;
- (NSMutableArray*)getAllDoctorMembershipsByGlobalId:(int)doctorId;
- (NSMutableArray*)getAllDoctorExpertiseByGlobalId:(int)doctorId;
- (NSMutableArray*) getAllUpdatedDoctorDeatilsWithGlobalId;
- (NSMutableArray*)getAllUpdatedDoctorExperienceByGlobalId:(int)doctorId;
- (NSMutableArray*)getAllUpdatedDoctorQualificationsByGlobalId:(int)doctorId;
- (NSMutableArray*)getAllUpdatedDoctorAchievementsByGlobalId:(int)doctorId;
- (NSMutableArray*)getAllUpdatedDoctorMembershipsByGlobalId:(int)doctorId;
- (NSMutableArray*)getAllUpdatedDoctorExpertiseByGlobalId:(int)doctorId;
- (NSMutableArray*)getAllschedulesByGlobalId;
- (SeriesDTO*)getSeriesBySeriesId:(int)seriesId;
- (void)addGlobalIdTocreatedSchedules:(ScheduleResponse*)scheduleResDAO;
- (void)addGlobalIdTocreatedSeries:(ScheduleResponse*)scheduleResDAO;
- (NSMutableArray*)getAllDeletedschedulesByGlobalId;
- (void)deleteschedule:(ScheduleResponse*)scheduleResDAO;
- (void)deleteseries:(ScheduleResponse*)scheduleResDAO;
- (NSMutableArray*)getallpatientsWithGlobalId;
- (NSMutableArray*)getallUpdatedPatientsWithGlobalId;
-(void)addGlobalIdTocreatedPatients:(PatientResponse*)patientResDAO;
-(NSMutableArray*)getallAppointmentsByGlobalId;
-(NSMutableArray*)getallupdatedAppointmentsByGlobalId;
-(void)addGlobalIdTocreatedAppointments:(AppointmentResponseDTO*)appointmentResDAO;
- (NSMutableArray*)getAllDeletedappointmentsByGlobalId;
- (void)deleteAppointmentByGlobalId:(AppointmentResponseDTO*)appointmentResDAO;
- (NSMutableArray*)getAllCasesByGlobalId;
- (int)getlogindetails:(DoctorDetail*)objDoctordetail;
-(void)updatefirstDownloadedTimeSyncTable:(NSString*)lastportalSyncTime;

-(void) addDocLoginPassword:(DoctorLoginDTO*)doctorLoginDto;

@end
