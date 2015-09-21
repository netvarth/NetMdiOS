//
//  DocDaoImpl.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 25/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "SyncableDaoImpl.h"

@implementation SyncableDaoImpl

+(SyncableDaoImpl*)sharedInstance
{
    static SyncableDaoImpl* sharedInstance;
    if (!sharedInstance) {
        sharedInstance = [[self alloc] init];
    }
    return sharedInstance;
}

-(id)init
{
    self    = [super init];
    if (self)
    {
        // Get the path to the documents directory and append the databaseName
        NSArray *documentPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        NSString *documentsDir = [documentPaths objectAtIndex:0];
        self.databasePath = [documentsDir stringByAppendingPathComponent:DATABASE_NAME];
        _dataBase = [FMDatabase databaseWithPath:self.databasePath];
        
    }
    return self;
}

-(RespDto*)addSyncableToDb:(SyncableDto*)syncableDto
{
    BOOL result = YES;
    RespDto* respDto = [[RespDto alloc] init];
    if ([_dataBase open])
    {
        
        NSLog(@"Opened database %@",self.databasePath);
        NSMutableString* destinationStr = [[NSMutableString alloc] init];
        [destinationStr appendString:syncableDto.destination.desCorporateId];
        [destinationStr appendString:@","];
        [destinationStr appendString:syncableDto.destination.desBranchId];
        [destinationStr appendString:@","];
        [destinationStr appendString:syncableDto.destination.desDeviceId];
        //NSLog(@"Destination string: ",destinationStr);
        //NSString* desStr = [NSString stringWithString:destinationStr];
        
        NSMutableString* sourceStr = [[NSMutableString alloc] init];
        [sourceStr appendString:syncableDto.source.corporateId];
        [sourceStr appendString:@","];
        [sourceStr appendString:syncableDto.source.branchId];
        [sourceStr appendString:@","];
        [sourceStr appendString:syncableDto.source.deviceId];
        //NSLog(@"Source string: ",sourceStr);
        //NSString* souStr = [NSString stringWithString:sourceStr];
        
        NSString* insertQuery = [NSString stringWithFormat:INSERT_TABLE_SYNCABLE,syncableDto.category,syncableDto.syncPriority,syncableDto.passPhrase,syncableDto.createDate,syncableDto.cloudableData,destinationStr,sourceStr];
        if (![_dataBase executeUpdate:insertQuery])
        {
            NSLog(@"Failed to insert record into the syncable_msg_tbl with Error::",_dataBase.lastErrorMessage);
            result = NO;
        }
        else
        {
            NSLog(@"Syncable inserted successfully into sync_msg_tbl table");
            respDto.tableId = [_dataBase lastInsertRowId];
        }

    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
        result = NO;
    }
    respDto.success = result;
    [_dataBase close];
    
    return respDto;
}

-(BOOL)deleteCloudAcceptedSyncable:(int) tableId
{
    BOOL success = true;
    if ([_dataBase open])
    {
        NSLog(@"Opened database at %@", self.databasePath);
        NSString* deleteQuery = [NSString stringWithFormat:DELETE_SYNCABLE_USING_ID,tableId];
        if (![_dataBase executeUpdate:deleteQuery])
        {
            NSLog(@"Deletion failed with error ::%@", _dataBase.lastErrorMessage);
        }
    }
    else
    {
        NSLog(@"Failed to load database syncable_msg_tbl with error :: %@", _dataBase.lastErrorMessage);
    }
    return success;
}

-(int)checkSyncableTblContent
{
    int count = 0;
    if ([_dataBase open])
    {
         NSLog(@"Opened database %@",self.databasePath);
        NSString* selectQuery = [NSString stringWithFormat:GET_COUNT_OF_SYNCABLE_MSG_TBL];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        while ([set next])
        {
            count = [set intForColumnIndex:0];
        }
    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }
    [_dataBase close];
    return count;
}

-(NSMutableArray*)getAllSyncableDetails
{
    NSMutableArray* allSyncableDetails = [[NSMutableArray alloc] init];
    
    if ([_dataBase open])
    {
        NSLog(@"Opened database %@",self.databasePath);
        NSString* selectQuery = [NSString stringWithFormat:SELECT_ALL_SYNCABLE_DETAILS];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        while ([set next])
        {
            SyncableDto* syncableDTO = [[SyncableDto alloc] init];
            SyncLocale* syncableLocale = [[SyncLocale alloc] init];
            SyncDesLocale* desLocale = [[SyncDesLocale alloc] init];
            
            syncableDTO.table_id = [[set stringForColumn:@"id"] intValue];
            syncableDTO.category = [set stringForColumn:@"category"];
            syncableDTO.cloudableData = [set stringForColumn:@"cloudableData"];
            syncableDTO.syncPriority = [set stringForColumn:@"syncPriority"];
            syncableDTO.passPhrase = [set stringForColumn:@"passPhrase"];
            syncableDTO.createDate = [set stringForColumn:@"createDate"];
            NSString* source = [set stringForColumn:@"source"];
            NSMutableArray* array = [source componentsSeparatedByString:@","];
            syncableLocale.corporateId = [array objectAtIndex:0];
            syncableLocale.branchId = [array objectAtIndex:1];
            syncableLocale.deviceId = [array objectAtIndex:2];
            syncableDTO.source = syncableLocale;
            NSString* destination = [set stringForColumn:@"destination"];
            NSMutableArray* dest = [destination componentsSeparatedByString:@","];
            desLocale.desCorporateId = [dest objectAtIndex:0];
            desLocale.desBranchId = [dest objectAtIndex:1];
            desLocale.desDeviceId = @"";
            syncableDTO.destination = desLocale;
            [allSyncableDetails addObject:syncableDTO];
            
        }
    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }
    [_dataBase close];
    return allSyncableDetails;
}

@end
