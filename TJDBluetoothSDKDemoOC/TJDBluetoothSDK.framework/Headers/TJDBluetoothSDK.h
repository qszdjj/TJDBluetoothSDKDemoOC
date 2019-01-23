//
//  TJDBluetoothSDK.h
//  TJDBluetoothSDK
//
//  Created by tjd on 2018/12/22.
//  Copyright © 2018年 tjd. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for TJDBluetoothSDK.
FOUNDATION_EXPORT double TJDBluetoothSDKVersionNumber;

//! Project version string for TJDBluetoothSDK.
FOUNDATION_EXPORT const unsigned char TJDBluetoothSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TJDBluetoothSDK/PublicHeader.h>

/*
 版本介绍
 v 1.0
 创建SDK
 
 v 1.1
 1.升级连接方法，升级断开连接方法
 2.修复FunctionSwitchModel发送错误
 3.修复DisplayUiModel发送错误
 
 v 1.2
 WUBleManager：
 1.将属性 isOn改为isBluetoothOn
 2.将方法 setUpManager改为setupManager
 3.移除 func connectBleDevice(_ peripheral: CBPeripheral?)
 4.移除 func disconnectBleDevice(_ peripheral: CBPeripheral?)
 5.增加OTA升级（固件升级）

 WUBleModel：
 1.增加字段 isBond，方便开发者自行保存绑定操作
 
 1.封装了系统蓝牙对象及回调
 2.优化了打印内容
 
 3.增加了英文注释
 */
