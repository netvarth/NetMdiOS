//
//  ScheduleDao.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/23/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ScheduleDTO.h"
#import "SeriesDTO.h"
#import "DoctorDetail.h"
#import "DocScheduleDTO.h"
#import "TimeSpecDTO.h"

@protocol ScheduleDao <NSObject>

- (BOOL)addSchedule:(ScheduleDTO *)scheduleDAO;
- (NSMutableArray*)getAllSchedules;
- (void)deleteScheduleById:(int) scheduleId;
- (BOOL)addSeries:(SeriesDTO *)seriesDAO;
- (int)getLastSeriesId;
- (NSMutableArray*) getAllSchedulesByDoctorId:(int)doctorId;

- (int)getSeriesIdByScheduleId:(int)scheduleId;
- (void)deleteFutureSchedulesBySeriesId:(int)seriesId ScheduleId:(int) scheduleId;
- (NSString*)GetthelatestScheduledate;
- (void)updateEnddateInSeriesTable:(NSString*)Enddate sId:(int)seriesId;
- (void)updateWeeklyTypeInSeriesTable:(NSString*)weeklyType;
- (BOOL)checkScheduleExist:(ScheduleDTO*)objScheduleDTO;
- (NSMutableArray*)getAllcurrentandUpcomingSchedulesByDoctorId:(int)doctorId currentdate:(NSString*)Date;
- (NSMutableArray*)AllseriesBySeriesId:(int)seriesId;
-(NSMutableArray*)getScheduleforseries:(int)seriesid;
-(void)deleteSchedulesBySeriesId:(int)seriesId;
- (int)getlogindetails:(DoctorDetail*)objDoctordetail;

//

-(int)saveDocScheduleToDb:(DocScheduleDTO*)docScheduleDto;
-(BOOL)saveTimeSpecToDb:(TimeSpecDTO*)timeSpecDto;
-(NSMutableArray*)getAllTimeSpecList;
-(NSMutableArray*)getAllDocIdFromDocScheduleTbl;
-(int)getTableId:(NSString*)timeSpec withDocId:(int)docId;
-(BOOL)updateTimeSpectbl:(NSString*)newTimeSpec withId:(int)tblId;

@end
