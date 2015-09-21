//
//  CustomQueue.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 20/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "CustomQueue.h"

@implementation CustomQueue
@synthesize count;

+(CustomQueue*)sharedInstance
{
    static CustomQueue* staticInstance;
    if (!staticInstance) {
        staticInstance = [[self alloc] init];
        [staticInstance initialiseArray];
    }
    return staticInstance;
}

-(void)initialiseArray
{
    cloudabledataQueue = [[NSMutableArray alloc] init];
    count = 0;
    
}

- (void)enqueueData:(id)anObj
{
    [cloudabledataQueue addObject:anObj];
    //count = cloudabledataQueue.count;
    NSLog(@"Queue Count:%lu", (unsigned long)cloudabledataQueue.count);
}

- (id)dequeue
{
    NSMutableArray* syncableList = [[NSMutableArray alloc] initWithCapacity:10];
    id obj = nil;
    while(cloudabledataQueue.count > 0 && count < 10)
    {
        obj = [cloudabledataQueue objectAtIndex:0];
        [cloudabledataQueue removeObjectAtIndex:0];
        [syncableList addObject:obj];
        count = count +1;
    }
    
    if (syncableList.count>0)
    {
        return syncableList;
        count = 0;
    }
    
    else
    return NULL;
}

- (void)clear
{
    [cloudabledataQueue removeAllObjects];
    count = 0;
}

@end
