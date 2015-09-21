//
//  DoctorDao.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/16/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DoctorDetail.h"
#import "DoctorExperienceDTO.h"
#import "DoctorExpertiseDTO.h"
#import "DoctorAchievementDTO.h"
#import "DoctorMembershipDTO.h"
#import "DoctorQualificationDTO.h"
#import "CurrentUserDTO.h"
#import "VacationSpecDTO.h"
#import "EmployeeVacation.h"

@protocol DoctorDao <NSObject>

- (BOOL)addDoctor:(DoctorDetail*)doctorDAO loginId:(int)loginId;
- (BOOL)editDoctor:(DoctorDetail*)doctorDAO;
- (NSMutableArray*)getAllDoctorDetails;
- (NSMutableArray*)getAllLoginUserName;
- (DoctorDetail*) getDoctorDeatilsByLoginId:(int)LoginId;


- (NSMutableArray*)getExperienceByDoctorId:(int)doctorId;
- (NSMutableArray*)getQualificationByDoctorId:(int)doctorId;
- (NSMutableArray*)getAchievementByDoctorId:(int)doctorId;
- (NSMutableArray*)getMembershipByDoctorId:(int)doctorId;
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
- (DoctorDetail*)addwelcomeMessage:(int)loginId;
- (int)getlogindetails:(DoctorDetail*)objDoctordetail;
- (void)updateUpdatedTime:(DoctorDetail*)objdoc;
- (NSString*)getUniqueIdFrmDocTbl:(int)docId;
- (int)saveVacationToDb:(VacationSpecDTO*)vacationSpecDTO;

@end
