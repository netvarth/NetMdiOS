//
//  CurrentUserDTO.m
//  NewNetMdBL
//
//  Created by Netvarth_Mac2 on 16/01/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import "CurrentUserDTO.h"

@implementation CurrentUserDTO

@synthesize userName, userType, password,Id,loginId,globalId, name, gender, email, phone, mobile, dateOfBirth, address, selectedDoctorId;

- (id)initWithCoder:(NSCoder *)aDecoder {
    if (self = [super init]) {
        self.Id = [aDecoder decodeIntForKey:@"Id"];
        self.globalId = [aDecoder decodeIntForKey:@"globalId"];
        self.loginId = [aDecoder decodeIntForKey:@"loginId"];
        self.name = [aDecoder decodeObjectForKey:@"name"];
        self.userName = [aDecoder decodeObjectForKey:@"userName"];
        self.userType = [aDecoder decodeObjectForKey:@"userType"];
        self.password = [aDecoder decodeObjectForKey:@"password"];
        self.gender = [aDecoder decodeObjectForKey:@"gender"];
        self.email = [aDecoder decodeObjectForKey:@"email"];
        self.phone = [aDecoder decodeObjectForKey:@"phone"];
        self.mobile = [aDecoder decodeObjectForKey:@"mobile"];
        self.dateOfBirth = [aDecoder decodeObjectForKey:@"dateOfBirth"];
        self.address = [aDecoder decodeObjectForKey:@"address"];
        self.selectedDoctorId = [aDecoder decodeIntForKey:@"selectedDoctorId"];
        
    }
    return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder {
    [aCoder encodeInt:Id forKey:@"Id"];
    [aCoder encodeInt:globalId forKey:@"globalId"];
    [aCoder encodeInt:loginId
     
               forKey:@"loginId"];
    [aCoder encodeObject:name forKey:@"name"];
    [aCoder encodeObject:userName forKey:@"userName"];
    [aCoder encodeObject:userType forKey:@"userType"];
    [aCoder encodeObject:password forKey:@"password"];
    [aCoder encodeObject:gender forKey:@"gender"];
    [aCoder encodeObject:email forKey:@"email"];
    [aCoder encodeObject:phone forKey:@"phone"];
    [aCoder encodeObject:mobile forKey:@"mobile"];
    [aCoder encodeObject:dateOfBirth forKey:@"dateOfBirth"];
    [aCoder encodeObject:address forKey:@"address"];
    [aCoder encodeInt:selectedDoctorId forKey:@"selectedDoctorId"];
}
@end
