//
//  PatientCellTableViewCell.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 06/08/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "PatientCellTableViewCell.h"

@interface PatientCellTableViewCell ()

@property(nonatomic,strong) IBOutlet UILabel*name;
@property(nonatomic,strong) IBOutlet UILabel*age;
@property(nonatomic,strong) IBOutlet UILabel*mob;
@property(nonatomic,strong) IBOutlet UILabel*lVisit;
@property(nonatomic,strong) IBOutlet UILabel*nVisit;
@property(nonatomic,strong) IBOutlet UILabel*mrId;

@end
@implementation PatientCellTableViewCell

- (void)awakeFromNib {
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
