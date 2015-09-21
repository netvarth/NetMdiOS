//
//  PassPhraseViewController.m
//  NetMdiOS
//
//  Created by Netvarth_Mac2 on 06/07/15.
//  Copyright (c) 2015 Netvarth_Mac2. All rights reserved.
//
#import "PassPhraseViewController.h"
#import "AFNetworking.h"
#import "NetMDLoginViewController.h"
#import "PassPhraseDTO.h"
#import "NetmdActivation.h"

@interface PassPhraseViewController ()

@property(nonatomic,strong) IBOutlet UITextField* passPhrase;
@property(nonatomic,strong) IBOutlet UIButton* submit;
@property(nonatomic,strong) IBOutlet UILabel* alertLbl;
@property (nonatomic,strong) PassPhraseDTO* passPhraseDAO;

@end

@implementation PassPhraseViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    _passPhraseDAO=[[PassPhraseDTO alloc] init];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


-(IBAction)submitPressed:(id)sender
{
    if ([self checkValidity])
    {
        //code to check with YNW and load login view controller, if entered passPhrase is true
  
        NSString* macId = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
        NSString* passphrase = _passPhrase.text;
        NSDictionary *parameters = @{@"passPhrase":passphrase, @"macId":macId};
        //check json valid or not
        NSError* errors=nil;
        id jsonData ;
        NSString *jsonString;
        if([NSJSONSerialization isValidJSONObject:parameters])
        {
            
            jsonData = [NSJSONSerialization dataWithJSONObject:parameters options:NSJSONWritingPrettyPrinted error:&errors];
            
            NSLog(@"Valid jsonobject");
            
            jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
            NSLog(@"Json in Client Macine:\n%@", jsonString);
            NSString* filePath = [[NSBundle mainBundle] pathForResource:@"Urls" ofType:@"plist"];
            NSDictionary* urlSet = [[NSDictionary alloc] initWithContentsOfFile:filePath];
            AFJSONRequestSerializer *requestSerializer = [AFJSONRequestSerializer serializer];
            [requestSerializer setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
            [requestSerializer setValue:@"application/json" forHTTPHeaderField:@"Accept"];
            
            NetMdLoginViewController* mainViewController = [self.storyboard instantiateViewControllerWithIdentifier:@"NetMdLoginViewController"];
            
            AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
            manager.requestSerializer   = requestSerializer;
            manager.responseSerializer  = [AFJSONResponseSerializer serializer];
            [manager POST:[urlSet valueForKey:@"ActivationUrl"] parameters:parameters
                  success:^(AFHTTPRequestOperation *operation, id responseObject) {
                      NSLog(@"Response JSON: %@", responseObject);
                      
                      int successValue=[responseObject[@"success"] intValue];
                      NSLog(@"success is %d", successValue);
                      if(successValue!=1)
                      {
                          _alertLbl.text=@"Wrong PassPhrase !!";
                          [_alertLbl setHidden:NO];
                          [self.view addSubview:_alertLbl];
                      }
                      else
                      {
                          [ _alertLbl setHidden:YES];
                          [[NSUserDefaults standardUserDefaults] setObject:[NSDate date] forKey:@"firsttimerun"];
                          [[NSUserDefaults standardUserDefaults] synchronize];
                          [[[UIApplication sharedApplication] keyWindow] setRootViewController:mainViewController];
                          NetmdActivation* netmd=[[NetmdActivation alloc]init];
                          _passPhraseDAO.passPhrase=passphrase;
                          _passPhraseDAO.macId=macId;
                          
                          NSString* devId = [responseObject objectForKey:@"id"];
                          _passPhraseDAO.devId = devId;
         
                          [netmd activateNetmd:responseObject passphrase:_passPhraseDAO];
                      }
                      
                  } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
                      NSLog(@"Error: %@", error);
                  }];
        }
        else
        {
            NSLog(@"Not valid object to convert to json");
        }
    }
}


-(BOOL)checkValidity
{
    BOOL result = YES;
    switch (_passPhrase.text.length)
    {
        case 0:
            NSLog(@"Passphrase is null");
            _alertLbl.text = @"Passphrase is null";
            [_alertLbl setHidden:NO];
            [self.view addSubview:_alertLbl];
            result = NO;
            break;
            
        default:
            [_alertLbl setHidden:YES];
            break;
    }
    return result;
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
