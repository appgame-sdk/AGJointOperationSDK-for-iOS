//
//  AGAnalysis.h
//  AGJointOperationSDK
//
//  Created by Mao on 16/3/15.
//  Copyright © 2016年 AppGame. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef void (^ErrorBlock)(NSError *error);
@interface AGAnalysis : NSObject

///上传应用的一些基本信息
+ (void)sendAppActivationDataWithCompletionBlock:(void(^)(NSError *error))block;



+ (void)setDebugModel:(BOOL)debug __attribute__((deprecated("使用 setDebugMode: 代替")));

/**
 * 设置调试模式
 */
+ (void)setDebugMode:(BOOL)debug;

/**
 初始化设备启动事件的相关数据 (在应用启动初始化时调用，调用前必须配置好 clientId 和 clientSecret)

 @param extraData 扩展数据
 @param block     完成回调
 */
+ (void)sendLaunchEventWithExtraData:(NSDictionary *)extraData
                     completionBlock:(ErrorBlock)block;


/**
 上传角色注册事件 (在成功创建新的游戏角色时调用)
 
 @param extraData 扩展数据
 @param block     完成回调
 */
+ (void)sendRoleRegisterEventWithExtraData:(NSDictionary *)extraData
                            completionBlock:(ErrorBlock)block;


/**
 上传角色登入事件 (在角色成功进入游戏时调用)
 
 @param extraData 扩展数据
 @param block     完成回调
 */
+ (void)sendRoleLoginEventWithExtraData:(NSDictionary *)extraData
                         completionBlock:(ErrorBlock)block;


/**
 上传角色登出事件 (角色从游戏退出时调用)
 
 @param extraData 扩展数据
 @param block     完成回调
 */
+ (void)sendRoleLogoutEventWithExtraData:(NSDictionary *)extraData
                          completionBlock:(ErrorBlock)block;


/**
 上传充值事件 (无需调用，充值成功自动调用)

 @param payParams 支付相关参数
 @param block     完成回调
 */
+ (void)sendPayEventWithParams:(NSDictionary *)payParams completionBlock:(ErrorBlock)block;


/**
 上传角色升级事件 (角色成功升级后调用)

 @param ulevel    角色等级
 @param extraData 扩展数据
 @param block     完成回调
 */
+ (void)sendRoleLevelupEventWithUlevel:(NSString *)ulevel
                             extraData:(NSDictionary *)extraData
                       completionBlock:(ErrorBlock)block;


/**
 上传角色标签设置事件(为角色分析提供更多的维度)

 @param action    操作类型 ('1' - 设置标签，'0' - 删除标签，默认为设置标签)
 @param tag1      一级标签
 @param tag2      二级标签
 @param extraData 扩展数据
 @param block     完成回调
 */
+ (void)sendRoleMarkEventWithAction:(NSString *)action
                               tag1:(NSString *)tag1
                               tag2:(NSString *)tag2
                          extraData:(NSDictionary *)extraData
                    completionBlock:(ErrorBlock)block;


/**
 发送虚拟货币事件

 @param action      操作类型 ('1' - 获得虚拟货币，'0' - 消费虚拟货币，默认为消费虚拟货币)
 @param reason      虚拟货币变动原因(比如购买道具，进入副本，战斗获得)(必填参数)
 @param point       虚拟货币变动节点（比如道具编号， 副本编号， ..... ）
 @param coinType    虚拟货币类型
 @param coinCount   虚拟货币变动数量
 @param coinBalance 虚拟货币剩余数量
 @param extraData   扩展数据
 @param block       完成回调
 */
+ (void)sendVirtualCoinEventWithAction:(NSString *)action
                                reason:(NSString *)reason
                                 point:(NSString *)point
                              coinType:(NSString *)coinType
                             coinCount:(NSString *)coinCount
                           coinBalance:(NSString *)coinBalance
                             extraData:(NSDictionary *)extraData
                       completionBlock:(ErrorBlock)block;


