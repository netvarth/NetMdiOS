//
//  DispatcherDto.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 28/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DispatcherDto : NSObject

@property (nonatomic, assign) BOOL  healthStatusRequest;
@property (nonatomic, assign) NSNumber* listSize;
@property (nonatomic, assign) NSMutableArray* syncList;

@end
