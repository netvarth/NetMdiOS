//
//  AppCommunicator.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 25/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "SyncableDto.h"
//#import "SyncableDaoImpl.h"
//#import "SyncDao.h"
//#import "SyncLocale.h"
#import "SyncableService.h"
#import "PollerService.h"
#import "PollerDaoImpl.h"
#import "SyncableDaoImpl.h"
#import "PollerResponseDaoImpl.h"
#import "PollerResponseService.h"
#import "ThreadActivator.h"
#import "ThreadsDeActivator.h"
#import "PollerRespDelegate.h"

@interface AppCommunicator : NSObject

@property(nonatomic,strong) id<PollerRespDelegate>pollerRespDelegate;

+(AppCommunicator*)sharedInstance;
-(void)setSyncable:(SyncableDto*)syncableDto;
-(BOOL)saveLocaleToPollerStatusTbl:(SyncLocale*)syncLocale;
-(int)getPollerStatustblCount;
-(NSMutableDictionary*)getRawDataFromSyncAgent;
-(void)passResponseToSyncAgent:(NSMutableDictionary*)dictionary;
-(void)activateSyncAgentThreads;
-(void)deactivateSyncAgentThreads;
-(int)checkSyncableTblContent;
-(void)getAllSyncableDetails;
-(void)alertNetMd;

@end
