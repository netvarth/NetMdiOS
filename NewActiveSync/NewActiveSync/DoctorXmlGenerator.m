//
//  DoctorXmlGenerator.m
//  ActiveSync
//
//  Created by Netvarth_Mac2 on 19/11/14.
//  Copyright (c) 2014 Netvarth_Mac2. All rights reserved.
//

#import "DoctorXmlGenerator.h"

@implementation DoctorXmlGenerator

+(DoctorXmlGenerator*)sharedInstance
{
    static DoctorXmlGenerator* staticInstance;
    if (!staticInstance) {
        staticInstance = [[self alloc] init];
        [staticInstance initialise];
    }
    return staticInstance;
}

-(void)initialise
{
    xmlStr = [[NSString alloc] init];
}

-(void)convertDocObjToXml:(DoctorDetailsDto*)docDto
{
    
       NSMutableString* returnValue = [[NSMutableString alloc] init];
    if (docDto)
    {
        [returnValue appendString:@"<Doctor>"];
        
        [returnValue appendString:@"<docFstName>"];
        [returnValue appendString:docDto.firstName];
        [returnValue appendString:@"</docFstName>"];
        
        [returnValue appendString:@"<docLastName>"];
        [returnValue appendString:docDto.lastName];
        [returnValue appendString:@"</docLastName>"];
        
        [returnValue appendString:@"<docDob>"];
        [returnValue appendString:docDto.dateOfBirth];
        [returnValue appendString:@"</docDob>"];
        
        [returnValue appendString:@"<gender>"];
        [returnValue appendString:docDto.gender];
        [returnValue appendString:@"</gender>"];
        
        [returnValue appendString:@"<workHistory>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</workHistory>"];
        
        [returnValue appendString:@"<docMob>"];
        [returnValue appendString:docDto.mobile];
        [returnValue appendString:@"</docMob>"];
        
        [returnValue appendString:@"<docPhone>"];
        [returnValue appendString:docDto.phone];
        [returnValue appendString:@"</docPhone>"];
        
        [returnValue appendString:@"<docEmail>"];
        [returnValue appendString:docDto.email];
        [returnValue appendString:@"</docEmail>"];
        
        [returnValue appendString:@"<docAddr>"];
        [returnValue appendString:docDto.address];
        [returnValue appendString:@"</docAddr>"];
        
        [returnValue appendString:@"<docWorkingPlace>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</docWorkingPlace>"];
        
        [returnValue appendString:@"<docDesignation>"];
        [returnValue appendString:docDto.designation];
        [returnValue appendString:@"</docDesignation>"];
        
        [returnValue appendString:@"<docSpcl>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</docSpcl>"];
        
        [returnValue appendString:@"<docConsultationInterval>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</docConsultationInterval>"];
        
        [returnValue appendString:@"<status>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</status>"];
        
        [returnValue appendString:@"<docCreatedDateTime>"];
        [returnValue appendString:docDto.createdDateTime];
        [returnValue appendString:@"</docCreatedDateTime>"];
        
        [returnValue appendString:@"<docUpdatedDateTime>"];
        [returnValue appendString:docDto.updatedDateTime];
        [returnValue appendString:@"</docUpdatedDateTime>"];
        
        [returnValue appendString:@"<docExperience>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</docExperience>"];
        
        [returnValue appendString:@"<docQualifications>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</docQualifications>"];
        
        [returnValue appendString:@"<expertise>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</expertise>"];
        
        [returnValue appendString:@"<membership>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</membership>"];
        
        [returnValue appendString:@"<achievement>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</achievement>"];
        
        [returnValue appendString:@"<errorCode>"];
        [returnValue appendString:@"nil"];
        [returnValue appendString:@"</errorCode>"];
        
        [returnValue appendString:@"<success>"];
        [returnValue appendString:@"true"];
        [returnValue appendString:@"</success>"];
        
        //[returnValue appendString:@"<objType>"];
        //[returnValue appendString:docDto.objType];
        //[returnValue appendString:@"</objType>"];
        
        
        [returnValue appendString:@"</Doctor>"];
    }
    NSLog(returnValue);
    if (returnValue) {
        [[CommonSyncableGenerator sharedInstance] syncableGenerator:returnValue];
    }
    
}
@end
