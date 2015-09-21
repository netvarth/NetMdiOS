//
//  NetMDDatabase.h
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 15/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SQLQueries.h"
#import "sqlite3.h"
#import "FMDB.h"
#import "FMDatabase.h"
#import "LoginUser.h"
#import "NetMdDTO.h"
#import "NetMdBranchDTO.h"
#import "PassPhraseDTO.h"
#import "HeaderDTO.h"


@class Patient;
@class LoginUser;
@class Case;
@class MedicalRecord;
@class Visit;

@interface NetMDDatabase : NSObject

@property (nonatomic, strong) NSString* databasePath;
@property (nonatomic,strong) FMDatabase* dataBase;

+ (NetMDDatabase*)sharedInstance;

- (void)checkAndCreateDatabase;

- (void)createTables;

- (BOOL)addLoginUser:(LoginUser*)user;

- (int)getloginuserid:(LoginUser*)user;

- (LoginUser*)getLoginUserByName:(NSString*)userName;

-(BOOL)addowner:(NetMdDTO*)owner;

- (BOOL)addPatient:(Patient*)patientDAO;

- (NSMutableArray*)getAllPatientDetails;
- (BOOL)updatePatient:(Patient*)patientDAO;

- (NSMutableArray*)getCaseByPatientId:(int)patientId;
- (BOOL)addCase:(Case*)caseDAO;

- (NSMutableArray*)getMedicalRecordByPatientId:(int)medicalrecordId;

- (NSMutableArray*)getVisitsByPatientId:(int)patientId;
- (int)getnetmdTabledetailsByglobalId:(int)globalId;
- (BOOL)addnetmdBranchDetails:(NetMdBranchDTO*)netmdBranch;
- (int)getnetmdBranchTabledetailsByglobalId:(int)globalId;
//(int)methodName:(int)arg1 withArg2:(int)arg2
- (BOOL)addPassphraseinfo:(PassPhraseDTO*)passphrasedao withnetmdId: (int)netmdId withBrId: (int)netmdBrId;
//sync
- (HeaderDTO*)syncHeaderinfo;
//-

-(void)addOne;
-(BOOL)updateUniqueId:(int)newId;
-(int)getUniqueIdValue;

@end
