//
//  ScheduleDetail.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SeriesDTO.h"

@interface ScheduleDetail : NSObject

@property (nonatomic, assign)int   Id;
@property (nonatomic, assign)int   doctorGlobalId;
@property (nonatomic, strong) SeriesDTO* series;
@property (nonatomic, strong) NSString* startDate;
@property (nonatomic, strong) NSString* startTime;
@property (nonatomic, strong) NSString* endTime;
@property (nonatomic, strong) NSString* scheduleStatus;
@property (nonatomic, assign)int   scheduleGlobalId;
@property (nonatomic, strong) NSString* status;

@end
