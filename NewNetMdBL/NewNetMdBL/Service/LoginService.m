//
//  LoginService.m
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/29/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "LoginService.h"


@implementation LoginService
@synthesize logindaodelegate;

+ (LoginService*)sharedInstance {
    static dispatch_once_t onceToken;
    static LoginService* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[LoginService alloc] init];
    });
    
    return sharedInstance;
}


- (int)addLoginUser:(LoginDTO*)user
{
    return [logindaodelegate addLoginUser:user];
}

- (LoginDTO*)getLoginUserByName:(NSString*)userName
{
    return[logindaodelegate getLoginUserByName:userName];
}


@end
