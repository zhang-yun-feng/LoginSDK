//
//  EDULoginManager.h
//  EDULoginSDK
//
//  Created by cloud on 2019/3/14.
//  Copyright © 2019 com.cmcc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EDUDefine.h"
NS_ASSUME_NONNULL_BEGIN

@interface EDULoginManager : NSObject

/**
 初始化SDK
 向互联网统一认证申请的相关参数，以及社交平台申请的参数
 
 @param apiKey 访问令牌,由微服务平台统一分配
 @param secretKey 访问令牌,由微服务平台统一分配
 @param appId 一键登录申请的appId
 @param appKey 一键登录申请的appKey
 @param sourceId 一键登录分配的sourceId
 @param sourceKey 一键登录分配的sourceKey
 @param service 本地登录地址
 @param qqAppId qq平台注册的应用的appId
 @param qqAppKey qq平台注册的应用的key
 @param weChatAppId 微信平台注册的应用的appId
 @param weChatAppSecret 微信平台注册的应用的密钥
 @param sinaWeiboAppKey 新浪微博平台注册的应用的appKey
 @param sinaWeiboAppSecret 新浪微博平台注册的应用的密钥
 @param sinaWeiboRedirectUrl 应⽤回调页，微博需要此参数
 */
+ (void)initSDKWithApiKey:(NSString *)apiKey
                secretKey:(NSString *)secretKey
                    appId:(NSString *)appId
                   appKey:(NSString *)appKey
                 sourceId:(NSString *)sourceId
                sourceKey:(NSString *)sourceKey
                  service:(NSString *)service
                  qqAppId:(NSString *)qqAppId
                 qqAppKey:(NSString *)qqAppKey
              weChatAppId:(NSString *)weChatAppId
          weChatAppSecret:(NSString *)weChatAppSecret
          sinaWeiboAppKey:(NSString *)sinaWeiboAppKey
       sinaWeiboAppSecret:(NSString *)sinaWeiboAppSecret
     sinaWeiboRedirectUrl:(NSString *)sinaWeiboRedirectUrl;

/**
 ! @brief 处理第三方登录（微信、微博、QQ）通过URL启动App时传递的数据
 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用。
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)handleOpenURL:(NSURL *)url;

#pragma mark - -----统一身份认证服务,登录相关

/**
 预取号，提前获取本机手机号信息
 resultCode 103000 为成功，
 根据返回字段operator的值判断运营商：1：中国移动；2：中国联通；3：中国电信
 @param complete 返回信息
 */
+ (void)preGetPhonenumber:(void (^)(id sender))complete;

/**
 本机号码一键登录

 @param role 选填，角色（分端app时必填）
 @param provinceCode 登录帐户省份编码（多帐户使用）
 @param opid 选填，登录帐户标识（多帐户使用）
 @param complete 信息回调
 */
+ (void)oneKeyLoginWithRole:(NSString *)role
               provinceCode:(NSString *)provinceCode
                       opid:(NSString *)opid
                   complete:(void(^)(id sender))complete;

/**
 获取短信验证码方法

 @param phone 手机号
 @param type 短信类型（1为短信登录,2注册，3忘记密码）
 @param complete 信息回调
 */
+ (void)getSmsCodeWithPhone:(NSString *)phone
                       type:(NSString *)type
                   complete:(void(^)(id sender))complete;

/**
 短信登录方法

 @param phone 手机号(des3+urlEncode)
 @param smsCode 短信验证码
 @param opid 选填，登录帐户标识（多帐户使用）
 @param role 选填，角色（分端app时必填）
 @param provinceCode 选填，选择省份编码（多帐户使用）
 @param complete 信息回调
 */
+ (void)smsLoginWithPhone:(NSString *)phone
                  smsCode:(NSString *)smsCode
                     opid:(NSString *)opid
                     role:(NSString *)role
             provinceCode:(NSString *)provinceCode
                 complete:(void(^)(id sender))complete;

