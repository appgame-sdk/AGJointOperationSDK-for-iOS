//
//  ViewController.m
//  AGJointOperationSDKDemo
//
//  Created by Mao on 16/2/25.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import "ViewController.h"
#import <AGJointOperationSDK/AGJointOperationSDK.h>
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [AGJointOperation setApplicationId:@"your " clientKey:@"xxx"];
    // Do any additional setup after loading the view, typically from a nib.
    [AGUser loginWithUsername:@"hahanihao" password:@"123456" completionBlock:^(AGUser * _Nonnull user, NSError * _Nonnull error) {
        
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
