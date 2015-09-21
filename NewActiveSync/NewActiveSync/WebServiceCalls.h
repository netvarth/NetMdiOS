//
//  WebServiceCalls.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 03/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"
#import "DispatcherResponseManager.h"
#import "PollerResponseManager.h"
#import "PollerThread.h"

@interface WebServiceCalls : NSObject
{
    BOOL isReachable;
}

+(WebServiceCalls*)sharedInstance;
-(void)pingingTheCloud:(NSTimer*)theTimer urlLink:(NSString*)url;
-(BOOL)isReachable;
-(void)passJsonDataToCloud:(NSMutableDictionary*)dic urlLink:(NSString*)url;

@end
