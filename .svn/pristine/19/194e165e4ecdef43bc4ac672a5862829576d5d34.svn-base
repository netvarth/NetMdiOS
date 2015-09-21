//
//  CurrentMedConditionView.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 13/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "CurrentMedConditionView.h"


@implementation CurrentMedConditionView

-(id)initWithFrame:(CGRect)frame
{
    self = [[[NSBundle mainBundle] loadNibNamed:@"CurrentMedConditionView" owner:self options:nil] lastObject];
    if (self)
    {
        self.frame = frame;
    }
    [self loadPatientDetailsHeader];
    return self;
}

-(void)loadPatientDetailsHeader
{
    _hDetails = [[PatientHeaderDetailsView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 600.0f, 80.0f)];
    [self addSubview:_hDetails];
}
@end
