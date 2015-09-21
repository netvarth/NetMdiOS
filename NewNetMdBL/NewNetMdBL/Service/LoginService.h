//
//  LoginService.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/29/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LoginDTO.h"
#import "LoginDao.h"

@interface LoginService : NSObject
@property(nonatomic,strong) id<LoginDao>logindaodelegate;

+ (LoginService*)sharedInstance;
- (int)addLoginUser:(LoginDTO*)user;
- (LoginDTO*)getLoginUserByName:(NSString*)userName;



@end
