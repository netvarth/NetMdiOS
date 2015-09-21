//
//  Error.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Errors : NSObject

@property (nonatomic, strong) NSString* errCode;
@property (nonatomic, strong) NSString* errMsg;

@end
