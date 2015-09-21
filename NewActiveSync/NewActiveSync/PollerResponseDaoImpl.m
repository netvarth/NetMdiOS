//
//  PollerResponseDaoImpl.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 10/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "PollerResponseDaoImpl.h"

@implementation PollerResponseDaoImpl

+(PollerResponseDaoImpl*)sharedInstance
{
    static PollerResponseDaoImpl* sharedInstance;
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

-(BOOL)savePollerResponseToDb:(PollerResponseDto*)pollerRespDto
{
    
    BOOL success = YES;
    if([_dataBase open])
    {
      NSLog(@"Opened database %@",self.databasePath);
      NSString* insertQuery = [NSString stringWithFormat:INSERT_TABLE_POLLER_RESPONSE_TBL,pollerRespDto.cloudableDataCategory,pollerRespDto.syncPriority,pollerRespDto.passPhrase,pollerRespDto.cloudableData,pollerRespDto.createdDateTime,pollerRespDto.syncMsgStatus,pollerRespDto.destination];
        
        if (![_dataBase executeUpdate:insertQuery])
        {
            NSLog(@"Failed to insert record into the poller_response_tbl with Error::",_dataBase.lastErrorMessage);
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

-(NSMutableDictionary*)getRawDataFromSyncAgent
{
    NSMutableDictionary* syncListDict = [[NSMutableDictionary alloc] init];
    NSMutableArray* syncListArray = [[NSMutableArray alloc] init];
    if([_dataBase open])
    {
        
        NSLog(@"Opened database %@",self.databasePath);
        NSString* insertQuery = @"SELECT * FROM poller_response_tbl";
        FMResultSet *resultSet = [_dataBase executeQuery:insertQuery];
        while ([resultSet next])
        {
            
            NSMutableDictionary* syncList = [[NSMutableDictionary alloc] init];
            int tblId = [resultSet intForColumn:@"id"];
            NSString* category = [resultSet stringForColumn:@"cloudable_data_category"];
            NSString* cloudableData = [resultSet stringForColumn:@"cloudable_data"];
            NSString* created_Date_Time = [resultSet stringForColumn:@"created_date_time"];
            [syncList setObject:[NSString stringWithFormat:@"%d",tblId] forKey:@"id"];
            [syncList setObject:category forKey:@"category"];
            [syncList setObject:cloudableData forKey:@"cloudableData"];
            [syncList setObject:created_Date_Time forKey:@"createdDateTime"];
            [syncListArray addObject:syncList];
        }
    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }
    
    [_dataBase close];
    [syncListDict setObject:syncListArray forKey:@"syncList"];
    NSLog(@"%@",syncListDict);
    
    return syncListDict;
}

-(void)passResponseToSyncAgent:(NSMutableDictionary*)dictionary
{
    NSMutableArray* responseList = [[NSMutableArray alloc] init];
    responseList = [dictionary valueForKey:@"response"];
    
    if ([_dataBase open])
    {
        NSLog(@"Opened database %@",self.databasePath);
        for(NSArray* array in responseList)
        {
            if ([array valueForKey:@"success"])
            {
                //code to delete the data by id
                int tblId = [[array valueForKey:@"id"] intValue];
                NSString* deleteQuery = [NSString stringWithFormat:DELETE_DATA_BY_ID,tblId];
                if (![_dataBase executeUpdate:deleteQuery])
                {
                    NSLog(@"Deletion failed with error ::%@", _dataBase.lastErrorMessage);
                }

            }
        }
    }
    else
    {
         NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }
    [_dataBase close];
}
@end
