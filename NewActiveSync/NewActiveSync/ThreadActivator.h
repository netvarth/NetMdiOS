//
//  ThreadActivator.h
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 19/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HeartBeatThread.h"
#import "PollerThread.h"
#import "DispatcherThread.h"

@interface ThreadActivator : NSObject

+(ThreadActivator*)sharedInstance;
-(void)loadThreads;

@end
