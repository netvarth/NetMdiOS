//
//  DocDaoImpl.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 25/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DbQueries.h"
#import "SyncableDto.h"
#import "sqlite3.h"
#import "FMDB.h"
#import "FMDatabase.h"
#import "RespDto.h"
#import "SyncLocale.h"
//#import "SyncableDto.h"
//#import "SyncLocale.h"
//#import "SyncDesLocale.h"

@interface SyncableDaoImpl : NSObject

@property(nonatomic,strong)NSString* databasePath;
@property(nonatomic,strong)FMDatabase* dataBase;

+(SyncableDaoImpl*)sharedInstance;
-(RespDto*)addSyncableToDb:(SyncableDto*)syncableDto;
-(BOOL)deleteCloudAcceptedSyncable:(int) tableId;
-(int)checkSyncableTblContent;
-(NSMutableArray*)getAllSyncableDetails;



@end
