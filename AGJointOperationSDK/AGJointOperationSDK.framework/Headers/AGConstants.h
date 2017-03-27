//
//  AGConstants.h
//  AppGameSDK
//
//  Created by Mao on 16/2/22.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AGJOINTOPERATIONSDK_VERSION @"1.3.2"

///--------------------------------------
#pragma mark - Notification

/// 登录消息。登录成功或者失败都会发送消息。
extern NSString *const _Nonnull AGLoginNotification;
/// 登出消息。登出失败或者成功都会发送消息。
extern NSString *const _Nonnull AGLogOutNotification;
///--------------------------------------

///--------------------------------------
#pragma mark - Logging Levels
///--------------------------------------

/**
 `AGLogLevel` enum 定义了不同的日志级别.
 
 @see `AppGame.+setLogLevel:`
 @see `AppGame.+logLevel`
 */
typedef NS_ENUM(uint8_t, AGLogLevel) {
    /**
     无日志输出.
     */
    AGLogLevelNone = 0,
    /**
     只输出Error日志。
     */
    AGLogLevelError = 1,
    /**
     输出Error和Warning日志。
     */
    AGLogLevelWarning = 2,
    /**
     输出Error，Warning和Info日志。
     */
    AGLogLevelInfo = 3,
    /**
     输出Error，Warning，Info和Debug日志
     */
    AGLogLevelDebug = 4
};

///--------------------------------------
#pragma mark - Errors
///--------------------------------------

/**
 用户NSError的错误域的名字。
 */
extern NSString *const _Nonnull AGErrorDomain;

/**
 `AGErrorCode` 自定义的错误码。
 */
typedef NS_ENUM(NSInteger, AGErrorCode) {
    /**
     服务端错误，无错误信息提供。
     */
    kAGErrorInternalServer = 1,
    /**
     网络连接错误。
     */
    kAGErrorConnectionFailed = 100,
    /**
     无效网络请求。
     */
    kAGErrorInvalidRequest = 102,
    /**
     无效的JSON格式。
     */
    kAGErrorInvalidJSON = 107,
    /**
     字段类型设置错误。
     */
    kAGErrorIncorrectType = 111,
    /**
     无效DeviceToken。
     */
    kAGErrorInvalidDeviceToken = 114,
    /**
     对象过大。
     */
    kAGErrorObjectTooLarge = 116,
    /**
     禁止的客户端操作。
     */
    kAGErrorOperationForbidden = 119,
    /**
     超时。
     */
    kAGErrorTimeout = 124,
    /**
     邮件格式错误。
     */
    kAGErrorInvalidEmailAddress = 125,
    /**
     值重复。
     */
    kAGErrorDuplicateValue = 137,
    /**
     用户名不存在或者是空的。
     */
    kAGErrorUsernameMissing = 200,
    /**
     密码不存在或者是空的。
     */
    kAGErrorUserPasswordMissing = 201,
    /**
     用户名被占用。
     */
    kAGErrorUsernameTaken = 202,
    /**
     无Session不允许修改用户信息。
     */
    kAGErrorUserCannotBeAlteredWithoutSession = 206,
    /**
     只有登录的情况下才能修改用户信息。
     */
    kAGErrorUserCanOnlyBeCreatedThroughSignUp = 207,
    /**
     当前SessionToken无效。
     */
    kAGErrorInvalidSessionToken = 209,
    /**
     用户Id缺失。
     */
    kAGErrorUserIdMismatch = 210,
    /**
     无效用户信息。
     */
    kAGErrorInvalidUserInfo = 211,
    /**
     找不到产品标识。
     */
    kAGErrorProductIdentifierMismatch = 301,
    /**
     无效的产品标识。
     */
    kAGErrorInvalidProductIdentifier = 302,
    /**
     无效的商品收据。
     */
    kAGErrorInvalidReceipt = 303,
    /**
     订单号丢失。
     */
    kAGErrorPaymentOrderIdLost = 304,
};

///--------------------------------------
#pragma mark - Deprecated Macros
///--------------------------------------

#ifndef APPGAME_DEPRECATED
#  ifdef __deprecated_msg
#    define APPGAME_DEPRECATED(_MSG) __deprecated_msg(_MSG)
#  else
#    ifdef __deprecated
#      define APPGAME_DEPRECATED(_MSG) __attribute__((deprecated))
#    else
#      define APPGAME_DEPRECATED(_MSG)
#    endif
#  endif
#endif

@interface AGConstants : NSObject

@end
