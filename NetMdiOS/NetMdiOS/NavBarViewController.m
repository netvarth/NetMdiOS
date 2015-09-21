//
//  NavBarViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 28/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "NavBarViewController.h"
#import "SettingsNavCntrl.h"

@interface NavBarViewController ()

@property(nonatomic,strong) IBOutlet UILabel* lblCompany;
@property(nonatomic,strong) IBOutlet UILabel* lblBranch;
@property(nonatomic,strong) IBOutlet UILabel* lblVersion;
@property(nonatomic,strong) IBOutlet UILabel* lblUserName;
@property(nonatomic,strong) IBOutlet UIButton* btnSettings;
@property(nonatomic,strong) SettingsNavCntrl* stngsNavCtrl;

-(IBAction)settingsPressed:(id)sender;

@end

@implementation NavBarViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(IBAction)settingsPressed:(id)sender
{
    _stngsNavCtrl = [self.storyboard instantiateViewControllerWithIdentifier:@"SettingsNavCntrl"];
   // _stngsNavCtrl.contentSizeForViewInPopover = CGSizeMake(200.0f, 200.0f);
    UIPopoverController* popOverCtrl = [[UIPopoverController alloc] initWithContentViewController:_stngsNavCtrl];
    popOverCtrl.popoverContentSize = CGSizeMake(200.0f, 300.0f);
    [popOverCtrl presentPopoverFromRect:_btnSettings.frame inView:self.view permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
    
}

@end