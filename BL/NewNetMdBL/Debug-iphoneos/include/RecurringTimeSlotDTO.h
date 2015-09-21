//
//  TimeSpecDTO.h
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 20/02/15.
//  Copyright (c) 2015 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RecurringTimeSlotDTO : NSObject

//@property(nonatomic,assign) int doctorId;
//@property(nonatomic,strong) NSString* startingDate;
//@property(nonatomic,strong) NSString* facility;
@property(nonatomic,strong) NSString* startingDate;
@property(nonatomic,strong) NSString* endingDate;
@property(nonatomic,strong) NSString* startingTime;
@property(nonatomic,strong) NSString* endingTime;
@property(nonatomic,strong) NSString* timeSpecPattern;
@property(nonatomic,strong) NSString* timeSpecOccPattern;
@property(assign) int occuranceCount;
@property(nonatomic,assign) NSMutableArray* days;
@property(assign) int dayOrdinal;
@property(nonatomic,strong) NSString* monthlyDate;


@end
