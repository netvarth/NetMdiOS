//
//  MesicalRecordsSyncResponseDTO.h
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 27/06/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface MesicalRecordsSyncResponseDTO : NSObject
@property (nonatomic, assign) int       Id;
@property (nonatomic, assign) int       globalId;
@property (nonatomic, strong) NSString* createDateTime;
@property (nonatomic, strong) NSString* updateDateTime;
@property (nonatomic, strong) NSString* actionName;
@property (nonatomic, strong) ErrorDTO* error;
@property (nonatomic, assign) BOOL     success;
@end
