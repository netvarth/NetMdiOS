//
//  SyncDTO.h
//  NewNetMdBL

//  Created by Netvarth_Mac2 on 08/05/14.
//  Copyright (c) 2014 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NetMdDTO.h"
#import "NetMdBranchDTO.h"
#import "HeaderDTO.h"

@interface SyncDTO : NSObject
@property(nonatomic,strong) HeaderDTO* header;
@property(nonatomic,strong) NSString* lastSyncTime;
@property(nonatomic,strong) NetMdDTO* updateNetmd;
@property(nonatomic,strong) NetMdBranchDTO* updateNetmdBranch;

@property(nonatomic,strong) NSMutableArray* createDoctorList;
@property(nonatomic,strong) NSMutableArray* updateDoctorList;
@property(nonatomic,strong) NSMutableArray* deleteDoctorList;

@property(nonatomic,strong) NSMutableArray* createpatientList;

@property(nonatomic,strong) NSMutableArray* updatePatientList;

@property(nonatomic,strong) NSMutableArray* deletePatientList;


@property(nonatomic,strong) NSMutableArray* createScheduleList;

@property(nonatomic,strong) NSMutableArray* updateScheduleList;

@property(nonatomic,strong) NSMutableArray* deleteScheduleList;

@property(nonatomic,strong) NSMutableArray* createAppointmentList;

@property(nonatomic,strong) NSMutableArray* updateAppointmentList;
@property(nonatomic,strong) NSMutableArray* deleteAppointmentList;

@property(nonatomic,strong) NSMutableArray*  createUserList;


@property(nonatomic,strong) NSMutableArray*  updateUserList;
@property(nonatomic,strong) NSMutableArray* deleteUserList;

@property(nonatomic,strong) NSMutableArray* user;

@property(nonatomic,strong) NSMutableArray* createCaseList;


@property(nonatomic,strong) NSMutableArray* updateCaseList;
@property(nonatomic,strong) NSMutableArray* deleteCaseList;

@property(nonatomic,strong) NSMutableArray* createMedicalRecordList;
@property(nonatomic,strong) NSMutableArray* updateMedicalRecordList;

@property(nonatomic,strong) NSMutableArray* createBillList;
@property(nonatomic,strong) NSMutableArray* updateBillList;


@property(nonatomic,strong) NSMutableArray* deleteMedicalRecordList;


@end
