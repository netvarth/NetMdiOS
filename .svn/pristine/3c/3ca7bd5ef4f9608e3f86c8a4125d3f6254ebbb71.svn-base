//
//  DictionaryFromObjGenerator.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 03/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "DictionaryFromObjGenerator.h"

@implementation DictionaryFromObjGenerator

+(DictionaryFromObjGenerator*)sharedInstance
{
    static DictionaryFromObjGenerator* sharedInstance;
    if (!sharedInstance) {
        sharedInstance = [[self alloc] init];
    }
    return sharedInstance;
}

-(NSMutableDictionary*)createSyncableDictinaryFromObj:(id)syncObj
{
    
    NSMutableDictionary* syncDic = [[NSMutableDictionary alloc] init];
    
    //[syncDic setObject:[syncObj valueForKey:@"cloudableData"] forKey:@"cloudableData"];
    
    [syncDic setObject:[syncObj valueForKey:@"cloudableData"] forKey:@"cloudableData"];
    [syncDic setObject:[syncObj valueForKey:@"createDate"] forKey:@"createdDate"];
    [syncDic setObject:[syncObj valueForKey:@"passPhrase"] forKey:@"passPhrase"];
    [syncDic setObject:[syncObj valueForKey:@"syncPriority"] forKey:@"syncPriority"];
    [syncDic setObject:[syncObj valueForKey:@"category"] forKey:@"category"];
    
    // [syncDic setObject:[syncObj valueForKey:@"destination"] forKey:@"destination"];
    
    NSMutableDictionary* syncLocale = [syncObj valueForKey:@"source"];
    
    NSMutableDictionary* source = [[NSMutableDictionary alloc] init];
    [source setObject:[syncLocale valueForKey:@"branchId"] forKey:@"branchId"];
    [source setObject:[syncLocale valueForKey:@"deviceId"] forKey:@"deviceId"];
    [source setObject:[syncLocale valueForKey:@"corporateId"] forKey:@"corporateId"];
    [syncDic setObject:source forKey:@"source"];
    
    NSMutableDictionary* syncDestinationLocale = [syncObj valueForKey:@"destination"];
    
    NSMutableDictionary* destination = [[NSMutableDictionary alloc] init];
    [destination setObject:[syncDestinationLocale valueForKey:@"desBranchId"] forKey:@"branchId"];
    [destination setObject:[syncDestinationLocale valueForKey:@"desDeviceId"] forKey:@"deviceId"];
    [destination setObject:[syncDestinationLocale valueForKey:@"desCorporateId"] forKey:@"corporateId"];
    
    NSMutableArray* destinationArray = [[NSMutableArray alloc] init];
    [destinationArray addObject:destination];
    [syncDic setObject:destinationArray forKey:@"destination"];
    [syncDic setObject:[syncObj valueForKey:@"table_id"] forKey:@"id"];
    
    
    return syncDic;
}

-(NSMutableDictionary*)createPollerDictionaryFromObj:(id)pollerObj
{
     NSMutableDictionary* pollerDic = [[NSMutableDictionary alloc] init];
    
     NSMutableArray* syncableObjArray = [[NSMutableArray alloc] init];
    [pollerDic setObject:syncableObjArray forKey:@"syncableObject"];
    [pollerDic setObject:[pollerObj valueForKey:@"passPhrase"] forKey:@"passPhrase"];
    [pollerDic setObject:[pollerObj valueForKey:@"lastUpdatedTime"] forKey:@"lastUpdatedTime"];
    [pollerDic setObject:([pollerObj valueForKey:@"healthStatusRequest"]?@"false":@"true") forKey:@"healthStatusRequest"];
    [pollerDic setObject:([pollerObj valueForKey:@"status"]?@"false":@"true") forKey:@"status"];
    [pollerDic setObject:[pollerObj valueForKey:@"errorMsg"] forKey:@"errorMsg"];
    
    NSMutableDictionary* syncLocale = [pollerObj valueForKey:@"source"];
    NSMutableDictionary* source = [[NSMutableDictionary alloc] init];
    [source setObject:[syncLocale valueForKey:@"branchId"] forKey:@"branchId"];
    [source setObject:[syncLocale valueForKey:@"deviceId"] forKey:@"deviceId"];
    [source setObject:[syncLocale valueForKey:@"corporateId"] forKey:@"corporateId"];
    [pollerDic setObject:source forKey:@"source"];
    
    [pollerDic setObject:source forKey:@"source"];
    
    return pollerDic;
    
}

@end
