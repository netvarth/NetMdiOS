//
//  SyncableService.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 04/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SyncableDto.h"
#import "CustomQueue.h"
#import "RespDto.h"
#import "SyncableDaoImpl.h"




@interface SyncableService : NSObject

//@property(nonatomic,strong)id<SyncDaoDelegate>syncDaoDelegate;

+(SyncableService*)sharedInsatnce;
-(void)addSyncableToDb:(SyncableDto*)syncableDto;
-(BOOL)deleteCloudAcceptedSyncable:(int) tableId;
-(int)checkSyncableTblContent;
-(void)getAllSyncableDetails;


@end
