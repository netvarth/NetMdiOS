//
//  LoginDaoImp.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 17/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "LoginDaoImp.h"

@implementation LoginDaoImp
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

+ (LoginDaoImp*)sharedInstance
{
    static LoginDaoImp* sharedInstance;
    if (!sharedInstance) {
        sharedInstance = [[self alloc] init];
    }
    return sharedInstance;
}

- (LoginDTO*)getLoginUserByName:(NSString*)userName {

    
    _login = [[LoginDTO alloc] init];
    if ([_dataBase open])
    {
         NSLog(@"Opened sqlite database at %@", self.databasePath);
         NSString* selectQuery   = [NSString stringWithFormat:SELECT_LOGIN_BY_USERNAME, userName];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        if ([set next])
        {
            _login.Id = [set intForColumnIndex:0];
            _login.userName = [set stringForColumnIndex:1];
            _login.password = [set stringForColumnIndex:2];
            _login.userType = [set stringForColumnIndex:3];

        }
        [set close];

    }
    else
    {
        NSLog(@"Failed to open database NetMDDatabase.sql Error::%@",_dataBase.lastErrorMessage);
        
    }
  
    return _login;
}


@end
