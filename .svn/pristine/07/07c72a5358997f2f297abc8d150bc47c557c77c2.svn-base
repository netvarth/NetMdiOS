//
//  PollerService.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 04/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "PollerService.h"

@implementation PollerService

+(PollerService*)sharedInstance
{
    static PollerService* sharedInstance;
    if (!sharedInstance)
    {
        sharedInstance = [[self alloc] init];
    }
    return sharedInstance;
}


-(int)getPollerStatustblCount
{
    return [[PollerDaoImpl sharedInstance] getPollerStatustblCount];
}

-(BOOL)saveLocaleToPollerStatusTbl:(SyncLocale*)syncLocale
{
    return [[PollerDaoImpl sharedInstance] saveLocaleToPollerStatusTbl:syncLocale];
}

-(NSString*)getCorporateId
{
    return [[PollerDaoImpl sharedInstance] getCorporateId];
}
-(NSString*)getBranchId
{
    return [[PollerDaoImpl sharedInstance] getBranchId];
    
}
-(NSString*)getDeviceId
{
    return [[PollerDaoImpl sharedInstance] getDeviceId];
}

-(NSString*)getLastUpdatedTime
{
    return [[PollerDaoImpl sharedInstance] getLastUpdatedTime];
}

-(BOOL)updateLstUpdatedTime:(NSString*)time
{
    return [[PollerDaoImpl sharedInstance] updateLstUpdatedTime:time];
}
@end
