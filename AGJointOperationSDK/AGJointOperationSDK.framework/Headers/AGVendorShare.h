//
//  AGVendorShare.h
//  AGJointOperationSDK
//
//  Created by 猎人 on 2017/1/11.
//  Copyright © 2017年 AppGame. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <ShareSDK/SSDKTypeDefine.h>


/**
 此类用来处理第三方登录的相关业务，依赖shareSDK实现，如您的项目中已经集成了shareSDK，请先移除再使用。
 */
@interface AGVendorShare : NSObject

/**
 注册第三方平台的基本信息

 @param shareAppId shareSDK 后台 appId
 @param weiboAppId 新浪微博 后台 appId
 @param weiboSecret 新浪微博 secret
 @param wechatAppId 微信 appId
 @param wechatSecret 微信 secret
 @param QQAppId QQ appId
 @param QQSecret QQ secret
 */
+ (void)registerAppWithShareAppId:(NSString *)shareAppId
                        WiboAppId:(NSString *)weiboAppId
                   andWeiboSecret:(NSString *)weiboSecret
                      weChatAppId:(NSString *)wechatAppId
                  andWeChatSecret:(NSString *)wechatSecret
                          QQAppId:(NSString *)QQAppId
                      andQQSecret:(NSString *)QQSecret;



/**
 获取各平台对应的appId

 @param platform 平台类型
 @return appId
 */
+ (NSString *)getAppIdWithPlatform:(SSDKPlatformType)platform;

@end
