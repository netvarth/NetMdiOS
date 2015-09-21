//
//  DoctorAchievement.m
//  NetMdBL
//
//  Created by Surendar Modugu on 3/15/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "DoctorAchievementDTO.h"

@implementation DoctorAchievementDTO

- (id)initWithAchievement:(int)achievementId
               doctorId :(int)doctorId
               membership:(NSString*)achievement
               actionName:(NSString*)actionName {
    
    self    = [super init];
    if (self != nil) {
        self.Id  = achievementId;
        self.doctorId       = doctorId;
        self.achievement    = achievement;
        self.actionName     = actionName;
    
    }
    
    return self;
}

@end
