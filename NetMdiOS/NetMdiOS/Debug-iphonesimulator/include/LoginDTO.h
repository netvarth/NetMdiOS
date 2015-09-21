//
//  Login.h
//  NetMdBL
//
//  Created by Surendar Modugu on 3/15/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LoginDTO : NSObject 

@property (nonatomic, assign) int  Id;
@property (nonatomic, assign) int   globalId;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSString* userName;
@property (nonatomic, strong) NSString* userType;
@property (nonatomic, strong) NSString* password;


@end
