//
//  UserDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HeaderDTO.h"

@interface UserDTO : NSObject 


@property (nonatomic, assign) int  Id;
@property (nonatomic, assign) int   globalId;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* userName;
@property (nonatomic, strong) NSString* userType;
@property (nonatomic, strong) NSString* password;
@property (nonatomic, strong) HeaderDTO* header;


@end
