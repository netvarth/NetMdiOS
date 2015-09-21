//
//  PatientService.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/9/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PatientDao.h"
#import "PatientDetail.h"
#import "CaseDTO.h"

@interface PatientService : NSObject

@property (nonatomic, strong) id<PatientDao> patientdaodelegate;

+ (PatientService*)sharedInstance;


- (BOOL)create:(PatientDetail*)patient;
- (BOOL)update:(PatientDetail*)patient;
- (NSMutableArray*)getAllPatientDeatils;
- (PatientDetail*)getPatientDetailsById:(int) patientId;
- (NSMutableArray*)getmedicalrecordbycaseid:(int)caseid;

- (NSMutableArray*)getCaseByPatientId:(int)patientId;
- (BOOL)addCaseByPatientId:(CaseDTO*)caseDto;
- (NSMutableArray*)getMedicalRecordByPatientId:(int)patientId;
- (BOOL)addMedicalRecordByPatientId:(MedicalRecordDTO*)MedicalRecordDto;
- (NSMutableArray*)getVisitsByPatientId:(int)patientId;
- (CaseDTO*)getcasedetailsbycaseId:(int)selectedcaseId;

- (void)editCaseById:(CaseDTO*)casedto;
- (void)deleteCaseById:(int)CaseId;
- (void)editMedRecordsById:(MedicalRecordDTO*)medicalto;
- (void)deleteMedRecordById:(int)MedRecId;
- (int)checkIfPatientExist:(NSString*)uniqueId;

@end
