//
//  AppDelegate.m
//  AGJointOperationSDKDemo
//
//  Created by Mao on 16/3/10.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import "AppDelegate.h"
#import <AGJointOperationSDK/AGVendorShare.h>
#import <AGJointOperationSDK/AGJointOperationSDK.h>
@interface AppDelegate ()

@end


/**
 *  运行代码前，请替换相关参数配置
 */
@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [AGJointOperationSDK setProductionMode:NO];
    
    [AGJointOperationSDK setClientId:@"tmcs" clientSecret:@"test.tmcs"];
    
    [AGVendorShare registerAppWithShareAppId:@"1a517044eb216" WiboAppId:@"811779025" andWeiboSecret:@"39ac9e1c06feccbae33b84ee920e4f07" weChatAppId:@"wx009fbcef29b998a9" andWeChatSecret:@"5c09b14b702e430cc7438ed8f7e81c6c" QQAppId:@"1105898464" andQQSecret:@"kGP25e1oyo5sDxaU"];
    
    //竖屏游戏
//    [AGJointOperationSDK setSupportedInterfaceOrientations:UIInterfaceOrientationMaskPortrait];
    //横屏游戏
    [AGJointOperationSDK setSupportedInterfaceOrientations:UIInterfaceOrientationMaskLandscape];
    
    [AGJointOperationSDK setRoleId:@"fdsaf"];
    [AGJointOperationSDK setGameServerId:@"aaaa"];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the backcdground.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
