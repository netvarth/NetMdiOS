//
//  ScheduleDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SeriesDTO.h"
@class SeriesDTO;

@interface ScheduleDTO : NSObject

@property (nonatomic, assign)int   Id;
@property (nonatomic, assign)int   doctorId;
@property (nonatomic, assign)int   seriesId;
@property (nonatomic, assign)int   scheduleGlobalId;
@property (nonatomic, assign)int   appointmentId;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* startDate;
@property (nonatomic, strong) NSString* startTime;
@property (nonatomic, strong) NSString* endTime;
@property (nonatomic, strong) NSString* endDate;
@property (nonatomic, strong) NSString* repeat;
@property (nonatomic, assign)int  noOfOccurances;
@property (nonatomic, strong) NSString* weeklySunThruSatList;
@property (nonatomic, strong) NSString* status;
@property (nonatomic, strong) NSString* scheduleStatus;
@property(nonatomic,strong)  NSString* createdTime;
@property(nonatomic,strong)  NSString* updatedTime;
@property(nonatomic,strong) NSString* typeSchedule;
@property (nonatomic, strong)SeriesDTO* series;
@property (nonatomic, strong) NSString* docUniqueId;

@end
