//
//  SyncableService.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 04/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "SyncableService.h"

@implementation SyncableService

+(SyncableService*)sharedInsatnce
{
    static SyncableService* sharedinsatnce;
    if (!sharedinsatnce)
    {
        sharedinsatnce = [[self alloc] init];
    }
    return sharedinsatnce;
}

-(void)addSyncableToDb:(SyncableDto*)syncableDto
{
    //SyncableDto* syncDto = [[syncable]];
    //syncDto = syncableDto;
    RespDto* respDto = [[RespDto alloc] init];
    SyncableDto* dto = [[SyncableDto alloc] init];
    //respDto = [_syncDaoDelegate addSyncableToDb:syncableDto];
    respDto = [[SyncableDaoImpl sharedInstance] addSyncableToDb:syncableDto];
    if (respDto.success)
    {
        //dto.source = syncableDto.source;
        //dto.cloudableData = syncableDto.cloudableData;
        
        syncableDto.table_id = respDto.tableId;
        [self placeSyncableToQueue:syncableDto];
        
    }
}

-(void)placeSyncableToQueue:(id)syncableDto
    {
        NSLog(@"Placing Data to Queue");
        [CustomQueue sharedInstance];
        id obj;
        obj = syncableDto;
        
        [[CustomQueue sharedInstance] enqueueData:obj];
    }

-(BOOL)deleteCloudAcceptedSyncable:(int) tableId
{
    //return [_syncDaoDelegate deleteCloudAcceptedSyncable:tableId];
    return [[SyncableDaoImpl sharedInstance] deleteCloudAcceptedSyncable:tableId];
}

-(int)checkSyncableTblContent
{
    //return [_syncDaoDelegate checkSyncableTblContent];
    return [[SyncableDaoImpl sharedInstance] checkSyncableTblContent];
}
-(void)getAllSyncableDetails
{
    //NSMutableArray* syncList = [_syncDaoDelegate getAllSyncableDetails];
    NSMutableArray* syncList = [[SyncableDaoImpl sharedInstance] getAllSyncableDetails];
    for(SyncableDto* dto in syncList)
    {
        [self placeSyncableToQueue:dto];
    }
}

@end
