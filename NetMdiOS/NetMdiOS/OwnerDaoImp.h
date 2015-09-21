//
//  OwnerDaoImp.h
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 17/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "sqlite3.h"
#import "SQLQueries.h"
#import "FMDatabase.h"
#import "FMDB.h"
#import "OwnerDetailDTO.h"

@interface OwnerDaoImp : NSObject
@property (nonatomic, strong) NSString* databasePath;
@property (nonatomic,strong) FMDatabase* dataBase;
-(NSString*)getPassPhrase;
-(NSString*)getNetMdId;
-(NSString*)getGlobalId;
-(NSString*)getDevId;

@end
