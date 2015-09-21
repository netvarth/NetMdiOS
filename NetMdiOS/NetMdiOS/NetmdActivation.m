//
//  NetmdActivation.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 10/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "NetmdActivation.h"
#import "NetMDDatabase.h"
@implementation NetmdActivation
-(void)activateNetmd:(id) responseObject passphrase:(PassPhraseDTO*)passphrasedao
{
    _netmddetail=[[NetMdDTO alloc]init];
    _logindetail=[[LoginDTO alloc]init];
    _netmdBranchDAO=[[NetMdBranchDTO alloc]init
                    ];
    
    NSDictionary *netmddata = [responseObject objectForKey:@"netmd"];
    NSString* gid=[netmddata objectForKey:@"globalId"];
    _netmddetail.globalId=[gid intValue];
    _netmddetail.ownerFirstName=[netmddata objectForKey:@"ownerFirstName"];
    _netmddetail.name=[netmddata objectForKey:@"name"];
    _netmddetail.ownerAddress=[netmddata objectForKey:@"ownerAddress"];
    _netmddetail.ownerEmail=[netmddata objectForKey:@"ownerEmail"];
    _netmddetail.ownerPhone=[netmddata objectForKey:@"ownerPhone"];
    _netmddetail.ownerMobile=[netmddata objectForKey:@"ownerMobile"];
    _netmddetail.status=[netmddata objectForKey:@"status"];
    _netmddetail.ownerLastName=[netmddata objectForKey:@"ownerLastName"];
    _netmddetail.headOfficeName=[netmddata objectForKey:@"headOfficeName"];
    _netmddetail.headOfficeAddress=[netmddata objectForKey:@"headOfficeAddress"];
    _netmddetail.headOfficePhone=[netmddata objectForKey:@"headOfficePhone"];
    _netmddetail.headOfficeMobile=[netmddata objectForKey:@"headOfficeMobile"];
    _netmddetail.headOfficeEmail=[netmddata objectForKey:@"headOfficeEmail"];
    _netmddetail.status=[netmddata objectForKey:@"status"];
    
    LoginUser* logindata=[[LoginUser alloc] init];
    logindata.userName=[netmddata objectForKey:@"userName"];
    logindata.userType=[netmddata objectForKey:@"userType"];
    logindata.userPassword=[netmddata objectForKey:@"password"];
  
    [[NetMDDatabase sharedInstance] addLoginUser:logindata];
     
    int logId;
    logId=[[NetMDDatabase sharedInstance]getloginuserid:logindata];
    _netmddetail.Id=logId;
    
    [[NetMDDatabase sharedInstance]addowner:_netmddetail];
    int netmd_Id;
    netmd_Id=[[NetMDDatabase sharedInstance]getnetmdTabledetailsByglobalId:[gid intValue]];
    NSDictionary *netmdbranchdata = [responseObject objectForKey:@"branch"];
    //NSString* netmdId=[netmdbranchdata objectForKey:@"netMdId"];
    _netmdBranchDAO.netMdId=netmd_Id;
    NSString* brGlobalID=[netmdbranchdata objectForKey:@"globalId"];
    _netmdBranchDAO.globalId=[brGlobalID intValue];
    _netmdBranchDAO.address=[netmdbranchdata objectForKey:@"address"];
    NSString* ID=[netmdbranchdata objectForKey:@"id"];
    _netmdBranchDAO.Id=[ID intValue];
    _netmdBranchDAO.name=[netmdbranchdata objectForKey:@"name"];
    _netmdBranchDAO.email=[netmdbranchdata objectForKey:@"email"];
    _netmdBranchDAO.phone=[netmdbranchdata objectForKey:@"phone"];
    _netmdBranchDAO.mobile=[netmdbranchdata objectForKey:@"mobile"];
    _netmdBranchDAO.name=[netmdbranchdata objectForKey:@"name"];
    _netmdBranchDAO.status=[netmdbranchdata objectForKey:@"status"];
    [[NetMDDatabase sharedInstance]addnetmdBranchDetails:_netmdBranchDAO];
    int netmdbrID=[[NetMDDatabase sharedInstance]getnetmdBranchTabledetailsByglobalId:[brGlobalID intValue]];
    [[NetMDDatabase sharedInstance]addPassphraseinfo:passphrasedao withnetmdId:netmd_Id withBrId:netmdbrID];
    
    //Add value 0 to field id in uniqueTbl
    [[NetMDDatabase sharedInstance] addOne];
 
   
  
}
@end
