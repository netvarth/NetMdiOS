//
//  HomeViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 20/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "HomeViewController.h"


@interface HomeViewController()
@end

@implementation HomeViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    
    return self;
}

-(void) viewDidLoad
{
    [super viewDidLoad];
    //[self loadNavigationBar];
}

- (void)viewWillAppear:(BOOL)animated
{

    
}


/*
-(void)settingsBtnPressed
{
    NSLog(@"Settings pressed");
    
    _settingsView = [[SettingsView alloc] init];
    _settingsView.whenViewLoaded;
    [ _settingsView setFrame:CGRectMake(450.0f, 55.0f, 285.0f, 346.0f)];
    _settingsView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    [self.view addSubview:_settingsView];
     
 }

-(void)settingsBtnPressed
{
    NSLog(@"Settings pressed");
    _stngsViewCntrl = [[UIViewController alloc]
                                        
                                        init];
    
    _stngsView = [[UIView alloc]
                           
                           initWithFrame:CGRectMake(0, 0, 200, 300)];
    
    _stngsView.backgroundColor = [UIColor whiteColor];
    
    _stngsViewCntrl.view = _stngsView;
    
    
    //resize the popover view shown
    //in the current view to the view's size
    
    _stngsViewCntrl.contentSizeForViewInPopover =
    
    CGSizeMake(200, 300);
    _stngsViewCntrl.title = @"Settings";
    
    //create a popover controller
    _settingsNavCtrl = [[UINavigationController alloc] initWithRootViewController:_stngsViewCntrl];
    _settingsNavCtrl.navigationBar.barTintColor = [UIColor colorWithRed:100.0f/255.0f green:176.0f/255.0f blue:195.0f/255.0f alpha:1.0f];
    UIPopoverController* popoverController = [[UIPopoverController alloc]
                              
                              initWithContentViewController:_settingsNavCtrl];
    
    
    //present the popover view non-modal with a
    //refrence to the button pressed within the current view
    [popoverController presentPopoverFromRect:_netMdNavBarView.btnSettings.frame
     
                                            inView:self.view
     
                          permittedArrowDirections:UIPopoverArrowDirectionAny
     
                                          animated:YES];
    
    

}


-(void)settingsBtnPressed
{
    NSLog(@"Settings pressed");
    _optnsList = [[NSArray alloc] initWithObjects:@"App Settings",@"System Settings",@"My Schedules",@"My vacations",@"Logout", nil];
    UITableViewController* tblViewCntrl = [[UITableViewController alloc] initWithStyle:UITableViewStyleGrouped];
    
    UITableView* tblView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, 200, 300) style:UITableViewStylePlain];
    //tblView.backgroundColor = [UIColor lightGrayColor];
    tblView.delegate = self;
    tblView.dataSource = self;
    tblViewCntrl.view = tblView;
    //resize the popover view shown
    //in the current view to the view's size
    
    tblViewCntrl.contentSizeForViewInPopover =
    
    CGSizeMake(200, 300);
    tblViewCntrl.title = @"Settings";
    //create a popover controller
    _settingsNavCtrl = [[UINavigationController alloc] initWithRootViewController:tblViewCntrl];
    _settingsNavCtrl.navigationBar.barTintColor = [UIColor colorWithRed:100.0f/255.0f green:176.0f/255.0f blue:195.0f/255.0f alpha:1.0f];
    UIPopoverController* popoverController = [[UIPopoverController alloc]
                                              
                                              initWithContentViewController:_settingsNavCtrl];
    
    
    //present the popover view non-modal with a
    //refrence to the button pressed within the current view
    [popoverController presentPopoverFromRect:_netMdNavBarView.btnSettings.frame
     
                                       inView:self.view
     
                     permittedArrowDirections:UIPopoverArrowDirectionAny
     
                                     animated:YES];
    
    

}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
#warning Potentially incomplete method implementation.
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
#warning Incomplete method implementation.
    // Return the number of rows in the section.
    return [_optnsList count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString* simpleTableIdentifier = @"OptionCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:simpleTableIdentifier];
        int index = indexPath.row;
        if (indexPath.row == 0 || indexPath.row == 1)
        {
             cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
        }
       
    }
    
    cell.textLabel.text = [_optnsList objectAtIndex:indexPath.row];
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    NSString *cellText = cell.textLabel.text;
    if (indexPath.row == 0 || indexPath.row == 1)
    {
      [self optionPressed:cellText];
    }
    else
    {
        
    }
}

-(void)optionPressed:(NSString*)cellText
{
    UIViewController* detailsViewCtrl = [[UIViewController alloc] init];
    UIView* detailView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 200, 300)];
    detailsViewCtrl.title = cellText;
    detailsViewCtrl.view = detailView;
    [_settingsNavCtrl pushViewController:detailsViewCtrl animated:YES];
}
  */
@end