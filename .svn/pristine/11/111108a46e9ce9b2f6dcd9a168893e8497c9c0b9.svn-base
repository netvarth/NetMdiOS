//
//  NewInvestigationsViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 25/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "NewInvestigationsViewController.h"

@interface NewInvestigationsViewController ()<UITableViewDataSource,UITableViewDelegate>
@property(nonatomic,strong) IBOutlet UITableView* tblView;
-(IBAction)cancelPrsd:(id)sender;
-(IBAction)donePrsd:(id)sender;
-(IBAction)editCellPrsd:(id)sender;
-(IBAction)deleteCellPrsd:(id)sender;

@end

@implementation NewInvestigationsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
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
    return 4;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString* simpleTableIdentifier = @"InvestigationCell";
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
    NSString *cellText = cell.textLabel.text;
}


-(IBAction)cancelPrsd:(id)sender
{
    [self.view removeFromSuperview];
}

-(IBAction)donePrsd:(id)sender
{
    
}
-(IBAction)editCellPrsd:(id)sender
{
    UIButton* cpyBtn = (UIButton*) sender;
    cpyBtn.selected =  !cpyBtn.selected;
}
-(IBAction)deleteCellPrsd:(id)sender
{
    
}

@end
