//
//  ViewScheduleDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ViewScheduleDTO : NSObject

@property (nonatomic, assign)int   Id;
@property (nonatomic, assign)int   doctorId;
@property (nonatomic, assign)int   seriesId;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* startDate;
@property (nonatomic, strong) NSString* startTime;
@property (nonatomic, strong) NSString* endTime;
@property (nonatomic, strong) NSString* status;
@property (nonatomic, strong) NSString* endDate;
@property (nonatomic, strong) NSString* occuranceType;
@property (nonatomic, strong) NSString* repeat;
@property (nonatomic, assign)int   endsOn;
@property (nonatomic, strong) NSArray* weeklySunThruSatList;






@end
