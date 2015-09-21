//
//  CaseDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/29/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface CaseDTO : NSObject

@property (nonatomic, assign) int       Id;
@property (nonatomic, assign) int       patientId;
@property (nonatomic, strong) NSString* caseName;
@property (nonatomic, strong) NSString* caseStatus;
@property (nonatomic, strong) NSString* shortDesc;
@property (nonatomic, strong) NSString* longDesc;
@property (nonatomic, strong) NSString* date;
@property (nonatomic, strong) NSString* createdTime;
@property (nonatomic, strong) NSString* updatedTime;
@property (nonatomic, assign) int       globalId;
@property (nonatomic, strong) NSString* actionName;
@property (nonatomic, strong) ErrorDTO* error;
@property (nonatomic, assign) BOOL     success;

@end
