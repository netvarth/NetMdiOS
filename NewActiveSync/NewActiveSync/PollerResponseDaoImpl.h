//
//  PollerResponseDaoImpl.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 10/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PollerResponseDto.h"
#import "sqlite3.h"
#import "DbQueries.h"
#import "FMDatabase.h"
#import "FMDB.h"



@interface PollerResponseDaoImpl : NSObject


@property(nonatomic,strong)NSString* databasePath;
@property(nonatomic,strong)FMDatabase* dataBase;

+(PollerResponseDaoImpl*)sharedInstance;
-(BOOL)savePollerResponseToDb:(PollerResponseDto*)pollerRespDto;
-(NSMutableDictionary*)getRawDataFromSyncAgent;
-(void)passResponseToSyncAgent:(NSMutableDictionary*)dictionary;

@end
