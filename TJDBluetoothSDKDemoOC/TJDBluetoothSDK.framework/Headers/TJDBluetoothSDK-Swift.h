// Generated by Apple Swift version 4.2.1 (swiftlang-1000.11.42 clang-1000.11.45.1)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if __has_feature(modules)
@import Foundation;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="TJDBluetoothSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif


SWIFT_CLASS("_TtC15TJDBluetoothSDK16AppleNotifyModel")
@interface AppleNotifyModel : NSObject
@property (nonatomic) BOOL isCall;
@property (nonatomic) BOOL isMessage;
@property (nonatomic) BOOL isQQ;
@property (nonatomic) BOOL isWechat;
@property (nonatomic) BOOL isFacebook;
@property (nonatomic) BOOL isTwitter;
@property (nonatomic) BOOL isLinkedin;
@property (nonatomic) BOOL isWhatapp;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK9DataModel")
@interface DataModel : NSObject
/// 蓝牙在iOS系统上的唯一标识符，用作生成蓝牙实例
/// Bluetooth unique identifier on iOS, used to generate Bluetooth instances
@property (nonatomic, copy) NSString * _Nonnull uuidString;
/// 设备mac地址
/// device mac address
@property (nonatomic, copy) NSString * _Nonnull mac;
/// 时间戳 单位：秒
/// timestamp unit: second
@property (nonatomic) NSInteger timeStamp;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK10BloodModel")
@interface BloodModel : DataModel
/// 数据总条数
/// Total number of data
@property (nonatomic) NSInteger indexCount;
/// 第几条数据 从1开始
/// The first few data starts from 1
@property (nonatomic) NSInteger index;
/// 血压高值
/// High blood pressure
@property (nonatomic) NSInteger max;
/// 血压低值
/// low blood pressure
@property (nonatomic) NSInteger min;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



SWIFT_CLASS("_TtC15TJDBluetoothSDK14DisplayUiModel")
@interface DisplayUiModel : NSObject
/// 记步页面
/// Steps page
@property (nonatomic) BOOL isStep;
/// 距离页面
/// Distance page
@property (nonatomic) BOOL isDistance;
/// 卡路里页面
/// Calorie page
@property (nonatomic) BOOL isCal;
/// 心率页面
/// Heart rate page
@property (nonatomic) BOOL isHeart;
/// 血压页面
/// Blood pressure page
@property (nonatomic) BOOL isBlood;
/// 查找手机页面
/// Find phone page
@property (nonatomic) BOOL isFindPhone;
/// mac地址页面
/// mac address page
@property (nonatomic) BOOL isMac;
/// 关机页面
/// Shutdown page
@property (nonatomic) BOOL isTurnOff;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK10DrinkModel")
@interface DrinkModel : NSObject
/// 分钟
/// minute
@property (nonatomic) NSInteger interval;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK17FunctionListModel")
@interface FunctionListModel : NSObject
/// 设备是否有关机功能
/// Is the device related to machine function?
@property (nonatomic) BOOL hasTurnOff;
/// 设备是否有记步功能
/// Does the device have a step counter function?
@property (nonatomic) BOOL hasStep;
/// 设备是否有心率功能
/// Does the device have heart rate function?
@property (nonatomic) BOOL hasHeart;
/// 设备是否有血压功能
/// Does the device have blood pressure?
@property (nonatomic) BOOL hasBlood;
/// 设备是否有抬手亮屏功能
/// Does the device have a hand-up bright screen function?
@property (nonatomic) BOOL hasLightScreen;
/// 设备是否有久坐提醒功能
/// Does the device have a sedentary reminder function?
@property (nonatomic) BOOL hasLongSit;
/// 设备是否有喝水提醒功能
/// Does the device have a water reminder function?
@property (nonatomic) BOOL hasDrink;
/// 设备是否有摇一摇拍照功能
/// Does the device have a shake function?
@property (nonatomic) BOOL hasTakePhoto;
/// 设备是否有防丢提醒功能
/// Does the device have anti-lost reminder function?
@property (nonatomic) BOOL hasAntiLost;
/// 设备是否有查找手机功能
/// Does the device have a function to find the phone?
@property (nonatomic) BOOL hasFindPhone;
/// 设备是否有苹果通知开关功能
@property (nonatomic) BOOL hasANCSSwitch;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK19FunctionSwitchModel")
@interface FunctionSwitchModel : NSObject
/// 抬手亮屏开关
/// Raise the bright screen switch
@property (nonatomic) BOOL isLightScreen;
/// 久坐提醒开关
/// Sedentary reminder switch
@property (nonatomic) BOOL isLongSit;
/// 喝水提醒开关
/// Drinking water reminder switch
@property (nonatomic) BOOL isDrink;
/// 摇摇拍照开关
/// Shake the photo switch
@property (nonatomic) BOOL isTakePhoto;
/// 电话挂断开关
/// Phone hang up switch
@property (nonatomic) BOOL isCallDown;
/// 防丢提醒开关
/// Anti-lost reminder switch
@property (nonatomic) BOOL isAntiLost;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK10HeartModel")
@interface HeartModel : DataModel
/// 数据总条数
/// Total number of data
@property (nonatomic) NSInteger indexCount;
/// 第几条数据 从1开始
/// The first few data starts from 1
@property (nonatomic) NSInteger index;
/// 心率值
/// heart rate value
@property (nonatomic) NSInteger heart;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK12LongSitModel")
@interface LongSitModel : NSObject
/// 分钟
/// minute
@property (nonatomic) NSInteger interval;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface NSObject (SWIFT_EXTENSION(TJDBluetoothSDK))
/// 保存对象的所有属性数据 使用 USerDefault
/// Save all attribute data of an object
/// \param model 要保存的对象
///
+ (void)setModel:(id _Nonnull)model;
/// 获取对象的所有数据
/// Get all the data of the object
///
/// returns:
/// AnyObject
+ (id _Nonnull)getModel SWIFT_WARN_UNUSED_RESULT;
@end





