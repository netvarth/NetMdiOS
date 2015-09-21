//
//  DispatcherResponseManager.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 01/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "DispatcherResponseManager.h"

@implementation DispatcherResponseManager

+(DispatcherResponseManager*)sharedInstance
{
    static DispatcherResponseManager* sharedInstance;
    if (!sharedInstance) {
        sharedInstance = [[self alloc] init];
        [sharedInstance initialiseRetainCount];
    }
    return sharedInstance;
}

-(void)initialiseRetainCount
{
    retainCount = 0;
}

-(void)responseHandler:(NSMutableDictionary*)response dictionary :(NSMutableDictionary*)dict
{
    NSMutableArray* responseArray = [[NSMutableArray alloc] init];
    NSMutableArray* syncedListIndex = [[NSMutableArray alloc] init];
    NSMutableArray* unSyncedListIndex = [[NSMutableArray alloc] init];
    NSMutableArray* syncList = [[NSMutableArray alloc] init];
    NSMutableArray* syncedList = [[NSMutableArray alloc] init];
    NSMutableArray* unSyncedList = [[NSMutableArray alloc] init];
    
    syncList = [dict objectForKey:@"syncList"];
    //stores the response list to responseArray
    responseArray = [response objectForKey:@"response"];
    int count = 0;
    for(NSArray* response in responseArray)
    {
        
        NSString* reason = [response valueForKey:@"reason"];
        int status = [[response valueForKey:@"status"] intValue];
        NSLog(@"%@",[response valueForKey:@"status"]);
        switch (status) {
                
            case 0:
                
                NSLog(@"Syncing of data at index %d unsuccessfull with reason", count, [response valueForKey:@"reason"]);
                if ([reason isEqualToString:@"queue connection failed"])
                {
                    //stores what all are the list index s that are unsynced
                    //[unSyncedListIndex addObject:[NSString stringWithFormat:@"%i",count]];
                    //[unSyncedListIndex addObject:[NSNumber numberWithInt:count]];
                    [unSyncedList addObject:[syncList objectAtIndex:count]];
                }
                else if ([reason isEqualToString:@"validation failed"])
                {
                    //place syncable dat that is rejected to unsynced queue because of validation failed
                    [self placeSyncableToQueue:[syncList objectAtIndex:count]];
                    
                }

                break;
                
            case 1:
                
                NSLog(@"Syncing of data at index %d successfull", count);
                [[SyncableService sharedInsatnce] deleteCloudAcceptedSyncable:[[response valueForKey:@"id"] intValue]];
                break;
                
                
               
            default:
                break;
        }
        
            count = count + 1;
    }
    
    /*
    //handle unsynced data
    if(unSyncedListIndex.count != 0)
    {
        syncList = [dict objectForKey:@"syncList"];
        
        for(NSNumber* index in unSyncedListIndex)
        {
            int val = [index intValue];
            [unSyncedList addObject:[syncList objectAtIndex:val]];
        }
        NSLog(@"UnSynced List Size: %i", unSyncedList.count);
        NSLog(@"Unsynced List : %@", unSyncedList);
        
        //code to handle unsynced data
        [self handleUnSynceddata:unSyncedList];
        
    }
    
     */
    
    if (unSyncedList.count >0)
    {
        [self handleUnSynceddata:unSyncedList];
    }
    else
        NSLog(@"All data synced successfully");
    
    
}

-(void)handleUnSynceddata:(NSMutableArray*)unSyncedList
{
    //Generate dictionary from unSyncedlist
    
    if(retainCount < 3)
    {
        BOOL healthStatusRequest = false;
        
        NSMutableDictionary* mainDict = [[NSMutableDictionary alloc] init];
        [mainDict setValue:unSyncedList forKey:@"syncList"];
        [mainDict setValue:[NSNumber numberWithInt:unSyncedList.count] forKey:@"listSize"];
        [mainDict setValue:(healthStatusRequest?@"true":@"false") forKey:@"healthStatusRequest"];
        NSLog(@"Tried Sending data to cloud for %i time",retainCount+1);
        retainCount = retainCount + 1;
        [[DispatcherThread sharedInstance] stopTimer];
        NSString* filePath = [[NSBundle mainBundle] pathForResource:@"Config" ofType:@"plist"];
        NSDictionary* urlSet = [[NSDictionary alloc] initWithContentsOfFile:filePath];
        NSLog(@"%@", urlSet);
        [[WebServiceCalls sharedInstance] passJsonDataToCloud:mainDict urlLink:[urlSet valueForKey:@"DispatcherURL"]];
    }
    else
    {
        //Code to place data to unSynceQueue
        retainCount = 0;
        NSLog(@"Tried Sending data to the cloud for 3 times");
        //save unSyncedList to queue
        [self placeSyncableToQueue:unSyncedList];
    }
    
}


-(void)placeSyncableToQueue:(id)syncableDto
{
    NSLog(@"Placing Data to UnSyncedQueue");
    [UnsyncedQueue sharedInstance];
    id obj;
    obj = syncableDto;
    [[UnsyncedQueue sharedInstance] enqueueData:obj];
}

@end
