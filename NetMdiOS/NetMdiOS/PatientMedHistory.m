//
//  PatientMedHistory.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 12/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "PatientMedHistory.h"

@interface PatientMedHistory ()<UITableViewDelegate,UITableViewDataSource>
@property(nonatomic,strong) IBOutlet UITableView* tblView;
@property(nonatomic,strong) IBOutlet UISegmentedControl* segmentCtrl;
@property(nonatomic,strong) NSArray* list;
@property(nonatomic,strong) IBOutlet UILabel* familyMedhistory;
@property(nonatomic,strong) IBOutlet UILabel* lblfor;
@property(nonatomic,strong) IBOutlet UITextField* txtDisease;
@property(nonatomic,strong) IBOutlet UITextField* txtMember;
@property(nonatomic,strong) IBOutlet UIButton* addBtn;

//personalsegment property
@property(nonatomic,strong) IBOutlet UILabel* diagnosed;
@property(nonatomic,strong) IBOutlet UILabel* otherDiseases;
@property(nonatomic,strong) IBOutlet UILabel* surgeriesDoneIfAny;
@property(nonatomic,strong) IBOutlet UITextView* diagnosedTxtView;
@property(nonatomic,strong) IBOutlet UITextView* surgeriesTxtView;
@property(nonatomic,strong) IBOutlet UITextField* otherTxfld;

-(IBAction)segmentValueChanged:(id)sender;
-(IBAction)cancelPrsd:(id)sender;

@end

@implementation PatientMedHistory
-(void)viewDidLoad
{
    [super viewDidLoad];
    _list = [[NSArray alloc] initWithObjects:@"Diabetics for mother",@"Blood pressure for Father", nil];
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return _list.count;
}

-(UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *simpleTableIdentifier = @"SimpleTableItem";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:simpleTableIdentifier];
    }
    
    cell.textLabel.text = [_list objectAtIndex:indexPath.row];
    return cell;
}

-(IBAction)segmentValueChanged:(id)sender
{
    UISegmentedControl* segment = (UISegmentedControl*)sender;
    switch (segment.selectedSegmentIndex)
    {
      
        case 0:
            //family
            
            //hide personal details
            _diagnosed.hidden = YES;
            _otherDiseases.hidden = YES;
            _surgeriesDoneIfAny.hidden = YES;
            _diagnosedTxtView.hidden = YES;
            _surgeriesTxtView.hidden = YES;
            _otherTxfld.hidden = YES;
            
            
        //show
            _familyMedhistory.hidden = NO;
            _lblfor.hidden = NO;
            _txtDisease.hidden = NO;
            _txtMember.hidden = NO;
            _tblView.hidden = NO;
            _addBtn.hidden =NO;
            break;
            
        case 1:
            //personal
            //hide all family details
     
            _familyMedhistory.hidden = YES;
            _lblfor.hidden = YES;
            _txtDisease.hidden = YES;
            _txtMember.hidden = YES;
            _tblView.hidden = YES;
            _addBtn.hidden =YES;
            
            //show all personal details
            _diagnosed = [[UILabel alloc] initWithFrame:CGRectMake(16.0f, 102.0f,111.0f, 21.0f)];
            _diagnosed.text = @"Diagsoned for";
            _diagnosed.textColor = [UIColor blackColor];
            _diagnosed.hidden = NO;
            _diagnosed.numberOfLines = 0;
            [self.view addSubview:_diagnosed];
            
            _otherDiseases = [[UILabel alloc] initWithFrame:CGRectMake(16.0f, 181.0f,115.0f, 21.0f)];
            _otherDiseases.text = @"Other diseases";
            _otherDiseases.textColor = [UIColor blackColor];
            _otherDiseases.hidden = NO;
            _otherDiseases.numberOfLines = 0;
            [self.view addSubview:_otherDiseases];
            
            _surgeriesDoneIfAny = [[UILabel alloc] initWithFrame:CGRectMake(16.0f, 271.0f,162.0f, 21.0f)];
            _surgeriesDoneIfAny.text = @"Surgeries done if any";
            _surgeriesDoneIfAny.textColor = [UIColor blackColor];
            _surgeriesDoneIfAny.hidden = NO;
            _surgeriesDoneIfAny.numberOfLines = 0;
            [self.view addSubview:_surgeriesDoneIfAny];
            
            _diagnosedTxtView = [[UITextView alloc] initWithFrame:CGRectMake(41.0f, 131.0f, 226.0f, 32.0f)];
            _diagnosedTxtView.hidden = NO;
            [self.view addSubview:_diagnosedTxtView];
            
            _surgeriesTxtView = [[UITextView alloc] initWithFrame:CGRectMake(41.0f, 300.0f, 226.0f, 32.0f)];
            _surgeriesTxtView.hidden = NO;
            [self.view addSubview:_surgeriesTxtView];
            
            _otherTxfld = [[UITextField alloc] initWithFrame:CGRectMake(41.0f, 215.0f, 226.0f, 30.0f)];
            _otherTxfld.hidden = NO;
            _otherTxfld.backgroundColor = [UIColor whiteColor];
            [self.view addSubview:_otherTxfld];
            
            break;
   
    }
}
-(IBAction)cancelPrsd:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
