//
//  DoctorListAchievementDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorDTO.h"

@interface DoctorListAchievementDTO : NSObject

@property (nonatomic, strong) NSArray*  achievement;
//@property (nonatomic, strong) ErrorDTO* error;
@property (nonatomic, assign) BOOL success;
@property (nonatomic, assign) long count;

@end
