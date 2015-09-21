//
//  ThreadsDeActivator.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 08/01/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HeartBeatThread.h"
#import "DispatcherThread.h"
#import "PollerThread.h"

@interface ThreadsDeActivator : NSObject

+(ThreadsDeActivator*)sharedInstance;
-(void)deactivateSyncAgentThreads;
@end
