//
//  ResponseDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface ResponseDTO : NSObject

@property (nonatomic, assign) int       Id;
@property (nonatomic, assign) int       uid;
@property (nonatomic, assign) BOOL      success;
@property (nonatomic, strong) ErrorDTO*    error;

@end
