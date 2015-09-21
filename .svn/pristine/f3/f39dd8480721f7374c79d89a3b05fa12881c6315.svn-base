//
//  PollerResponseService.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 10/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PollerResponseDto.h"
#import "PollerResponseDaoImpl.h"


@interface PollerResponseService : NSObject

+(PollerResponseService*)sharedInstance;
-(BOOL)savePollerResponseToDb:(PollerResponseDto*)pollerRespDto;
-(NSMutableDictionary*)getRawDataFromSyncAgent;
-(void)passResponseToSyncAgent:(NSMutableDictionary*)dictionary;


@end
