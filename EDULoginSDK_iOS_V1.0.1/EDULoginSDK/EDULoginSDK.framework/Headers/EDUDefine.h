//
//  EDUDefine.h
//  EDULoginSDK
//
//  Created by cloud on 2019/3/14.
//  Copyright © 2019 com.cmcc. All rights reserved.
//

#ifndef EDUDefine_h
#define EDUDefine_h

/**
 第三方平台类型
 */
typedef NS_ENUM(NSUInteger, ESDKPlatformType) {
    ESDKPlatformTypeQQ = 100,///<QQ平台
    ESDKPlatformTypeSinaWeibo,///<新浪微博平台
    ESDKPlatformTypeWeChat,///<微信平台
};

// 版本号
#define VERSION_NUMBER  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define BUNDLE_NUMBER   [[[NSBundle mainBundle] infoDictionary] stringValueForKey:@"CFBundleVersion"]
// 版本
#define IOS_VERSION_NUMBER  [[UIDevice currentDevice] systemVersion]

// 屏幕
#define SCREEN_FRAME                   [UIScreen mainScreen].bounds
// 屏幕宽度
#define SCREEN_WIDTH  ([UIScreen mainScreen].bounds.size.width)
// 屏幕高度
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)
// 宽度适配
#define PTW_375 (SCREEN_WIDTH/375)

#define is_iPhone ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
#define is_iPad ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)

//判断iPhoneX
#define IS_IPHONE_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !is_iPad : NO)
//判断iPHoneXr
#define IS_IPHONE_Xr ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) && !is_iPad : NO)
//判断iPhoneXs
#define IS_IPHONE_Xs ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !is_iPad : NO)
//判断iPhoneXs Max
#define IS_IPHONE_Xs_Max ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) && !is_iPad : NO)

#define IS_IPHONE_X_SERIES IS_IPHONE_X || IS_IPHONE_Xr || IS_IPHONE_Xs || IS_IPHONE_Xs_Max


#define SAFE_MAIN(block)                            \
do {                                                \
if ([[NSThread currentThread] isMainThread]) {      \
block();                                        \
} else {                                            \
dispatch_async(dispatch_get_main_queue(), ^{    \
block();                                    \
});                                             \
}                                                   \
} while(0)

#pragma mark - EDULog定义
// 是否开启Log

#ifdef DEBUG
#define OPEN_LOG 1
#else
#define OPEN_LOG 0
#endif

#if OPEN_LOG
#define ICLog(format, ...)    NSLog(format, ##__VA_ARGS__)
#define EDULog(...) NSLog(__VA_ARGS__);
#define EDULogFunc EDULog(@"%s", __FUNCTION__);
#define EDULogLine EDULog(@"Line:%d", __LINE__);
#define EDULogFile EDULog(@"%s", __FILE__);
#define EDULogError(__ERROR) EDULog(@"%s, Error:%@", __FUNCTION__, __ERROR);
#define EDULogObj(__OBJ) EDULog(@"%s, %@", __FUNCTION__, __OBJ);
#else
#define ICLog(format, ...)
#define EDULog(...) \
{               \
}
#define EDULogFunc \
{              \
}
#define EDULogLine \
{              \
}
#define EDULogFile \
{              \
}
#define EDULogError(__ERROR) \
{                        \
}
#define EDULogObj(__OBJ) \
{                    \
}
#endif


// 网络状态提示语
#define NETWORK_MESSAGE_NOT        @"网络连接已断开"
#define NETWORK_MESSAGE_WIFI       @"wifi已连接"
#define NETWORK_MESSAGE_WWAN       @"蜂窝移动数据已连接"
#define NETWORK_MESSAGE_UNKNOWN    @"未知网络"

/*
 服务器异常：哎哟，服务器开个小差~  === 弹框提示
 有网没数据：还没有数据呢，过几天再来试试吧：） === 页面空白展示
 没有网络：网络出错啦！快去看看网络设置吧~ ==== 页面空白展示
 */
