# AGJointOperationSDK-iOS
[任玩堂](http://appgame.com)联运iOS SDK
## 内容摘要

- [系统要求](#系统要求)
- [功能特性](#功能特性)
- [文档支持](#文档支持)
- [快速开始](#快速开始)
- [版本历史](#版本历史)


## 系统要求

- iOS Target : >= iOS 7

## 功能特性

- [x] 支持任玩堂账号中心
	- [x] 支持手机号码和玩+号注册和登录
	- [x] 支持QQ、微信、微博登录和分享
	- [x] 支持手机绑定
	- [x] 支持手机号重置密码
	- [x] 支持游客登录
- [x] 支持苹果内购
	- [x] 封装StoreKit内购过程，方便用户一个函数搞定内购
	- [x] 内置本地收据验证和服务端收据验证 
- [x] 支持数据统计分析
- [x] 网络及接口
	- [x] 支持IPv6。苹果明文规定，2016年6月1日开始所有提交到App Store的应用必须支持IPv6-only网络，为确保项目能正常通过审核，请在项目中增加相关配置来适应App Store的新策略。
	- [x] 支持https访问。SDK中所有接口在正式环境下使用`https`接口，测试环境下使用`http`接口提交数据。
	
## 不支持功能

- [x] 暂时不支持Bitcode功能。苹果的Bitcode还略有问题，如有需要后续可以支持Bitcode。
- [x] UI 上面并没有专为iPad做适配。


## 文档支持

AGJointOperationSDK-iOS 使用 HeaderDoc 注释来做文档支持。
开发者无需单独查阅文档，直接通过 Xcode 就可以查看接口和类的相关信息，减少不必要的麻烦。
## 快速开始

先来看看 AGJointOperationSDK-iOS 接入的步骤

### CocoaPods方式接入

- 配置你的 Podfile 文件，添加如下配置信息

```shell
pod 'AGJointOperationSDK'
```

- 安装 CocoaPods 依赖

```shell
pod install
```

或

```shell
pod update
```

- Done! 运行你工程的 workspace


### 手动添加
>注：1.2.0 版本加入了第三方登录，如选择手动安装，需要在您的项目中手动配置shareSDK。建议使用pod安装 `AGJointOperationSDK`。

1. 下载整个项目，将`AGJointOperationSDK.framework` 和 `AGJointOperationSDKResource.bundle`拖到您的工程内
	> 两个文件需在同一目录下
	
	![](http://o9xc0bh9t.bkt.clouddn.com/QQ20161215-114953.png)
2. 添加系统库`MobileCoreServices.framework`，`SystemConfiguration.framework`，`AdSupport.framework`，`UIKit.framework`，`libsqlite3.tbd`。

	![](http://o9xc0bh9t.bkt.clouddn.com/14828273371003.jpg)
3. 配置工程。
	- 添加`-ObjC`标志到Other Linker Flags。
	
	  ![](http://o9xc0bh9t.bkt.clouddn.com/14817743000443.jpg)
	  
	- 设置 `Enable Bitcode` 为 `No`
		
	  ![](http://o9xc0bh9t.bkt.clouddn.com/14817744325203.jpg)
	  
	- 配置QQ、微信、微博
	  ![](http://o9xc0bh9t.bkt.clouddn.com/14876729585276.jpg)
	  
	- `info.plist` 添加白名单
	
	  ![](http://o9xc0bh9t.bkt.clouddn.com/14876732573247.jpg)
	  

### 示例代码

在需要的地方添加

```Objective-C
#import <AGJointOperationSDK/AGJointOperationSDK.h>
```
初始化

```Objective-C

//默认为正式环境，NO为测试环境
[AGJointOperationSDK setProductionMode:NO];

//配置clentId, seceret 和 热云 appKey
[AGJointOperationSDK setClientId:@"你的client id" clientSecret:@"你的client secret" reYunAppKey:@"热云appKey"];

//配置shareSDK
[AGVendorShare registerAppWithShareAppId:@"shareAppId" WiboAppId:@"weiboAppId" andWeiboSecret:@"weiboSecret" weChatAppId:@"weChatId" andWeChatSecret:@"WeChatSecret" QQAppId:@"QQAppId" andQQSecret:@"QQSecret"];
```
显示登录界面

```Objective-C
[AGUser showBindOrUnbindPhoneUIWithAnimated:YES];
```

退出登录

```Objective-C
[AGUser logOutWithCompletionBlock:^(BOOL success, NSError * _Nonnull error) {
   
}];
```

内购

```Objective-C
// 购买
[[AGPurchase sharedInstance] purchaseWithProductIdentifier:@"你的产品商品id" callBackUrl:@"你的回调地址" tradeId:@"你的订单号" privateInfo:@{@"你的参数":@""} success:^(SKPaymentTransaction *transaction) {
	  NSLog(@"购买成功");
} failure:^(NSError *error) {
	  NSLog(@"购买失败");
}];
```

分享到新浪微博，需要把链接加到分享内容里。如下所示，要分享的链接为 `http://www.baidu.com`

```Objective-C
NSArray *imageArray = @[[UIImage imageNamed:@"testImage"]];
[AGVendorShare sharedWithTitle:@"分享测试" url:[NSURL URLWithString:@"http://www.baidu.com"] contentText:@"分享内容http://www.baidu.com" image:imageArray];
```

数据统计分析

* 开启数据统计的 debug 模式

```Objective-C
// 开启debug模式下，您可以实时观察数据变化
// 默认为关闭状态
[AGAnalysis setDebugMode:YES];
```
* 调用

```Objective-C
// 在需要采集数据的地方调用对应的接口来采集和上传数据，例如：角色注册事件(在角色注册成功后调用)
[AGAnalysis sendRoleRegisterEventWithExtraData:nil completionBlock:^(NSError *error) {
    if (error) {
        NSLog(@"%@", error);
    }
}];
```

* debug模式下查看统计结果

	- 浏览器中打开: http://106.75.18.10/chat.html?channel=appkey
	- appkey的位置填写游戏对应的clientID
	- 错误提示
		- 字段【xxx】内容无效: 表示参数 `xxx` 的格式不正确
		- 校验失败: 签名错误
		- unknow appkey - xxx：表示  `clientID` 无效
	
###回调地址说明

用户完成支付之后，SDK服务器会给开发商服务器发起POST回调，通知订单处理结果。开发商需要在内购的时候传入回调地址。

####回调参数说明：

名字 | 可选 | 说明
------- | ------- | ------
trade_id | 否 | 开发商提交的订单号
appgame_order_id | 否 | 支付系统生成的订单号
amount | 否 | 交易金额，以"元"为单位
status | 否 | 订单支付状态：complete - 完成 failed - 失败 canceled - 已取消
time | 否 | 回调请求发起时间，Unix时间戳形式
provider | 否 | 支付渠道标识码，根据 CP 接入的渠道而异，目前苹果的标识码为Apple
private_info | 是 | CP 在发起支付请求时，若提供 private_info，则原值返回，若未提供，则无此参数
sign | 否 | 通知请求签名，用于验证通知有效性。

#### 回调过程

开发商收到通知之后请处理支付结果，并返回字符串 ok 表示回调处理成功。
若SDK服务器发送通知请求之后，未得到 ok 响应，则会在一段时间内尝试重新发起请求。
尝试重发间隔为：1 分钟，2 分钟，10 分钟，30 分钟，1 小时，2 小时，4 小时，12 小时，24 小时，最多重发 9 次。



####如何生成签名（Sign）

将所有参数键值对（参数=值，不包含sign本身）按照参数名从小到大顺序排序，用&符号连接起来，计算出MD5值，连接上开发商的APP Secret再次计算 MD5 值即为签名值：

```
md5(md5("参数1=值1&参数2=值2")+秘钥)
```
###验证用户信息有效性
通过SDK客户端获取Access Token成功后，如果对安全要就比较高，可以用它向SDK服务器请求用户资源来进行认证，示例如下：

```
GET https://passport.appgame.com/resource/userinfo?access_token=aKmsEfsLLmLDpJneSTmyykYYNe4jKiwvn20YAb6v
```

测试环境下请调用测试服务器接口：

```
GET http://passport.test.appgame.com/resource/userinfo?access_token=aKmsEfsLLmLDpJneSTmyykYYNe4jKiwvn20YAb6v
```
如果请求成功，服务器将返回类似如下格式的 JSON 数据：

```JSON
{
    "id":"1000",
    "passport_id":"1000",
    "username":"Fishdrowned",
    "email":"fishdrowned@gmail.com",
    "mobile":"137XXXXXXXX",
    "avatar": "http://avatar.static.appgame.com/uploads/avatar/4d/Z9/4cCx.png",
    "nickname":"Fishdrowned",
    "sex": 0, 
    "province": 1, 
    "province_name":"北京市",
    "city": 2,
    "city_name":"市区"
}
```
如果请求失败，服务器将返回类似如下格式的 JSON 数据：

```JSON
{
    "status":401,
    "error":"unauthorized",
    "error_message":"Access token is not valid"
}
```
## 版本历史
- 1.3.1
	- 修改了分享接口，增加了 URL 参数。
	- 修改了游客登录的文案。
- 1.2.1 
	- 加入第三方分享。
- 1.2.0
	- 加入第三方登录。
	- 修复若干bug。
- 1.1.4
	- 优化内购流程。 
- 1.1.3
	- 修复若干bug。
- 1.1.2
	- 修复重复记录账号的bug。
- 1.1.1
	- 全面支持https接口。
	- 规范一些接口的命名。
	- 修复若干bug。
- 1.1.0
	- 加入热云统计
	- 修复若干bug。
- 1.0.16
	- 优化统计接口。
	- 修复若干bug。
- 1.0.15
	- 界面改版，替换为弹框形式。
	- 增加统计分析功能。
	- 修复若干bug。
- 1.0.14
	- 修复一个可能丢单的问题。 
- 1.0.13
	- 修改服务器地址。
	- game server id为必选参数。
	- 增加可选的游戏角色id
- 1.0.12
	- 增加transaction id的校验。 
- 1.0.11
    - 修复账号若干bugs。
- 1.0.10
    - 修复账号若干bugs。
- 1.0.9
    - 修复丢单问题。
- 1.0.8
    - 修改匿名账号处理方式。匿名账号直到被绑定手机号码的情况下，下次匿名登录才会创建新的匿名账号。
- 1.0.7
    - 增加gameServerId设置.
- 1.0.6
    - 增加屏幕支持方向设置。例如`[AGJointOperationSDK setSupportedInterfaceOrientations:UIInterfaceOrientationMaskLandscape]`。
    - 修复若干bug.
- 1.0.5
	- 内购接口增加privateInfo参数。CP可以传入任意参数，这些信息会在服务接收回调的时候被带上。
- 1.0.4
	- 增加登录发送通知功能。通过接收通知可获得登录状态及相关信息。通知消息定义在`AGConstants.h`里面。
- 1.0.3
	- 增加滑动列表收起键盘功能。
- 1.0.2
	- 增加IDFA跟踪。因此提交商店版本的时候请选择对应的广告用途。
- 1.0.1
	- 修复一些小缺陷
- 1.0.0
	- 接入任玩堂账号中心
	- 封装StoreKit



