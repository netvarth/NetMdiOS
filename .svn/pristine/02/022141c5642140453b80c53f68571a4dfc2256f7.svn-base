//
//  OwnerService.m
//  NewNetMdBL
//
//  Created by Remesh Kuruppath on 1/22/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import "OwnerService.h"

@implementation OwnerService
@synthesize ownerdaodelegate;


+ (OwnerService*)sharedInstance
{
    static dispatch_once_t onceToken;
    static OwnerService* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[OwnerService alloc] init];
    });
    
    return sharedInstance;
}

- (OwnerDetailDTO*) getOwnerDetails : (int) loginId
{
    return [ownerdaodelegate getOwnerDetails: loginId];
}

-(NSString*)getPassPhrase
{
    return [ownerdaodelegate getPassPhrase];
}

-(NSString*)getNetMdId
{
    return [ownerdaodelegate getNetMdId];
}

-(NSString*)getMacId
{
    return [ownerdaodelegate getMacId];
}

-(NSString*)getGlobalId
{
    return [ownerdaodelegate getGlobalId];
}
@end
