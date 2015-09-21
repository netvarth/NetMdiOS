//
//  ScheduleView.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 23/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "ScheduleView.h"

@implementation ScheduleView

-(ScheduleView*)init
{
    ScheduleView* result = nil;
    NSArray* elements = [[NSBundle mainBundle] loadNibNamed:NSStringFromClass([self class]) owner:self options:nil];
    for (id anObject in elements )
    {
        if ([anObject isKindOfClass:[self class]])
        {
            result = anObject;
            break;
        }
    }
    return result;
}

@end
