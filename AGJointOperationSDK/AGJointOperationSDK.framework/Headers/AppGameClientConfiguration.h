/**
 * Copyright (c) 2015-present, Parse, LLC.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/**
 The `ParseClientConfiguration` represents the local configuration of the SDK to connect to the server with.

 These configurations can be stored, copied, and compared, but cannot be safely changed once the SDK is initialized.

 Use this object to construct a configuration for the SDK in your application, and pass it to
 `Parse.+initializeWithConfiguration:`.
 */
@interface AppGameClientConfiguration : NSObject <NSCopying>

@property (nullable, nonatomic, copy, readwrite) NSString *applicationId;
@property (nullable, nonatomic, copy, readwrite) NSString *clientKey;
@property (nonatomic, assign, readwrite) NSUInteger networkRetryAttempts;

///--------------------------------------
#pragma mark - Creating a Configuration
///--------------------------------------

/**
 Create a new SDK configuration object. This will create a temporarily modifiable configuration, and pass it to a block
 to be initialized.
 
 Example usage:
 
 ```
 [ParseClientConfiguration configurationWithBlock:^(id<ParseMutableClientConfiguration> configuration) {
     configuration.applicationId = ...;
     configuration.clientKey = ...;
     configuration.localDatastoreEnabled = ...;
 }];
 ```

 @param configurationBlock A block used to modify the created configuration.

 @return A newly created configuration.
 */
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
