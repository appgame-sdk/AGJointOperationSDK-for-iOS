//
//  AGUser.h
//  AppGameSDK
//
//  Created by Mao on 16/2/22.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AGJointOperationSDK/AGConstants.h>
@class AGUser;
NS_ASSUME_NONNULL_BEGIN

typedef void (^BindFaceBookCompletion)(AGUser *user, NSError *error);

/**
 任玩堂的OAuth认证信息
 */
@interface AGCredentialInfo : NSObject<NSSecureCoding>
@property(nonatomic,   copy, readonly) NSString   *accessToken;
@property(nonatomic, assign, readonly) int64_t    expires;
@property(nonatomic, assign, readonly) int64_t    expiresIn;
@property(nonatomic,   copy, readonly) NSString   *refreshToken;
@property(nonatomic, assign, readonly) int64_t    refreshTokenExpires;
@property(nonatomic, assign, readonly) int64_t    refreshTokenExpiresIn;
@property(nonatomic,   copy, readonly) NSString   *tokenType;


- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

- (BOOL)refreshTokenExpired;
@end

/**
 任玩堂用户对象。
 */
@interface AGUser : NSObject<NSSecureCoding>
@property (nonatomic, strong, readonly)         AGCredentialInfo *credentialInfo;
///用户id
@property (nonatomic,   copy, readonly)         NSString *userId;
///Passport ID
@property (nonatomic,   copy, readonly)         NSString *passportId;
///头像
@property (nullable, nonatomic, copy, readonly) NSString *avatar;
///邮件
@property (nullable, nonatomic, copy, readonly) NSString *email;
///电话
@property (nullable, nonatomic, copy, readonly) NSString *mobile;
///昵称
@property (nullable, nonatomic, copy, readonly) NSString *nickname;
///用户名
@property (nullable, nonatomic, copy, readonly) NSString *username;
///是否为社交账号登录
@property (nonatomic, assign, readonly) BOOL    social;
///性别。0表示未知，1表示男，2表示女
@property (nonatomic, assign, readonly) int     sex;
///省份id
@property (nonatomic, assign, readonly) int     province;
///省份名字
@property (nullable, nonatomic, copy, readonly) NSString *provinceName;
///城市id
@property (nonatomic, assign, readonly) int     city;
///城市名字
@property (nullable, nonatomic, copy, readonly) NSString *cityName;
///用户描述
@property (nullable, nonatomic, copy, readonly) NSString *info;
///用户第三方平台描述
@property (nonatomic, strong, readonly) NSDictionary *provider_info;
///是否为匿名（游客）登录
@property (nonatomic, assign, readonly, getter=isAnonymous) BOOL anonymous;

///是否实名认证
@property (nonatomic, assign, readonly) BOOL identification;

/**
 获得当前登录的用户，可能为nil。
 */
+ (instancetype)currentUser;
/**
 退出当前用户的登录状态。
 */
+ (void)logOutWithCompletionBlock:(void (^)(BOOL success, NSError *error))block;


@end

NS_ASSUME_NONNULL_END
