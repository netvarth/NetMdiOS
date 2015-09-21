//
//  User.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface User : NSObject


@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSDate* loginTime;
@property (nonatomic, strong) NSString* userName;
@property (nonatomic, assign)int   Id;
@property (nonatomic, assign)int   doctorId;
@property (nonatomic, strong) NSString* userType;
@property (nonatomic, assign) BOOL  primaryDevice;
@property (nonatomic, assign) NSInteger ownerId;
@property (nonatomic, strong) NSArray* userPermissions;




@end
