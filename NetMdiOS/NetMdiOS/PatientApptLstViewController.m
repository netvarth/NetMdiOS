//
//  PatientApptLstViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 11/09/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "PatientApptLstViewController.h"

@interface PatientApptLstViewController ()<UITableViewDelegate,UITableViewDataSource>

@property(nonatomic,strong) IBOutlet UITableView* tbl;

-(IBAction)backBtnPrsd:(id)sender;
-(IBAction)NewApptBtnPrsd:(id)sender;

@end

@implementation PatientApptLstViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)backBtnPrsd:(id)sender
{
    [self.view removeFromSuperview];
}

-(IBAction)NewApptBtnPrsd:(id)sender
{
    UIViewController* rvc = [[[UIApplication sharedApplication] keyWindow] rootViewController];
    UIViewController* vc =[self.storyboard instantiateViewControllerWithIdentifier:@"PatientNewApptViewController"];
    vc.view.frame = CGRectMake(0.0f, 78.0f, 768.0f, 897.0f);
    [rvc.view addSubview:vc.view];
    [rvc addChildViewController:vc];
    [vc didMoveToParentViewController:rvc];
}
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
#warning Potentially incomplete method implementation.
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
#warning Incomplete method implementation.
    // Return the number of rows in the section.
    return 5;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString* simpleTableIdentifier = @"ApptList";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:simpleTableIdentifier];
    }
    
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
}
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 80.0f;
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
