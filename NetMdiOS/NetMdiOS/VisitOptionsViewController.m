//
//  VisitOptionsViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 20/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "VisitOptionsViewController.h"

@interface VisitOptionsViewController ()

-(IBAction)labPrsd:(id)sender;
-(IBAction)rxPrsd:(id)sender;
-(IBAction)delPrsd:(id)sender;
-(IBAction)cancelPrsd:(id)sender;

@end

@implementation VisitOptionsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)labPrsd:(id)sender
{
    CGRect frame = CGRectMake(0.0f, 79.0f, 768.0f, 897.0f);
    [self loadViewControllers:@"NewInvestigationsViewController" withCGrect:(CGRect)frame];
}
-(IBAction)rxPrsd:(id)sender
{
    CGRect frame = CGRectMake(0.0f, 79.0f, 768.0f, 897.0f);
    [self loadViewControllers:@"NewMedicationViewController" withCGrect:(CGRect)frame];
}
-(IBAction)delPrsd:(id)sender
{
    
}
-(void)loadViewControllers:(NSString*)vcName withCGrect:(CGRect)frame
{
    UIViewController* rvc = [[[UIApplication sharedApplication] keyWindow] rootViewController];
    UIViewController* vc= [self.storyboard instantiateViewControllerWithIdentifier:vcName];
    vc.view.frame = frame;
    [rvc.view addSubview:vc.view];
    [rvc addChildViewController:vc];
    [vc didMoveToParentViewController:rvc];
    [self.view removeFromSuperview];
}

-(IBAction)cancelPrsd:(id)sender
{
    [self.view removeFromSuperview];
}
@end