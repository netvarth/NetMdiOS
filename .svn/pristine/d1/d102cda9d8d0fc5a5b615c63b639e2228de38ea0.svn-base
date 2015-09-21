//
//  NetMDDatabase.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 15/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "NetMDDatabase.h"
#import "LoginUser.h"
@implementation NetMDDatabase

+ (NetMDDatabase*)sharedInstance {
    
    static dispatch_once_t onceToken;
    static NetMDDatabase* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[NetMDDatabase alloc] init];
    });
    return sharedInstance;
    
}

- (id)init
{
    self    = [super init];
    if (self)
    {
        // Get the path to the documents directory and append the databaseName
        NSArray *documentPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        NSString *documentsDir = [documentPaths objectAtIndex:0];
        self.databasePath = [documentsDir stringByAppendingPathComponent:DATABASE_NAME];
        _dataBase = [FMDatabase databaseWithPath:self.databasePath];
        [self checkAndCreateDatabase];
        [self createTables];
    }
    return self;
}

- (void)checkAndCreateDatabase {
    
    BOOL success;
    
    // Create a FileManager object, we will use this to check the status
    // of the database and to copy it over if required
    NSFileManager *fileManager = [NSFileManager defaultManager];
    
    // Check if the database has already been created in the users filesystem
    success = [fileManager fileExistsAtPath:self.databasePath];
    
    // If the database already exists then return without doing anything
    if(success) return;
    
    // If not then proceed to copy the database from the application to the users filesystem
    
    // Get the path to the database in the application package
    NSString *databasePathFromApp = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:DATABASE_NAME];
    
    // Copy the database from the package to the users filesystem
    [fileManager copyItemAtPath:databasePathFromApp toPath:self.databasePath error:nil];
    
}

- (void)createTables
{
    
    if([_dataBase open])
    {
        NSLog(@"opened database with path %@",self.databasePath);
        if (![_dataBase executeUpdate:CREATE_TABLE_LOGIN])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        
        if (![_dataBase executeUpdate:CREATE_TABLE_NETMD])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_DOCTOR])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_DOCTOR_PRACTICE_EXPERIENCE])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_DOCTOR_EDUCATIONAL_QUALIFICATION])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_DOCTOR_ACHIEVEMENT])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_DOCTOR_MEMBERSHIP])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_DOCTOR_EXPERTISE])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_PATIENT])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_USER])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_LAB])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_PATIENT_APPOINTMENTS])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_RESULTS])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_SERIES])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_CASE])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_MEDICAL_RECORD])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_MESSAGE])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_SERIES])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_SYNC])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_NETMD_BRANCH_TABLE])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_PASSPHRASE])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_SYNCMESSAGE])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_UNIQUE_ID])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_DOC_SCHEDULE])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_TIME_SPEC])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        if (![_dataBase executeUpdate:CREATE_TABLE_EMPLOYEE_VACATION])
        {
            NSLog(@"Failed to create login_tbl with Error:: %@",_dataBase.lastErrorMessage);
        }
        

    }
    else
    {
        NSLog(@"Failed to open database NetMDDatabase.sql Error::%@",_dataBase.lastErrorMessage);
    }
    
    
    [_dataBase close];
}

- (BOOL)addLoginUser:(LoginUser*)user
{
    
    BOOL result = YES;
    if ([_dataBase open])
    {
         NSLog(@"Opened database %@",self.databasePath);
         NSString* insertQuery   = [NSString stringWithFormat:INSERT_TABLE_LOGIN, user.userName, user.userPassword, user.userType];
        if (![_dataBase executeUpdate:insertQuery])
        {
            NSLog(@"Failed to insert record into the login_tbl with Error::",_dataBase.lastErrorMessage);
            result = NO;
        }
        else
        {
            NSLog(@"Data inserted successfully into login_tbl");
          
        }

    }
    else
    {
        NSLog(@"Failed to open database NetMDDatabase.sql Error::%@",_dataBase.lastErrorMessage);
        result = NO;
    }
    [_dataBase close];
    return result;
}


- (int)getloginuserid:(LoginUser*)user
{
    int userId=0;
     if ([_dataBase open])
     {
         NSLog(@"Opened sqlite database at %@", self.databasePath);
         NSString* selectQuery   = [NSString stringWithFormat:SELECT_USERID_USERNAME,user.userName];
         FMResultSet* set = [_dataBase executeQuery:selectQuery];
         if ([set next])
         {
             userId = [set intForColumn:@"login_tbl_id"];
         }
         [set close];
     }
     else
     {
         NSLog(@"Failed to open database at %@ with error::%@", self.databasePath, _dataBase.lastErrorMessage);
         
     }

    [_dataBase close];
    return userId;
}

