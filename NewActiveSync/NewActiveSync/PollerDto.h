//
//  PollerDto.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 03/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SyncLocale.h"

@interface PollerDto : NSObject

@property (nonatomic, assign) NSMutableArray* syncableObject;
@property(nonatomic,assign)SyncLocale* source;
@property(nonatomic,assign)NSString* passPhrase;
@property(nonatomic,assign)NSString* lastUpdatedTime;
@property(nonatomic,assign)BOOL healthStatusRequest;
@property(nonatomic,assign)BOOL status;
@property(nonatomic,assign)NSString* errorMsg;

@end
