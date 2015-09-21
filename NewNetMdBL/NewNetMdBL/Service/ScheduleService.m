//
//  ScheduleService.m
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/26/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "ScheduleService.h"

@implementation ScheduleService
@synthesize scheduledaodelegate;

+ (ScheduleService*)sharedInstance
{
    static dispatch_once_t onceToken;
    static ScheduleService* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[ScheduleService alloc] init];
    });
    
    return sharedInstance;
}


- (BOOL)addSchedule:(ScheduleDTO *)scheduleDto
{
    return [scheduledaodelegate addSchedule:scheduleDto];
    
}

- (NSMutableArray*)getAllSchedules
{
   return  [scheduledaodelegate getAllSchedules];
}

- (void)deleteScheduleById:(int) ScheduleId;
{
    [scheduledaodelegate deleteScheduleById:ScheduleId];
}

- (BOOL)addSeries:(SeriesDTO *)seriesDto
{
    return [scheduledaodelegate addSeries:seriesDto];
}

- (int)getLastSeriesId
{
    return [scheduledaodelegate getLastSeriesId];
}
- (NSMutableArray*) getAllSchedulesByDoctorId:(int)doctorId;
{
    return [scheduledaodelegate getAllSchedulesByDoctorId:doctorId];
}

- (void)deleteAllSchedulesInSeriesIdOfThisSchedule:(int)ScheduleId
{
    int seriesId=[scheduledaodelegate getSeriesIdByScheduleId:ScheduleId];
    [scheduledaodelegate deleteSchedulesBySeriesId:seriesId];
}

- (void)deleteFutureSchedulesInSeriesIdOfThisSchedule:(int)scheduleId
{
    int seriesId=[scheduledaodelegate getSeriesIdByScheduleId:scheduleId];
    [scheduledaodelegate deleteFutureSchedulesBySeriesId:seriesId ScheduleId:scheduleId];
}
- (NSString*)GetthelatestScheduledate
{
    return [scheduledaodelegate GetthelatestScheduledate];
}
- (void)updateEnddateInSeriesTable:(NSString*)Enddate sId:(int)seriesId
{
    [scheduledaodelegate updateEnddateInSeriesTable:Enddate sId:seriesId];
}
- (void)updateWeeklyTypeInSeriesTable:(NSString*)weeklyType;
{
    [scheduledaodelegate updateWeeklyTypeInSeriesTable:weeklyType];
}
- (BOOL)checkScheduleExist:(ScheduleDTO*)objScheduleDTO
{
    return [scheduledaodelegate checkScheduleExist:(ScheduleDTO*)objScheduleDTO];
}
- (NSMutableArray*)getAllcurrentandUpcomingSchedulesByDoctorId:(int)doctorId currentdate:(NSString*)Date;{
    return [scheduledaodelegate getAllcurrentandUpcomingSchedulesByDoctorId:doctorId currentdate:Date];
}
-(NSMutableArray*)getScheduleforseries:(int)seriesid
{
    return [scheduledaodelegate getScheduleforseries:seriesid];
}
-(int)getlogindetails:(DoctorDetail*)objDoctordetail
{
    return [scheduledaodelegate getlogindetails:objDoctordetail];
}

-(BOOL)saveDocScheduleToDb:(DocScheduleDTO*)docScheduleDto
{
    return [scheduledaodelegate saveDocScheduleToDb:docScheduleDto];
}

-(int)saveTimeSpecToDb:(TimeSpecDTO*)timeSpecDto
{
    return [scheduledaodelegate saveTimeSpecToDb:timeSpecDto];
}

-(NSMutableArray*)getAllTimeSpecList
{
    return [scheduledaodelegate getAllTimeSpecList];
}

-(NSMutableArray*)getAllDocIdFromDocScheduleTbl
{
    return [scheduledaodelegate getAllDocIdFromDocScheduleTbl];
}

-(int)getTableId:(NSString*)timeSpec withDocId:(int)docId
{
    return [scheduledaodelegate getTableId:timeSpec withDocId:docId];
}

-(BOOL)updateTimeSpectbl:(NSString*)newTimeSpec withId:(int)tblId
{
    return [scheduledaodelegate updateTimeSpectbl:newTimeSpec withId:tblId];
}

@end
