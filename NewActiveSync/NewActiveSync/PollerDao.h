//
//  PollerDao.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 04/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//


#import <Foundation/Foundation.h>

@class SyncLocale;

@protocol PollerDaoDelegate <NSObject>

-(BOOL)saveLocaleToPollerStatusTbl:(SyncLocale*)syncLocale;
-(int)getPollerStatustblCount;
-(NSString*)getCorporateId;
-(NSString*)getBranchId;
-(NSString*)getDeviceId;
-(NSString*)getLastUpdatedTime;
-(BOOL)updateLstUpdatedTime:(NSString*)time;

@end

@interface PollerDao : NSObject

@end
