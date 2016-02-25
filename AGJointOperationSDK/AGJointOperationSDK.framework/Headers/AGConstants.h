//
//  AGConstants.h
//  AppGameSDK
//
//  Created by Mao on 16/2/22.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import <Foundation/Foundation.h>

///--------------------------------------
#pragma mark - Logging Levels
///--------------------------------------

/**
 `AGLogLevel` enum specifies different levels of logging that could be used to limit or display more messages in logs.
 
 @see `AppGame.+setLogLevel:`
 @see `AppGame.+logLevel`
 */
typedef NS_ENUM(uint8_t, AGLogLevel) {
    /**
     Log level that disables all logging.
     */
    AGLogLevelNone = 0,
    /**
     Log level that if set is going to output error messages to the log.
     */
    AGLogLevelError = 1,
    /**
     Log level that if set is going to output the following messages to log:
     - Errors
     - Warnings
     */
    AGLogLevelWarning = 2,
    /**
     Log level that if set is going to output the following messages to log:
     - Errors
     - Warnings
     - Informational messages
     */
    AGLogLevelInfo = 3,
    /**
     Log level that if set is going to output the following messages to log:
     - Errors
     - Warnings
     - Informational messages
     - Debug messages
     */
    AGLogLevelDebug = 4
};

///--------------------------------------
#pragma mark - Errors
///--------------------------------------

/**
 Error domain used for all `NSError`s in the SDK.
 */
extern NSString *const _Nonnull AGErrorDomain;

/**
 `AGErrorCode` enum contains all custom error codes that are used as `code` for `NSError` for callbacks on all classes.
 
 These codes are used when `domain` of `NSError` that you receive is set to `AGParseErrorDomain`.
 */
typedef NS_ENUM(NSInteger, AGErrorCode) {
    /**
     Internal server error. No information available.
     */
    kAGErrorInternalServer = 1,
    /**
     The connection to the Parse servers failed.
     */
    kAGErrorConnectionFailed = 100,
    kAGErrorInvalidRequest = 102,
    /**
     Malformed json object. A json dictionary is expected.
     */
    kAGErrorInvalidJSON = 107,
    /**
     Field set to incorrect type.
     */
    kAGErrorIncorrectType = 111,
    /**
     Invalid device token.
     */
    kAGErrorInvalidDeviceToken = 114,
    /**
     The object is too large.
     */
    kAGErrorObjectTooLarge = 116,
    /**
     That operation isn't allowed for clients.
     */
    kAGErrorOperationForbidden = 119,
    /**
     Keys in `NSDictionary` values may not include `$` or `.`.
     */
    kAGErrorInvalidNestedKey = 121,
    /**
     Invalid file name.
     A file name can contain only `a-zA-Z0-9_.` characters and should be between 1 and 36 characters.
     */
    kAGErrorInvalidFileName = 122,
    /**
     The request timed out on the server. Typically this indicates the request is too expensive.
     */
    kAGErrorTimeout = 124,
    /**
     The email address was invalid.
     */
    kAGErrorInvalidEmailAddress = 125,
    /**
     A unique field was given a value that is already taken.
     */
    kAGErrorDuplicateValue = 137,
    /**
     Username is missing or empty.
     */
    kAGErrorUsernameMissing = 200,
    /**
     Password is missing or empty.
     */
    kAGErrorUserPasswordMissing = 201,
    /**
     Username has already been taken.
     */
    kAGErrorUsernameTaken = 202,
    /**
     Email has already been taken.
     */
    kAGErrorUserEmailTaken = 203,
    /**
     The email is missing, and must be specified.
     */
    kAGErrorUserEmailMissing = 204,
    /**
     A user with the specified email was not found.
     */
    kAGErrorUserWithEmailNotFound = 205,
    /**
     The user cannot be altered by a client without the session.
     */
    kAGErrorUserCannotBeAlteredWithoutSession = 206,
    /**
     Users can only be created through sign up.
     */
    kAGErrorUserCanOnlyBeCreatedThroughSignUp = 207,
    /**
     Error code indicating that the current session token is invalid.
     */
    kAGErrorInvalidSessionToken = 209,
    kAGErrorUserIdMismatch = 210,
    kAGErrorInvalidUserInfo = 211
};

///--------------------------------------
#pragma mark - Blocks
///--------------------------------------

@class AGUser;

typedef void (^AGBooleanResultBlock)(BOOL succeeded, NSError *_Nullable error);
typedef void (^AGIntegerResultBlock)(int number, NSError *_Nullable error);
typedef void (^AGArrayResultBlock)(NSArray *_Nullable objects, NSError *_Nullable error);
typedef void (^AGSetResultBlock)(NSSet *_Nullable channels, NSError *_Nullable error);
typedef void (^AGUserResultBlock)(AGUser *_Nullable user, NSError *_Nullable error);
typedef void (^AGDataResultBlock)(NSData *_Nullable data, NSError *_Nullable error);
typedef void (^AGDataStreamResultBlock)(NSInputStream *_Nullable stream, NSError *_Nullable error);
typedef void (^AGFilePathResultBlock)(NSString *_Nullable filePath, NSError *_Nullable error);
typedef void (^AGStringResultBlock)(NSString *_Nullable string, NSError *_Nullable error);
typedef void (^AGIdResultBlock)(_Nullable id object, NSError *_Nullable error);
typedef void (^AGProgressBlock)(int percentDone);

extern uint8_t const AGDefaultMaxNetworkRetryAttempts;

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
