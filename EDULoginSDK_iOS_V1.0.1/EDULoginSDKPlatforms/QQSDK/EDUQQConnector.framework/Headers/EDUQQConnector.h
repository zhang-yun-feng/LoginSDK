//
//  EDUQQConnector.h
//  DSFLogin
//
//  Created by cloud on 2019/5/20.
//  Copyright © 2019 com.cmcc. All rights reserved.
//
/**
 QQ连接器，QQ登录的SDK相关调用。
 */
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^complete)(NSDictionary *sender);
@interface EDUQQConnector : NSObject
/**
 注册SDK
 
 @param appId 第三方应用在互联开放平台申请的唯一标识
 @param delegate 第三方应用用于接收请求返回结果的委托对象
 */
- (void)registerApp:(NSString *)appId andDelegate:(id)delegate;

/*! @brief 处理通过URL启动App时传递的数据
 *
 * 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用。
 * @param url 启动第三方应用时传递过来的URL
 * @return 成功返回YES，失败返回NO。
 */
- (BOOL)handleOpenURL:(NSURL *)url;


/**
 登录
 
 @param complete 登录授权成功的回调，返回accessToken，openId。
 }
 */
- (void)qqLoginComplete:(complete)complete;

@end

NS_ASSUME_NONNULL_END
