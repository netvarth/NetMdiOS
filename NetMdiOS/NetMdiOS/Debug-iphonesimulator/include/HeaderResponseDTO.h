//
//  HeaderResponseDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface HeaderResponseDTO : NSObject

@property (nonatomic, assign) BOOL primaryDevice;
@property (nonatomic, assign) BOOL success;
@property (nonatomic, strong) ErrorDTO* error;
@end
