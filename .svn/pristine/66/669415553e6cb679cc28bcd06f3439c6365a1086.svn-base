//
//  PollerResponseManager.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 01/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PollerService.h"
#import "PollerResponseDto.h"
#import "PollerResponseService.h"
#import "RespDto.h"
#import "RawDataDTO.h"
#import "AppCommunicator.h"
#import "PollerResponseService.h"


@interface PollerResponseManager : NSObject
{
    NSMutableArray* syncList;
    NSMutableDictionary* syncableDict;
}

+(PollerResponseManager*)sharedInstance;
-(void)responseHandler:(NSMutableDictionary*)response dictionary :(NSMutableDictionary*)dict;
@end
