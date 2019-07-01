//
//  EDUWBConnector.h
//  DSFLogin
//
//  Created by cloud on 2019/5/21.
//  Copyright © 2019 com.cmcc. All rights reserved.
//
/**
 微博连接器，微博登录的SDK相关调用。
 */
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
typedef void(^complete)(NSDictionary *sender);
@interface EDUWBConnector : NSObject
/**
 注册SDK
 
 @param appId 申请的APPId
 */
- (void)registerApp:(NSString *)appId;

/*! @brief 处理微博通过URL启动App时传递的数据
 *
 * 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用。
 * @param url 启动第三方应用时传递过来的URL
 * @param delegate  WeiboSDKDelegate对象，用来接收微博触发的消息。
 * @return 成功返回YES，失败返回NO。
 */
- (BOOL)handleOpenURL:(NSURL *)url delegate:(id)delegate;

/**
 登录

 @param redirectURI 微博开放平台第三方应用授权回调页地址
 @param complete 登录授权成功的回调，返回accessToken，openId。
 */
- (void)wbLoginWithRedirectURI:(NSString *)redirectURI complete:(complete)complete;

@end

NS_ASSUME_NONNULL_END
