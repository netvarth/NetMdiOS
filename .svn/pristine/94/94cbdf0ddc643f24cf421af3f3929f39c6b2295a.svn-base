//
//  PollerThread.h
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 19/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PollerDto.h"
#import "SyncLocale.h"
#import "PollerService.h"
#import "DictionaryFromObjGenerator.h"
#import "WebServiceCalls.h"

//#import "SyncDao.h"
//#import "SyncableDaoImpl.h"

@interface PollerThread : NSObject
{
    NSMutableArray* syncableList;
}

@property(nonatomic,strong) NSTimer* timer;

+(PollerThread*)sharedInstance;
-(void)load;
-(void)getDataFromCloud:(NSTimer*)timer;
-(void)stopTimer;


@end
