//
//  PatientDao.h
//  NetMdBL
//
//  Created by Remesh Kuruppath on 11/29/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PatientDetail.h"
#import "CaseDTO.h"
#import "MedicalRecordDTO.h"

@protocol PatientDao <NSObject>

- (BOOL)addPatient:(PatientDetail*)patientDAO;
- (NSMutableArray*)getAllPatientDetails;
- (BOOL)editPatient:(PatientDetail*)patientDAO;
- (PatientDetail*)getPatientDetailsById:(int) patientId;
- (CaseDTO*)getcasedetailsbycaseId:(int)selectedcaseId;
- (NSMutableArray*)getmedicalrecordbycaseid:(int)caseid;
- (NSMutableArray*)getCaseByPatientId:(int)patientId;
- (BOOL)addCaseByPatientId:(CaseDTO*)caseDAO;
- (NSMutableArray*)getMedicalRecordByPatientId:(int)patientId;
- (BOOL)addMedicalRecordByPatientId:(MedicalRecordDTO*)MedicalRecordDAO;
- (NSMutableArray*)getVisitsByPatientId:(int)patientId;
- (void)editCaseById:(CaseDTO*)casedto;
- (void)deleteCaseById:(int)CaseId;
- (void)editMedRecordsById:(MedicalRecordDTO*)medicalto;
- (void)deleteMedRecordById:(int)MedRecId;
- (int)checkIfPatientExist:(NSString*)uniqueId;



@end
