//
//  AGUser+AGUI.h
//  AGJointOperationSDK
//
//  Created by Mao on 16/3/9.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import <AGJointOperationSDK/AGJointOperationSDK.h>
#import <UIKit/UIKit.h>

@interface AGUser (AGUI)
/**
 显示用户登录UI。
 @warning 必须保证调用时window.rootViewController存在。因为登录的UI是present在rootViewController上面的。
 @param animated 显示的时候是否需要动画。转场样式为UIModalTransitionStyleCrossDissolve。
 */
+ (void)showLoginUIWithAnimated:(BOOL)animated;

/**
 显示用户绑定手机号UI，如果已经绑定则显示解绑UI。
 @warning 必须保证调用时window.rootViewController存在。因为登录的UI是present在rootViewController上面的。
 @param animated 显示的时候是否需要动画。转场样式为UIModalTransitionStyleCrossDissolve。
 */
+ (void)showBindOrUnbindPhoneUIWithAnimated:(BOOL)animated;


+ (void)showUserCenterWithAnimated:(BOOL)animated;

@end
