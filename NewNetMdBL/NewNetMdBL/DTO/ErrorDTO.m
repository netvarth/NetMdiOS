//
//  Error.m
//  NetMdBL
//
//  Created by Surendar Modugu on 3/17/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "ErrorDTO.h"

@implementation ErrorDTO

@synthesize errCode,params,displayError;

- (id)initWithError:(NSString*)ErrorCode
             params:(NSArray*)Params
       displayError:(BOOL)DisplayError {
    
    self    = [super init];
    if (self != nil) {
        errCode    = ErrorCode;
        params         = Params;
        displayError   = DisplayError;
    }
    
    return self;
}

@end
