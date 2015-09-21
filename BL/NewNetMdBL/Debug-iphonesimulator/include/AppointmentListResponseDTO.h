//
//  AppointmentListResponseDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/29/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"
#import "LoginDTO.h"

@interface AppointmentListResponseDTO : NSObject

@property (nonatomic, strong) NSArray*  achievement;
@property (nonatomic, strong) ErrorDTO*    error;
@property (nonatomic, assign) BOOL      success;
@property (nonatomic, strong) LoginDTO*    login;

@end
