//
//  AGUser.h
//  AppGameSDK
//
//  Created by Mao on 16/2/22.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AGJointOperationSDK/AGConstants.h>

NS_ASSUME_NONNULL_BEGIN

@interface AGCredentialInfo : NSObject
@property(nonatomic,   copy, readonly) NSString   *accessToken;
@property(nonatomic, assign, readonly) int64_t    expires;
@property(nonatomic, assign, readonly) int64_t    expiresIn;
@property(nonatomic,   copy, readonly) NSString   *refreshToken;
@property(nonatomic, assign, readonly) int64_t    refreshTokenExpires;
@property(nonatomic, assign, readonly) int64_t    refreshTokenExpiresIn;
@property(nonatomic,   copy, readonly) NSString   *tokenType;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;
@end

@interface AGUser : NSObject
@property (nullable, nonatomic, strong, readonly) AGCredentialInfo *credentialInfo;
@property (nonatomic, copy, readonly) NSString *userId;
@property (nonatomic, copy, readonly) NSString *passportId;
@property (nullable, nonatomic, copy, readonly) NSString *avatar;
@property (nullable, nonatomic, copy, readonly) NSString *email;
@property (nullable, nonatomic, copy, readonly) NSString *mobile;
@property (nullable, nonatomic, copy, readonly) NSString *nickname;
@property (nullable, nonatomic, copy, readonly) NSString *username;
@property (nonatomic, assign, readonly) BOOL social;
@property (nonatomic, assign, readonly) int sex;
@property (nonatomic, assign, readonly) int province;
@property (nonatomic, copy, readonly) NSString *provinceName;
@property (nonatomic, assign, readonly) int  city;
@property (nonatomic, copy, readonly) NSString *cityName;
@property (nonatomic, copy, readonly) NSString *info;

#pragma mark - 刷新SessionToken
+ (void)refreshAccessTokenWithRefreshToken:(NSString*)refreshToken
                           completionBlock:(void (^)(AGCredentialInfo *credentialInfo, NSError *error))block;
#pragma mark - 登录

/**
 *  使用账号密码登录
 *
 *  @param username 用户名或者手机号
 *  @param password 密码
 *  @param block    回调block
 */
+ (void)loginWithUsername:(NSString *)username
                 password:(NSString *)password
          completionBlock:(void (^)(AGUser *user, NSError *error))block;


/**
 *  微信登录登录
 *
 *  @param authData 微信平台返回的用户验证数据
 *      微信平台
 *      {
 *      "openid": "0395BA18A5CD6255E5BA185E7BEBA242",
 *      "unionid": "o6_bmasdasdsad6_2sgVt7hMZOPfL", 
 *      "access_token": "12345678-SaMpLeTuo3m2avZxh5cjJmIrAfx4ZYyamdofM7IjU",
 *      "expires_in": 1382686496
 *      }
 *  @param block    回调block
 */
+ (void)loginWithWechatAuthData:(NSDictionary*)authData
                completionBlock:(void (^)(AGUser *user, NSError *error))block;
#pragma mark - 注册

/**
 *  普通注册（用户名+密码注册）
 *
 *  @param username 用户名
 *  @param password 密码
 *  @param block    回调block
 */
+ (void)registerWithUsername:(NSString *)username
                    password:(NSString *)password
             completionBlock:(void (^)(AGUser* user, NSError *error))block;

/**
 *  手机号码注册
 *
 *  @param phoneNumber 手机号码
 *  @param captcha     验正码
 *  @param password    密码
 *  @param block       回调block
 */
+ (void)registerWithPhoneNumber:(NSString *)phoneNumber
                        captcha:(NSString *)captcha
                       password:(NSString *)password
                completionBlock:(void (^)(AGUser* user, NSError *error))block;
/**
 *  此步骤用于不填写密码的快速注册，由 OAuth 服务器生成初始密码。
 *
 *  @param code   验证码
 *  @param mobile 手机号
 *  @param block  回调block：成功会返回初始密码
 */
+ (void)registerWithPhoneNumber:(NSString *)phoneNumber
                        captcha:(NSString *)captcha
                completionBlock:(void (^)(NSString *initialPassword, NSError *error))block;

/**
 *  发生注册验证码到手机号
 *
 *  @param mobile 手机号
 *  @param block  回调block
 */
