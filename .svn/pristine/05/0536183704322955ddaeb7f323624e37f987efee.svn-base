//
//  WebServiceCalls.m
//  NewActiveSync
//
//  Created by Netvarth_Mac2 on 03/12/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "WebServiceCalls.h"

@implementation WebServiceCalls

+(WebServiceCalls*)sharedInstance
{
    static WebServiceCalls* sharedInstance;
    if (!sharedInstance) {
        sharedInstance = [[self alloc] init];
    }
    return sharedInstance;
}


-(void)pingingTheCloud:(NSTimer*)theTimer urlLink:(NSString*)url;
{
    NSLog(@"Started pinging the cloud");
    
    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"Config" ofType:@"plist"];
    NSDictionary *urlSet = [[NSDictionary alloc] initWithContentsOfFile:filePath];
    // NSLog(@"Dictionary:%@", dict);
    
    NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:[urlSet objectForKey:@"HeartBeatURL"]]];
    
    AFHTTPRequestOperation *operation = [[AFHTTPRequestOperation alloc] initWithRequest:request];
    [operation setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id responseObject) {
        NSLog(@"Cloud is alive");
        isReachable = YES;
        [[DispatcherThread sharedInstance] load];
        [[PollerThread sharedInstance] load];

    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
        NSLog(@"Cloud is down :%@", error);
        isReachable = NO;
       [[DispatcherThread sharedInstance] stopTimer];
       [[PollerThread sharedInstance] stopTimer];
    }];
 
    [operation start];
    
}

-(BOOL)isReachable
{
    return isReachable;
}

-(void)passJsonDataToCloud:(NSMutableDictionary*)dic urlLink:(NSString*)url
{
    
    NSError* errors=nil;
    id jsonData ;
    NSString *jsonString;
    if([NSJSONSerialization isValidJSONObject:dic])
    {
       
        jsonData = [NSJSONSerialization dataWithJSONObject:dic options:NSJSONWritingPrettyPrinted error:&errors];
        
        NSLog(@"Valid jsonobject");
        
        jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        NSLog(@"Json in Client Macine:\n%@", jsonString);
        
        NSString* filePath = [[NSBundle mainBundle] pathForResource:@"Config" ofType:@"plist"];
        NSDictionary* urlSet = [[NSDictionary alloc] initWithContentsOfFile:filePath];
        //NSLog(@"%@", urlSet);
        
        //manager.responseSerializer.acceptableContentTypes = [NSSet setWithObject:@"text/html"];
        
        NSError* error;
        NSData *executionsData = [NSJSONSerialization dataWithJSONObject:dic options:NSJSONWritingPrettyPrinted error:&error];
        
        NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:url]];
        [request setTimeoutInterval:600];
        [request setHTTPMethod:@"POST"];
        [request setValue:[NSString stringWithFormat:@"%lu", (unsigned long)executionsData.length] forHTTPHeaderField:@"Content-Length"];
        [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
        [request setHTTPBody:executionsData];
        [request setValue:[self userAgent] forHTTPHeaderField:@"User-Agent"];
        
        
        AFHTTPRequestOperation *op = [[AFHTTPRequestOperation alloc] initWithRequest:request];
        op.responseSerializer = [AFJSONResponseSerializer serializer];
        [op setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id responseObject) {
            NSDictionary* resultsDict   = (NSDictionary*)responseObject;
            NSLog(@"%@", resultsDict);
            if(resultsDict)
            {
                //process result json dictionary
                NSLog(@"Got Response from the cloud");
                if ([url isEqualToString:[urlSet valueForKey:@"DispatcherURL"]])
                {
                    [[DispatcherResponseManager sharedInstance] responseHandler:resultsDict dictionary:dic];
                }
                else
                {
                    [[PollerResponseManager sharedInstance] responseHandler:resultsDict dictionary:dic];
                }
            }
        } failure:^(AFHTTPRequestOperation *operation, NSError *error)
        {
            NSString* respData = [[NSString alloc] initWithData:operation.responseData encoding:NSUTF8StringEncoding];
            NSLog(@"Error:%@, response from the cloud:%@",error, respData);
            
        }];
        
        [[NSOperationQueue mainQueue] addOperation:op];

    }
    else
    {
        NSLog(@"Not valid object to convert to json");
    }
    
}

- (NSString*)userAgent
{
    NSDictionary* infoDictionary    = [[NSBundle mainBundle] infoDictionary];
    NSString* appName = [infoDictionary objectForKey:@"CFBundleDisplayName"];
    NSString* appVersion = [infoDictionary objectForKey:@"CFBundleVersion"];
    NSString* deviceModal = [[UIDevice currentDevice] model];
    NSString* deviceVersion = [[UIDevice currentDevice] systemVersion];
    
    
    NSArray* userAgentList  = @[appName, appVersion, deviceModal, deviceVersion];
    NSLog(@"User-Agent: %@", [userAgentList componentsJoinedByString:@","]);
    return [userAgentList componentsJoinedByString:@","];
    
}
@end