@class SleepTimeModel;

SWIFT_CLASS("_TtC15TJDBluetoothSDK10SleepModel")
@interface SleepModel : DataModel
/// 0…6共 7天
/// 0…6 total 7 days
@property (nonatomic) NSInteger day;
/// 某天数据总条数，indexCount为0,表示数据无效。
/// The total number of data in a day, indexCount is 0, indicating that the data is invalid.
@property (nonatomic) NSInteger indexCount;
/// 某天第几条数据 从0开始
/// The first few data of a day starts from 0
@property (nonatomic) NSInteger index;
/// 1, 2, 3 清醒，浅睡，深睡，表示该时刻进入了相应睡眠状态
/// 1, 2, 3 awake, light sleep, deep sleep, indicating that the moment has entered the corresponding sleep state
@property (nonatomic) NSInteger state;
/// 获得睡眠分段数据信息 Get sleep segmentation data information
/// \param array 一天的睡眠SleepModel
///
///
/// returns:
/// [SleepTimeModel]
+ (NSArray<SleepTimeModel *> * _Nonnull)sleepTime:(NSArray<SleepModel *> * _Nonnull)array SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK14SleepTimeModel")
@interface SleepTimeModel : SleepModel
@property (nonatomic) NSInteger sleepTime;
/// 返回一天的详细 清醒时间，浅睡时间，深睡时间  单位：分钟
/// Return to the details of the day. Awakening time, light sleep time, deep sleep time Unit: minute
/// \param array 传入「sleepTime(_ array: [SleepModel]) -> [SleepTimeModel]」的返回结果
///
///
/// returns:
/// array [wake, light, deep]
+ (NSArray<NSNumber *> * _Nonnull)detailSleep:(NSArray<SleepTimeModel *> * _Nonnull)array SWIFT_WARN_UNUSED_RESULT;
/// 睡眠质量获取
/// \param array 传入「detailSleep(_ array: [SleepTimeModel]) -> [Int]」的返回结果
///
///
/// returns:
/// 0 - 3对应 无 一般，良好，优秀
+ (NSInteger)sleepQuality:(NSArray<NSNumber *> * _Nonnull)array SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK9StepModel")
@interface StepModel : DataModel
/// 0…6共 7天
/// 0…6 total 7 days
@property (nonatomic) NSInteger day;
/// 某天数据总条数，indexCount为0,表示数据无效。
/// The total number of data in a day, indexCount is 0, indicating that the data is invalid.
@property (nonatomic) NSInteger indexCount;
/// 第几条数据 从0开始
/// The first few data starts from 0
@property (nonatomic) NSInteger index;
/// 单位  步
/// unit step
@property (nonatomic) NSInteger step;
/// 单位 米
/// Unit: m
@property (nonatomic) NSInteger distance;
/// 单位 卡
@property (nonatomic) NSInteger cal;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK12WUAlarmClock")
@interface WUAlarmClock : NSObject
/// 闹钟id 0…4 总共五组闹钟
/// Alarm id 0…4 A total of five alarm clocks
@property (nonatomic) NSInteger clockId;
/// 闹钟开关状态
/// Alarm switch status
@property (nonatomic) BOOL isOn;
/// 2的 0，1，2，3，4，5，6，分别代表天数 累计的和表示有哪几天, 0表示星期天
/// 2 0,1,2,3,4,5,6, respectively, represent the number of days. The cumulative sum indicates which days, 0 means Sunday.
@property (nonatomic) NSInteger weekday;
/// 重复间隔（稍后提醒功能）
/// Repeat interval (reminder later)
@property (nonatomic) NSInteger repeatInterval;
/// 重复次数（稍后提醒的次数）
/// Number of repetitions (number of reminders later)
@property (nonatomic) NSInteger repeatCount;
/// 闹钟触发的时间的小时值  0…23
/// The hour value of the alarm trigger time 0…23
@property (nonatomic) NSInteger hour;
/// 闹钟触发的时间的分钟值  0…59
/// The minute value of the time the alarm is triggered 0…59
@property (nonatomic) NSInteger minute;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK12WUAppManager")
@interface WUAppManager : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) WUAppManager * _Nonnull shared;)
+ (WUAppManager * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
/// 控制是否打印
/// Control whether to print
SWIFT_CLASS_PROPERTY(@property (nonatomic, class) BOOL isDebug;)
+ (BOOL)isDebug SWIFT_WARN_UNUSED_RESULT;
+ (void)setIsDebug:(BOOL)value;
/// 打印对象的数据结构
/// Print object data structure
/// \param any Any
///
+ (void)testPrint:(id _Nonnull)any;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class WUBleModel;
@class WUUserInfo;
@protocol WristbandSetDelegate;

SWIFT_CLASS("_TtC15TJDBluetoothSDK12WUBleManager")
@interface WUBleManager : NSObject
/// 单例
/// Singleton
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) WUBleManager * _Nonnull shared;)
+ (WUBleManager * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
/// 如果要过滤设备，请在{startFindBleDevices}之前设置一个客户已知的字符串, 不设置默认只搜索本公司的设备
/// If you want to filter the device, please set a string known to the customer before {startFindBleDevices}, and do not set the default to search only the company’s device.
@property (nonatomic, copy) NSString * _Nonnull filterString;
/// 自己封装的蓝牙对象
/// Self-encapsulated Bluetooth object
@property (nonatomic, strong) WUBleModel * _Nonnull activeModel;
/// 蓝牙搜索后的设备列表
/// List of devices after Bluetooth search
@property (nonatomic, copy) NSArray<WUBleModel *> * _Nonnull bleModels;
/// 蓝牙是否开启
/// Is Bluetooth enabled?
@property (nonatomic) BOOL isBluetoothOn;
/// 蓝牙是否连接
/// Is Bluetooth connected?
@property (nonatomic, readonly) BOOL isConnected;
/// 计步数据
/// Step count data
@property (nonatomic) NSInteger step;
@property (nonatomic) NSInteger cal;
@property (nonatomic) NSInteger distance;
/// 睡眠数据 单位 分钟
/// Sleep data Unit minutes
@property (nonatomic) NSInteger sleep;
/// 电池和充电状态
/// Battery and charge status
@property (nonatomic) NSInteger batteryLevel;
/// 是否进入相机界面
/// enter the camera interface
@property (nonatomic) BOOL isEnterCamera;
/// 该变量接收了手环传来的用户信息。
/// This variable receives the user information from the bracelet.
@property (nonatomic, strong) WUUserInfo * _Nonnull userInfo;
/// 该变量接收了手环传来的设备上是否要显示的UI。
/// This variable receives the UI to display on the device from the bracelet.
@property (nonatomic, strong) DisplayUiModel * _Nonnull displayUiModel;
/// 该变量接收了手环传来的设备上功能的开关。
/// This variable receives the function switch on the device from the bracelet.
@property (nonatomic, strong) FunctionSwitchModel * _Nonnull functionSwitchModel;
/// 该变量接收了手环传来的设备上是否含有该功能。
/// This variable receives the function on the device from the bracelet.
@property (nonatomic, strong) FunctionListModel * _Nonnull funcListModel;
/// 喝水提醒的时间间隔。
/// The time interval for drinking water reminders.
@property (nonatomic, strong) DrinkModel * _Nonnull drinkModel;
/// 久坐提醒的时间间隔。
/// The interval between sedentary reminders.
@property (nonatomic, strong) LongSitModel * _Nonnull longSitModel;
/// 苹果通知开关
@property (nonatomic, strong) AppleNotifyModel * _Nonnull notifyModel;
@property (nonatomic, strong) id <WristbandSetDelegate> _Nullable wristbandDelegate;
/// 当前发送的ota包序号
/// The currently sent ota package serial number
@property (nonatomic) NSUInteger otaPackIndex;
/// 建立蓝牙管理   ！**************** 只调用一次 ************   ！
/// Establish Bluetooth management! **************** Only called once ************ !
- (void)setupManager;
/// 开始搜索设备 回调通过 scan通知后 查看 bleModels。
/// Start searching for device callbacks View bleModels after a scan notification.
- (void)startFindBleDevices;
/// 停止查找设备
/// Stop finding devices
- (void)stopFindBleDevices;
- (void)connectBleDeviceWithModel:(WUBleModel * _Nonnull)model SWIFT_AVAILABILITY(ios,introduced=1.1);
- (void)disconnectBleDevice SWIFT_AVAILABILITY(ios,introduced=1.1);
/// 重连设备，在连接过一次设备后并保存了WUBleModel，下次直接发起连接
/// Reconnect the device, save the WUBleModel after connecting the device once, and directly initiate the connection next time.
- (void)reConnectDevice;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface WUBleManager (SWIFT_EXTENSION(TJDBluetoothSDK))
/// 给手环设置时间
/// Set the time for the bracelet
- (void)setTimeForWristband;
/// 获取手环电量
/// Get the bracelet power
- (void)getBatteryForWristband;
/// 手环语言设置 检测手机是否为中文和繁体文，其余的语言都默认为英文
/// Bracelet language setting Check if the phone is Chinese and Traditional, the rest of the language is English by default.
- (void)setLanguageForWristband;
/// 设置手环的默认单位，公制和英制，12小时制和24小时制
/// Set the default units of the bracelet, metric and imperial, 12-hour and 24-hour
/// @param model WUUserInfo
- (void)setZhiShiForWristband:(WUUserInfo * _Nonnull)model;
/// 获取设置信息，包含固件版本，固件版本，产品型号
/// Get setup information, including firmware version, firmware version, product model
- (void)getDeviceInfoForWristband;
/// 查找设备，手环会亮屏，同时震动
/// Find the device, the bracelet will light up and shake at the same time
- (void)findDeviceForWristband;
/// 进入或退出相机时，给手环发送对应的操作
/// Send the corresponding action to the bracelet when entering or exiting the camera
/// @param isIn 进入或退出相机 Enter or exit the camera
- (void)setCameraForWristband:(BOOL)isIn;
/// 拍照成功后回复手环
/// Respond to the bracelet after the photo is successful
- (void)responseCameraForWristband;
- (void)getLongSitForWristband;
/// 设置久坐提醒时间间隔 Set sedentary reminder interval
/// \param model LongSitModel
///
- (void)setLongSitForWristband:(LongSitModel * _Nonnull)model;
- (void)getDrinkForWristband;
/// 设置喝水提醒时间间隔 Set drinking water reminder time interval
/// \param model DrinkModel
///
- (void)setDrinkForWristband:(DrinkModel * _Nonnull)model;
/// 获取手环相关功能的开启或关闭状态
/// Get the open or closed status of the bracelet related function
- (void)getSwitchForWristband;
- (void)setSwitchForWristband:(FunctionSwitchModel * _Nonnull)model;
- (void)getDisplayForWristband;
- (void)setDisplayForWristband:(DisplayUiModel * _Nonnull)model;
- (void)getAlarmForWristband;
- (void)setAlarmForWristband:(WUAlarmClock * _Nonnull)model;
- (void)getUserinfoForWristband;
- (void)setUserinfoForWristband:(WUUserInfo * _Nonnull)model;
/// 获取当前记步 Get current step
/// \param days 0 - 6 0指今天，6指6天前 0 means today, 6 fingers 6 days ago
///
- (void)getStepWith:(NSInteger)days;
/// 获取分段记步 Get segmentation step
/// \param days 0 - 6 0指今天，6指6天前 0 means today, 6 fingers 6 days ago
///
- (void)aloneGetStepWith:(NSInteger)days;
/// 当前睡眠 Current sleep
/// \param days 0 - 6 0指今天，6指6天前 0 means today, 6 fingers 6 days ago
///
- (void)getSleepWith:(NSInteger)days;
/// 分段睡眠 Segmented sleep
/// \param days 0 - 6 0指今天，6指6天前 0 means today, 6 fingers 6 days ago
///
- (void)aloneGetSleepWith:(NSInteger)days;
/// 同步测量数据 Synchronous measurement data
/// \param type WristbandMeasureType.heart
///
- (void)aloneGetMeasure:(uint8_t)type;
/// 开始测量 Start measuring
/// \param type WristbandMeasureType.heart
///
- (void)startMeasure:(uint8_t)type;
- (void)getAncsSwitchForWristband;
- (void)setAncsSwitchForWristband:(AppleNotifyModel * _Nonnull)model;
/// ota开始指令
/// Ota start command
- (void)beginOTA;
/// ota结束指令
/// ota end command
- (void)endOTA;
/// 发送ota包
/// Send ota package
- (void)sendOta:(NSData * _Nonnull)data;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK22WUBleManagerNotifyKeys")
@interface WUBleManagerNotifyKeys : NSObject
/// 蓝牙已关闭通知
/// Bluetooth has turned off notifications
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull off;)
+ (NSNotificationName _Nonnull)off SWIFT_WARN_UNUSED_RESULT;
/// 蓝牙已打开通知
/// Bluetooth is turned on notification
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull on;)
+ (NSNotificationName _Nonnull)on SWIFT_WARN_UNUSED_RESULT;
/// 蓝牙搜索回调通知
/// Bluetooth search callback notification
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull scan;)
+ (NSNotificationName _Nonnull)scan SWIFT_WARN_UNUSED_RESULT;
/// 蓝牙连接失败回调通知 系统提供的连接方法不存在超时，调用连接后会一直尝试连接,如需要，请自行设计
/// Bluetooth connection failure callback notification The connection method provided by the system does not have timeout. After the connection is called, the connection will always be tried. If necessary, please design it yourself.
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull connected;)
+ (NSNotificationName _Nonnull)connected SWIFT_WARN_UNUSED_RESULT;
/// 蓝牙断开回调通知
/// Bluetooth disconnect callback notification
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull disconnected;)
+ (NSNotificationName _Nonnull)disconnected SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK10WUBleModel")
@interface WUBleModel : NSObject
/// 增加是否绑定字段，方便开发者自行设置绑定，自行连接使用
/// Increase whether or not to bind fields, so that developers can set their own bindings and connect by themselves.
@property (nonatomic) BOOL isBond;
/// 苹果系统里设备的唯一标识符
/// Unique identifier for the device in the Apple system
@property (nonatomic, copy) NSString * _Nonnull uuidString;
/// 设备名
/// Equipment name
@property (nonatomic, copy) NSString * _Nonnull name;
/// 广播名
/// broadcast name
@property (nonatomic, copy) NSString * _Nonnull localName;
/// 搜索的设备广播强度，可用来大致判断距离
/// search for device broadcast strength, which can be used to roughly determine distance
@property (nonatomic) NSInteger rssi;
/// 设备mac地址
/// device mac address
@property (nonatomic, copy) NSString * _Nonnull mac;
/// 硬件版本
/// hardware version
@property (nonatomic, copy) NSString * _Nonnull hardwareVersion;
/// 固件版本
/// Firmware version
@property (nonatomic, copy) NSString * _Nonnull firmwareVersion;
/// 厂商数据 ascii字符串，用于产商识别
/// Vendor data ascii string for manufacturer identification
@property (nonatomic, copy) NSString * _Nonnull vendorNumberASCII;
/// 厂商数据 16进制字符串，用于本公司固件升级服务器请求使用
/// Vendor data hexadecimal string for the company’s firmware upgrade server request to use
@property (nonatomic, copy) NSString * _Nonnull vendorNumberString;
/// 内部型号
/// Internal model
@property (nonatomic, copy) NSString * _Nonnull internalNumber;
/// YWQ 公司专用设备id, 其他公司无
@property (nonatomic, copy) NSString * _Nonnull deviceID;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK6WUDate")
@interface WUDate : NSObject
@property (nonatomic) NSInteger year;
@property (nonatomic) NSInteger month;
@property (nonatomic) NSInteger day;
@property (nonatomic) NSInteger hour;
@property (nonatomic) NSInteger minute;
@property (nonatomic) NSInteger second;
/// 星期几 0是周日
/// Day of the week 0 is Sunday
@property (nonatomic) NSInteger weekday;
+ (WUDate * _Nonnull)setupWithCurrent:(NSDate * _Nonnull)date SWIFT_WARN_UNUSED_RESULT;
/// date转时间戳 Date to timestamp
/// \param timeStamp Int
///
///
/// returns:
/// Date
+ (NSDate * _Nonnull)dateFromTimeStamp:(NSInteger)timeStamp SWIFT_WARN_UNUSED_RESULT;
/// 时间戳转对应时间 timestamp to Date
/// \param date date
///
///
/// returns:
/// Int
+ (NSInteger)timeStampFromDate:(NSDate * _Nonnull)date SWIFT_WARN_UNUSED_RESULT;
/// 把WUDate转成对应的Date Turn WUDate into the corresponding Date
///
/// returns:
/// Date
- (NSDate * _Nonnull)currentDate SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK10WUUserInfo")
@interface WUUserInfo : NSObject
@property (nonatomic, copy) NSString * _Nonnull name;
/// 0表示女性，1表示男性
/// 0 means female, 1 means male
@property (nonatomic) NSInteger sex;
@property (nonatomic) NSInteger age;
@property (nonatomic) double height;
@property (nonatomic) double weight;
/// 0 公制，1 英制
/// 0 metric, 1 inch
@property (nonatomic) NSInteger unit;
/// 0 24小时制，1 12小时制
/// 0 24 hour system, 1 12 hour system
@property (nonatomic) NSInteger timeUnit;
/// 步数 目标数
/// Steps Targets
@property (nonatomic) NSInteger stepGoal;
/// 生日 初始值 2000-01-01
/// Birthday Initial value 2000-01-01
@property (nonatomic) NSInteger birthday;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_DEPRECATED_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK20WristbandMeasureType")
@interface WristbandMeasureType : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) uint8_t heart;)
+ (uint8_t)heart SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) uint8_t blood;)
+ (uint8_t)blood SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15TJDBluetoothSDK19WristbandNotifyKeys")
@interface WristbandNotifyKeys : NSObject
/// 手环连接稳定了，可以去读写信息了。
/// The bracelet connection is stable and you can read and write information.
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull readyToWrite;)
+ (NSNotificationName _Nonnull)readyToWrite SWIFT_WARN_UNUSED_RESULT;
/// 读取设备基本信息
/// Read device basic information
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull getDevInfo;)
+ (NSNotificationName _Nonnull)getDevInfo SWIFT_WARN_UNUSED_RESULT;
/// 设置/读取设备制式(公制，英制， 保存在WUUserinfo)
/// Set/read device format (metric, imperial, saved in WUUserinfo)
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull setOrRead_ZhiShi;)
+ (NSNotificationName _Nonnull)setOrRead_ZhiShi SWIFT_WARN_UNUSED_RESULT;
/// 电量同步
/// Power sync
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull syncEle;)
+ (NSNotificationName _Nonnull)syncEle SWIFT_WARN_UNUSED_RESULT;
/// 时间设置/读取
/// Time setting/reading
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull setOrRead_Time;)
+ (NSNotificationName _Nonnull)setOrRead_Time SWIFT_WARN_UNUSED_RESULT;
/// 设置/读取设备闹钟
/// Set/read device alarm
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull setOrRead_Alarm;)
+ (NSNotificationName _Nonnull)setOrRead_Alarm SWIFT_WARN_UNUSED_RESULT;
/// 设置/读取用户参数
/// Set/read user parameters
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull setOrRead_UserInfo;)
+ (NSNotificationName _Nonnull)setOrRead_UserInfo SWIFT_WARN_UNUSED_RESULT;
/// 设置/读取要显示的UI界面
/// Set/read the UI interface to be displayed
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull setOrRead_Display_UI;)
+ (NSNotificationName _Nonnull)setOrRead_Display_UI SWIFT_WARN_UNUSED_RESULT;
/// 设置/读取功能开关
/// Set/read function switch
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull setOrRead_Switch;)
+ (NSNotificationName _Nonnull)setOrRead_Switch SWIFT_WARN_UNUSED_RESULT;
/// 查找设备
/// Find device
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull search_Dev;)
+ (NSNotificationName _Nonnull)search_Dev SWIFT_WARN_UNUSED_RESULT;
/// 查找手机
/// Find a phone
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull search_Phone;)
+ (NSNotificationName _Nonnull)search_Phone SWIFT_WARN_UNUSED_RESULT;
/// 设置/读取久坐提醒参数
/// Set/read sedentary reminder parameters
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull setOrRead_SitParam;)
+ (NSNotificationName _Nonnull)setOrRead_SitParam SWIFT_WARN_UNUSED_RESULT;
/// 设置/读取喝水提醒参数
/// Set/read drinking water reminder parameters
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull setOrRead_DrinkParam;)
+ (NSNotificationName _Nonnull)setOrRead_DrinkParam SWIFT_WARN_UNUSED_RESULT;
/// 进入/退出拍照模式
/// Enter/exit photo mode
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull inOrExit_TakePhoto;)
+ (NSNotificationName _Nonnull)inOrExit_TakePhoto SWIFT_WARN_UNUSED_RESULT;
/// 响应拍照命令
/// Respond to the photo command
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull takePhoto;)
+ (NSNotificationName _Nonnull)takePhoto SWIFT_WARN_UNUSED_RESULT;
/// 启动测量模式
/// Start measurement mode
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull startCeLiang;)
+ (NSNotificationName _Nonnull)startCeLiang SWIFT_WARN_UNUSED_RESULT;
/// 设备发送心率测量结果
/// The device sends heart rate measurement results
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull devSendCeLiang_heart;)
+ (NSNotificationName _Nonnull)devSendCeLiang_heart SWIFT_WARN_UNUSED_RESULT;
/// 设备发送血压测量结果
/// The device sends blood pressure measurement results
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull devSendCeLiang_blood;)
+ (NSNotificationName _Nonnull)devSendCeLiang_blood SWIFT_WARN_UNUSED_RESULT;
/// 历史心率同步
/// Historical heart rate synchronization
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull sysCeLiang_heart;)
+ (NSNotificationName _Nonnull)sysCeLiang_heart SWIFT_WARN_UNUSED_RESULT;
/// 历史血压同步
/// Historical blood pressure synchronization
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull sysCeLiang_blood;)
+ (NSNotificationName _Nonnull)sysCeLiang_blood SWIFT_WARN_UNUSED_RESULT;
/// 读取当天运动数据
/// Read the day’s exercise data
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull read_Sport;)
+ (NSNotificationName _Nonnull)read_Sport SWIFT_WARN_UNUSED_RESULT;
/// 读取历史运动数据
/// Read historical motion data
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull read_All_Sport;)
+ (NSNotificationName _Nonnull)read_All_Sport SWIFT_WARN_UNUSED_RESULT;
/// 读取当天睡眠数据
/// Read the day’s sleep data
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull read_Sleep;)
+ (NSNotificationName _Nonnull)read_Sleep SWIFT_WARN_UNUSED_RESULT;
/// 读取历史睡眠数据
/// Read historical sleep data
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull read_All_Sleep;)
+ (NSNotificationName _Nonnull)read_All_Sleep SWIFT_WARN_UNUSED_RESULT;
/// 同步手机系统语言 1中文，0英文
/// Synchronize the phone system language 1 Chinese, 0 English
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull syncLanguage;)
+ (NSNotificationName _Nonnull)syncLanguage SWIFT_WARN_UNUSED_RESULT;
/// 苹果ancs开关
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSNotificationName _Nonnull ancsSwitch;)
+ (NSNotificationName _Nonnull)ancsSwitch SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// 这个协议是发送数据后，手环返回确认的。
/// After the protocol is sent, the bracelet returns to confirm.
SWIFT_PROTOCOL("_TtP15TJDBluetoothSDK20WristbandSetDelegate_")
@protocol WristbandSetDelegate
@optional
/// 手环收到设置时间后回复
/// After the bracelet receives the set time, reply
/// \param isSuccess yes 成功 no 失败
///
- (void)didSetWristbandWithTime:(BOOL)isSuccess;
/// 手环收到设置闹钟后回复
/// The bracelet receives a reply after setting the alarm
/// \param isSuccess isSuccess: yes 成功 no 失败
///
/// \param index 闹钟序号id
///
- (void)didSetWristbandWithAlarm:(BOOL)isSuccess index:(NSInteger)index;
/// 用户给手环设置用户信息后手环回复
/// The user answers the wristband after setting the user information to the bracelet.
- (void)didSetWristbandWithUserinfo:(BOOL)isSuccess;
/// 用户设置手环的显示UI后回复
/// User sets the display UI of the bracelet and replies
- (void)didSetWristbandWithDisplayUi:(BOOL)isSuccess;
/// 用户设置手环的功能开关后回复
/// User sets the function switch of the bracelet and replies
- (void)didSetWristbandWithSwitch:(BOOL)isSuccess;
/// 手机查找手环后回复
/// After the phone looks up the bracelet, reply
- (void)didSetWristbandWithFindDevice:(BOOL)isSuccess;
/// 设置久坐提醒时间后回复
/// Set the sedentary reminder time to reply
- (void)didSetWristbandWithLongSit:(BOOL)isSuccess;
/// 设置喝水提醒后回复
/// Set a drink reminder to reply
- (void)didSetWristbandWithDrink:(BOOL)isSuccess;
/// 手机给手环发送进入了拍照界面后回复
/// The phone sends a message to the bracelet and enters the camera interface.
/// \param isSuccess 手环启动拍照页面成功或失败
///
/// \param isEnter 是否进入了拍照界面
///
- (void)didSetWristbandWithCamera:(BOOL)isSuccess isEnter:(BOOL)isEnter;
/// 发送开始测量后手环回复
/// Send the bracelet after the start of measurement
/// \param isSuccess 启动测量成功
///
/// \param type WristbandMeasureType.heart or  blood
///
- (void)didSetWristbandWithStartMeasure:(BOOL)isSuccess type:(uint8_t)type;
/// 苹果推送开关设置
- (void)didSetWristbandWithAncsSwitch:(BOOL)isSuccess;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
