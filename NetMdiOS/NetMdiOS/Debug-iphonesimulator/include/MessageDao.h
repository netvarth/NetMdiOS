//
//  MessageDao.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 1/3/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MessageDTO.h"

@protocol MessageDao <NSObject>

- (BOOL)addMessage:(MessageDTO*) messageDto;
- (MessageDTO*)getMessageById:(int) messageId;
- (NSMutableArray*)getMessagesByDoctorId:(int) doctorId;
- (NSMutableArray*)getMessages ;
- (BOOL)editMessage:(MessageDTO*) messageDto;

@end
