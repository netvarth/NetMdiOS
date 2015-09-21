//
//  ScheduleService.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/26/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ScheduleDao.h"
#import "DoctorDetail.h"

@interface ScheduleService : NSObject

@property (nonatomic, strong) id<ScheduleDao> scheduledaodelegate;

+ (ScheduleService*)sharedInstance;
- (BOOL)addSchedule:(ScheduleDTO *)scheduleDto;
- (NSMutableArray*)getAllSchedules;
- (void)deleteScheduleById:(int) scheduleId;
- (BOOL)addSeries:(SeriesDTO *)seriesDto;
- (int)getLastSeriesId;
- (NSMutableArray*) getAllSchedulesByDoctorId:(int)doctorId;

- (void)deleteAllSchedulesInSeriesIdOfThisSchedule:(int)scheduleId;

- (void)deleteFutureSchedulesInSeriesIdOfThisSchedule:(int)scheduleId;
- (NSString*)GetthelatestScheduledate;
- (void)updateEnddateInSeriesTable:(NSString*)Enddate sId:(int)seriesId;
- (void)updateWeeklyTypeInSeriesTable:(NSString*)weeklyType;
- (BOOL)checkScheduleExist:(ScheduleDTO*)objScheduleDTO;

- (NSMutableArray*)getAllcurrentandUpcomingSchedulesByDoctorId:(int)doctorId currentdate:(NSString*)Date;
- (NSMutableArray*)AllseriesBySeriesId:(int)seriesId;
-(NSMutableArray*)getScheduleforseries:(int)seriesid;
- (void)deleteSchedulesBySeriesId:(int)seriesId;
- (int)getlogindetails:(DoctorDetail*)objDoctordetail;
//
-(int)saveDocScheduleToDb:(DocScheduleDTO*)docScheduleDto;
-(BOOL)saveTimeSpecToDb:(TimeSpecDTO*)timeSpecDto;
-(NSMutableArray*)getAllTimeSpecList;
-(NSMutableArray*)getAllDocIdFromDocScheduleTbl;
-(int)getTableId:(NSString*)timeSpec withDocId:(int)docId;
-(BOOL)updateTimeSpectbl:(NSString*)newTimeSpec withId:(int)tblId;


@end
