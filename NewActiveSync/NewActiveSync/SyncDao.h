//
//  SyncDao.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 25/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SyncableDto.h"
#import "RespDto.h"

@protocol SyncDaoDelegate <NSObject>

-(RespDto*)addSyncableToDb:(SyncableDto*)syncableDto;
-(BOOL)deleteCloudAcceptedSyncable:(int) tableId;
-(int)checkSyncableTblContent;
-(NSMutableArray*)getAllSyncableDetails;

@end

@interface SyncDao : NSObject

@end

