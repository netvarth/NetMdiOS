//
//  PollerDaoImpl.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 04/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "sqlite3.h"
#import "DbQueries.h"
#import "SyncLocale.h"
#import "FMDatabase.h"
#import "FMDB.h"
//#import "FMDatabaseAdditions.h"

@interface PollerDaoImpl : NSObject

@property(nonatomic,strong)NSString* databasePath;
@property(nonatomic,strong)FMDatabase* dataBase;


+(PollerDaoImpl*)sharedInstance;
-(int)getPollerStatustblCount;
-(BOOL)saveLocaleToPollerStatusTbl:(SyncLocale*)syncLocale;
-(NSString*)getCorporateId;
-(NSString*)getBranchId;
-(NSString*)getDeviceId;
-(NSString*)getLastUpdatedTime;
-(BOOL)updateLstUpdatedTime:(NSString*)time;


@end
