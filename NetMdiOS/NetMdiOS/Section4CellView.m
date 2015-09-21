//
//  Section4CellView.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 03/09/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "Section4CellView.h"

@interface Section4CellView ()<UITableViewDataSource,UITableViewDelegate>
@property(nonatomic,strong) IBOutlet UITableView* subTblView;
@end

@implementation Section4CellView


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
    
    static NSString* cell1Identifier = @"Section4CellSubCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cell1Identifier forIndexPath:indexPath];
    
    if (cell == nil)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cell1Identifier];
    }
    
    return cell;
    
}

@end