/**
 帐密登录方法

 @param account 帐号
 @param pwd 密码
 @param role 选填，角色（ 1：教师 2：家长 3：学生)
 @param provinceCode 省份编码
 @param complete 信息回调
 */
+ (void)accountLoginWithAccount:(NSString *)account
                            pwd:(NSString *)pwd
                           role:(NSString *)role
                   provinceCode:(NSString *)provinceCode
                       complete:(void(^)(id sender))complete;

/**
 第三方登录，QQ、微信、新浪微博

 @param platformType 第三方类型
 @param role 选填，角色（分端app时必填）:1,教师;2,学生;3,家长
 @param complete 信息回调
 */
+ (void)thirdpartyLoginWith:(ESDKPlatformType)platformType
                       role:(NSString *)role
                   complete:(void(^)(id sender))complete;

/**
 检查微信是否已被用户安装
 
 @return 微信已安装返回YES，未安装返回NO。
 */
+ (BOOL)isWXAppInstalled;

/**
 第三方帐户绑定登录接口
 
 @param key 第三方用户信息绑定key
 @param smsCode 短信验证码
 @param phone 绑定手机号
 @param opid 选填，登录帐户标识（多帐户使用）
 @param provinceCode 选填，选择省份编码（多帐户使用）
 @param role 选填，角色（分端app时必填）
 @param complete 信息回调
 */
+ (void)thirdpartyBindLoginWithKey:(NSString *)key
                           smsCode:(NSString *)smsCode
                             phone:(NSString *)phone
                              opid:(NSString *)opid
                      provinceCode:(NSString *)provinceCode
                              role:(NSString *)role
                          complete:(void(^)(id sender))complete;

/**
 注册方法

 @param phone 手机号
 @param pwd 密码（8-20位字母（大小写），数字组合）
 @param smsCode 短信验证码
 @param provinceCode 选填，省份编码
 @param nickName 选填，用户昵称(为空时系统生成)
 @param trueName 选填，用户姓名(为空时系统生成)
 @param role 选填，注册互联网角色（1，教师，2学生，3家长）
 @param complete 信息回调
 */
+ (void)registerWithPhone:(NSString *)phone
                      pwd:(NSString *)pwd
                  smsCode:(NSString *)smsCode
             provinceCode:(NSString *)provinceCode
                 nickName:(NSString *)nickName
                 trueName:(NSString *)trueName
                     role:(NSString *)role
                 complete:(void(^)(id sender))complete;

/**
 忘记密码方法

 @param phone 手机号
 @param pwd 设置新密码
 @param smsCode 短信验证码
 @param provinceCode 省份编码
 @param account 选填，指定帐户(为空时默认重置该省所有帐户)
 @param complete 信息回调
 */
+ (void)forgetPwdWithPhone:(NSString *)phone
                       pwd:(NSString *)pwd
                   smsCode:(NSString *)smsCode
              provinceCode:(NSString *)provinceCode
                   account:(NSString *)account
                  complete:(void(^)(id sender))complete;

/**
 注销登录方法，退出登录时调用
 */
+ (void)logout;

#pragma mark - -----用户相关服务-----
#pragma mark - -----用户信息模块-----
/**
 根据用户标识获取用户基础信息
 
 @param xUserId 用户标识
 @param complete 信息回调
 */
+ (void)userQuerySimpleUserWithUserId:(NSString *)xUserId
                             complete:(void(^)(id sender))complete;
/**
 根据手机号查询用户信息
 
 @param phone 用户手机号：密文上传DES3+URL
 @param complete 信息回调
 */
+ (void)userQueryPhoneUserSimple:(NSString *)phone
                        complete:(void(^)(id sender))complete;

/**
 获取用户详细信息
 
 @param xUserId 用户标识
 @param complete 信息回调
 */
+ (void)userQueryUserWithUserId:(NSString *)xUserId
                       complete:(void(^)(id sender))complete;

/**
 获取当前用户角色列表
 
 @param xUserId 用户标识
 @param complete 信息回调
 */
