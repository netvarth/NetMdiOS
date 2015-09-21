//
//  NewMedicationViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 03/09/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "NewMedicationViewController.h"

@interface NewMedicationViewController ()<UITableViewDelegate,UITableViewDataSource>

@property(nonatomic,strong) IBOutlet UITableView* medicationTblView;
-(IBAction)cancelPrsd:(id)sender;
@end

@implementation NewMedicationViewController

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
    return 3;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    static NSString* cellIdentifier = @"MecicationCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier forIndexPath:indexPath];
    
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
    }
    
    return cell;
    
}

-(IBAction)cancelPrsd:(id)sender
{
    [self.view removeFromSuperview];
}
@end
