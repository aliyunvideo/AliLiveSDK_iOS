//
//  AliLiveRaceBeautyManager.h
//  AliLiveSdk
//
//  Created by siheng on 2020/7/22.
//  Copyright © 2020 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//!美颜参数，值为float，除基础美颜外需要先将功能打开，对应参数才有效
typedef NS_ENUM(NSInteger, AliLiveRaceBeautyParams){
    //! 磨皮，值的范围[0,1] 默认0.6
    kAliLiveRaceBeautyParamsSkinBuffing      = 1,
    //! 美白，值的范围[0,1] 默认0.6
    kAliLiveRaceBeautyParamsWhitening        = 2,
};


@interface AliLiveRaceBeautyManager : NSObject

/**
 * @brief是否开启美颜
*/
@property (nonatomic, assign) BOOL isBeautyOpen;

#pragma mark - "美颜类型和美颜参数API"
/**
 * @brief打开或者关闭美颜
 * @param isOpen 美颜开关，打开或者关闭美颜
*/
- (void)enableBeautyEffect:(BOOL)isOpen;

/**
 * @brief 设置美颜参数
 * @param param 美颜参数类型，AliLiveRaceBeautyParams 中的一个
 * @param value 需要设置的数值，值的范围都是[0,1],小于0的置0，大于1的置1
 */
- (void)setRaceBeautyParams:(AliLiveRaceBeautyParams) param value:(float) value;


@end

NS_ASSUME_NONNULL_END
