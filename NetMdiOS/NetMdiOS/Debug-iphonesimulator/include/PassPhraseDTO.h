//
//  PassPhraseDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PassPhraseDTO : NSObject

@property (nonatomic, strong) NSString* passPhrase;
@property (nonatomic, strong) NSString* macId;
@property (nonatomic, strong) NSString* devId;
@property (nonatomic, assign) BOOL isPrimary;
@end
