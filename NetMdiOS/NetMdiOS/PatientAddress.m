//
//  PatientAddress.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 12/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "PatientAddress.h"

@interface PatientAddress()
-(IBAction)cancelPrsd:(id)sender;
@end

@implementation PatientAddress
-(void)viewDidLoad
{
    [super viewDidLoad];
}

-(IBAction)cancelPrsd:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

@end