+ (void)sendMobileCaptchaForRegisterWithPhoneNumber:(NSString *)phoneNumber
                                    completionBlock:(void (^)(BOOL success, NSError *error))block;



#pragma mark - 绑定手机号
/**
 *  向手机号发用于绑定的验证码
 *
 *  @param phoneNumber 手机号
 *  @param block       回调block
 */
+ (void)sendMobileCaptchaForBindingMobileWithPhoneNumber:(NSString *)phoneNumber
                                            sessionToken:(NSString *)token
                                         completionBlock:(void (^)(BOOL success, NSError *error))block;
/**
 *  验证用于绑定的验证码是否正确
 *
 *  @param phoneNumber 手机号
 *  @param captcha     验证码
 *  @param block       回调block
 */
+ (void)verifyMobileCaptchaForBindingMobileWithPhoneNumber:(NSString *)phoneNumber
                                                   captcha:(NSString *)captcha
                                              sessionToken:(NSString *)token
                                           completionBlock:(void (^)(BOOL success, NSError *error))block;
#pragma mark - 解绑手机号
/**
 *  向手机号发用于解绑的验证码
 *
 *  @param phoneNumber 手机号
 *  @param block       回调block
 */
+ (void)sendMobileCaptchaForUnbindingMobileWithPhoneNumber:(NSString *)phoneNumber
                                              sessionToken:(NSString *)token
                                           completionBlock:(void (^)(BOOL success, NSError *error))block;
/**
 *  验证用于解绑的验证码是否正确
 *
 *  @param phoneNumber 手机号
 *  @param captcha     验证码
 *  @param block       回调block
 */
+ (void)verifyMobileCaptchaForUnBindingMobileWithPhoneNumber:(NSString *)phoneNumber
                                                sessionToken:(NSString *)token
                                                     captcha:(NSString *)captcha
                                             completionBlock:(void (^)(BOOL success, NSError *error))block;
#pragma mark - 修改密码
/**
 *  修改密码
 *
 *  @param username    用户名或者手机号
 *  @param oldPassword 旧密码
 *  @param newPassword 新密码
 */
+ (void)changePasswrodWithUsername:(NSString *)username
                      sessionToken:(NSString *)token
                       oldPasswrod:(NSString *)oldPassword
                       newPassword:(NSString *)newPassword
                   completionBlock:(void (^)(BOOL success, NSError *error))block;
#pragma mark - 重置密码
/**
 *  向手机号发用于重置密码的验证码
 *
 *  @param phoneNumber 手机号
 *  @param block       回调block
 */
+ (void)sendMobileCaptchaForResetPasswordWithPhoneNumber:(NSString *)phoneNumber
                                         completionBlock:(void (^)(BOOL success, NSError *error))block;
/**
 *  验证用于重置密码的验证码是否正确
 *
 *  @param phoneNumber 手机号
 *  @param captcha     验证码
 *  @param block       回调block
 */
+ (void)verifyMobileCaptchaForResetPasswordWithPhoneNumber:(NSString *)phoneNumber
                                              sessionToken:(NSString *)token
                                                   captcha:(NSString *)captcha
                                           completionBlock:(void (^)(BOOL success, NSError *error))block;
/**
 *  利用手机号重置密码
 *
 *  @param phoneNumber          手机号码
 *  @param captcha              验证码
 *  @param password             密码
 *  @param passwordConfirmation 确认密码
 */
+ (void)resetPasswordWithPhoneNumber:(NSString *)phoneNumber
                             captcha:(NSString *)captcha
                            password:(NSString *)password
                passwordConfirmation:(NSString *)passwordConfirmation
                     completionBlock:(void (^)(BOOL success, NSError *error))block;

+ (void)sendResetPasswordEmail:(NSString*)email
               completionBlock:(void (^)(BOOL success, NSError *error))block;

+ (void)changeEmail:(NSString *)email
       sessionToken:(NSString *)token
    completionBlock:(void (^)(BOOL success, NSError *error))block;

#pragma mark - 退出登录
/**
 *  注销。调用接口注销，同时删除本地keychain里面的用户信息
 */
+ (void)logOutWithAccessToken:(NSString*)accessToken
              completionBlock:(void (^)(BOOL success, NSError *error))block;

@end

NS_ASSUME_NONNULL_END
