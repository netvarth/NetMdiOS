//
//  TimeSlotDTO.h
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 03/03/15.
//  Copyright (c) 2015 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TimeSpecDTO : NSObject

@property(nonatomic,strong) NSMutableArray* timeSpec;
@property(nonatomic,assign) int scheduleId;
@property(nonatomic,strong) NSString* facility;

@end
