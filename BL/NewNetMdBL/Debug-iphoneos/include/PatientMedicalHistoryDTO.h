//
//  PatientMedicalHistoryDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PatientMedicalHistoryDTO : NSObject

@property (nonatomic, assign) int       Id;
@property (nonatomic, assign) int       patientId;
@property (nonatomic, strong) NSString* medicalIssue;
@property (nonatomic, strong) NSString* diagonisedAge;
@property (nonatomic, strong) NSString* tenure;
@property (nonatomic, strong) NSString* treatment;
@property (nonatomic, strong) NSString* surgery;
@property (nonatomic, strong) NSString* address;
@property (nonatomic, strong) NSString* medication;
@property (nonatomic, strong) NSString* isCured;
@property (nonatomic, strong) NSString* actionName;

@end
