//
//  EDUWXConnector.h
//  DSFLogin
//
//  Created by cloud on 2019/5/20.
//  Copyright © 2019 com.cmcc. All rights reserved.
//
/**
 微信连接器，微信登录的SDK相关调用。
 */
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^complete)(NSDictionary *sender);

@interface EDUWXConnector : NSObject

/**
 注册SDK

 @param appId 申请的APPId
 */
- (void)registerApp:(NSString *)appId;

/*! @brief 处理微信通过URL启动App时传递的数据
 *
 * 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用。
 * @param url 微信启动第三方应用时传递过来的URL
 * @param delegate  WXApiDelegate对象，用来接收微信触发的消息。
 * @return 成功返回YES，失败返回NO。
 */
- (BOOL)handleOpenURL:(NSURL *)url delegate:(id)delegate;



/**
 登录

 @param appId appId description
 @param secret secret description
 @param complete 登录授权成功的回调，返回accessToken，openId。
 */
- (void)wxLoginWithAppId:(NSString *)appId
                  secret:(NSString *)secret
                complete:(complete)complete;

/**
 检查微信是否已被用户安装

 @return 微信已安装返回YES，未安装返回NO。
 */
- (BOOL)isWXAppInstalled;

@end

NS_ASSUME_NONNULL_END
