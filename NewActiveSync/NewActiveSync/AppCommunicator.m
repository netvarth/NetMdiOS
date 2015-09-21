//
//  AppCommunicator.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 25/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "AppCommunicator.h"

@implementation AppCommunicator


+(AppCommunicator*)sharedInstance
{
    static AppCommunicator* sharedInstane;
    if (!sharedInstane) {
        sharedInstane = [[self alloc] init];
        //[sharedInstane setDaoDelegate];
    }
    return sharedInstane;
}

/*
-(void)setDaoDelegate
{
    SyncableDaoImpl* syncableDaoImpl = [[SyncableDaoImpl alloc] init];
    PollerDaoImpl* pollerDaoImpl = [[PollerDaoImpl alloc] init];
    PollerResponseDaoImpl* pollerResponseDaoImpl = [[PollerResponseDaoImpl alloc] init];
    [SyncableService sharedInsatnce].syncDaoDelegate = syncableDaoImpl;
    [PollerService sharedInstance].pollerDaoDelegate = pollerDaoImpl;
    [PollerResponseService sharedInstance].pollerResponseDaoDelegate = pollerResponseDaoImpl;
}
*/

-(void)setSyncable:(SyncableDto*)syncableDto
{
    NSLog(@"Got syncable from the application");
    [[SyncableService sharedInsatnce] addSyncableToDb:syncableDto];
    
}


-(int)getPollerStatustblCount
{
    return [[PollerService sharedInstance] getPollerStatustblCount];
}

-(BOOL)saveLocaleToPollerStatusTbl:(SyncLocale*)syncLocale
{
    NSLog(@"Got Locale from app");
    return [[PollerService sharedInstance] saveLocaleToPollerStatusTbl:syncLocale];
}

-(NSMutableDictionary*)getRawDataFromSyncAgent
{
    return [[PollerResponseService sharedInstance] getRawDataFromSyncAgent];
}

-(void)passResponseToSyncAgent:(NSMutableDictionary*)dictionary
{
  [[PollerResponseService sharedInstance] passResponseToSyncAgent:dictionary];
}

-(void)activateSyncAgentThreads
{
    [[ThreadActivator sharedInstance] loadThreads];
}

-(void)deactivateSyncAgentThreads
{
    [[ThreadsDeActivator sharedInstance] deactivateSyncAgentThreads];
}

-(int)checkSyncableTblContent
{
    return [[SyncableService sharedInsatnce] checkSyncableTblContent];
}

-(void)getAllSyncableDetails
{
    [[SyncableService sharedInsatnce] getAllSyncableDetails];
}

-(void)alertNetMd
{
    _pollerRespDelegate.alertNetMd;
}
@end
