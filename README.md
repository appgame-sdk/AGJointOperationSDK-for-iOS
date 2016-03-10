# AGJointOperationSDK-iOS
[任玩堂](http://appgame.com)联运iOS SDK
## 内容摘要
- [系统要求](#系统要求)
- [功能特性](#功能特性)
- [文档支持](#文档支持)
- [快速开始](#快速开始)
	- [配置工程](#配置工程)
	- [示例代码](#示例代码)
- [版本历史](#版本历史)
## 系统要求

- iOS Target : >= iOS 7

## 功能特性

- [x] 支持任玩堂账号中心
	- [x] 支持手机号码和玩+号注册和登录
	- [x] 支持手机绑定
	- [x] 支持手机号重置密码
	- [x] 支持游客登录
- [x] 支持苹果内购
	- [x] 封装StoreKit内购过程，方便用户一个函数搞定内购
	- [x] 内置本地收据验证和服务端收据验证 

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
下载整个项目，将AGJointOperationSDK内的文件拖到工程内。添加系统库`MobileCoreServices`，`SystemConfiguration`和`UIKit`依赖。添加`-ObjC`标志到Other Linker Flags。


### 示例代码

在需要的地方添加

```Objective-C
#import <AGJointOperationSDK/AGJointOperationSDK.h>
```
初始化

```Objective-C
[AGJointOperationSDK setClientId:@"你的id" clientSecret:@"你的secret"];

//默认为正式环境，NO为测试环境，内购沙盒测试请设置为NO
[AGJointOperationSDK setProductionMode:NO];
```
显示登录界面

```Objective-C
[AGUser showBindOrUnbindPhoneUIWithAnimated:YES];
```
内购

```Objective-C
[[AGPurchase sharedInstance] purchaseWithProductIdentifier:@"你的产品商品id" callBackUrl:@"你的回调地址" tradeId:@"你的订单号" success:^(SKPaymentTransaction *transaction) {
	  NSLog(@"购买成功");
} failure:^(NSError *error) {
	  NSLog(@"购买失败");
}];
```

##回调地址说明

用户完成支付之后，SDK服务器会给开发商服务器发起POST回调，通知订单处理结果。
回调请求如下：
POST http://game-cp.com/callback?
trade_id=orderid123456&
appgame_order_id=agorderid123456&
amount=10&
status=complete&
time=1392803618&
provider=Appgame&
private_info=private_info&
sign=the_callback_sign

参数解释：
trade_id            - 开发商提交订单号
appgame_order_id   - 支付系统生成的订单号
amount              - 交易金额，以"元"为单位
status              - 订单支付状态：
                        complete - 完成
                        failed - 失败
                        canceled - 已取消
time                - 回调请求发起时间
provider            - 支付渠道标识码，根据 CP 接入的渠道而异：
                        任玩堂      Appgame
                        奇虎360     Qihoo360
                        百度        Baidu
                        华为        Huawei
                        小米        Xiaomi
                        应用宝      Yingyongbao
private_info (可选参数)     - CP 在发起支付请求时，
                        若提供 private_info，则原值返回，
                        若未提供，则无此参数。
sign                - 通知请求签名，用于验证通知有效性
其中回调请求签名的生成方法请见 如何生成签名（Sign）
开发商收到通知之后请处理支付结果，并返回字符串 ok 表示回调处理成功。
若SDK服务器发送通知请求之后，未得到 ok 响应，则会在一段时间内尝试重新发起请求。
尝试重发间隔为：1 分钟，2 分钟，10 分钟，30 分钟，1 小时，2 小时，4 小时，12 小时，24 小时，最多重发 9 次。



##如何生成签名（Sign）
将所有参数键值对（参数=值，不包含sign本身）按照参数名从小到大顺序排序，用&符号连接起来，计算出MD5值，连接上开发商的APP Secret再次计算 MD5 值即为签名值：
md5(md5("参数1=值1&参数2=值2")+秘钥)



