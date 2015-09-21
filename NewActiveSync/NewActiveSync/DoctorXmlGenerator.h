//
//  DoctorXmlGenerator.h
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 19/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DoctorDetailsDto.h"
#import "CommonSyncableGenerator.h"

@interface DoctorXmlGenerator : NSObject
{
    NSString* xmlStr;
}

+(DoctorXmlGenerator*)sharedInstance;
-(void)convertDocObjToXml:(DoctorDetailsDto*)docDto;
@end
