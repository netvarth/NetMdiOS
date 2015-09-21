//
//  NetMdLoginViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 08/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//

#import "NetMdLoginViewController.h"
#import "EncryptionController.h"
#import "LoginDaoImp.h"
#import "LoginService.h"
#import "CurrentUserDTO.h"
#import "OwnerDetailDTO.h"
#import "OwnerService.h"
#import "OwnerDaoImp.h"
#import "NetMDViewController.h"
#import "LoginDTO.h"
#import "NavigationController.h"
#import "LoginDaoImp.h"
#import "NetMDTabBarController.h"
@interface NetMdLoginViewController ()

@property (nonatomic, strong) IBOutlet  UITextField*    txfUsername;
@property (nonatomic, strong) IBOutlet  UITextField*    txfPassword;
@property (nonatomic, strong) IBOutlet  UILabel*        lblErrorMsg;
@property(nonatomic,strong)EncryptionController* encryptionController;
@property(nonatomic,strong)LoginDaoImp* loginDaoimpl;
@property(nonatomic,strong)OwnerDetailDTO* owner;
@property(nonatomic,strong)LoginDTO* user;
@property(nonatomic,strong)CurrentUserDTO* currentUser;
@property(nonatomic,strong)NavigationController* navigationController;
@property(nonatomic,strong)NetMDTabBarController* tabBarctrl;

-(IBAction)loginPressed:(id)sender;

@end

@implementation NetMdLoginViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    LoginDaoImp* loginDaoimpl = [[LoginDaoImp alloc] init];
    [[LoginService sharedInstance] setLogindaodelegate:loginDaoimpl];
    OwnerDaoImp* ownerDaoImpl = [[OwnerDaoImp alloc] init];
    [[OwnerService sharedInstance] setOwnerdaodelegate:ownerDaoImpl];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)loginPressed:(id)sender
{
    NSString* username = self.txfUsername.text;
    NSString* password = self.txfPassword.text;
    NSString* dataToEncrypt=[password stringByTrimmingCharactersInSet:
                             [NSCharacterSet whitespaceCharacterSet]];
    
    _encryptionController = [[EncryptionController alloc] init];
    NSData* dataEncrypted=[_encryptionController encrypt :dataToEncrypt];
    
    NSLog(@"%@",dataEncrypted);
    
    NSString *stringDataEncrypted = [dataEncrypted base64Encoding];
    NSLog(@"%@",stringDataEncrypted);
    
    if (!username || !password || [username isEqualToString:@""] || [password isEqualToString:@""])
    {
        [self.lblErrorMsg setText:@"Please enter username and password."];
    }
    else
   {
 
       _loginDaoimpl = [[LoginDaoImp alloc] init];
       _user = [[LoginDTO alloc] init];
       _user = [[LoginService sharedInstance] getLoginUserByName:username];
       /*
       if (!_user)
       {
           [self.lblErrorMsg setText:@"User not found."];
       }
       else if(![_user.password isEqualToString:stringDataEncrypted])
       {
           [self.lblErrorMsg setText:@"Username and password do not match."];
       }
       else
       {
           */
          //NetMDViewController* mainViewController = [self.storyboard instantiateViewControllerWithIdentifier:@"NetMDViewController"];
           NavigationController* navigationController = [self.storyboard instantiateViewControllerWithIdentifier:@"NavigationController"];
       //_tabBarctrl =[self.storyboard instantiateViewControllerWithIdentifier:@"NetMDTabBarController"];
           _currentUser = [[CurrentUserDTO alloc] init];
           if([_user.userType isEqualToString:@"owner"])
           {
               _owner=[[OwnerDetailDTO alloc] init];
               _owner=[[OwnerService sharedInstance] getOwnerDetails:_user.Id];
               _currentUser.selectedDoctorId=0;
               _currentUser.name = [NSString stringWithFormat:@"%@ %@",_owner.firstName,_owner.lastName];
               _currentUser.Id = _owner.Id;
               _currentUser.loginId = _user.Id;
               _currentUser.userName = _user.userName;
               _currentUser.userType = _user.userType;
               _currentUser.password = _user.password;
               _currentUser.gender = _owner.gender;
               _currentUser.email = _owner.email;
               _currentUser.mobile = _owner.mobile;
               _currentUser.phone = _owner.phone;
               _currentUser.address = _owner.address;
               _currentUser.dateOfBirth = _owner.dateOfBirth;

           }
          
           NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
           NSData *data = [NSKeyedArchiver archivedDataWithRootObject:_currentUser];
           [defaults setObject:data forKey:@"currentUserObj"];
           [defaults synchronize];
           [[[UIApplication sharedApplication] keyWindow] setRootViewController:navigationController];
           //[[[UIApplication sharedApplication] keyWindow] setRootViewController:_tabBarctrl];
       //}
       
   }
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
@end