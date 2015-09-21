//
//  ThreadActivator.m
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 19/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "ThreadActivator.h"

@implementation ThreadActivator

+(ThreadActivator*)sharedInstance
{
    static ThreadActivator* staticInstance;
    if (!staticInstance) {
        staticInstance = [[self alloc] init];
    }
    return staticInstance;
}

-(void)loadThreads
{
    [[HeartBeatThread sharedInstance] load];
    //[[DispatcherThread sharedInstance] load];
    //[[PollerThread sharedInstance] load];
    
}

@end
