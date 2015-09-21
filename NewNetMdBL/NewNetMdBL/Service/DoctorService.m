//
//  DoctorService.m
//  NetMdBL
//
//  Created by Surendar Modugu on 3/17/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "DoctorService.h"



@interface DoctorService()

@property (nonatomic, strong) DoctorValidator*  validator;

@end


@implementation DoctorService
@synthesize logindaodelegate, doctordaodelegate,scheduledaodelegate;

- (id)init {
    self    = [super init];
    if (self != nil) {
        self.validator  = [[DoctorValidator alloc] init] ;
    }
    
    return self;
}

+ (DoctorService*)sharedInstance {
    static dispatch_once_t onceToken;
    static DoctorService* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[DoctorService alloc] init];
    });
    
    return sharedInstance;
}

- (ResponseDTO*)create:(DoctorDetail*)doctor
{
    ResponseDTO* result    = [[ResponseDTO alloc] init];
    int loginId=[logindaodelegate addLoginUser:doctor.login];
    result.success = [doctordaodelegate addDoctor:doctor loginId:loginId];
    return result;
}

- (ResponseDTO*)update:(DoctorDetail*)doctor {
    ResponseDTO* result    = [[ResponseDTO alloc] init];
    [doctordaodelegate editDoctor:doctor];
    
    return result;
}

- (NSMutableArray*)getAllDoctorDeatils{
    
     return [doctordaodelegate getAllDoctorDetails];
}
- (NSMutableArray*)getAllLoginUserName
{
    return[doctordaodelegate getAllLoginUserName];
}

- (DoctorDetail*) getDoctorDeatilsByLoginId:(int)LoginId
{
    return [doctordaodelegate getDoctorDeatilsByLoginId:LoginId];
}

- (DoctorListResponse*)list:(Filter*)filter {
    DoctorListResponse* result  = [[DoctorListResponse alloc] init] ;

    //Implement code to retrieve the list of doctors
    
    return result;
}

- (NSMutableArray*)getExperiencesByDoctorId:(int)doctorId
{
    return [doctordaodelegate getExperienceByDoctorId:doctorId];
    
}

- (NSMutableArray*)getQualificationByDoctorId:(int)doctorId
{
    return [doctordaodelegate getQualificationByDoctorId:doctorId];
}

- (NSMutableArray*)getAchievementsByDoctorId:(int)doctorId
{
    return [doctordaodelegate getAchievementByDoctorId:doctorId];
}

- (NSMutableArray*)getMembershipsByDoctorId:(int)doctorId
{
    return [doctordaodelegate getMembershipByDoctorId:doctorId];
}

- (NSMutableArray*)getExpertiseByDoctorId:(int)doctorId
{
    return [doctordaodelegate getExpertiseByDoctorId:doctorId];
}

- (DoctorExperienceDTO*)getallExperiencesByDoctorId:(int)doctorId
{
    return [doctordaodelegate getallExperiencesByDoctorId:doctorId];
}
-(void)addDoctorExperience:(DoctorExperienceDTO*)experience
{
    [doctordaodelegate addDoctorExperience:experience];
}
-(void)addDoctorQualification:(DoctorQualificationDTO*)qualification
{
    [doctordaodelegate addDoctorQualification:qualification];
}
-(void)addDoctorAchievement:(DoctorAchievementDTO*)achievement
{
    [doctordaodelegate addDoctorAchievement:achievement];
}
-(void)addDoctorMembership:(DoctorMembershipDTO*)membership
{
    [doctordaodelegate addDoctorMembership:membership];
}
-(void)addDoctorExpertise:(DoctorExpertiseDTO*)expertise
{
    [doctordaodelegate addDoctorExpertise:expertise];
}


- (void)editExperienceById:(DoctorExperienceDTO*)experience
{
    [doctordaodelegate editExperienceById:experience];
}
- (void)editAchievementById:(DoctorAchievementDTO*)achievement
{
    [doctordaodelegate editAchievementById:achievement];
}

- (void)editQualificationById:(DoctorQualificationDTO*)qualification
{
    [doctordaodelegate editQualificationById:qualification];
}
- (void)editMembershipById:(DoctorMembershipDTO*)membership
{
    [doctordaodelegate editMembershipById:membership];
}
- (void)editExpertiseById:(DoctorExpertiseDTO*)expertise
{
    [doctordaodelegate editExpertiseById:expertise];
}


- (void)deleteExperienceById:(int)ExperienceId
{
    [doctordaodelegate deleteExperienceById:ExperienceId];
}
- (void)deleteQualificationById:(int)QualificationId
{
    [doctordaodelegate deleteQualificationById:QualificationId];
}
- (void)deleteAchievementById:(int)AchievementId
{
     [doctordaodelegate deleteAchievementById:AchievementId];
}
- (void)deleteMembershipById:(int)MembershipId
{
    [doctordaodelegate deleteMembershipById:MembershipId];
}
- (void)deleteExpertiseById:(int)ExpertiseId
{
    [doctordaodelegate deleteExpertiseById:ExpertiseId];
}
- (BOOL)addSchedule:(ScheduleDTO *)scheduleDto
{
    [scheduledaodelegate addSchedule:scheduleDto];
    return YES;
}
- (DoctorDetail*)addwelcomeMessage:(int)loginId
{
    return [doctordaodelegate addwelcomeMessage:loginId];
}
- (int)getlogindetails:(DoctorDetail*)objDoctordetail
{
   
    return [doctordaodelegate getlogindetails:objDoctordetail];
    
}
- (void)updateUpdatedTime:(DoctorDetail*)objdoc
{
    return [doctordaodelegate updateUpdatedTime:objdoc];
}

- (NSString*)getUniqueIdFrmDocTbl:(int)docId
{
    return [doctordaodelegate getUniqueIdFrmDocTbl:docId];
}

- (int)saveVacationToDb:(VacationSpecDTO*)vacationSpecDTO
{
    return [doctordaodelegate saveVacationToDb:vacationSpecDTO];
}


@end
