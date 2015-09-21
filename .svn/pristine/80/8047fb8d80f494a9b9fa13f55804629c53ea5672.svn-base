//
//  SettingsView.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 22/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "SettingsView.h"
#import "ScheduleView.h"

@interface SettingsView()
@property(nonatomic,strong) IBOutlet UITableView* settingsList;
@property(nonatomic,strong) NSArray* options;
@property(nonatomic,strong)ScheduleView* scheduleView;
@end
@implementation SettingsView

-(SettingsView*)init
{
    SettingsView* result = nil;
    NSArray* elements = [[NSBundle mainBundle] loadNibNamed:NSStringFromClass([self class]) owner:self options:nil];
    for (id anObject in elements )
    {
        if ([anObject isKindOfClass:[self class]])
        {
            result = anObject;
            break;
        }
    }
    return result;
}

-(void)whenViewLoaded
{
    _options = [[NSArray alloc] initWithObjects:@"App Settings",@"System Settings",@"My Schedules",@"My Vacations",@"Logout",@"Logout",@"Logout",@"Logout",@"Logout",@"Logout",@"Logout",nil];

}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [_options count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *simpleTableIdentifier = @"SimpleTableCell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:simpleTableIdentifier];
    }
    
    cell.textLabel.text = [_options objectAtIndex:indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    _scheduleView = [[ScheduleView alloc] init];
    [  _scheduleView setFrame:CGRectMake(0.0f, 0.0f, 20.0f, 20.0f)];
    [self removeFromSuperview];
    [self addSubview:_scheduleView];
}
@end
