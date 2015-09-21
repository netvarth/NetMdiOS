//
//  PatientLabViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 04/09/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "PatientLabViewController.h"
#import "PatientHeaderDetailsView.h"

@interface PatientLabViewController ()<UITableViewDataSource,UITableViewDelegate>

@property(nonatomic,strong) PatientHeaderDetailsView* hDetails;
@property(nonatomic,strong) IBOutlet UITableView* rxTbl;
-(IBAction)backBtnPrsd:(id)sender;
-(IBAction)newLabPrsd:(id)sender;

@end

@implementation PatientLabViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
     [self loadPatientDetailsHeader];
}

-(void)loadPatientDetailsHeader
{
    _hDetails = [[PatientHeaderDetailsView alloc] initWithFrame:CGRectMake(15.0f, 60.0f, 600.0f, 80.0f)];
    [self.view addSubview:_hDetails];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
    
    static NSString* cell1Identifier = @"RxCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cell1Identifier forIndexPath:indexPath];
    
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cell1Identifier];
    }
    
    return cell;
    
}

-(IBAction)backBtnPrsd:(id)sender
{
    [self.view removeFromSuperview];
}

-(IBAction)newLabPrsd:(id)sender
{
    UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:@"NewInvestigationsViewController"];
    vc.view.frame = CGRectMake(0.0f, 0.0f, 768.0f, 897.0f);
    [self.view addSubview:vc.view];
    [self addChildViewController:vc];
    [vc didMoveToParentViewController:self];
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
