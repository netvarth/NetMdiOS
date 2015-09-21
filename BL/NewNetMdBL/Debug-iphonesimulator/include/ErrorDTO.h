//
//  Error.h
//  NetMdBL
//
//  Created by Surendar Modugu on 3/17/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ErrorDTO : NSObject

@property (nonatomic, strong) NSString*     errCode;
@property (nonatomic, strong) NSArray*      params;
@property (nonatomic, assign) BOOL          displayError;

@end
