//
//  EDUOneKeyLoginVC.h
//  loginDemo
//
//  Created by cloud on 2019/4/12.
//  Copyright © 2019 com.cmcc. All rights reserved.
//

#import "EDUBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface EDUOneKeyLoginVC : EDUBaseViewController
/**
 返回登录结果
 */
@property (nonatomic, copy) void(^successBlock)(id info);
/**
 手机号掩码。通过预取号接口获得
 */
@property (nonatomic, copy) NSString *securityphone;

@end

NS_ASSUME_NONNULL_END