+ (void)userQueryUserRolesWithUserId:(NSString *)xUserId
                            complete:(void(^)(id sender))complete;

/**
 获取教师详细信息
 
 @param xUserId 用户标识
 @param complete 信息回调
 */
+ (void)userQueryTeacherUserWithUserId:(NSString *)xUserId
                              complete:(void(^)(id sender))complete;

/**
 获取家长详细信息:根据用户标识获取本人家长详细信息查询
 
 @param xUserId 用户标识
 @param complete 信息回调
 */
+ (void)userQueryParentUserWithUserId:(NSString *)xUserId
                             complete:(void(^)(id sender))complete;

/**
 获取学生详细信息:根据用户标识查询本人学生详细信息
 
 @param xUserId 用户标识
 @param complete 信息回调
 */
+ (void)userQueryStudentUserWithUserId:(NSString *)xUserId
                              complete:(void(^)(id sender))complete;

/**
 用户基础信息更新
 
 @param xUserId 用户标识
 @param nickName 选填，昵称
 @param trueName 选填，真实姓名
 @param phone 选填，用户手机号
 @param email 选填，邮箱
 @param birthday 选填，生日yyyy-mm-dd
 @param provinceCode 选填，用户归属地省份(省份城市配套)
 @param cityCode 选填，用户归属地城市（所在省份城市）
 @param complete 信息回调
 */
+ (void)userUpdateSimpleUserWithUserId:(NSString *)xUserId
                              nickName:(NSString *)nickName
                              trueName:(NSString *)trueName
                                 phone:(NSString *)phone
                                 email:(NSString *)email
                              birthday:(NSString *)birthday
                          provinceCode:(NSString *)provinceCode
                              cityCode:(NSString *)cityCode
                              complete:(void(^)(id sender))complete;

/**
 用户密码修改
 
 @param xUserId 用户标识
 @param oldPwd 原密码(aes)
 @param newPwd 新密码(aes)
 @param complete 信息回调
 */
+ (void)userUpdateUserPwdWithUserId:(NSString *)xUserId
                             oldPwd:(NSString *)oldPwd
                             newPwd:(NSString *)newPwd
                           complete:(void(^)(id sender))complete;

/**
 用户标签更新
 
 @param xUserId 用户标识
 @param provinceCode 选填，省份id
 @param gradeCode 选填，年级id
 @param role 选填，角色类型（1教师3家长2学生）
 @param complete 信息回调
 */
+ (void)userUpdateUserLableWithUserId:(NSString *)xUserId
                         provinceCode:(NSString *)provinceCode
                            gradeCode:(NSString *)gradeCode
                                 role:(NSString *)role
                             complete:(void(^)(id sender))complete;

/**
 用户标签查询
 
 @param xUserId 用户标识
 @param complete 信息回调
 */
+ (void)userQueryUserLableWithUserId:(NSString *)xUserId
                            complete:(void(^)(id sender))complete;

/**
 家长列表查询:查询当前用户所有家长
 
 @param xUserId 用户标识
 @param complete 信息回调
 */
+ (void)userQueryParentListWithUserId:(NSString *)xUserId
                             complete:(void(^)(id sender))complete;

/**
 学生列表查询:查询当前用户所有学生
 
 @param xUserId 用户标识
 @param complete 信息回调
 */
+ (void)userQueryChildListWithUserId:(NSString *)xUserId
                            complete:(void(^)(id sender))complete;

/**
 重置学生密码:重置当前用户学生的密码
 
 @param xUserId 用户标识
 @param childAccount 选填，学生帐户（为空时重置所有学生密码）
 @param newPwd 新密码(aes)
 @param complete 信息回调
 */
+ (void)userResetChildPwdWithUserId:(NSString *)xUserId
                       childAccount:(NSString *)childAccount
                             newPwd:(NSString *)newPwd
                           complete:(void(^)(id sender))complete;

