//
//  Login.m
//  NetMdBL
//
//  Created by Surendar Modugu on 3/15/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "LoginDTO.h"

@implementation LoginDTO

@synthesize userName, userType, password,Id ,globalId, name ;

- (id)initWithUsername:(NSString*)Username
              password:(NSString*)Password
                  name:(NSString*)Name
              usertype:(NSString*)Usertype

{
    
    self    = [super init];
    if (self != nil) {
        self.userName   = Username;
        self.password   = Password;
        self.name       = Name;
        self.userType   = Usertype;
    }
    
    return self;
}


@end
