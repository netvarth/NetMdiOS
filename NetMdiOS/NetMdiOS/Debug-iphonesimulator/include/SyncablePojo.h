//
//  SyncablePojo.h
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 24/11/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SourceLocale.h"
#import "DesLocale.h"

@interface SyncablePojo : NSObject

@property(nonatomic,strong)SourceLocale* source;
@property(nonatomic,strong)DesLocale* destination;
@property(nonatomic,strong)NSString* cloudableData;
@property(nonatomic,strong)NSString* createDate;
@property(nonatomic,strong)NSString* passPhrase;
@property(nonatomic)NSString* syncPriority;
@property(nonatomic,strong)NSString* category;
@property(nonatomic,assign)int tbl_Id;

@end