/**
 根据手机号获取帐户身份列表
 
 @param phone 手机号（aes加密)
 @param complete 信息回调
 */
+ (void)userGetRolePhoneWithPhone:(NSString *)phone
                         complete:(void(^)(id sender))complete;

/**
 第三方帐户解除绑定接口
 
 @param xUserId 省用户ID
 @param phone 手机号
 @param type 第三方类型:1,qq;2,微信;3,新浪微博
 @param complete 信息回调
 */
+ (void)userOtherUnbindWithXUserId:(NSString *)xUserId
                             phone:(NSString *)phone
                              type:(NSString *)type
                          complete:(void(^)(id sender))complete;

/**
 查询用户绑定的第三方帐号信息
 
 @param xUserId 省用户ID
 @param phone 手机号
 @param complete 信息回调
 */
+ (void)userOtherBindListWithXUserId:(NSString *)xUserId
                               phone:(NSString *)phone
                            complete:(void(^)(id sender))complete;

#pragma mark - -----用户组织模块-----

/**
 获取学校列表
 
 @param cityCode 城市编码
 @param districtCode 区县编码(不为空时，cityCode不可为空)
 @param pageIndex 查询页码(默认1)
 @param pageSize 查询条目数(默认10)
 @param complete 信息回调
 */
+ (void)orgQuerySchoolListWithCityCode:(NSString *)cityCode
                          districtCode:(NSString *)districtCode
                             pageIndex:(NSInteger)pageIndex
                              pageSize:(NSInteger)pageSize
                              complete:(void(^)(id sender))complete;

/**
 获取学校详细信息
 
 @param xSchoolId 学校Id
 @param complete 信息回调
 */
+ (void)orgQuerySchoolWithSchoolId:(NSString *)xSchoolId
                          complete:(void(^)(id sender))complete;

/**
 获取学校下年级列表:根据学校标识查询学校下存在的年级
 
 @param xSchoolId 学校Id
 @param complete 信息回调
 */
+ (void)orgQuerySchoolGradeListWithSchoolId:(NSString *)xSchoolId
                                   complete:(void(^)(id sender))complete;

/**
 获取学校下任课教师列表:根据学校标识获取学校所有教师基础信息
 
 @param xSchoolId 学校Id
 @param complete 信息回调
 */
+ (void)orgQuerySchoolTeacherListWithSchoolId:(NSString *)xSchoolId
                                     complete:(void(^)(id sender))complete;

/**
 获取年级详细信息
 
 @param gradeId 年级id
 @param xSchoolId 学校Id
 @param complete 信息回调
 */
+ (void)orgQueryGradeWithGradeId:(NSString *)gradeId
                       xSchoolId:(NSString *)xSchoolId
                        complete:(void(^)(id sender))complete;

/**
 获取用户年级列表：查询用户所在年级列表数据
 
 @param xUserId 用户Id
 @param complete 信息回调
 */
+ (void)orgQueryUserGradeListWithUserId:(NSString *)xUserId
                               complete:(void(^)(id sender))complete;

/**
 获年级下班级列表:获取年级下班级列表数据
 
 @param gradeId 选填，年级标识
 @param xSchoolId 选填，学校id（与年级标识二选一）
 @param gradeCode 选填，年级编码(与学校数据配套使用)
 @param complete 信息回调
 */
+ (void)orgQueryGradeClassListWithGradeId:(NSString *)gradeId
                                xSchoolId:(NSString *)xSchoolId
                                gradeCode:(NSString *)gradeCode
                                 complete:(void(^)(id sender))complete;

/**
 获取用户学校身份
 
 @param xUserId 用户id
 @param xSchoolId 学校Id
 @param complete 信息回调
 */
+ (void)orgUserSchoolRoleListWithUserId:(NSString *)xUserId
                              xSchoolId:(NSString *)xSchoolId
                               complete:(void(^)(id sender))complete;
/**
 获取用户班级列表：根据用户标识获取用户班级列表数据
 
 @param xUserId 用户id
 @param complete 信息回调
 */
