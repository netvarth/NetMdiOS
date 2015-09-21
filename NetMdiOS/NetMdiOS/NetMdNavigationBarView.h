//
//  NetMdNavigationBarView.h
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 21/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SettingsView.h"

@interface NetMdNavigationBarView : UIView

@property(nonatomic,strong) IBOutlet UILabel* lblCompany;
@property(nonatomic,strong) IBOutlet UILabel* lblBranch;
@property(nonatomic,strong) IBOutlet UILabel* lblVersion;
@property(nonatomic,strong) IBOutlet UILabel* lblUserName;
@property(nonatomic,strong) IBOutlet UIButton* btnSettings;
@property(nonatomic,strong) SettingsView* settingsView;

-(IBAction)settingsPressed:(id)sender;

@end
