//
//  DoctorLoginDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface DoctorLoginDTO : NSObject

@property (nonatomic, strong) NSString*  password;
@property (nonatomic, assign) int     doctorGlobalId;
@property (nonatomic, strong) ErrorDTO*    error;
@property (nonatomic, strong) NSString*  email;
@property (nonatomic, assign) BOOL     success;


@end
