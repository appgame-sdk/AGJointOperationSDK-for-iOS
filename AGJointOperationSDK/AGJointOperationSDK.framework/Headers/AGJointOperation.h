//
//  AppGame.h
//  AppGameSDK
//
//  Created by Mao on 16/2/22.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AGJointOperation : NSObject
+ (void)setApplicationId:(NSString *)applicationId clientKey:(NSString *)clientKey;
/**
 The current application id that was used to configure Parse framework.
 */
+ (NSString *)getApplicationId;

/**
 The current client key that was used to configure Parse framework.
 */
+ (NSString *)getClientKey;
@end