+ (void)orgQueryUserClassListWithUserId:(NSString *)xUserId
                               complete:(void(^)(id sender))complete;


/**
 获取班级联系人:根据用户标识和指定班级查询班级成员列表
 
 @param xUserId 用户id
 @param xClassId 班级id
 @param complete 信息回调
 */
+ (void)orgQueryClassUserListWithUserId:(NSString *)xUserId
                               xClassId:(NSString *)xClassId
                               complete:(void(^)(id sender))complete;

/**
 获取年级下任课教师列表
 
 @param gradeId 选填，年级id
 @param xSchoolId 选填，学校id（与年级id二选一）
 @param gradeCode 选填，年级编码（与学校学校数据配套使用）
 @param complete 信息回调
 */
+ (void)orgQueryGradeTeacherListWithGradeId:(NSString *)gradeId
                                  xSchoolId:(NSString *)xSchoolId
                                  gradeCode:(NSString *)gradeCode
                                   complete:(void(^)(id sender))complete;

/**
 获取用户年级身份:根据用户标识查询用户年级身份
 
 @param xUserId 用户id
 @param gradeId 选填，年级id（年级编码二选一）
 @param xSchoolId 学校id
 @param gradeCode 选填，年级编码（与学校学校数据配套使用）
 @param complete 信息回调
 */
+ (void)orgqueryUserGradeRoleListWithUserId:(NSString *)xUserId
                                    gradeId:(NSString *)gradeId
                                  xSchoolId:(NSString *)xSchoolId
                                  gradeCode:(NSString *)gradeCode
                                   complete:(void(^)(id sender))complete;

/**
 用户班级关系补充
 
 @param xUserId 用户id
 @param xClassId 班级Id
 @param xSchoolId 学校Id
 @param role 角色类型（1教师，2学生，3家长）
 @param complete 信息回调
 */
+ (void)orgUserAddClassRelationWithUserId:(NSString *)xUserId
                                 xClassId:(NSString *)xClassId
                                xSchoolId:(NSString *)xSchoolId
                                     role:(NSString *)role
                                 complete:(void(^)(id sender))complete;

#pragma mark - -----用户好友模块-----

/**
 获取用户好友分组列表:根据用户标识查询用户好友分组列表
 
 @param xUserId 用户Id
 @param complete 信息回调
 */
+ (void)friendQueryUserFriendGroupListWithUserId:(NSString *)xUserId
                                        complete:(void(^)(id sender))complete;

/**
 新增好友分组:根据用户添加好友分组
 
 @param xUserId 用户Id
 @param groupName 选填，组别名称
 @param complete 信息回调
 */
+ (void)friendAddUserFriendGroupWithUserId:(NSString *)xUserId
                                 groupName:(NSString *)groupName
                                  complete:(void(^)(id sender))complete;

/**
 更新好友分组排序:用户更新好友分组名称排序展示
 
 @param xUserId 用户id
 @param order 定义顺序
 @param groupId 组别id
 @param complete 信息回调
 */
+ (void)friendUpdateUserFriendGroupOrderWithUserId:(NSString *)xUserId
                                             order:(NSInteger)order
                                           groupId:(NSString *)groupId
                                          complete:(void(^)(id sender))complete;

/**
 更新好友分组名称
 
 @param xUserId 用户Id
 @param groupName 组别名称
 @param groupId 组别id
 @param complete 信息回调
 */
+ (void)friendUpdateUserFriendGroupWithUserId:(NSString *)xUserId
                                    groupName:(NSString *)groupName
                                      groupId:(NSString *)groupId
                                     complete:(void(^)(id sender))complete;

/**
 删除好友分组:用户删除好友分组（该组下好友全部删除）
 
 @param xUserId 用户Id
 @param groupId 组别id
 @param complete 信息回调
 */
+ (void)friendDeleteUserFriendGroupWithUserId:(NSString *)xUserId
                                      groupId:(NSString *)groupId
                                     complete:(void(^)(id sender))complete;

