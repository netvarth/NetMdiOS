//
//  PollerResponseManager.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 01/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "PollerResponseManager.h"

@implementation PollerResponseManager

+(PollerResponseManager*)sharedInstance
{
    static PollerResponseManager* sharedInstance;
    if (!sharedInstance) {
        sharedInstance = [[self alloc] init];
    }
    return sharedInstance;
}

-(void)responseHandler:(NSMutableDictionary*)response dictionary :(NSMutableDictionary*)dict
{

    NSError* error=nil;
    id jsonData ;
    NSString *jsonString;
    if([NSJSONSerialization isValidJSONObject:response])
    {
        
        jsonData = [NSJSONSerialization dataWithJSONObject:response options:NSJSONWritingPrettyPrinted error:&error];
        
        NSLog(@"Valid jsonobject");
        
        jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        NSLog(@"Json Format Response Got From The Cloud By Pollerthread:\n%@", jsonString);
    }
    else
        
    {
        NSLog(@"Not valid object to convert to json");
    }
    PollerResponseDto* pollerRespDto = [[PollerResponseDto alloc] init];
    NSString* lastUpdatedTime = [response valueForKey:@"lastUpdatedTime"];
    if ((lastUpdatedTime != [NSNull null])) {
        BOOL success = [[PollerService sharedInstance] updateLstUpdatedTime:lastUpdatedTime];
    }
    
    NSMutableArray* syncableObject = [response valueForKey:@"syncableObject"];
    NSLog(@"Syncable Object Count: %lu ",(unsigned long)syncableObject.count);
    if(syncableObject.count > 0)
    {
    for(NSArray* syncable in syncableObject)
    {
        
        pollerRespDto.cloudableDataCategory = [syncable valueForKey:@"category"];
        pollerRespDto.syncPriority = [syncable valueForKey:@"syncPriority"];
        pollerRespDto.passPhrase = [syncable valueForKey:@"passPhrase"];
        pollerRespDto.cloudableData = [syncable valueForKey:@"cloudableData"];
        pollerRespDto.createdDateTime = [syncable valueForKey:@"createdDate"];
        pollerRespDto.syncMsgStatus = @"on hold";
        
        NSMutableArray* destinationArray = [syncable valueForKey:@"destination"];
        for(NSArray* array in  destinationArray)
        {
            NSMutableDictionary* destinationDict = [[NSMutableDictionary alloc] init];
            [destinationDict setValue:[array valueForKey:@"corporateId"] forKey:@"corporateId"];
            [destinationDict setValue:[array valueForKey:@"branchId"] forKey:@"branchId"];
            [destinationDict setValue:[array valueForKey:@"deviceId"] forKey:@"deviceId"];
            
            NSString* corporateId = [destinationDict valueForKey:@"corporateId"];
            id bId = [destinationDict valueForKey:@"branchId"];
            id dId = [destinationDict valueForKey:@"deviceId"];
            
            NSString* branchId = @"";
            NSString* deviceId = @"";
            
            NSMutableString* destination = [[NSMutableString alloc] init];
            [destination appendString:corporateId];
            [destination appendString:@","];
            /*
            if (!branchId)
            {
                [destination appendString:@"0"];
                [destination appendString:@","];
            }
            else
            {
               [destination appendString:branchId];
               [destination appendString:@","];
            }
            
            if (!deviceId)
            {
                [destination appendString:@"0"];
                [destination appendString:@","];
            }
            else
            {
                [destination appendString:deviceId];
                [destination appendString:@","];
            }
            */
            if (bId == [NSNull null] && dId == [NSNull null])
            {
                [destination appendString:@"0"];
                [destination appendString:@","];
                [destination appendString:@"0"];
                [destination appendString:@","];

            }
            else
            {
                if (bId == [NSNull null])
                {
                    [destination appendString:@"0"];
                    [destination appendString:@","];
                }
                else
                {
                    [destination appendString:(NSString*)bId];
                    [destination appendString:@","];
                }
                
                if (dId == [NSNull null])
                {
                    [destination appendString:@"0"];
                    [destination appendString:@","];
                }
                else
                {
                    [destination appendString:(NSString*)dId];
                    [destination appendString:@","];
                }

            }

            pollerRespDto.destination = destination;
            BOOL success = [[PollerResponseService sharedInstance] savePollerResponseToDb:pollerRespDto];
            
            /*
            if (respDto.success)
            {
                //RawDataDTO* rawDataDto = [[RawDataDTO alloc] init];
                //rawDataDto.tbl_id = respDto.tableId;
                //rawDataDto.category = pollerRespDto.cloudableDataCategory;
                //rawDataDto.cloudableData = pollerRespDto.cloudableData;
                //rawDataDto.created_date_time = pollerRespDto.createdDateTime;
                NSMutableDictionary* rawDataDic = [[NSMutableDictionary alloc] init];
                [rawDataDic setObject:[NSString stringWithFormat:@"%d",respDto.tableId] forKey:@"id"];
                [rawDataDic setObject:pollerRespDto.cloudableDataCategory forKey:@"category"];
                [rawDataDic setObject:pollerRespDto.cloudableData forKey:@"cloudableData"];
                [rawDataDic setObject:pollerRespDto.createdDateTime forKey:@"createdDateTime"];
                [syncList addObject:rawDataDic];
            }
            */
        }
    }
        [syncableDict setObject:syncList forKey:@"syncList"];
        
        //NSMutableDictionary* responseDict = [[AppCommunicator sharedInstance] passRawDataToApp:syncableDict];
        [[AppCommunicator sharedInstance] alertNetMd];
    }//end of if(data exist in syncList)
    else
    {
        NSLog(@"There is no data received from the cloud by poller thread this time");
        //[[AppCommunicator sharedInstance] alertNetMd];
    }
    
}


@end
