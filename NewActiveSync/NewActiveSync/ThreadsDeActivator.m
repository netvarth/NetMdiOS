//
//  ThreadsDeActivator.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 08/01/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "ThreadsDeActivator.h"

@implementation ThreadsDeActivator

+(ThreadsDeActivator*)sharedInstance
{
    static ThreadsDeActivator* sharedInstance;
    if (!sharedInstance) {
        sharedInstance = [[self alloc] init];
    }
    return sharedInstance;
}

-(void)deactivateSyncAgentThreads
{
    [[HeartBeatThread sharedInstance] stopTimer];
    [[DispatcherThread sharedInstance] stopTimer];
    [[PollerThread sharedInstance] stopTimer];
}
@end
