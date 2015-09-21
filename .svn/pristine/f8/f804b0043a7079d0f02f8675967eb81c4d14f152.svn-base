//
//  DispatcherThread.m
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 19/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "DispatcherThread.h"

@implementation DispatcherThread

+(DispatcherThread*)sharedInstance
{
    static DispatcherThread* staticInstance;
    if (!staticInstance) {
        staticInstance = [[self alloc] init];
    }
    return staticInstance;
}

-(void)load
{
    [self passDataToCloud:nil];
    if (!self.timer || ![self.timer isValid]) {
        
        self.timer = [NSTimer scheduledTimerWithTimeInterval:10*4
                                                      target:self
                                                    selector:@selector(passDataToCloud:)
                                                    userInfo:nil
                                                     repeats:YES];
    }
}

-(void)passDataToCloud:(NSTimer*)theTimer
{
    if (![[WebServiceCalls sharedInstance] isReachable]) {
        return ;
    }
    NSLog(@"Logged into the dispatcher");
    DispatcherDto* dispatcherDto = [[DispatcherDto alloc] init];
    syncableList = [[NSMutableArray alloc] initWithCapacity:10];
    NSMutableDictionary* dic = [[NSMutableDictionary alloc] init];
    NSMutableArray* dicArray = [[NSMutableArray alloc] init];
    id obj = [[CustomQueue sharedInstance] dequeue];
    
    //id obj = syncArray;
    int count = 0;
    for (id item in obj ) {
        dic = [[DictionaryFromObjGenerator sharedInstance] createSyncableDictinaryFromObj:item];
        [dicArray addObject:dic];
        [dispatcherDto.syncList addObject:dic];
        count = count +1;
    }
    dispatcherDto.listSize = [NSNumber numberWithInt:count];
    dispatcherDto.healthStatusRequest = false;
    

    if (count != 0)
    {
        NSString* filePath = [[NSBundle mainBundle] pathForResource:@"Config" ofType:@"plist"];
        NSDictionary* urlSet = [[NSDictionary alloc] initWithContentsOfFile:filePath];
        //NSLog(@"%@", urlSet);

        NSMutableDictionary* mainDic = [[NSMutableDictionary alloc] initWithCapacity:10];
        [mainDic setObject:dicArray forKey:@"syncList"];
        [mainDic setObject:(dispatcherDto.healthStatusRequest?@"true":@"false") forKey:@"healthStatusRequest"];
        [mainDic setObject:dispatcherDto.listSize forKey:@"listSize"];
        
        NSLog(@"Main Dictionary Value ie Passing To Cloud By DispatcherThread:%@", mainDic);
        [[WebServiceCalls sharedInstance] passJsonDataToCloud:mainDic urlLink:[urlSet valueForKey:@"DispatcherURL"]];
        
    }
        else
        {
            NSLog(@"Queue is null");
        }
}

-(void)stopTimer
{
    if (self.timer || [self.timer isValid]) {
        NSLog(@"Dispatcher Thread Stopped");
        [self.timer invalidate];
        self.timer = nil;
    }
}
@end
