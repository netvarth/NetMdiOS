//
//  NetmdActivation.h
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 10/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NetMdDTO.h"
#import "LoginDTO.h"
#import "LoginService.h"
//#import "NetMDDatabase.h"
#import "LoginUser.h"
#import "NetMdBranchDTO.h"
#import "PassPhraseDTO.h"

@interface NetmdActivation : NSObject
@property (nonatomic, strong) NetMdDTO* netmddetail;
@property (nonatomic,strong) LoginDTO* logindetail;
@property (nonatomic,strong) NSString* key;
@property (nonatomic,strong) NetMdBranchDTO* netmdBranchDAO;
@property (nonatomic,strong) PassPhraseDTO* passPhraseDAO;
-(void)activateNetmd:(id) responseObject passphrase:(PassPhraseDTO*)passphrasedao;

@end
