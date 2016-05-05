//
//  AGPurchase.h
//  AGJointOperationSDK
//
//  Created by Mao on 16/2/26.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

/**
 内购类。包装了StoreKit的内购过程，同时包含了本地收据验证和服务器收据验证，提高了内购的安全验证。
 @warning 请不要直接调用系统的StoreKit进行内购开发，这样会绕过我们的购买记录和收据验证。
 */
@interface AGPurchase : NSObject

+ (AGPurchase*)sharedInstance;
/**
 内购购买方法。
 @param productIdentifier 对应苹果内购服务的商品id
 @param callBackUrl 交易回调地址
 @param tradeId 用户自己的交易系统对应的订单号
 @param privateInfo CP自定义的一些信息，可以回调给CP服务端。
 @param successBlock 内购成功后回调
 @param failureBlock 内购失败后回调
 */
- (void)purchaseWithProductIdentifier:(NSString *)productIdentifier
                          callBackUrl:(NSString *)callBackUrl
                              tradeId:(NSString *)tradeId
                          privateInfo:(NSDictionary *)privateInfo
                              success:(void (^)(SKPaymentTransaction *transaction))successBlock
                              failure:(void (^)(NSError *error))failureBlock;
/**
 内购恢复方法。
 @param successBlock 恢复内购成功后回调
 @param failureBlock 恢复内购失败后回调
 */
- (void)restoreTransactionsOnSuccess:(void (^)(NSArray *transactions))successBlock
                             failure:(void (^)(NSError *error))failureBlock;
@end
