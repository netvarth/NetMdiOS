//
//  OwnerDao.h
//  NewNetMdBL
//
//  Created by Remesh Kuruppath on 1/22/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OwnerDetailDTO.h"

@protocol OwnerDaoDelegate <NSObject>

- (OwnerDetailDTO*) getOwnerDetails:(int) loginId;
-(NSString*)getPassPhrase;
-(NSString*)getNetMdId;
-(NSString*)getMacId;
-(NSString*)getGlobalId;

@end

@interface OwnerDao : NSObject

@end