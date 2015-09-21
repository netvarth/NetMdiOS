//
//  NewVisitViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 21/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "NewVisitViewController.h"

@interface NewVisitViewController ()<UIPickerViewDelegate,UIPickerViewDataSource>
@property(nonatomic,strong) IBOutlet UILabel* date;
@property(nonatomic,strong) IBOutlet UILabel* time;
@property(nonatomic,strong) IBOutlet UIButton* calenderBtn;
@property(nonatomic,strong) IBOutlet UIButton* clockBtn;
@property(nonatomic,strong) IBOutlet UIDatePicker* datePicker;
@property(nonatomic,strong) NSDateFormatter* dateFormatter;
@property(nonatomic,strong) NSArray* timeArray;
@property(nonatomic,strong) UIPickerView* timePicker;
-(IBAction)calenderBtnPrsd:(id)sender;
-(IBAction)clockBtnPrsd:(id)sender;
-(IBAction)cancelBtnPrsd:(id)sender;
-(IBAction)addReadings:(id)sender;
-(IBAction)viewReadings:(id)sender;
-(IBAction)addInvestigation:(id)sender;
-(IBAction)viewInvestigation:(id)sender;
-(IBAction)addMedication:(id)sender;
-(IBAction)viewMedication:(id)sender;
-(IBAction)addPreExamination:(id)sender;
-(IBAction)viewPreExamination:(id)sender;


@end

@implementation NewVisitViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor lightGrayColor];
    _dateFormatter = [[NSDateFormatter alloc] init];
    _dateFormatter.dateFormat = @"yyyy-MM-dd";
    _dateFormatter.timeZone = [NSTimeZone systemTimeZone];
    _datePicker = [[UIDatePicker alloc] init];
    _datePicker.datePickerMode = UIDatePickerModeDate;
    _datePicker.date = [NSDate date];
     [_datePicker addTarget:self action:@selector(dateChanged:) forControlEvents:UIControlEventValueChanged];
    _date.text = [_dateFormatter stringFromDate:[NSDate date]];
    _timeArray = [[NSArray alloc] initWithObjects:@"12:00 AM", @"12:30 AM",
                  @"01:00 AM",
                  @"01:30 AM",
                  @"02:00 AM",
                  @"02:30 AM",
                  @"03:00 AM",
                  @"03:30 AM",
                  @"04:00 AM",
                  @"04:30 AM",
                  @"05:00 AM",
                  @"05:30 AM",
                  @"06:00 AM",
                  @"06:30 AM",
                  @"07:00 AM",
                  @"07:30 AM",
                  @"08:00 AM",
                  @"08:30 AM",
                  @"09:00 AM",
                  @"09:30 AM",
                  @"10:00 AM",
                  @"10:30 AM",
                  @"11:00 AM",
                  @"11:30 AM",
                  @"12:00 PM",
                  @"12:30 PM",
                  @"01:00 PM",
                  @"01:30 PM",
                  @"02:00 PM",
                  @"02:30 PM",
                  @"03:00 PM",
                  @"03:30 PM",
                  @"04:00 PM",
                  @"04:30 PM",
                  @"05:00 PM",
                  @"05:30 PM",
                  @"06:00 PM",
                  @"06:30 PM",
                  @"07:00 PM",
                  @"07:30 PM",
                  @"08:00 PM",
                  @"08:30 PM",
                  @"09:00 PM",
                  @"09:30 PM",
                  @"10:00 PM",
                  @"10:30 PM",
                  @"11:00 PM",
                  @"11:30 PM",
                  nil];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)calenderBtnPrsd:(id)sender
{
    UIViewController* vc = [[UIViewController alloc] init];
    vc.view = _datePicker;
    UIPopoverController* popOver = [[UIPopoverController alloc] initWithContentViewController:vc];
    popOver.popoverContentSize = CGSizeMake(250.0f, 200.0f);
    [popOver presentPopoverFromRect:CGRectMake(250.0f, 400.0f, 250.0f, 200.0f) inView:self.view permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
   
}

-(IBAction)clockBtnPrsd:(id)sender
{
    UIViewController* vc = [[UIViewController alloc] init];
    _timePicker = [[UIPickerView alloc] init];
    _timePicker.showsSelectionIndicator = YES;
    _timePicker.hidden = NO;
    _timePicker.delegate = self;
    _timePicker.dataSource = self;
    [_timePicker selectRow:18 inComponent:0 animated:YES];
    vc.view = _timePicker;
    UIPopoverController* timeListPopOverCtrl = [[UIPopoverController alloc] initWithContentViewController:vc];
    timeListPopOverCtrl.popoverContentSize = CGSizeMake(250.0f, 200.0f);
    [timeListPopOverCtrl presentPopoverFromRect:_clockBtn.frame inView:_clockBtn.superview permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
}

-(IBAction)cancelBtnPrsd:(id)sender
{
    [self.view removeFromSuperview];
}

-(void)dateChanged:(id)sender
{
    _date.text = [_dateFormatter stringFromDate:_datePicker.date];
}

//Columns in picker views

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView; {
    return 1;
}
//Rows in each Column

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component; {
    return _timeArray.count;
    
}

-(NSString*) pickerView:(UIPickerView*)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    return [_timeArray objectAtIndex:row];
    
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;
{
    _time.text = [_timeArray objectAtIndex:row];
    
}
-(IBAction)addReadings:(id)sender
{
    [self loadViewController:@"NewReadingsViewController"];
}
-(IBAction)viewReadings:(id)sender
{
    
}
-(IBAction)addInvestigation:(id)sender
{
     [self loadViewController:@"NewInvestigationsViewController"];
}
-(IBAction)viewInvestigation:(id)sender
{
    
}
-(IBAction)addMedication:(id)sender
{
     [self loadViewController:@"NewMedicationViewController"];
}
-(IBAction)viewMedication:(id)sender
{
    
}
-(IBAction)addPreExamination:(id)sender
{
     [self loadViewController:@"NewPreExaminationViewController"];
}
-(IBAction)viewPreExamination:(id)sender
{
    
}

-(void)loadViewController:(NSString*)vcName
{
    UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:vcName];
    vc.modalPresentationStyle = UIModalPresentationCustom;
    vc.modalTransitionStyle = UIModalTransitionStyleCoverVertical;
    vc.view.frame = CGRectMake(0.0f, 0.0f, 768.0f, 897.0f);
    [self.view addSubview:vc.view];
    [self addChildViewController:vc];
    [vc didMoveToParentViewController:self];

}
@end
