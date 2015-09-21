//
//  LoginUser.h
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 13/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LoginUser : NSCoder
{
    
}
@property (nonatomic, assign) int userId;
@property (nonatomic, strong) NSString* userName;
@property (nonatomic, strong) NSString* userPassword;
@property (nonatomic, strong) NSString* userType;

-(id)initWithName:(NSString*)name password:(NSString*)password type:(NSString*)type;

@end
