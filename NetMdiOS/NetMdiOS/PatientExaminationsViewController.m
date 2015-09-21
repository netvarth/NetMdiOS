//
//  PatientExaminationsViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 17/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "PatientExaminationsViewController.h"
#import "PatientHeaderDetailsView.h"

@interface PatientExaminationsViewController ()<UITableViewDelegate,UITableViewDataSource,UIGestureRecognizerDelegate>
@property(nonatomic,strong) IBOutlet UITableView* tblView;
@property(nonatomic,strong)PatientHeaderDetailsView* hDetails;

-(IBAction)backBtnPrsd:(id)sender;
-(IBAction)newVisitPrsd:(id)sender;

@end

@implementation PatientExaminationsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
     [self loadPatientDetailsHeader];
    UILongPressGestureRecognizer* lpgr = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(handleLongPress:)];
    lpgr.minimumPressDuration = .5; //seconds
    lpgr.delegate = self;
    [self.view addGestureRecognizer:lpgr];
}

-(void)handleLongPress:(UILongPressGestureRecognizer *)gestureRecognizer
{
    if (gestureRecognizer.state != UIGestureRecognizerStateEnded) {
        return;
    }
    UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:@"VisitOptionsViewController"];
    vc.modalPresentationStyle = UIModalPresentationCustom;
    vc.modalTransitionStyle = UIModalTransitionStyleCoverVertical;
    vc.view.frame = CGRectMake(0.0f, 0.0f, 768.0f, 897.0f);
    [self.view addSubview:vc.view];
    [self addChildViewController:vc];
    [vc didMoveToParentViewController:self];
    
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
    return 10;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString* simpleTableIdentifier = @"ExaminationCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:simpleTableIdentifier];
        
    }
    
    
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:@"VisitDetailsViewController"];
    vc.view.frame = CGRectMake(0.0f, 0.0f, 768.0f, 870.0f);
    [self.view addSubview:vc.view];
    [self addChildViewController:vc];
    [vc didMoveToParentViewController:self];

}


-(void)loadPatientDetailsHeader
{
    _hDetails = [[PatientHeaderDetailsView alloc] initWithFrame:CGRectMake(0.0f, 43.0f, 750.0f, 65.0f)];
    [self.view addSubview:_hDetails];
}

-(IBAction)backBtnPrsd:(id)sender
{
    [self.view removeFromSuperview];
}
-(IBAction)newVisitPrsd:(id)sender
{
    UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:@"NewVisitViewController"];
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
