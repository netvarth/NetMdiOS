//
//  PatientDetailsViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 06/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "PatientDetailsViewController.h"
#import "NavigationController.h"

@interface PatientDetailsViewController ()
@property(nonatomic,strong) NavigationController* navCtrl;
@property(nonatomic,strong) IBOutlet UIButton* backBtn;
-(IBAction)backBtnPressed:(id)sender;

@end

@implementation PatientDetailsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)backBtnPressed:(id)sender
{
    [self.view removeFromSuperview];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
