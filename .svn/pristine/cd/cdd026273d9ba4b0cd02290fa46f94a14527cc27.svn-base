//
//  ActiveSyncDataBase.m
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 18/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "ActiveSyncDataBase.h"

@implementation ActiveSyncDataBase

+(ActiveSyncDataBase*)sharedInstance
{
    static dispatch_once_t onceToken;
    static ActiveSyncDataBase* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[ActiveSyncDataBase alloc] init];
    });
    return sharedInstance;
}

-(id)init
{
    self = [super init];
    if (self) {
        NSArray *documentPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        NSString *documentsDir = [documentPaths objectAtIndex:0];
        self.databasePath = [documentsDir stringByAppendingPathComponent:DATABASE_NAME];
        _dataBase = [FMDatabase databaseWithPath:self.databasePath];
        [self checkAndCreateDatabase];
        [self createTables];
    }
    return self;
}

- (void)checkAndCreateDatabase {
    
    BOOL success;
    
	// Create a FileManager object, we will use this to check the status
	// of the database and to copy it over if required
	NSFileManager *fileManager = [NSFileManager defaultManager];
    
	// Check if the database has already been created in the users filesystem
	success = [fileManager fileExistsAtPath:self.databasePath];
    
	// If the database already exists then return without doing anything
	if(success) return;
    
	// If not then proceed to copy the database from the application to the users filesystem
    
	// Get the path to the database in the application package
	NSString *databasePathFromApp = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:DATABASE_NAME];
    
	// Copy the database from the package to the users filesystem
	[fileManager copyItemAtPath:databasePathFromApp toPath:self.databasePath error:nil];
    
}

- (void)createTables
{
    
    if([_dataBase open])
    {
        NSLog(@"opened database with path %@",self.databasePath);
        if (![_dataBase executeUpdate:CREATE_TABLE_SYNC])
        {
        NSLog(@"Failed to create syncable_msg_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_POLLER_STATUS])
        {
        NSLog(@"Failed to create poller_status_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
       if (![_dataBase executeUpdate:CREATE_TABLE_POLLER_RESPONSE])
        {
        NSLog(@"Failed to create poller_status_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
    }
    else
    {
        NSLog(@"Failed to open database ActiveSyncDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }
    
    
    [_dataBase close];
}

@end
