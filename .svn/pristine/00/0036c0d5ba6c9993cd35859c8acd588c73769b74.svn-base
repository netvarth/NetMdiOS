//
//  Section2CellView.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 26/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "Section2CellView.h"

@interface Section2CellView ()<UITableViewDataSource,UITableViewDelegate>
@property(nonatomic,strong) IBOutlet UITableView* subTblView;
@end

@implementation Section2CellView

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
#warning Potentially incomplete method implementation.
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
#warning Incomplete method implementation.
    // Return the number of rows in the section.
    return 10;
}


 - (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    static NSString* cell1Identifier = @"Section2CellSubCell";
 UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cell1Identifier forIndexPath:indexPath];
 
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cell1Identifier];
    }
 
 return cell;
    
 }


/*
 // Override to support conditional editing of the table view.
 - (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
 // Return NO if you do not want the specified item to be editable.
 return YES;
 }
 */


@end
