//
//  UnsyncedQueue.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 12/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "UnsyncedQueue.h"

@implementation UnsyncedQueue


+(UnsyncedQueue*)sharedInstance
{
    static UnsyncedQueue* staticInstance;
    if (!staticInstance)
    {
        staticInstance = [[self alloc] init];
        [staticInstance initialiseArray];
    }
    return staticInstance;
}

-(void)initialiseArray
{
    cloudabledataQueue = [[NSMutableArray alloc] init];
    _count = 0;
    syncableList = [[NSMutableArray alloc] initWithCapacity:10];
}

- (void)enqueueData:(id)anObj
{
    [cloudabledataQueue addObject:anObj];
    _count = cloudabledataQueue.count;
    NSLog(@"UnSyncedQueue Count:%d", _count);
}

- (id)dequeue
{
    id obj = nil;
    while(cloudabledataQueue.count > 0)
    {
        obj = [cloudabledataQueue objectAtIndex:0 ];
        [cloudabledataQueue removeObjectAtIndex:0];
        [syncableList addObject:obj];
    }
    return syncableList;
}

- (void)clear
{
    [cloudabledataQueue removeAllObjects];
    _count = 0;
}


@end
