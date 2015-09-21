//
//  OwnerDaoImp.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 17/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "OwnerDaoImp.h"

@implementation OwnerDaoImp

- (id)init {
    self    = [super init];
    if (self) {
        // Get the path to the documents directory and append the databaseName
        NSArray *documentPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        NSString *documentsDir = [documentPaths objectAtIndex:0];
        self.databasePath = [documentsDir stringByAppendingPathComponent:DATABASE_NAME];
        _dataBase = [FMDatabase databaseWithPath:self.databasePath];
    }
    return self;
}

- (OwnerDetailDTO*) getOwnerDetails:(int) loginId
{
        
    OwnerDetailDTO* ownerDto = [[OwnerDetailDTO alloc]init];
    if ([_dataBase open])
    {
        NSLog(@"Opened sqlite database at %@", self.databasePath);
         NSString* selectQuery   = [NSString stringWithFormat:SELECT_OWNER_FROM_NETMDTABLE,loginId];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        if ([set next])
        {
            ownerDto.loginId = [set intForColumnIndex:7]  ;
            ownerDto.Id = [set intForColumnIndex:0];
            ownerDto.firstName =[set stringForColumnIndex:1];
            ownerDto.lastName =[set stringForColumnIndex:9];
            
            ownerDto.address =[set stringForColumnIndex:3];
            ownerDto.email =[set stringForColumnIndex:4];
            ownerDto.phone =[set stringForColumnIndex:5];
            ownerDto.mobile =[set stringForColumnIndex:6];

        }
         [set close];
    }
    else
    {
         NSLog(@"Failed to open database NetMDDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }
    
        return ownerDto;
}
/*
-(NSString*)getPassPhrase
{
    sqlite3_config(SQLITE_CONFIG_SERIALIZED);
    sqlite3* dbHandler = nil;
    NSString* passPhrase = [[NSString alloc] init];
    if (sqlite3_open([self.dbPath UTF8String], &dbHandler) ==SQLITE_OK) {
        NSLog(@"Opened sqlite database at %@", self.dbPath);
        NSString* selectQuery = [NSString stringWithFormat:SELECT_PASSPHRASE];
        sqlite3_stmt* selectstmt;
        if (sqlite3_prepare_v2(dbHandler, [selectQuery UTF8String], -1, &selectstmt, NULL) == SQLITE_OK)
        {
            if (sqlite3_step(selectstmt) == SQLITE_ROW)
            {
                passPhrase= [NSString stringWithUTF8String:(char *)sqlite3_column_text(selectstmt, 0)];
            }
            sqlite3_finalize(selectstmt);
        }
        else
        {
            NSLog(@"Failed to get pass phrase from table netmd_passphrase_tbl: Error: '%s'", sqlite3_errmsg(dbHandler));
            
            
        }
        
    }
    else
    {
        NSLog(@"Failed to open database at %@ with error '%s'", self.dbPath, sqlite3_errmsg(dbHandler));
    }
    
    sqlite3_close(dbHandler);
    return passPhrase;
}

-(NSString*)getNetMdId
{
    
    NSString* idStr;
    sqlite3_config(SQLITE_CONFIG_SERIALIZED);
    sqlite3* dbHandler = nil;
    
    if (sqlite3_open([self.dbPath UTF8String], &dbHandler) == SQLITE_OK) {
        NSLog(@"Opened database at %@", self.dbPath);
        NSString* selectQuery = [NSString stringWithFormat:SELECT_NETMD_ID_FROM_NETMD_BRANCH_TABLE];
        sqlite3_stmt* statment;
        if (sqlite3_prepare_v2(dbHandler, [selectQuery UTF8String], -1, &statment, NULL) == SQLITE_OK) {
            if (sqlite3_step(statment) == SQLITE_ROW) {
                idStr = [NSString stringWithUTF8String:(char *)sqlite3_column_text(statment, 0)];
                
            }
            sqlite3_finalize(statment);
        }
        else
        {
            NSLog(@"failed to get netmd_Id from netmd branch_tbl with error :'%s'", sqlite3_errmsg(dbHandler));
        }
    }
    else
    {
        NSLog(@"Failed to open database netmd_branch_tbl at %@ with error '%s'",self.dbPath,sqlite3_errmsg(dbHandler));
    }
    
    sqlite3_close(dbHandler);
    return idStr;
}

-(NSString*)getMacId
{
    NSString* macId;
    sqlite3_config(SQLITE_CONFIG_SERIALIZED);
    sqlite3* dbHandler;
    if(sqlite3_open([self.dbPath UTF8String], &dbHandler) == SQLITE_OK)
    {
        NSLog(@"Opened database at path %@", self.dbPath);
        NSString* selectQuery = [NSString stringWithFormat:SELECT_MACID_FROM_NETMD_PASSPHRASE_TABLE];
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(dbHandler, [selectQuery UTF8String], -1, &stmt, NULL) == SQLITE_OK) {
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                macId = [NSString stringWithUTF8String:(char *)sqlite3_column_text(stmt, 0)];
            }
            sqlite3_finalize(stmt);
        }
    }
    else
    {
        NSLog(@"Failed to open database table netmd_passPhrase_tbl at %@ with error: '%s'",self.dbPath,sqlite3_errmsg(dbHandler));
    }
    sqlite3_close(dbHandler);
    return macId;
}

-(NSString*)getGlobalId
{
    int global_id = 0;
    NSString* str_GlobalId;
    sqlite3_config(SQLITE_CONFIG_SERIALIZED);
    sqlite3* dbHandler;
    if (sqlite3_open([self.dbPath UTF8String], &dbHandler) == SQLITE_OK) {
        NSLog(@"Database opened at path %@", self.dbPath);
        NSString* selectQuery = [NSString stringWithFormat:SELECT_GLOBALID_FROM_NETMD_BRANCH_TABLE];
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(dbHandler, [selectQuery UTF8String], -1, &stmt, NULL) == SQLITE_OK) {
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                global_id = sqlite3_column_int(stmt, 0);
                str_GlobalId = [NSString stringWithFormat:@"%i", global_id];
            }
            sqlite3_finalize(stmt);
        }
    }
    else
    {
        NSLog(@"Failed to open database at path %@ with error: '%s'", self.dbPath,sqlite3_errmsg(dbHandler));
    }
    sqlite3_close(dbHandler);
    return str_GlobalId;
}

-(NSString*)getDevId
{
    NSString* devId;
    sqlite3_config(SQLITE_CONFIG_SERIALIZED);
    sqlite3* dbHandler;
    if(sqlite3_open([self.dbPath UTF8String], &dbHandler) == SQLITE_OK)
    {
        NSLog(@"Opened database at path %@", self.dbPath);
        NSString* selectQuery = [NSString stringWithFormat:SELECT_DEVID_FROM_NETMD_PASSPHRASE_TABLE];
        sqlite3_stmt* stmt;
        if (sqlite3_prepare_v2(dbHandler, [selectQuery UTF8String], -1, &stmt, NULL) == SQLITE_OK) {
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                devId = [NSString stringWithUTF8String:(char *)sqlite3_column_text(stmt, 0)];
            }
            sqlite3_finalize(stmt);
        }
    }
    else
    {
        NSLog(@"Failed to open database table netmd_passPhrase_tbl at %@ with error: '%s'",self.dbPath,sqlite3_errmsg(dbHandler));
    }
    sqlite3_close(dbHandler);
    return devId;
}
*/
@end