/**
 获取用户好友列表功能:根据用户标识查询用户好友列表
 
 @param xUserId 用户Id
 @param groupId 组别id
 @param complete 信息回调
 */
+ (void)friendQueryUserFriendListWithUserId:(NSString *)xUserId
                                    groupId:(NSString *)groupId
                                   complete:(void(^)(id sender))complete;

/**
 用户好友添加功能:用户好友添加功能(默认双向好友关系)
 
 @param friendXuserId 好友用户id
 @param remark 好友说明(30字符以内)
 @param xUserId 用户id
 @param groupId 选填，好友组别
 @param complete 信息回调
 */
+ (void)friendUserAddFriendWithFriendXuserId:(NSString *)friendXuserId
                                      remark:(NSString *)remark
                                      userId:(NSString *)xUserId
                                     groupId:(NSString *)groupId
                                    complete:(void(^)(id sender))complete;

/**
 用户好友组别更新功能:用户好友移动至新组
 
 @param friendXuserId 好友用户id
 @param xUserId 用户id
 @param groupId 选填，好友组别
 @param complete 信息回调
 */
+ (void)friendUserFriendRemoveWithFriendXuserId:(NSString *)friendXuserId
                                         userId:(NSString *)xUserId
                                        groupId:(NSString *)groupId
                                       complete:(void(^)(id sender))complete;

/**
 用户好友说明更新
 
 @param friendXuserId 好友用户id
 @param remark 好友说明(30字符以内)
 @param xUserId 用户id
 @param complete 信息回调
 */
+ (void)friendUpdateUserFriendRemarkWithFriendXuserId:(NSString *)friendXuserId
                                               userId:(NSString *)xUserId
                                               remark:(NSString *)remark
                                             complete:(void(^)(id sender))complete;

/**
 用户好友移除功能:移除用户好友
 
 @param friendIds 选填，好友id列表(不为空时移除指定好友，指定组别时为移除该组指定好友)
 @param xUserId 用户id
 @param groupId 选填，好友组别（不为空时移除该组所有好友）
 @param complete 信息回调
 */
+ (void)friendUserDeleteFriendsWithFriendIds:(NSString *)friendIds
                                      userId:(NSString *)xUserId
                                     groupId:(NSString *)groupId
                                    complete:(void(^)(id sender))complete;

#pragma mark - -----基础数据模块-----

/**
 获取省份列表功能
 
 @param complete 信息回调
 */
+ (void)baseQueryProvinceListWithComplete:(void(^)(id sender))complete;

/**
 获取省下城市列表功能
 
 @param complete 信息回调
 */
+ (void)baseQueryCityListWithComplete:(void(^)(id sender))complete;

/**
 获取城市下区县列表功能
 
 @param cityCode 城市标识
 @param complete 信息回调
 */
+ (void)baseQueryDistrictListWithCityCode:(NSString *)cityCode
                                 complete:(void(^)(id sender))complete;

/**
 获取年级列表功能:获取年级列表数据(K12)
 
 @param complete 信息回调
 */
+ (void)baseQueryGradeListWithComplete:(void(^)(id sender))complete;


#pragma mark - 其他方法
/**
 获取SDK的版本号
 */
+ (NSString *)getSDKVersion;


/**
 获取登录成功时的location。注意：只有登录成功之后才会存在location，否则为空。
 */
+ (NSString *)getLocation;

/**
 取消请求
 */
+ (void)cancelRequest;

/**
 设置SDK请求超时时间，单位秒，默认120s。

 @param outTime 超时时间
 */
+ (void)setRequestOutTime:(NSInteger)outTime;

/**
 获取服务政策的链接
 
 @param type 类型：移动认证服务协议-> 1，用户服务协议-> 2，隐私政策-> 3.
 @return urlInfo
 */
+ (NSDictionary *)getServiceTermUrlWithType:(NSInteger)type;


@end

NS_ASSUME_NONNULL_END
