//
//  LoginUser.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 13/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "LoginUser.h"

@implementation LoginUser

-(id)initWithName:(NSString*)name password:(NSString*)password type:(NSString*)type {
    self = [super init];
    if(self) {
        self.userId = -1;
        self.userName = name;
        self.userPassword = password;
        self.userType = type;
    }
    return self;
}

- (id)initWithCoder:(NSCoder *)aDecoder {
    self = [super init];
    if(self) {
        self.userId = [aDecoder decodeIntegerForKey:@"id"];
        self.userName   = [aDecoder decodeObjectForKey:@"name"];
        self.userPassword = [aDecoder decodeObjectForKey:@"password"];
        self.userType   = [aDecoder decodeObjectForKey:@"type"];
    }
    return self;
}

- (void)encodeWithCoder:(NSCoder *)encoder {
    [encoder encodeInteger:self.userId forKey:@"id"];
    [encoder encodeObject:self.userName forKey:@"name"];
    [encoder encodeObject:self.userPassword forKey:@"password"];
    [encoder encodeObject:self.userType forKey:@"type"];
}

@end
