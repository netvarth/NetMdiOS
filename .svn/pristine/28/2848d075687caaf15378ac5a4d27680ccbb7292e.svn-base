//
//  PollerThread.m
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 19/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "PollerThread.h"

@implementation PollerThread

+(PollerThread*)sharedInstance
{
    static PollerThread* staticInstance;
    if (!staticInstance)
    {
        staticInstance = [[self alloc] init];
    }
    return staticInstance;
    
}

-(void)load
{
    [self getDataFromCloud:nil];
    if ( !self.timer || ![self.timer isValid]) {
        self.timer = [NSTimer
                      scheduledTimerWithTimeInterval:10*5
                      target:self
                      selector:@selector(getDataFromCloud:)
                      userInfo:nil
                      repeats:YES];
    }
    
}

-(void)getDataFromCloud:(NSTimer*)theTimer
{
    
    NSLog(@"Logged into the poller");
    int count = 0;
    NSString* filePath = [[NSBundle mainBundle] pathForResource:@"Config" ofType:@"plist"];
    NSDictionary* urlSet = [[NSDictionary alloc] initWithContentsOfFile:filePath];
    //NSLog(@"%@", urlSet);
    PollerDto* pollerDto = [[PollerDto alloc] init];
    
    SyncLocale* syncLocale = [[SyncLocale alloc] init];
    
    if(count == 0)
    {
        count = count +1;
        syncLocale.corporateId = [[PollerService sharedInstance] getCorporateId];
        syncLocale.branchId = [[PollerService sharedInstance] getBranchId];
        syncLocale.deviceId = [[PollerService sharedInstance] getDeviceId];
    }
    pollerDto.source = syncLocale;
    pollerDto.passPhrase = [NSNull null];
    NSString* lastUpdatedTime = [[PollerService sharedInstance] getLastUpdatedTime];
    if(!lastUpdatedTime)
    pollerDto.lastUpdatedTime = @"NEW_INSTALLATION";
    else
    pollerDto.lastUpdatedTime = lastUpdatedTime;
    
    pollerDto.syncableObject = [[NSMutableArray alloc] init];
    pollerDto.healthStatusRequest = false;
    pollerDto.status = false;
    pollerDto.errorMsg = [NSNull null];
    
    NSMutableDictionary* mainDic  = [[DictionaryFromObjGenerator sharedInstance] createPollerDictionaryFromObj:pollerDto];
    
    NSLog(@"Main Dictionary Value ie passing to cloud by pollerthread:%@", mainDic);
    
    
    NSError* error=nil;
    id jsonData ;
    NSString *jsonString;
    if([NSJSONSerialization isValidJSONObject:mainDic])
    {
        
        jsonData = [NSJSONSerialization dataWithJSONObject:mainDic options:NSJSONWritingPrettyPrinted error:&error];
        
        NSLog(@"Valid jsonobject");
        
        jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        //NSLog(@"Json in Client Macine:\n%@", jsonString);
        [[WebServiceCalls sharedInstance] passJsonDataToCloud:mainDic urlLink:[urlSet valueForKey:@"PollerURL"]];
    }
    else
        
    {
        NSLog(@"Not valid object to convert to json");
    }
}
-(void)stopTimer
{
    if (self.timer && [self.timer isValid])
    {
        NSLog(@"Poller Thread Stopped");
        [self.timer invalidate];
        self.timer = nil;
    }
    
}


@end
