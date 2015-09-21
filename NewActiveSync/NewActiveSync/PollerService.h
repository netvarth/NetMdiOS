//
//  PollerService.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 04/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PollerDaoImpl.h"
//#import "SyncLocale.h"

@interface PollerService : NSObject

//@property(nonatomic,strong)id<PollerDaoDelegate>pollerDaoDelegate;

+(PollerService*)sharedInstance;
-(int)getPollerStatustblCount;
-(BOOL)saveLocaleToPollerStatusTbl:(SyncLocale*)syncLocale;
-(NSString*)getCorporateId;
-(NSString*)getBranchId;
-(NSString*)getDeviceId;
-(NSString*)getLastUpdatedTime;
-(BOOL)updateLstUpdatedTime:(NSString*)time;


@end
