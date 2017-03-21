//
//  ViewController.m
//  AGJointOperationSDKDemo
//
//  Created by Mao on 16/3/10.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import "ViewController.h"
#import <AGJointOperationSDK/AGJointOperationSDK.h>
#import "MBProgressHUD.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
        [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(handleLoginNotification:) name:AGLoginNotification object:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)showLoginUI:(id)sender {
    [AGUser showLoginUIWithAnimated:YES];
}


- (IBAction)showBindPhoneUI:(id)sender {
    [AGUser showBindOrUnbindPhoneUIWithAnimated:YES];
}
- (IBAction)showConsumableBuy:(id)sender {
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [[AGPurchase sharedInstance] purchaseWithProductIdentifier:@"com.sydl.zs128"
                                                   callBackUrl:@"http://www.baidu.com"
                                                       tradeId:[[NSDate date] description]
                                                   privateInfo:@{@"haha shenme gui":@"xxxxxxx"}
                                                       success:^(SKPaymentTransaction *transaction) {
                                                           [hud hideAnimated:YES];
                                                           NSLog(@"购买成功");
                                                       } failure:^(NSError *error) {
                                                           NSLog(@"购买失败");
                                                           [hud hideAnimated:YES];
                                                       }];
}
- (IBAction)showNonConsumableBuy:(id)sender {
    MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    [[AGPurchase sharedInstance] purchaseWithProductIdentifier:@"com.youcan.coin2"
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

- (IBAction)showShareView:(id)sender {
    NSArray *imageArray = @[[UIImage imageNamed:@"AGJointOperationSDKResource.bundle/vendorLogin_weibo"]];
    
    [AGVendorShare sharedWithTitle:@"分享测试" url:[NSURL URLWithString:@"http://www.baidu.com"] contentText:@"分享内容http://www.baidu.com" image:imageArray];
}

- (IBAction)showUserCenter:(id)sender {
        [AGUser showUserCenterWithAnimated:YES];
}

- (IBAction)logout:(id)sender {
    [AGUser logOutWithCompletionBlock:^(BOOL success, NSError * _Nonnull error) {
        if (success) {
            NSLog(@"登出成功");
        }else {
            NSLog(@"%@", error);
        }
    }];
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
@end
