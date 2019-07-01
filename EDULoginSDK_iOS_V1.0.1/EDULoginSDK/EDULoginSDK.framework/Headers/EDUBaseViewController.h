//
//  EDUBaseViewController.h
//  EDULoginSDK
//
//  Created by cloud on 2019/3/14.
//  Copyright © 2019 com.cmcc. All rights reserved.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN
@class MBProgressHUD;
@interface EDUBaseViewController : UIViewController <UIScrollViewDelegate>

@property (nonatomic, strong) MBProgressHUD *hud;


- (void)showHudWithTitle:(NSString *)title;

- (void)hideHud;

- (void)showMessageOnly:(NSString *)msg;


#pragma mark - Error

/**
 *  处理通用的错误,子类直接调用
 *
 *  @param error 错误信息
 */
- (void)handleCommonError:(NSError*)error;
@end



NS_ASSUME_NONNULL_END