/**
 发送道具事件

 @param action      操作类型（'1' - 获得道具， '0' - 失去道具， 默认为失去道具）
 @param reason      道具变动原因（比如购买道具， 战斗获得， 道具丢弃(必填参数)）
 @param point       道具变动节点（对道具变动原因的补充， 比如用于标识获得道具的场景或者使用道具的场景）
 @param itemType    道具类型
 @param itemID      道具标识
 @param itemCount   道具变动数量
 @param itemBalance 道具剩余数量
 @param extraData   扩展数据
 @param block       完成回调
 */
+ (void)sendItemEventWithWithAction:(NSString *)action
                             reason:(NSString *)reason
                              point:(NSString *)point
                           itemType:(NSString *)itemType
                             itemID:(NSString *)itemID
                          itemCount:(NSString *)itemCount
                        itemBalance:(NSString *)itemBalance
                          extraData:(NSDictionary *)extraData
                    completionBlock:(ErrorBlock)block;


/**
 发送副本事件

 @param dungeonType 副本类型（普通， 精英， .....）
 @param dungeonID   副本编号
 @param isAuto      是否自动战斗（'1' - 自动战斗， '0' - 非自动战斗， 默认非自动战斗）
 @param isMaiden    是否初次胜利（'1' - 初次胜利， '0' - 非初次胜利， 默认非初次胜利）
 @param isSweep     是否扫荡副本（'1' - 扫荡副本， '0' - 非扫荡副本， 默认非扫荡副本）
 @param result      战斗结果（'0' - 战斗失败， '1' - 一星胜利， .....）
 @param reason      战斗失败原因
 @param duration    副本战斗时长（秒）
 @param extraData   扩展数据
 @param block       完成回调
 */
+ (void)sendDungeonEventWithDungeonType:(NSString *)dungeonType
                              dungeonID:(NSString *)dungeonID
                                 isAuto:(BOOL)isAuto
                               isMaiden:(BOOL)isMaiden
                                isSweep:(BOOL)isSweep
                                 result:(NSString *)result
                                 reason:(NSString *)reason
                               duration:(NSString *)duration
                              extraData:(NSDictionary *)extraData
                        completionBlock:(ErrorBlock)block;


/**
 发送任务事件

 @param taskType  任务类型（普通， 每日， 活动， .....）
 @param taskID    任务编号
 @param action    操作类型（'0' - 领取任务， '1' - 完成任务， '2' - 任务失败）
 @param reason    任务失败原因
 @param duration  任务时长（秒）
 @param extraData 扩展数据
 @param block     完成回调
 */
+ (void)sendTaskEventWithTaskType:(NSString *)taskType
                           taskID:(NSString *)taskID
                           action:(NSString *)action
                           reason:(NSString *)reason
                         duration:(NSString *)duration
                        extraData:(NSDictionary *)extraData
                  completionBlock:(ErrorBlock)block;


/**
 发送自定义事件（帮助统计某些CP希望统计的事件类型）

 @param eventType 事件类型
 @param eventID   事件编号
 @param action    事件操作（'0' - 触发事件， '1' - 事件完成， '2' - 事件失败）
 @param duration  事件时长（秒）
 @param extraData 扩展数据
 @param block     完成回调
 */
+ (void)sendCustomEventWithEventType:(NSString *)eventType
                             eventID:(NSString *)eventID
                              action:(NSString *)action
                            duration:(NSString *)duration
                           extraData:(NSDictionary *)extraData
                     completionBlock:(ErrorBlock)block;


/**
 发送错误报告（帮助定位游戏错误）

 @param summary 错误描述 (错误分组， 设计错误报告时需要精细选择)
 @param message 错误内容
 @param block   完成回调
 */
+ (void)sendReportEventWithSummary:(NSString *)summary
                           message:(NSString *)message
                   completionBlock:(ErrorBlock)block;

@end
