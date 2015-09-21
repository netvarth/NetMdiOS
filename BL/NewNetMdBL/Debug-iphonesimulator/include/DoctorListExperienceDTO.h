//
//  DoctorListExperienceDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface DoctorListExperienceDTO : NSObject

@property (nonatomic, strong) NSArray*  experience;
@property (nonatomic, strong) ErrorDTO* error;
@property (nonatomic, assign) BOOL success;
@property (nonatomic, assign) long count;

@end