-(BOOL)addowner:(NetMdDTO*)owner
{
    BOOL result = YES;
        NSString* insertQuery   = [NSString stringWithFormat:INSERT_TABLE_NETMD,owner.ownerFirstName,owner.name,owner.ownerAddress,owner.ownerEmail,owner.ownerPhone,owner.ownerMobile,owner.Id,owner.status,owner.ownerLastName,owner.headOfficeName,owner.headOfficeAddress,owner.headOfficePhone,owner.headOfficeMobile,owner.headOfficeEmail,owner.globalId];
 if ([_dataBase open])
 {
     NSLog(@"Opened sqlite database at %@", self.databasePath);
     if (![_dataBase executeUpdate:insertQuery])
     {
         NSLog(@"Failed to insert record into the netmd_tbl with Error::",_dataBase.lastErrorMessage);
         result = NO;
     }
     else
     {
         NSLog(@"Data inserted successfully into netmd_tbl");
         
     }
 }
 else
 {
     NSLog(@"Failed to open database at %@ with error::%@", self.databasePath, _dataBase.lastErrorMessage);
     result = NO;
 }
    [_dataBase close];
    return result;
}

- (int)getnetmdTabledetailsByglobalId:(int)globalId
{
    
    int Id=0;
    if ([_dataBase open])
    {
        NSLog(@"Opened sqlite database at %@", self.databasePath);
        NSString* selectQuery   = [NSString stringWithFormat:SELECT_NETMDID_FROM_NETMDTABLE,globalId];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        if ([set next])
        {
            Id = [set intForColumn:@"global_id"];
        }
        [set close];
    }
    else
    {
        NSLog(@"Failed to open database at %@ with error::%@", self.databasePath, _dataBase.lastErrorMessage);
   
    }
    [_dataBase close];
    return Id;
}

- (BOOL)addnetmdBranchDetails:(NetMdBranchDTO*)netmdBranch
{
    BOOL result = YES;
    if ([_dataBase open])
    {
         NSLog(@"Opened sqlite database at %@", self.databasePath);
        NSString* insertQuery   = [NSString stringWithFormat:INSERT_TABLE_NETMD_BRANCH_TABLE,netmdBranch.name,netmdBranch.address,netmdBranch.netMdId,netmdBranch.phone,netmdBranch.mobile,netmdBranch.email,netmdBranch.status,@" ",@" ",netmdBranch.globalId];
        if (![_dataBase executeUpdate:insertQuery])
        {
            NSLog(@"Failed to insert record into the netmd_branch_tbl with Error::",_dataBase.lastErrorMessage);
            result = NO;
        }
        else
        {
            NSLog(@"Data inserted successfully into netmd_branch_tbl");
            
        }
    }
    else
    {
        NSLog(@"Failed to open database at %@ with error::%@", self.databasePath, _dataBase.lastErrorMessage);
        result = NO;
    }
    [_dataBase close];
    return result;
    
}

- (int)getnetmdBranchTabledetailsByglobalId:(int)globalId
{
    int Br_Id=0;
    if ([_dataBase open])
    {
        NSLog(@"Opened sqlite database at %@", self.databasePath);
        NSString* selectQuery   = [NSString stringWithFormat:SELECT_NETMDBRID_FROM_NETMDBRANCHTABLE,globalId];
        FMResultSet* set = [_dataBase executeQuery:selectQuery];
        if ([set next])
        {
            Br_Id = [set intForColumnIndex:10];
        }
        [set close];
    }
    else
    {
        NSLog(@"Failed to open database at %@ with error::%@", self.databasePath, _dataBase.lastErrorMessage);
    }
    [_dataBase close];
    return Br_Id;
}

- (BOOL)addPassphraseinfo:(PassPhraseDTO*)passphrasedao withnetmdId: (int)netmdId withBrId: (int)netmdBrId
{

    BOOL result = YES;
    if ([_dataBase open])
    {
        NSLog(@"Opened sqlite database at %@", self.databasePath);
         NSString* insertQuery   = [NSString stringWithFormat:INSERT_TABLE_PASSPHRASE,passphrasedao.macId,passphrasedao.passPhrase,netmdBrId,netmdId,passphrasedao.devId];
        if (![_dataBase executeUpdate:insertQuery])
        {
            NSLog(@"Failed to insert record into the netmd_passphrase_tbl with Error::",_dataBase.lastErrorMessage);
            result = NO;
        }
        else
        {
            NSLog(@"Data inserted successfully into netmd_passphrase_tbl");
            
        }

    }
    else
    {
        NSLog(@"Failed to open database at %@ with error::%@", self.databasePath, _dataBase.lastErrorMessage);
        result = NO;
    }
    [_dataBase close];
    return result;
}

-(void)addOne
{
    if ([_dataBase open])
    {
        NSLog(@"Opened sqlite database at %@", self.databasePath);
        NSString* insertQuery  = [NSString stringWithFormat:INSERT_QUERY,1];
        if (![_dataBase executeUpdate:insertQuery])
        {
            NSLog(@"Failed to insert record into the uniqueId_tbl with Error::",_dataBase.lastErrorMessage);
        }
        else
        {
            NSLog(@"Data inserted successfully into uniqueId_tbl");
            
        }
    }
    else
    {
        NSLog(@"Failed to open database at %@ with error %@", self.databasePath, _dataBase.lastErrorMessage);
        
    }
  [_dataBase close];
}

@end