//
//  ActiveSyncDataBase.h
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 18/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "sqlite3.h"
#import "DbQueries.h"
#import "FMDB.h"
#import "FMDatabase.h"




@interface ActiveSyncDataBase : NSObject

@property (nonatomic, strong) NSString* databasePath;
@property (nonatomic,strong) FMDatabase* dataBase;

+(ActiveSyncDataBase*)sharedInstance;
- (void)checkAndCreateDatabase;
- (void)createTables;


@end