#define NETWORK_MESSAGE_ABNORMAL   @"哎哟，服务器开个小差~"
#define NONE_DATA_VIEW_TIP  @"还没有数据呢，过几天再来试试吧：）"
#define NETWORK_NONE_VIEW_TIP  @"网络出错啦！快去看看网络设置吧~"

#pragma mark - 系统颜色定义
//clear color
#define CLEAR_COLOR [UIColor clearColor]
//black color
#define BLACK_COLOR [UIColor blackColor]
//white color
#define WHITE_COLOR [UIColor whiteColor]
//grayColor color
#define GRAY_COLOR [UIColor grayColor]
//readColor color
#define RED_COLOR [UIColor redColor]
//greenColor color
#define GREEN_COLOR [UIColor greenColor]
//blueColore color
#define BLUE_COLOR [UIColor blueColor]
//和教育五期颜色
#pragma mark - 和教育五期颜色
//统一橘色
//#define EDU_COLOR_ORANGE_FB9265 UIColorFromRGB(0xFB9265)
#define EDU_COLOR_ORANGE UIColorFromRGB(0xFE6E31)
//统一浅橘色
#define EDU_COLOR_LIGHT_ORANGE UIColorFromRGB(0xFFF0E4)
//登录
#define EDU_COLOR_GARY_C1C1C1 UIColorFromRGB(0xC1C1C1)
#define EDU_COLOR_GARY_9B9B9B  UIColorFromRGB(0x9B9B9B)
#define EDU_COLOR_BLACK_4A4A4A UIColorFromRGB(0x4A4A4A)
#define EDU_COLOR_BLUE_0599D9 UIColorFromRGB(0x0599D9)
#define EDU_COLOR_BLUE_005281 UIColorFromRGB(0x005281)
#define EDU_COLOR_GARY_DADADA UIColorFromRGB(0xDADADA)
#define EDU_COLOR_RED_FF5512 UIColorFromRGB(0xFF5512)

// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 blue:((float)(rgbValue & 0xFF)) / 255.0 alpha:1.0]
#define UIColorFromRGBA(rgbValue,alp) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 blue:((float)(rgbValue & 0xFF)) / 255.0 alpha:alp]
//带有RGBA的颜色设置
#define RGBA(r, g, b, a) [UIColor colorWithRed:(r) / 255.0f green:(g) / 255.0f blue:(b) / 255.0f alpha:(a)]

#define RGB(r, g, b) RGBA(r, g, b, 1.0f)
//随机色
#define RANDOM_COLOR [UIColor colorWithRed:arc4random_uniform(255)/255.0 green:arc4random_uniform(255)/255.0 blue:arc4random_uniform(255)/255.0 alpha:1]

//system font with size
#define NFont(__SIZE) [UIFont systemFontOfSize:__SIZE]
// imageNamed
#define IMAGE_WITH_NAME(_NAME) [UIImage imageNamed:[NSString stringWithFormat:@"EDUResource.bundle/%@.png",_NAME]]


// 版本
#define IOS_VERSION_NUMBER  [[UIDevice currentDevice] systemVersion]
#define IOS6_OR_LATER            (([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0) ? YES : NO)
#define IOS7_OR_LATER            (([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0) ? YES : NO)
#define IOS8_OR_LATER            (([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) ? YES : NO)
#define IOS9_OR_LATER            (([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) ? YES : NO)
#define IOS10_OR_LATER           (([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0) ? YES : NO)
#define IOS11_OR_LATER           (([[[UIDevice currentDevice] systemVersion] floatValue] >= 11.0) ? YES : NO)

// 状态栏高度
#define  DISTANCE_TOP    ((IOS7_OR_LATER) ? [[UIApplication sharedApplication] statusBarFrame].size.height :0)


#endif /* EDUDefine_h */




