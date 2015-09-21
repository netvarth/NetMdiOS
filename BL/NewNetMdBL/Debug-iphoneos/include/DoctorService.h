//
//  DoctorService.h
//  NetMdBL
//
//  Created by Surendar Modugu on 3/17/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DoctorDetail.h"
#import "DoctorListResponse.h"
#import "Filter.h"
#import "ResponseDTO.h"
#import "LoginDao.h"
#import "DoctorDao.h"
#import "DoctorAchievementDTO.h"
#import "DoctorExperienceDTO.h"
#import "DoctorExpertiseDTO.h"
#import "DoctorMembershipDTO.h"
#import "DoctorQualificationDTO.h"
#import "DoctorValidator.h"
#import "ScheduleDao.h"
#import "ScheduleDTO.h"
#import "CurrentUserDTO.h"




@interface DoctorService : NSObject


@property (nonatomic,strong) id<LoginDao> logindaodelegate;
@property (nonatomic, strong) id<DoctorDao> doctordaodelegate;
@property (nonatomic, strong) id<ScheduleDao> scheduledaodelegate;


+ (DoctorService*)sharedInstance;

- (ResponseDTO*)create:(DoctorDetail*)doctor;

- (ResponseDTO*)update:(DoctorDetail*)doctor;
- (NSMutableArray*) getAllDoctorDeatils;
- (NSMutableArray*)getAllLoginUserName;

- (DoctorDetail*) getDoctorDeatilsByLoginId:(int)LoginId;
- (DoctorListResponse*)list:(Filter*)filter;
//- (ResponseDTO*)validateQualification:(DoctorQualificationDTO*)qualification;
//- (ResponseDTO*)validateAchievement:(DoctorAchievementDTO*)achievement;
//- (ResponseDTO*)validateExperience:(DoctorExperienceDTO*)experience;
//- (ResponseDTO*)validateExpertise:(DoctorExpertiseDTO*)expertise;
//- (ResponseDTO*)validateMembdership:(DoctorMembershipDTO*)membership;

- (NSMutableArray*)getExperiencesByDoctorId:(int)doctorId;
- (NSMutableArray*)getQualificationByDoctorId:(int)doctorId;
- (NSMutableArray*)getAchievementsByDoctorId:(int)doctorId;
- (NSMutableArray*)getMembershipsByDoctorId:(int)doctorId;
- (NSMutableArray*)getExpertiseByDoctorId:(int)doctorId;

- (DoctorExperienceDTO*)getallExperiencesByDoctorId:(int)doctorId;

-(void)addDoctorExperience:(DoctorExperienceDTO*)experience;
-(void)addDoctorQualification:(DoctorQualificationDTO*)qualification;
-(void)addDoctorAchievement:(DoctorAchievementDTO*)achievement;
-(void)addDoctorMembership:(DoctorMembershipDTO*)membership;
-(void)addDoctorExpertise:(DoctorExpertiseDTO*)expertise;

- (void)editExperienceById:(DoctorExperienceDTO*)experience;
- (void)editAchievementById:(DoctorAchievementDTO*)achievement;
- (void)editQualificationById:(DoctorQualificationDTO*)qualification;
- (void)editMembershipById:(DoctorMembershipDTO*)membership;
- (void)editExpertiseById:(DoctorExpertiseDTO*)expertise;

- (void)deleteExperienceById:(int)ExperienceId;
- (void)deleteQualificationById:(int)QualificationId;
- (void)deleteAchievementById:(int)AchievementId;
- (void)deleteMembershipById:(int)MembershipId;
- (void)deleteExpertiseById:(int)ExpertiseId;

- (BOOL)addSchedule:(ScheduleDTO *)scheduleDto;

- (DoctorDetail*)addwelcomeMessage:(int)loginId;
- (int)getlogindetails:(DoctorDetail*)objDoctordetail;
- (void)updateUpdatedTime:(DoctorDetail*)objdoc;
- (NSString*)getUniqueIdFrmDocTbl:(int)docId;
- (BOOL)saveVacationToDb:(VacationSpecDTO*)vacationSpecDTO;






@end
