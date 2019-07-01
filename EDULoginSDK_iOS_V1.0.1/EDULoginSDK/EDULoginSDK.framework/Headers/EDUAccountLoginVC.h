//
//  EDUAccountAndShortMessageLoginVC.h
//  andedu_iphone5
//
//  Created by WYYT on 2018/12/29.
//  Copyright © 2018 com.cmcc. All rights reserved.
//
/**
 帐密和短信登录界面
 */

#import "EDUBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 登录方式
 */
typedef NS_ENUM(NSUInteger, EDULoginType) {
    EDULoginTypeSMS,///<短信登录
    EDULoginTypeAccount,///<帐号登录
};


@interface EDUAccountLoginVC : EDUBaseViewController

/**
 返回登录结果
 */
@property (nonatomic, copy) void(^successBlock)(id info);
/**
 当前的登录类型,默认为短信登录
 */
@property (nonatomic, assign) EDULoginType currentLoginType;

@end

NS_ASSUME_NONNULL_END
