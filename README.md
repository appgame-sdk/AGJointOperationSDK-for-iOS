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
## 文档支持

AGJointOperationSDK-iOS 使用 HeaderDoc 注释来做文档支持。
开发者无需单独查阅文档，直接通过 Xcode 就可以查看接口和类的相关信息，减少不必要的麻烦。
## 快速开始

先来看看 AGJointOperationSDK-iOS 接入的步骤

### CocoaPods方式接入

- 配置你的 Podfile 文件，添加如下配置信息

```shell
pod 'AGJointOperationSDK-iOS'
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

### 示例代码

在需要的地方添加

```Objective-C
#import <AGJointOperationSDK/AGJointOperationSDK.h>
```

