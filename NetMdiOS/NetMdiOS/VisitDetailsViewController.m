//
//  VisitDetailsViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 26/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "VisitDetailsViewController.h"
#import "Section1Cell.h"
#import "Section2Cell.h"
#import "Section3Cell.h"
#import "Section4Cell.h"
#import "Section5Cell.h"

@interface VisitDetailsViewController ()<UITableViewDelegate,UITableViewDataSource>
{
    NSMutableIndexSet *expandedSections;
    int selectedSec;
}
@property(nonatomic,strong) IBOutlet UITableView* tbl;
@property(nonatomic,strong) NSArray* array;
@property(nonatomic,strong) NSArray* labArray;
@property(nonatomic,strong) NSArray* rxArray;

-(IBAction)cancelPrsd:(id)sender;

@end

@implementation VisitDetailsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    if (!expandedSections)
    {
        expandedSections = [[NSMutableIndexSet alloc] init];
        selectedSec = -1;
    }
    _array = [[NSArray alloc] initWithObjects:@"Visit",@"Rx",@"Lab",@"Readings",@"Observations", nil];
    _labArray = [[NSArray alloc] initWithObjects:@"Sugar(210)",@"BP(120)",@"Blood(AB-)", nil];
    _rxArray = [[NSArray alloc] initWithObjects:@"Dolo",@"Paracitamole",@"Caratin", nil];

}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
#warning Potentially incomplete method implementation.
    // Return the number of sections.
    
    return _array.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    
    if (selectedSec == section) {
        return 1;
    }
    return 0;
}

-(UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section {
    
    
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, tableView.frame.size.width, 40)];
    
    //[view setBackgroundColor:[UIColor colorWithRed:166/255.0 green:177/255.0 blue:186/255.0 alpha:1.0]];
    
    UILabel *label1 = [[UILabel alloc] initWithFrame:CGRectMake(10, 6, tableView.frame.size.width, 35)];
    
    [label1 setFont:[UIFont boldSystemFontOfSize:20]];
    
    [label1 setText:[_array objectAtIndex:section]];
    [label1 setBackgroundColor:[UIColor colorWithRed:166/255.0 green:177/255.0 blue:186/255.0 alpha:1.0]];
    
    [view addSubview:label1];
    
    if (section == 0)
    {
        UILabel *label2 = [[UILabel alloc] initWithFrame:CGRectMake(450.0f, 6.0f, 150.0f, 35.0f)];
        [label2 setFont:[UIFont boldSystemFontOfSize:17]];
        [label2 setText:@"2/2/2015, 10 am"];
        [label2 setBackgroundColor:[UIColor colorWithRed:166/255.0 green:177/255.0 blue:186/255.0 alpha:1.0]];
        [view addSubview:label2];
    }
    else
    {
        UILabel *count = [[UILabel alloc] initWithFrame:CGRectMake(450.0f, 6.0f, 10.0f, 35.0f)];
        [count setFont:[UIFont boldSystemFontOfSize:17]];
        [count setText:@"4"];
        [count setBackgroundColor:[UIColor colorWithRed:166/255.0 green:177/255.0 blue:186/255.0 alpha:1.0]];
        [view addSubview:count];
    }
    
    
    UIButton* btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = CGRectMake(0, 0, tableView.frame.size.width, 35 );
    [btn addTarget:self action:@selector(sectionPrsd:) forControlEvents:UIControlEventTouchUpInside] ;
    btn.tag = section;
    [view addSubview:btn];
    return view;
    
}

-(IBAction)sectionPrsd:(id)sender
{
    UIButton* btn = (UIButton*)sender;
    NSLog(@"Selected row is %lu",btn.tag);
    selectedSec = btn.tag;
    [_tbl reloadData];
}

- (CGFloat) tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
    
    return 60;
    
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    if (indexPath.section == 0) {
        static NSString* cell1Identifier = @"Section1Cell";
        Section1Cell *cell1 = [tableView dequeueReusableCellWithIdentifier:cell1Identifier forIndexPath:indexPath];
        if (cell1 == nil)
        {
            cell1 = (Section1Cell*)[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cell1Identifier];
        }
        return cell1;
        
    }
    else if (indexPath.section == 1)
    {
        static NSString* cell2Identifier = @"Section2Cell";
        Section2Cell *cell = [tableView dequeueReusableCellWithIdentifier:cell2Identifier forIndexPath:indexPath];
        if (cell == nil)
        {
            cell = (Section2Cell*)[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cell2Identifier];
        }
        return cell;
    }
    else if (indexPath.section == 2)
    {
        static NSString* cell3Identifier = @"Section3Cell";
        Section3Cell *cell = [tableView dequeueReusableCellWithIdentifier:cell3Identifier forIndexPath:indexPath];
        if (cell == nil)
        {
            cell = (Section3Cell*)[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cell3Identifier];
        }
        return cell;
    }
    else if (indexPath.section == 3)
    {
        static NSString* cell4Identifier = @"Section4Cell";
        Section4Cell *cell = [tableView dequeueReusableCellWithIdentifier:cell4Identifier forIndexPath:indexPath];
        if (cell == nil)
        {
            cell = (Section4Cell*)[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cell4Identifier];
        }
        return cell;
    }
    else if (indexPath.section == 4)
    {
        static NSString* cell5Identifier = @"Section5Cell";
        Section5Cell *cell = [tableView dequeueReusableCellWithIdentifier:cell5Identifier forIndexPath:indexPath];
        if (cell == nil)
        {
            cell = (Section5Cell*)[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cell5Identifier];
        }
        return cell;
    }


    return nil;
}


- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.section == 0)
    {
        return 120.0f;
    }
    else if (indexPath.section == 1)
    {
        return 200.0f;
    }
    else if (indexPath.section == 2)
    {
        return 130.0f;
    }
    else if (indexPath.section == 3)
    {
        return 120.0f;
    }
    else if (indexPath.section == 4)
    {
        return 120.0f;
    }
    return 44.0f;
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)cancelPrsd:(id)sender
{
    [self.view removeFromSuperview];
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
