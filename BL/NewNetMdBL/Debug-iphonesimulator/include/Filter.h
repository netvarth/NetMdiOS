//
//  Filter.h
//  NetMdBL
//
//  Created by Surendar Modugu on 3/17/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Expression.h"

@interface Filter : NSObject

@property (nonatomic, strong) NSArray*  expList;
@property (nonatomic, assign) int       from;
@property (nonatomic, assign) int       count;
@property (nonatomic, assign) BOOL      asc;

@end
