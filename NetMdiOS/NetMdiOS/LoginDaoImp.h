//
//  LoginDaoImp.h
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 17/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SQLQueries.h"
#import "LoginDao.h"
#import "LoginUser.h"
#import "FMDB.h"
#import "FMDatabase.h"
@class LoginDTO;

@interface LoginDaoImp : NSObject
+ (LoginDaoImp*)sharedInstance;
- (int)addLoginUser:(LoginDTO*)use;
- (LoginDTO*)getLoginUserByName:(NSString*)userName;

@property (nonatomic, strong) NSString* databasePath;
@property (nonatomic, strong) LoginDTO* login;
@property (nonatomic,strong) FMDatabase* dataBase;

@end
