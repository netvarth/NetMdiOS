//
//  PatientNewApptViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 11/09/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "PatientNewApptViewController.h"

@interface PatientNewApptViewController ()<UIPickerViewDataSource,UIPickerViewDelegate,UITableViewDelegate,UITableViewDataSource>

-(IBAction)backBtnPrsd:(id)sender;
@property(nonatomic,strong) IBOutlet UITextField* purpose;
@property(nonatomic,strong) IBOutlet UITextField* when;
@property(nonatomic,strong) UIPickerView* purposeList;
@property(nonatomic,strong) UIPickerView* whenList;
@property(nonatomic,strong) NSArray* purposeListArray;
@property(nonatomic,strong) NSArray* whenListArray;
@property(nonatomic,strong) IBOutlet UITableView* tbl;

@end

@implementation PatientNewApptViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    _purpose.delegate = self;
    _when.delegate = self;
}

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField
{
    UIViewController* pickerVC = [[UIViewController alloc] init];
    if (textField.tag == 1)
    {
        _purposeListArray = [[NSArray alloc] initWithObjects:@"Procedure",@"Backup",@"Procedure",@"Procedure" ,nil];
        _purposeList = [[UIPickerView alloc] init];
        _purposeList.hidden = NO;
        _purposeList.showsSelectionIndicator = YES;
        _purposeList.tag = 3;
        _purposeList.delegate = self;
        pickerVC.view = _purposeList;
        UIPopoverController* popOver = [[UIPopoverController alloc] initWithContentViewController:pickerVC];
        popOver.popoverContentSize = CGSizeMake(150.0f, 90.0f);
        [popOver presentPopoverFromRect:textField.frame inView:textField.superview permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
    }
    else if(textField.tag == 2)
    {
        _whenListArray = [[NSArray alloc] initWithObjects:@"Procedure",@"Backup",@"Procedure",@"Procedure" , nil];
        _whenList = [[UIPickerView alloc] init];
        _whenList.showsSelectionIndicator = YES;
        _whenList.hidden = NO;
        _whenList.tag = 4;
        _whenList.delegate = self;
        pickerVC.view =_whenList;
        UIPopoverController* popOver = [[UIPopoverController alloc] initWithContentViewController:pickerVC];
        popOver.popoverContentSize = CGSizeMake(150.0f, 90.0f);
        [popOver presentPopoverFromRect:textField.frame inView:textField.superview permittedArrowDirections:UIPopoverArrowDirectionAny animated:YES];
    }
    return NO;
}
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView; {
    return 1;
}
//Rows in each Column

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component; {
    if (pickerView.tag == 3)
    {
        return _purposeListArray.count;
    }
    else if (pickerView.tag == 4)
    {
        return _whenListArray.count;
    }
    return 0;
}

-(NSString*) pickerView:(UIPickerView*)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    if (pickerView.tag == 3)
    {
        return [_purposeListArray objectAtIndex:row];
    }
    else if (pickerView.tag == 4)
    {
        return [_whenListArray objectAtIndex:row];
    }
  return 0;
    
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;
{
    if (pickerView.tag ==3)
    {
        _purpose.text = _purposeListArray[row];
    }
    else if (pickerView.tag ==4)
    {
        _when.text = _whenListArray[row];
    }
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)backBtnPrsd:(id)sender
{
    [self.view removeFromSuperview];
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
    static NSString* simpleTableIdentifier = @"ApptBookingList";
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

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
