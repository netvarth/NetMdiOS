//
//  PatientService.m
//  NetMdBL
//
//  Created by Remesh Kuruppath on 12/9/13.
//  Copyright (c) 2013 Netvarth. All rights reserved.
//

#import "PatientService.h"

@implementation PatientService
@synthesize patientdaodelegate;


+ (PatientService*)sharedInstance {
    static dispatch_once_t onceToken;
    static PatientService* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[PatientService alloc] init];
    });
    
    return sharedInstance;
}

- (BOOL)create:(PatientDetail*)patient
{
    return [patientdaodelegate addPatient:patient];
    
}

- (BOOL)update:(PatientDetail*)patient
{
    return [patientdaodelegate editPatient:patient];
}

- (NSMutableArray*)getAllPatientDeatils{
    
    return [patientdaodelegate getAllPatientDetails];
}

- (PatientDetail*)getPatientDetailsById:(int) patientId
{
    return [patientdaodelegate getPatientDetailsById:patientId];
}
- (CaseDTO*)getcasedetailsbycaseId:(int)selectedcaseId
{
    return [patientdaodelegate getcasedetailsbycaseId:selectedcaseId];
}
- (NSMutableArray*)getmedicalrecordbycaseid:(int)caseid
{
    return[patientdaodelegate getmedicalrecordbycaseid:caseid];
}

- (NSMutableArray*)getCaseByPatientId:(int)patientId
{
    return [patientdaodelegate getCaseByPatientId:patientId];
}

- (BOOL)addCaseByPatientId:(CaseDTO*)caseDto
{
    return [patientdaodelegate addCaseByPatientId:caseDto];
}
- (void)editCaseById:(CaseDTO*)casedto
{
     return [patientdaodelegate editCaseById:casedto];
}
- (void)editMedRecordsById:(MedicalRecordDTO*)medicalto
{
    return [patientdaodelegate editMedRecordsById:medicalto];
}
- (void)deleteCaseById:(int)CaseId
{
    return [patientdaodelegate deleteCaseById:CaseId];
}
- (void)deleteMedRecordById:(int)MedRecId
{
    return [patientdaodelegate deleteMedRecordById:MedRecId];
}
- (NSMutableArray*)getMedicalRecordByPatientId:(int)patientId
{
    return [patientdaodelegate getMedicalRecordByPatientId:patientId];
}

- (BOOL)addMedicalRecordByPatientId:(MedicalRecordDTO*)MedicalRecordDto
{
    return [patientdaodelegate addMedicalRecordByPatientId:MedicalRecordDto];
}

- (NSMutableArray*)getVisitsByPatientId:(int)patientId
{
    return [patientdaodelegate getVisitsByPatientId:patientId];
}

-(int)checkIfPatientExist:(NSString*)uniqueId
{
    return [patientdaodelegate checkIfPatientExist:uniqueId];
}

@end
