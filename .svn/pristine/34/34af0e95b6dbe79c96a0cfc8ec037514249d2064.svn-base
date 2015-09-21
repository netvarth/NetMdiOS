//
//  PollerDaoImpl.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 04/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "PollerDaoImpl.h"

@implementation PollerDaoImpl

+(PollerDaoImpl*)sharedInstance
{
    static PollerDaoImpl* sharedInstance;
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

-(BOOL)saveLocaleToPollerStatusTbl:(SyncLocale*)syncLocale
{
    BOOL result = YES;
    
    if ([_dataBase open])
    {
        NSLog(@"Opened database %@",self.databasePath);
        NSString* insertQuery = [NSString stringWithFormat:INSERT_POLLER_STATUS_TBL,syncLocale.corporateId,syncLocale.branchId,syncLocale.deviceId];
        if (![_dataBase executeUpdate:insertQuery])
        {
            NSLog(@"Failed to insert record into the poller_status_tbl with Error::",_dataBase.lastErrorMessage);
            result = NO;

        }
    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
        result = NO;
    }
    
    [_dataBase close];
    return result;
}

-(int)getPollerStatustblCount
{
    int count = 0;
    
    if ([_dataBase open])
    {
        NSLog(@"Opened database %@",self.databasePath);
        NSString* selectQuery = [NSString stringWithFormat:GET_COUNT_OF_POLLER_STATUS_TBL];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        while ([set next]) {
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

-(NSString*)getCorporateId
{
    NSString* corporateId;
    
    if ([_dataBase open])
    {
        NSLog(@"Opened database %@",self.databasePath);
        NSString* selectQuery = [NSString stringWithFormat:SELECT_CORPORATEID];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        if ([set next])
        {
            corporateId = [set stringForColumn:@"corporate_id"];
        }
        
        [set close];
    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }

    
    [_dataBase close];
    return corporateId;

}

-(NSString*)getBranchId
{
    NSString* branchId;
    
    if ([_dataBase open])
    {
        NSLog(@"Opened database %@",self.databasePath);
        NSString* selectQuery = [NSString stringWithFormat:SELECT_BRANCHID];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        if ([set next])
        {
            branchId = [set stringForColumn:@"branch_id"];
        }
        
        [set close];
    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }

    [_dataBase close];
    return branchId;
    
}
-(NSString*)getDeviceId
{
     NSString* deviceId;
    if ([_dataBase open])
    {
        NSLog(@"Opened database %@",self.databasePath);
        NSString* selectQuery = [NSString stringWithFormat:SELECT_DEVICEID];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        if ([set next])
        {
            deviceId = [set stringForColumn:@"device_id"];
        }
        
        [set close];
    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }
    
    [_dataBase close];
    return deviceId;
}

-(NSString*)getLastUpdatedTime
{
    NSString* lastUpdatedtime;
    
    if ([_dataBase open])
    {
        NSLog(@"Opened database %@",self.databasePath);
        NSString* selectQuery = [NSString stringWithFormat:SELECT_LASTUPDATEDTIME];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        if ([set next])
        {
            lastUpdatedtime = [set stringForColumn:@"lastUpdatedTime"];
        }
        [set close];
    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }

    [_dataBase close];
    return lastUpdatedtime;
}

-(BOOL)updateLstUpdatedTime:(NSString*)time
{
    BOOL success = YES;
    if([_dataBase open])
    {
        NSLog(@"Opened database %@",self.databasePath);
        NSString* updateQuery = [NSString stringWithFormat:UPDATE_TIME,time,1];
        if (![_dataBase executeUpdate:updateQuery]) {
            NSLog(@"Failed to update lastUpdatedTime Error::%@",_dataBase.lastErrorMessage);
            success = NO;
    }
    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
        success = NO;
    }
    
    [_dataBase close];
    return success;
}

@end
