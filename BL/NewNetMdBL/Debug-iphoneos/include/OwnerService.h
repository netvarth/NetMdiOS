//
//  OwnerService.h
//  NewNetMdBL
//
//  Created by Remesh Kuruppath on 1/22/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OwnerDao.h"

@interface OwnerService : NSObject

@property (nonatomic, strong) id<OwnerDaoDelegate> ownerdaodelegate;

+ (OwnerService*)sharedInstance;
- (OwnerDetailDTO*) getOwnerDetails: (int) loginId;
-(NSString*)getPassPhrase;
-(NSString*)getNetMdId;
-(NSString*)getMacId;
-(NSString*)getGlobalId;
@end
