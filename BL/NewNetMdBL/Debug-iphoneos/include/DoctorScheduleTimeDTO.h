//
//  DoctorScheduleTimeDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DoctorScheduleTimeDTO : NSObject

@property (nonatomic, strong) NSDate* startDate;
@property (nonatomic, strong) NSDate* endingTime;
@property (nonatomic, strong) NSDate* startingTime;

@end
