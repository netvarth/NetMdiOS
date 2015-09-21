//
//  HeaderDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/29/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HeaderDTO : NSObject

@property (nonatomic, assign) int       headOfficeId;
@property (nonatomic, strong) NSString*       macId;
@property (nonatomic, strong) NSString* passPhrase;
@property (nonatomic, assign) int branchId;

@end
