//
//  MessageService.m
//  NetMdBL
//
//  Created by Remesh Kuruppath on 1/3/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import "MessageService.h"

@implementation MessageService
@synthesize messageDaoDelegate;

+ (MessageService*)sharedInstance {
    static dispatch_once_t onceToken;
    static MessageService* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[MessageService alloc] init];
    });
    
    return sharedInstance;
}

-(BOOL)addMessage:(MessageDTO*) messageDto
{
    [messageDaoDelegate addMessage:messageDto];
    return YES;
}
- (MessageDTO*)getMessageById:(int) messageId{
    
    return [messageDaoDelegate getMessageById:messageId];
}
- (NSMutableArray*)getMessagesByDoctorId:(int) doctorId
{
    return [messageDaoDelegate getMessagesByDoctorId:doctorId];
}
- (NSMutableArray*)getMessages{
    
    return [messageDaoDelegate getMessages];

}
- (BOOL)editMessage:(MessageDTO*) messageDto
{
     return [messageDaoDelegate editMessage:messageDto];
}
@end
