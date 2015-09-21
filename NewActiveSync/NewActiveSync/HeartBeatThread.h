//
//  HeartBeatThread.h
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 19/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"
#import "WebServiceCalls.h"


@interface HeartBeatThread : NSObject

@property(nonatomic,strong) NSTimer* timer;

+(HeartBeatThread*)sharedInstance;
-(void)stopTimer;
-(void)load;
-(void)pingingTheCloud:(NSTimer*)theTimer;
-(BOOL)isReachable;

@end
