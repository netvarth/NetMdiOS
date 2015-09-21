//
//  PatientDetailsView.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 13/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "PatientDetailsView.h"

@implementation PatientDetailsView

-(id)initWithFrame:(CGRect)frame
{
    self = [[[NSBundle mainBundle] loadNibNamed:@"PatientDetailsView" owner:self options:nil] lastObject];
    if (self)
    {
        self.frame = frame;
    }
    return self;
}

@end
