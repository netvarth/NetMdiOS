//
//  HeartBeatThread.m
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 19/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "HeartBeatThread.h"

@implementation HeartBeatThread

+(HeartBeatThread*)sharedInstance
{
    static HeartBeatThread* staticInstance;
    if (!staticInstance) {
        staticInstance = [[self alloc] init];
    }
    return staticInstance;
}

-(void)load
{
   
    if (!self.timer || ![self.timer isValid])
    {
         [self pingingTheCloud:nil];
        self.timer = [NSTimer scheduledTimerWithTimeInterval:10*6
                                                      target:self
                                                    selector:@selector(pingingTheCloud:)
                                                    userInfo:nil
                                                     repeats:YES];
    }
    
}

-(void)pingingTheCloud:(NSTimer*)theTimer
{
    NSString* filePath = [[NSBundle mainBundle] pathForResource:@"Config" ofType:@"plist"];
    NSDictionary* urlSet = [[NSDictionary alloc] initWithContentsOfFile:filePath];
    //NSLog(@"%@", urlSet);
    [[WebServiceCalls sharedInstance] pingingTheCloud:theTimer urlLink:[urlSet valueForKey:@"HeartBeatURL"]];
    
}

-(BOOL)isReachable
{
   return  [[WebServiceCalls sharedInstance] isReachable];
}
-(void)stopTimer
{
    
    if (self.timer && [self.timer isValid]) {
        NSLog(@"Heartbeat Thread Stopped");
        
        [self.timer invalidate];
        self.timer = nil;
        
        
    }
    
}

@end
