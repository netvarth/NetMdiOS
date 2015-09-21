//
//  MessageService.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 1/3/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MessageDTO.h"
#import "MessageDao.h"


@interface MessageService : NSObject

@property (nonatomic, strong) id<MessageDao> messageDaoDelegate;

+ (MessageService*)sharedInstance;

- (BOOL)addMessage:(MessageDTO*) messageDto;
- (MessageDTO*)getMessageById:(int) messageId;
- (NSMutableArray*)getMessagesByDoctorId:(int) doctorId;
- (NSMutableArray*)getMessages ;
- (BOOL)editMessage:(MessageDTO*) messageDto;
@end
