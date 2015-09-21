//
//  SyncResponseDTO.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/2/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HeaderDTO.h"
#import "RetrievealDoctorResponseDTO.h"
#import "RetrievalUserResponseDTO.h"
#import "RetrievalAppointmentResponseDTO.h"
#import "RetrievalPatientResponseDTO.h"
#import "RetrievalScheduleResponseDTO.h"
#import "RetrieveResultsResponseDTO.h"
#import "DoctorLoginDTO.h"
#import "ErrorDTO.h"
#import "HeaderResponseDTO.h"
#import "NetMdDTO.h"
#import "NetMdBranchDTO.h"


@interface SyncResponseDTO : NSObject

@property (nonatomic, strong) HeaderResponseDTO* headerResponse;
@property (nonatomic,strong) NetMdDTO* netmdResponse;
@property (nonatomic,strong) NetMdBranchDTO* netmdBranchResponse;
@property (nonatomic, strong) NSArray* doctorResponse;
@property (nonatomic, strong) NSArray* scheduleResponse;
@property (nonatomic, strong) NSArray* patientResponse;
@property (nonatomic, strong) NSArray* userResponse;
@property (nonatomic, strong) NSArray* appointmentResponse;
@property (nonatomic, strong) RetrievealDoctorResponseDTO* retrievalDoctorList;
@property (nonatomic, strong) RetrievalUserResponseDTO* retrievalUsersList;
@property (nonatomic, strong) RetrievalAppointmentResponseDTO* retrievalAppointmentList;
@property (nonatomic, strong) RetrievalPatientResponseDTO* retrievalPatientDTO;
@property (nonatomic, strong) RetrievalScheduleResponseDTO* retrievalScheduleList;
//@property (nonatomic, strong) RetrieveResultsResponseDTO* retrievalResults;
@property (nonatomic,strong) NSArray* retieveResults;
@property (nonatomic, strong) RetrievalAppointmentResponseDTO* retrievalAppointmentListForPrimary;
@property (nonatomic, strong) NSArray* doctorLogin;
@property (nonatomic, strong) NSArray* billResponse;
@property (nonatomic,strong) NSArray* patientCaseResponse;
@property (nonatomic,strong) NSArray* patientMedicalResponse;
//@property (nonatomic, strong) NSArray* retrievalBillList;
@property (nonatomic, strong) NSString* lastSyncTime;
@property (nonatomic, strong) ErrorDTO* error;
@property (nonatomic, assign) BOOL success;


@end
