//
//  DispatcherResponseManager.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 01/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SyncableDaoImpl.h"
#import "DispatcherDto.h"
#import "DispatcherThread.h"
#import "WebServiceCalls.h"
#import "UnsyncedQueue.h"
#import "SyncableService.h"

@interface DispatcherResponseManager : NSObject
{
    int retainCount ;
}

@property(nonatomic,strong)NSNumber* rCount;
-(void)responseHandler:(NSMutableDictionary*)response dictionary :(NSMutableDictionary*)dict;

+(DispatcherResponseManager*)sharedInstance;
@end
