//
//  NetMdActivationResponseDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"
#import "NetMdBranchDTO.h"
#import "NetMdDTO.h"

@interface NetMdActivationResponseDTO : NSObject

@property (nonatomic, strong)ErrorDTO* error;
@property (nonatomic, assign) BOOL success;
@property (nonatomic, strong) NetMdBranchDTO* branch;
@property (nonatomic, strong) NetMdDTO* netmd;
@property (nonatomic, strong) NSArray* user;
@property (nonatomic, strong) NSArray* retrieveDoctorsList;
@property (nonatomic, strong) NSArray* retrievePatients;
@property (nonatomic, strong) NSArray* retrieveScheduleList;
@property (nonatomic, strong) NSArray* retrieveAppointments;
@property (nonatomic, assign) BOOL primary;

@end
