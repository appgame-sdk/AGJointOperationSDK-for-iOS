//
//  ViewController.m
//  AGJointOperationSDKDemo
//
//  Created by Mao on 16/3/2.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import "ViewController.h"
#import <AGJointOperationSDK/AGJointOperationSDK.h>
#import <StoreKit/StoreKitDefines.h>
#import "MBProgressHUD.h"
#import "AGJointOperationSDK/AGVendorShare.h"

@interface ViewController ()
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(handleLoginNotification:) name:AGLoginNotification object:nil];
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(handleLoginNotification:) name:AGLogOutNotification object:nil];
}

- (void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)handleLoginNotification:(NSNotification*)notification{
    NSLog(@"%@", notification);
    NSDictionary *userInfo = notification.userInfo;
    if (userInfo[@"user"]) {
        MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:[UIApplication sharedApplication].keyWindow animated:YES];
        
        hud.label.text =  [userInfo[@"user"] username];
        hud.mode = MBProgressHUDModeText;
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [hud hideAnimated:YES];
        });
        
    }
}

- (IBAction)showLoginUI:(id)sender {
    [AGUser showLoginUIWithAnimated:YES];
}

- (IBAction)logout:(id)sender{
    [AGUser logOutWithCompletionBlock:^(BOOL success, NSError * _Nonnull error) {
        
    }];
}

- (IBAction)showBindPhoneUI:(id)sender {
    [AGUser showBindOrUnbindPhoneUIWithAnimated:YES];
}
- (IBAction)showConsumableBuy:(id)sender {
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [[AGPurchase sharedInstance] purchaseWithProductIdentifier:@"com.sydl.zs6"
                                                   callBackUrl:@"http://www.baidu.com"
                                                       tradeId:[[NSDate date] description]
                                                   privateInfo:@{@"haha shenme gui":@"xxxxxxx"}
                                                       success:^(SKPaymentTransaction *transaction) {
                                                           [hud hideAnimated:YES];
                                                           NSLog(@"购买成功");
                                                       } failure:^(NSError *error) {
                                                           NSLog(@"购买失败");
                                                           [hud hideAnimated:YES];
                                                           NSLog(@"%@", error);
                                                       }];
}
- (IBAction)showNonConsumableBuy:(id)sender {
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [[AGPurchase sharedInstance] purchaseWithProductIdentifier:@"com.sydl.zs18"
                                                   callBackUrl:@"http://www.baidu.com"
                                                       tradeId:[[NSDate date] description]
                                                   privateInfo:@{@"haha shenme gui":@"xxxxxxx"}
                                                       success:^(SKPaymentTransaction *transaction) {
                                                           [hud hideAnimated:YES];
                                                           NSLog(@"购买成功");
                                                       } failure:^(NSError *error) {
                                                           [hud hideAnimated:YES];
                                                           NSLog(@"购买失败");
                                                       }];
}

- (IBAction)restoreBuy:(id)sender {
    [[AGPurchase sharedInstance] restoreTransactionsOnSuccess:^(NSArray *transactions) {
        NSLog(@"恢复购买成功%@", transactions);
    } failure:^(NSError *error) {
        NSLog(@"恢复购买失败%@", error);
    }];
}

- (IBAction)showShearView:(id)sender{
    NSArray *imageArray = @[[UIImage imageNamed:@"AGJointOperationSDKResource.bundle/vendorLogin_weibo"]];
    
    //设置显示平台 只能分享视频的YouTube MeiPai 不显示
    NSArray *items = @[
                       @(SSDKPlatformTypeQQ),
                       @(SSDKPlatformTypeWechat),
                       @(SSDKPlatformTypeSinaWeibo)
                       ];
    
//    [self.view addSubview:view];
    
    [AGVendorShare sharedWithView:self.view
                             items:items
                             title:@"分享测试"
                               url:[NSURL URLWithString:@"http://www.baidu.com"]
                       contentText:@"分享内容http://www.baidu.com"
                             image:imageArray
                   completionBlock:^(AGShareStatus sharestatus, NSError *error) {
                       
                       UIAlertView *alerView = [[UIAlertView alloc]initWithTitle:@"" message:nil delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
                       switch (sharestatus) {
                           case AGShareStateSuccess:
                               [alerView setTitle:@"分享成功"];
                               [alerView show];
                               break;
                           case AGShareStateFail:
                               [alerView setTitle:@"分享失败"];
                               [alerView show];
                           case AGShareStateCancel:
                               [alerView setTitle:@"分享取消"];
                               [alerView show];
                           default:
                               break;
                       }
                   }];
    
}

- (IBAction)showUserCenter:(id)sender {
    [AGUser showUserCenterWithAnimated:YES];
}

- (IBAction)showIdentificationWindow:(id)sender {
    [AGUser showIdentification:YES];
}

//- (IBAction)bindFacebookAccount:(id)sender {
//    [AGUser bindFacebookAccountWithAppIdKey:@"1263536620388517" presentOnViewController:self completion:^(AGUser * _Nonnull user, NSError * _Nonnull error) {
//        if (error) {
//            NSLog(@"%@", error);
//        }else {
//            NSLog(@"%@", user);
//        }
//    }];
//}

@end
