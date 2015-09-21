//
//  CaseListResponseDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/29/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "ErrorDTO.h"
#import <Foundation/Foundation.h>


@interface CaseListResponseDTO : NSObject

@property (nonatomic, strong) NSArray*  caseList;
@property (nonatomic, strong) ErrorDTO* error;
@property (nonatomic, assign) BOOL success;
@property (nonatomic, assign) long count;


@end
