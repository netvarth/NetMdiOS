//
//  ErrorDTO.h
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 21/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SyncErrorDTO : NSObject

@property (nonatomic, strong) NSString*     errCode;
@property (nonatomic, strong) NSArray*      params;
@property (nonatomic, assign) BOOL          displayError;

@end
