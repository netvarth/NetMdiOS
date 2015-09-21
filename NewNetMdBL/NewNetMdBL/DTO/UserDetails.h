//
//  UserDetails.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UserDetails : NSObject

@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* userName;
@property (nonatomic, strong) NSString* userType;
@property (nonatomic, assign) NSInteger   Id;
@property (nonatomic, assign) NSInteger   doctorId;
@property (nonatomic, assign) NSInteger   ownerId;
@property (nonatomic, assign) BOOL  primaryDevice;

@end
