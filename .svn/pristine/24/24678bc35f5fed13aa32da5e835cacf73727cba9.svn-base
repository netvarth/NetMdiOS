//
//  NetMDTabBarController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 20/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "NetMDTabBarController.h"
#import "NetMdNavigationBarView.h"
#import "NavBarViewController.h"

@interface NetMDTabBarController()

@property(nonatomic,strong) NetMdNavigationBarView* netMdNavBarView;

@end

@implementation NetMDTabBarController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
/*
    [self.navigationController.navigationBar setHidden:YES];
    _netMdNavBarView = [[NetMdNavigationBarView alloc] init];
    [_netMdNavBarView setFrame:CGRectMake(0.0f, 0.0f, self.navigationController.navigationBar.frame.size.width, _netMdNavBarView.frame.size.height)];
    _netMdNavBarView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    [self.view addSubview:_netMdNavBarView];
*/
  
    [self.navigationController.navigationBar setHidden:YES];
    NavBarViewController* nav = [self.storyboard instantiateViewControllerWithIdentifier:@"NavBarViewController"];
    nav.view.frame = CGRectMake(0.0f, 0.0f, 768.0f, 78.0f);
    [self.view addSubview:nav.view];
    [self addChildViewController:nav];
    [nav didMoveToParentViewController:self];
   
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator
{
    NSLog(@"");
}
@end
