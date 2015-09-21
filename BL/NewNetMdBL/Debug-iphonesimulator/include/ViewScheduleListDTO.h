//
//  ViewScheduleListDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface ViewScheduleListDTO : NSObject

@property (nonatomic, strong) NSArray* schedule;
@property (nonatomic, strong) ErrorDTO* error;
@property (nonatomic, assign) BOOL success;

@end
