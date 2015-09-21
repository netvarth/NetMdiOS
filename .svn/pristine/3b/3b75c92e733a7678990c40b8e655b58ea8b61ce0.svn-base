//
//  DispatcherThread.h
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 19/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DispatcherDto.h"
#import "CustomQueue.h"
#import "HeartBeatThread.h"
#import "DispatcherResponseManager.h"
#import "DictionaryFromObjGenerator.h"
#import "WebServiceCalls.h"

@interface DispatcherThread : NSObject
{
  NSMutableArray* syncableList;   
}

@property(nonatomic,strong) NSTimer* timer;
+(DispatcherThread*)sharedInstance;
-(void)load;
-(void)passDataToCloud:(NSTimer*)theTimer;
-(void)stopTimer;


@end
