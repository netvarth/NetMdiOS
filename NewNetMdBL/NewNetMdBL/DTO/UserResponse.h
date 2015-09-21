//
//  UserResponse.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface UserResponse : NSObject

@property (nonatomic, assign) NSString*   Id;
@property (nonatomic, assign) NSString*  globalId;
@property (nonatomic, strong) NSString* createdDateTime;
@property (nonatomic, strong) NSString* updatedDateTime;
@property (nonatomic, strong) ErrorDTO* error;
@property (nonatomic, assign) BOOL success;

@end
