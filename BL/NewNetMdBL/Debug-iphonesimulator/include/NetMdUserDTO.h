//
//  NetMdUserDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NetMdUserDetail.h"
#import "HeaderDTO.h"
#import "ErrorDTO.h"

@interface NetMdUserDTO : NSObject

@property (nonatomic, strong) NetMdUserDetail* user;
@property (nonatomic, strong) HeaderDTO* header;
@property (nonatomic, assign) BOOL success;
@property (nonatomic, strong) ErrorDTO* error;



@end
