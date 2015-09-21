//
//  RetrieveResultsResponseDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface RetrieveResultsResponseDTO : NSObject

@property (nonatomic, assign)int   resultGlobalId;
@property (nonatomic, strong) NSString* result;
@property (nonatomic, assign)int   patientId;
@property (nonatomic, strong) NSString* orderDate;
@property (nonatomic, strong) NSString* orderUid;
@property (nonatomic, strong) NSString* labName;
@property (nonatomic, strong) NSString* labBranchName;
@property (nonatomic, strong) NSArray* retrieveUsersList;
@property (nonatomic, assign) BOOL      success;
@property (nonatomic, strong) ErrorDTO* error;


@end
