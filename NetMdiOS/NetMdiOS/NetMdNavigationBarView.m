//
//  NetMdNavigationBarView.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 21/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "NetMdNavigationBarView.h"
#import "SettingsNavCntrl.h"
@interface NetMdNavigationBarView()
@property(nonatomic,strong) SettingsNavCntrl* settingsNavCntrl;
@end
@implementation NetMdNavigationBarView


-(NetMdNavigationBarView *) init
{
    NetMdNavigationBarView *result = nil;
    NSArray* elements = [[NSBundle mainBundle] loadNibNamed: NSStringFromClass([self class]) owner:self options: nil];
    for (id anObject in elements)
    {
        if ([anObject isKindOfClass:[self class]])
        {
            result = anObject;
            break;
        }
    }
    return result;
}

-(IBAction)settingsPressed:(id)sender
{
    NSLog(@"Settings pressed");
    UIStoryboard* storyboard = [UIStoryboard storyboardWithName:@"MainStoryboard" bundle:nil];
    _settingsNavCntrl = [storyboard instantiateViewControllerWithIdentifier:@"SettingsNavCntrl"];
    _settingsNavCntrl.modalPresentationStyle = UIModalPresentationPopover;
   
}

@end
