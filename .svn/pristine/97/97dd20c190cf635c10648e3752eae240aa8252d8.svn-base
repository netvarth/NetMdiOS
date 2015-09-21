//
//  SettingsTableViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 29/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "SettingsTableViewController.h"
#import "ScheduleViewController.h" 
#import "NetMDTabBarController.h"
#import "SettingsSubOptionsTableViewCtrl.h"
#import "NetMdLoginViewController.h"

@interface SettingsTableViewController ()
@property(nonatomic,strong)NSArray* stngsList;
@property(nonatomic,strong)NetMDTabBarController* netMdTabBarCtrl;
@property(nonatomic,strong)SettingsSubOptionsTableViewCtrl* suboptnsTblViewCtrl;
@property(nonatomic,strong)NetMdLoginViewController* loginViewCtrl;
@end

@implementation SettingsTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Settings";
    _stngsList = [[NSArray alloc] initWithObjects:@"App Settings",@"System Settings",@"My Schedules",@"My vacations",@"Logout", nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
#warning Potentially incomplete method implementation.
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
#warning Incomplete method implementation.
    // Return the number of rows in the section.
    return [_stngsList count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString* simpleTableIdentifier = @"OptionsCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    if (!(cell == nil))
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:simpleTableIdentifier];
        if (indexPath.row == 0 || indexPath.row == 1)
        {
            cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
        }
    }
    
    cell.textLabel.text = [_stngsList objectAtIndex:indexPath.row];
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    NSString *cellText = cell.textLabel.text;
    int rowIndex = indexPath.row;
    switch (rowIndex)
    {
        case 0:
            //App settings
            [self loadSubMenu:cellText];
            break;
        case 1:
             //Sys settings
            [self loadSubMenu:cellText];
            break;
        case 2:
             //My Schedules
            [self loadCorrespondingViewController:@"ScheduleViewController"];
            [self.navigationController dismissViewControllerAnimated:YES completion:nil];
            break;
        case 3:
             //My Vacation
            [self loadCorrespondingViewController:@"VacationViewController"];
            [self.navigationController dismissViewControllerAnimated:YES completion:nil];
            break;
        default:
             //Logout
            [self logoutPressed];
            [self.navigationController dismissViewControllerAnimated:YES completion:nil];
            break;
    }
}

-(void)loadSubMenu:(NSString*)cellText
{
    _suboptnsTblViewCtrl = [self.storyboard instantiateViewControllerWithIdentifier:@"SettingsSubOptionsTableViewCtrl"];
    _suboptnsTblViewCtrl.title = cellText;
    [self.navigationController pushViewController:_suboptnsTblViewCtrl animated:YES];
}

-(void)loadCorrespondingViewController:(NSString*)vcName
{
    
    UIViewController* rvc = [[[UIApplication sharedApplication] keyWindow] rootViewController];
    UIViewController* vc = [self.storyboard instantiateViewControllerWithIdentifier:vcName];
    vc.view.frame = CGRectMake(0.0f, 78.0f, 768.0f, 897.0f);
    [rvc.view addSubview:vc.view];
    [rvc addChildViewController:vc];
    [vc didMoveToParentViewController:rvc];
    
}

-(void)logoutPressed
{
    NSUserDefaults* defaults = [NSUserDefaults standardUserDefaults];
    [defaults setObject:NULL forKey:@"currentUserObj"];
    [defaults synchronize];
    _loginViewCtrl = [self.storyboard instantiateViewControllerWithIdentifier:@"NetMdLoginViewController"];
    [[[UIApplication sharedApplication] keyWindow] setRootViewController:_loginViewCtrl];
}

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    } else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath {
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath {
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
