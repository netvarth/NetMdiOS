//
//  PollerResponseService.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 10/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "PollerResponseService.h"

@implementation PollerResponseService

+(PollerResponseService*)sharedInstance
{
    static PollerResponseService* sharedInstance;
    if (!sharedInstance)
    {
        sharedInstance = [[self alloc] init];
    }
    return sharedInstance;
}

-(BOOL)savePollerResponseToDb:(PollerResponseDto*)pollerRespDto
{
    return [[PollerResponseDaoImpl sharedInstance] savePollerResponseToDb:pollerRespDto];
}

-(NSMutableDictionary*)getRawDataFromSyncAgent
{
    return [[PollerResponseDaoImpl sharedInstance] getRawDataFromSyncAgent];
}

-(void)passResponseToSyncAgent:(NSMutableDictionary*)dictionary
{
    [[PollerResponseDaoImpl sharedInstance] passResponseToSyncAgent:dictionary];
}

@end
