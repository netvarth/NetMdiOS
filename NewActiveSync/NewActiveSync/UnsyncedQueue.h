//
//  UnsyncedQueue.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 12/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UnsyncedQueue : NSObject
{
    NSMutableArray* cloudabledataQueue;
    NSMutableArray* syncableList;
}

+(UnsyncedQueue*)sharedInstance;
- (void)enqueueData:(id)anObj;
- (id)dequeue;
- (void)clear;

@property (nonatomic, readonly) int count;

@end
