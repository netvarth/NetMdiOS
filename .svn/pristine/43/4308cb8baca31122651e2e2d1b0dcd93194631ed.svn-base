//
//  CommonSyncableGenerator.m
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 20/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "SyncAgentCommonSyncableGenerator.h"

@implementation SyncAgentCommonSyncableGenerator

+(SyncAgentCommonSyncableGenerator*)sharedInstance
{
    static SyncAgentCommonSyncableGenerator* staticInstance;
    if (!staticInstance) {
        staticInstance = [[self alloc] init];
    }
    return staticInstance;
}

-(void)syncableGenerator:(NSString*)xmlString
{
    typedef NS_ENUM(NSInteger, Priority)
    {
        urgent = 0,
        normal = 1
       
    };

    
    
    NSString *sep = @" <>";
    NSCharacterSet *set = [NSCharacterSet characterSetWithCharactersInString:sep];
    NSMutableArray *array = [xmlString componentsSeparatedByCharactersInSet:set];
    NSString* cate = [array objectAtIndex:1];
    
    SyncableDto* syncableDto = [[SyncableDto alloc] init];
    SyncLocale* locale = [[SyncLocale alloc] init];
    NSDateFormatter* dateFormater = [[NSDateFormatter alloc] init];
    [dateFormater setDateFormat:@"yyyy-MM-dd"];
    
    syncableDto.cloudableData = xmlString;
    syncableDto.createDate = [dateFormater stringFromDate:[NSDate date]];
    syncableDto.category = cate;
    syncableDto.syncPriority = @"urgent";
    
    
    [self addValuesintoDb:syncableDto];
    [self addValuesintoQueue:syncableDto];
    
}

-(void)addValuesintoQueue:(id)dto

{
    [CustomQueue sharedInstance];
    id obj;
    obj = dto;
    [[CustomQueue sharedInstance] enqueueData:obj];
    
}

-(void)addValuesintoDb:(SyncableDto*)syncableDto
{
    
}
@end
