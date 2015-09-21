//
//  LoginDao.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/15/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LoginDTO.h"

@protocol LoginDao <NSObject>

- (int)addLoginUser:(LoginDTO*)user;
- (LoginDTO*)getLoginUserByName:(NSString*)userName;


@end
