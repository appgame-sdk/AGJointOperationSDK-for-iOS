#
# Be sure to run `pod lib lint AGJointOperationSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "AGJointOperationSDK"
  s.version          = "1.3.11"
  s.summary          = "AppGame Joint Operation SDK for iOS"
  s.homepage         = "http://www.appgame.com"
  s.license          = 'Apache License, Version 2.0'
  s.author           = { "Mao" => "625257555@qq.com" }
  s.source           = { :git => "https://github.com/appgame-sdk/AGJointOperationSDK-for-iOS.git", :tag => s.version.to_s }

  s.platform     = :ios, '8.0'
  s.requires_arc = true

  s.frameworks = 'MobileCoreServices', 'SystemConfiguration', 'UIKit'
  s.library = 'sqlite3'
  s.vendored_frameworks = 'AGJointOperationSDK/AGJointOperationSDK.framework'
  s.resources = 'AGJointOperationSDK/AGJointOperationSDKResource.bundle'
  s.xcconfig = {'OTHER_LDFLAGS' => '$(inherited) -ObjC'}

  s.dependency 'ShareSDK3'
  s.dependency 'ShareSDK3/ShareSDKUI'
  s.dependency 'MOBFoundation'
	s.dependency 'ShareSDK3/ShareSDKPlatforms/QQ'
	s.dependency 'ShareSDK3/ShareSDKPlatforms/SinaWeibo'
	s.dependency 'ShareSDK3/ShareSDKPlatforms/WeChat'
	s.dependency 'ShareSDK3/PlatformConnector/QQ'
	s.dependency 'ShareSDK3/PlatformConnector/SinaWeibo'
	s.dependency 'ShareSDK3/PlatformConnector/WeChat'
end
