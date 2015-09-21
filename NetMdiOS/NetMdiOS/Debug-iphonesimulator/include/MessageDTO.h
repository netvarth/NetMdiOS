//
//  MessageDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MessageDTO : NSObject

@property (nonatomic, assign) int Id;
@property (nonatomic, strong) NSString* message;
@property (assign) int viewed;
@property (nonatomic, assign) int doctorId;
@property (nonatomic, strong) NSString* doctorName;
@property (nonatomic, strong) NSString* createdTime;

@end
