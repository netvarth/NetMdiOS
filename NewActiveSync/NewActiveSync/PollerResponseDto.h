//
//  PollerResponseDto.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 10/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PollerResponseDto : NSObject

@property(nonatomic,strong) NSString* cloudableDataCategory;
@property(nonatomic,strong) NSString* syncPriority;
@property(nonatomic,strong) NSString* passPhrase;
@property(nonatomic,strong) NSString* cloudableData;
@property(nonatomic,strong) NSString* createdDateTime;
@property(nonatomic,strong) NSString* syncMsgStatus;
@property(nonatomic,strong) NSString* destination;

@end
