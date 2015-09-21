//
//  PatientsViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 20/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "PatientsViewController.h"
#import "AddPatientViewController.h"
#import "NewPatientViewController.h"
#import "PatientCellTableViewCell.h"
#import "PatientDetailsViewController.h"

@interface PatientsViewController()<UITableViewDataSource,UITableViewDelegate,UIGestureRecognizerDelegate>
//@property(nonatomic,strong) AddPatientViewController* addPatientVc;
@property(nonatomic,strong) NewPatientViewController* addPatientVc;
@property(nonatomic,strong) IBOutlet UITableView* tblView;
@property(nonatomic,strong) PatientDetailsViewController* patientDetailsVc;

-(IBAction)newPatientPressed:(id)sender;

@end

@implementation PatientsViewController

-(void) viewDidLoad
{
    [super viewDidLoad];
    UILongPressGestureRecognizer* lpgr = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(handleLongPress:)];
    lpgr.minimumPressDuration = .5; //seconds
    lpgr.delegate = self;
    [self.view addGestureRecognizer:lpgr];
    _patientDetailsVc = [self.storyboard instantiateViewControllerWithIdentifier:@"PatientDetailsViewController"];
  
}
-(IBAction)newPatientPressed:(id)sender
{
    //_addPatientVc = [self.storyboard instantiateViewControllerWithIdentifier:@"AddPatientViewController"];
    _addPatientVc = [self.storyboard instantiateViewControllerWithIdentifier:@"NewPatientViewController"];
    _addPatientVc.modalPresentationStyle = UIModalPresentationCustom;
    _addPatientVc.modalTransitionStyle = UIModalTransitionStyleCoverVertical;
     _addPatientVc.view.frame = CGRectMake(0.0f, 79.0f, 768.0f, 897.0f);
    [self.view addSubview:_addPatientVc.view];
    [self addChildViewController:_addPatientVc];
    [_addPatientVc didMoveToParentViewController:self];
    
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 3;
}

-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString* cellIdentifier = @"PatientCell";
    PatientCellTableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier forIndexPath:indexPath];
    if (cell == nil)
    {
        cell = [[PatientCellTableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
    }
    
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
   
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    UITableViewCell* cell = [tableView cellForRowAtIndexPath:indexPath];
    NSString* title = cell.textLabel.text;
    _patientDetailsVc.view.frame = CGRectMake(0.0f, 148.0f, 768.0f, 830.0f);
  
    [self.view addSubview:_patientDetailsVc.view];
    [self addChildViewController:_patientDetailsVc];
    [_patientDetailsVc didMoveToParentViewController:self];
    
}
-(void)handleLongPress:(UILongPressGestureRecognizer *)gestureRecognizer
{
    if (gestureRecognizer.state != UIGestureRecognizerStateEnded) {
        return;
    }
    UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:@"PatientOptions"];
    vc.modalPresentationStyle = UIModalPresentationCustom;
    vc.modalTransitionStyle = UIModalTransitionStyleCoverVertical;
    vc.view.frame = CGRectMake(0.0f, 79.0f, 768.0f, 897.0f);
    [self.view addSubview:vc.view];
    [self addChildViewController:vc];
    [vc didMoveToParentViewController:self];

}
- (void)viewWillAppear:(BOOL)animated
{
}
@end
