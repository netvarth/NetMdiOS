//
//  NewPatientViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 05/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "NewPatientViewController.h"

@interface NewPatientViewController ()<UIPickerViewDataSource,UIPickerViewDelegate>
@property(nonatomic,strong) IBOutlet UITextField* fName;
@property(nonatomic,strong) IBOutlet UITextField* lName;
@property(nonatomic,strong) IBOutlet UITextField* gender;
@property(nonatomic,strong) IBOutlet UITextField* landLine;
@property(nonatomic,strong) IBOutlet UITextField* mob;
@property(nonatomic,strong) IBOutlet UITextField* dob;
@property(nonatomic,strong) IBOutlet UIButton* calender;
@property(nonatomic,strong) IBOutlet UITextField* mStatus;
@property(nonatomic,strong) IBOutlet UITextField* email;
@property(nonatomic,strong) IBOutlet UIButton* addressBtn;
@property(nonatomic,strong) IBOutlet UIButton* emergencyInfoBtn;
@property(nonatomic,strong) IBOutlet UIButton* medInfoBtn;
@property(nonatomic,strong) IBOutlet UIButton* currentMedCondBtn;
@property(nonatomic,strong) IBOutlet UIButton* patMedHistoryBtn;
@property(nonatomic,strong) IBOutlet UIDatePicker* datePicker;
@property(nonatomic,strong) NSDateFormatter* dateFormatter;
@property(nonatomic,strong) UIPickerView* genderList;
@property(nonatomic,strong) UIPickerView* statusList;
@property(nonatomic,strong) NSArray* genderArray;
@property(nonatomic,strong) NSArray* statusArray;

-(IBAction)calenderPrsd:(id)sender;
-(IBAction)addressPrsd:(id)sender;
-(IBAction)emergencyContactPrsd:(id)sender;
-(IBAction)medBasicPrsd:(id)sender;
-(IBAction)currentMedCondPrsd:(id)sender;
-(IBAction)patMedHistoryPrsd:(id)sender;
-(IBAction)cancelPrsd:(id)sender;
-(IBAction)savePrsd:(id)sender;
-(void)valueChanged;
@end

@implementation NewPatientViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    _dateFormatter = [[NSDateFormatter alloc] init];
    _dateFormatter.dateFormat = @"yyyy-MM-dd";
    _dateFormatter.timeZone = [NSTimeZone systemTimeZone];
    _datePicker = [[UIDatePicker alloc] init];
    _datePicker.datePickerMode = UIDatePickerModeDate;
    _datePicker.date = [NSDate date];
    [_datePicker addTarget:self action:@selector(valueChanged:) forControlEvents:UIControlEventValueChanged];

    _mStatus.delegate = self;
    _gender.delegate = self;
}

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField
{
 UIViewController* pickerVC = [[UIViewController alloc] init];
    if (textField.tag == 1)
    {
        
         _genderArray = [[NSArray alloc] initWithObjects:@"Male",@"Female",@"Transgender", nil];
        _genderList = [[UIPickerView alloc] init];
        _genderList.tag = 3;
        _genderList.showsSelectionIndicator = YES;
        _genderList.hidden = NO;
        _genderList.delegate = self;
        pickerVC.view = _genderList;
        
        UIPopoverController* popOver = [[UIPopoverController alloc] initWithContentViewController:pickerVC];
        popOver.popoverContentSize = CGSizeMake(150.0f, 90.0f);
        [popOver presentPopoverFromRect:textField.frame inView:textField.superview permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
    }
    else
    {

        _statusArray = [[NSArray alloc] initWithObjects:@"Single",@"Married",@"Divorsed",@"Widowed",@"Widower", nil];
        _statusList = [[UIPickerView alloc] init];
        _statusList.tag = 4;
        _statusList.showsSelectionIndicator = YES;
        _statusList.hidden = NO;
        _statusList.delegate = self;
        pickerVC.view = _statusList;
        
        UIPopoverController* popOver = [[UIPopoverController alloc] initWithContentViewController:pickerVC];
        popOver.popoverContentSize = CGSizeMake(140.0f, 180.0f);
        [popOver presentPopoverFromRect:textField.frame inView:textField.superview permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];

    }
    return NO;
}

//Columns in picker views

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView; {
    return 1;
}
//Rows in each Column

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component; {
    if (pickerView.tag == 3)
    {
        return _genderArray.count;
    } else
    {
        return _statusArray.count;
    }
    
}

-(NSString*) pickerView:(UIPickerView*)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    if (pickerView.tag == 3)
    {
         return [_genderArray objectAtIndex:row];
    } else
    {
        return [_statusArray objectAtIndex:row];
    }
   
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;
{
    if (pickerView.tag ==3)
    {
         _gender.text = _genderArray[row];
    } else
    {
        _mStatus.text = _statusArray[row];
    }
   
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)calenderPrsd:(id)sender
{
    UIViewController* datePickerVC = [[UIViewController alloc] init];
    datePickerVC.view = _datePicker;
    UIPopoverController* _popOver = [[UIPopoverController alloc] initWithContentViewController:datePickerVC];
    _popOver.popoverContentSize = CGSizeMake(250.0f, 200.0f);
    [_popOver presentPopoverFromRect:_calender.frame inView:_calender.superview permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
    _dob.text = [_dateFormatter stringFromDate:_datePicker.date];
    
}

-(void)valueChanged:(id)sender
{
    _dob.text = [_dateFormatter stringFromDate:[_datePicker date]];
}

-(IBAction)addressPrsd:(id)sender
{
    
}
-(IBAction)emergencyContactPrsd:(id)sender
{
    
}
-(IBAction)medBasicPrsd:(id)sender
{
    
}
-(IBAction)currentMedCondPrsd:(id)sender
{
    UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:@"PatientCurrentMedCondition"];
    UIPopoverController* popOver = [[UIPopoverController alloc] initWithContentViewController:vc];
    popOver.popoverContentSize = CGSizeMake(400.0f, 550.0f);
    [popOver presentPopoverFromRect:_currentMedCondBtn.frame inView:_currentMedCondBtn.superview permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
}
-(IBAction)patMedHistoryPrsd:(id)sender
{
    
}
-(IBAction)cancelPrsd:(id)sender
{
    [self.view removeFromSuperview];
}
-(IBAction)savePrsd:(id)sender
{
    
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
