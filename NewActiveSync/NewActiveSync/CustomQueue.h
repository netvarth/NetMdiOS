//
//  CustomQueue.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 20/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SyncableDto.h"

@interface CustomQueue : NSObject
{
    NSMutableArray* cloudabledataQueue;
    
}

+(CustomQueue*)sharedInstance;
- (void)enqueueData:(id)anObj;
- (id)dequeue;
- (void)clear;

@property (nonatomic, readonly) int count;
@end


