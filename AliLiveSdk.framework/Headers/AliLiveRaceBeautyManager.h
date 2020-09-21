//
//  AliLiveRaceBeautyManager.h
//  AliLiveSdk
//
//  Created by siheng on 2020/7/22.
//  Copyright © 2020 aliyun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//!美颜类型，需要哪种美颜需要先打开
typedef NS_ENUM(NSInteger, AliLiveRaceBeautyType) {
    //! 脸部美颜（主要包括去眼袋、法令纹）
    kAliLiveRaceBeautyTypeFaceBuffing    = 1,
    //! 美妆（主要包括整妆、高光、美瞳、口红、眼妆）
    kAliLiveRaceBeautyTypeMakeup         = 2,
    //! 美型（主要包括瘦脸、瘦下巴、大眼、瘦鼻、美唇等）
    kAliLiveRaceBeautyTypeFaceShape      = 3,
    //! 滤镜，当设置滤镜后，可以指定一个滤镜图片
    kAliLiveRaceBeautyTypeLUT            = 4
};

//!美颜参数，值为float，除基础美颜外需要先将功能打开，对应参数才有效
typedef NS_ENUM(NSInteger, AliLiveRaceBeautyParams){
    //! 1.基础美颜参数项，基础美颜默认打开，不需要手动调用打开接口
    //! 磨皮，值的范围[0,1] 默认0.6
    kAliLiveRaceBeautyParamsSkinBuffing      = 1,
    //! 锐化，值的范围[0,1] 默认0.8
    kAliLiveRaceBeautyParamsSharpen          = 2,
    //! 美白，值的范围[0,1] 默认0.6
    kAliLiveRaceBeautyParamsWhitening        = 3,
    //! 2.脸部美颜参数项，需要先打开AliLiveRaceBeautyTypeFaceBuffing 项
    //! 去眼袋，值的范围[0,1]
    kAliLiveRaceBeautyParamsPouch            = 4,
    //! 去法令纹，值的范围[0,1]
    kAliLiveRaceBeautyParamsNasolabialFolds  = 5,
    //! 3.色卡滤镜强度，需要先打开AliLiveRaceBeautyTypeLUT 项
    kAliLiveRaceBeautyParamsLUT              = 6
};

//!美妆类型，需要先打开AliLiveRaceBeautyTypeMakeup 类型
typedef NS_ENUM(NSInteger, AliLiveRaceBeautyMakeupType)
{
    //! 整妆
    kAliLiveRaceBeautyMakeupTypeWhole       = 0,
    //! 高光
    kAliLiveRaceBeautyMakeupTypeHighlight   = 1,
    //! 美瞳
    kAliLiveRaceBeautyMakeupTypeEyeball     = 2,
    //! 口红
    kAliLiveRaceBeautyMakeupTypeMouth       = 3,
    //! 眼妆
    kAliLiveRaceBeautyMakeupTypeEyeBrow     = 4,
    //! 最大值
    kAliLiveRaceBeautyMakeupTypeMakeupMax   = 5
};

//!美型类型，需要先打开kAliLiveRaceBeautyTypeFaceShape 类型
typedef NS_ENUM(NSInteger, AliLiveRaceBeautyFaceShapeType)
{
    //! 颧骨，值的范围[0,1]
    kAliLiveRaceBeautyFaceShapeTypeCutCheek      = 0,
    //! 削脸，值的范围[0,1]
    kAliLiveRaceBeautyFaceShapeTypeCutFace       = 1,
    //! 瘦脸，值的范围[0,1]
    kAliLiveRaceBeautyFaceShapeTypeThinFace      = 2,
    //! 脸长，值的范围[0,1]
    kAliLiveRaceBeautyFaceShapeTypeLongFace      = 3,
    //! 下巴缩短，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeLowerJaw      = 4,
    //! 下巴拉长，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeHigherJaw     = 5,
    //! 瘦下巴，值的范围[0,1]
    kAliLiveRaceBeautyFaceShapeTypeThinJaw       = 6,
    //! 瘦下颌，值的范围[0,1]
    kAliLiveRaceBeautyFaceShapeTypeThinMandible  = 7,
    //! 大眼，值的范围[0,1]
    kAliLiveRaceBeautyFaceShapeTypeBigEye        = 8,
    //! 眼角1，值的范围[0,1]
    kAliLiveRaceBeautyFaceShapeTypeEyeAngle1     = 9,
    //! 眼距，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeCanthus       = 10,
    //! 拉宽眼距，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeCanthus1      = 11,
    //! 眼角2，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeEyeAngle2     = 12,
    //! 眼睛高度，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeEyeTDAngle    = 13,
    //! 瘦鼻，值的范围[0,1]
    kAliLiveRaceBeautyFaceShapeTypeThinNose      = 14,
    //! 鼻翼，值的范围[0,1]
    kAliLiveRaceBeautyFaceShapeTypeNosewing      = 15,
    //! 鼻长，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeNasalHeight   = 16,
    //! 鼻头长，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeNoseTipHeight = 17,
    //! 唇宽，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeMouthWidth    = 18,
    //! 嘴唇大小，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeMouthSize     = 19,
    //! 唇高，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypeMouthHigh     = 20,
    //! 人中，值的范围[-1,1]
    kAliLiveRaceBeautyFaceShapeTypePhiltrum      = 21,
    //! 最大值
    kAliLiveRaceBeautyFaceShapeTypeMAX           = 22
   
};

typedef NS_ENUM(NSInteger, AliLiveRaceBeautyBlend)
{
    //!正常
    AliLiveRaceBeautyBlendNormal = 0,
    //!变亮
    AliLiveRaceBeautyBlendLighten = 1,
    //!变暗
    AliLiveRaceBeautyBlendDarken = 2,
    //!正片叠底
    AliLiveRaceBeautyBlendMultiply = 3,
    //!划分
    AliLiveRaceBeautyBlendDivide = 4,
    //!平均
    AliLiveRaceBeautyBlendAverage = 5,
    //!线性减淡
    AliLiveRaceBeautyBlendAdd = 6,
    //!减去
    AliLiveRaceBeautyBlendSubtract = 7,
    //!差值
    AliLiveRaceBeautyBlendDifference = 8,
    
    AliLiveRaceBeautyBlendNegation = 9,
    //!排除
    AliLiveRaceBeautyBlendExclusion = 10,
    //!滤色
    AliLiveRaceBeautyBlendScreen = 11,
    //!叠加
    AliLiveRaceBeautyBlendOverlay = 12,
    //!柔光
    AliLiveRaceBeautyBlendSoftLight = 13,
    //!强光
    AliLiveRaceBeautyBlendHardLight = 14,
    //!颜色减淡
    AliLiveRaceBeautyBlendColorDodge = 15,
    //!颜色加深
    AliLiveRaceBeautyBlendColorBurn = 16,
    //!线性减淡
    AliLiveRaceBeautyBlendLinearDodge = 17,
    //!线性加深
    AliLiveRaceBeautyBlendLinearBurn = 18,
    //!线性光
    AliLiveRaceBeautyBlendLinearLight = 19,
    //!亮光
    AliLiveRaceBeautyBlendVividLight = 20,
    //!点光
    AliLiveRaceBeautyBlendPinLight = 21,
    //!实色混合
    AliLiveRaceBeautyBlendHardMix = 22,
    
    AliLiveRaceBeautyBlendReflect = 23,
    
    AliLiveRaceBeautyBlendGlow = 24,
    
    AliLiveRaceBeautyBlendPhoenix = 25,
    //!色相
    AliLiveRaceBeautyBlendHue = 26,
    //!饱和度
    AliLiveRaceBeautyBlendSaturation = 27,
    //!明度
    AliLiveRaceBeautyBlendLuminosity = 28,
    //!颜色
    AliLiveRaceBeautyBlendColor = 29,
    
    AliLiveRaceBeautyBlendMax = 999
};


@interface AliLiveRaceBeautyManager : NSObject

#pragma mark - "美颜类型和美颜参数API"
/**
 * @brief 打开或者关闭某个美颜类型
 * @param type AliLiveRaceBeautyType 类型的一个值
 * @param isOpen YES: 打开，NO:关闭
 *
 */
- (void)setRaceBeautyType:(AliLiveRaceBeautyType)type enable:(BOOL) isOpen;

/**
 * @brief 设置美颜参数
 * @param param 美颜参数类型，AliLiveRaceBeautyParams 中的一个
 * @param value 需要设置的数值，值的范围都是[0,1],小于0的置0，大于1的置1
 */
- (void)setRaceBeautyParams:(AliLiveRaceBeautyParams) param value:(float) value;

#pragma mark - "滤镜相关API"

/**
 * @brief 设置滤镜图片,设置滤镜图片前需要将kAliLiveRaceBeautyTypeLUT打开
 * @param imagePath 所要设置的滤镜图片的地址
 */
- (void)setLutImagePath:(NSString *)imagePath;

#pragma mark - "美型相关API"
/**
 *  @brief 设置美型类型,设置前需要将kAliLiveRaceBeautyTypeFaceShape打开
 *  @param faceShapeType  需要设置美型的类型，参考AliLiveRaceBeautyFaceShapeType
 *  @param value 需要设置的值
 */
- (void)setFaceShape:(AliLiveRaceBeautyFaceShapeType)faceShapeType value:(float) value;

#pragma mark - "美妆相关api"
/**
 * @brief 设置美妆类型和图片素材路径，设置美妆需要将kAliLiveRaceBeautyTypeMakeup 打开
 * @param makeupType 美妆类型
 * @param imagePaths 美妆素材地址集合
 * @param blend 混合类型
 */
- (void)setMakeupImageWithType:(AliLiveRaceBeautyMakeupType) makeupType paths:(NSArray<NSString *> *)imagePaths blendType:(AliLiveRaceBeautyBlend)blend;

/**
 * @brief 设置美妆类型和图片素材路径
 * @param makeupType 美妆类型
 * @param imagePaths 美妆素材地址集合
 * @param blend 混合类型
 * @param fps 对应的帧率
 */
- (void)setMakeupImageWithType:(AliLiveRaceBeautyMakeupType) makeupType paths:(NSArray<NSString *> *)imagePaths blendType:(AliLiveRaceBeautyBlend)blend fps:(int) fps;

/**
 * @brief 设置美妆类型对应的值，可指定性别
 * @param makeupType 美妆类型
 * @param isFeMale 是否是女性，女性:YES，男性:NO
 * @param alpha 需要设置的值
 */
- (void) setMakeupWithType:(AliLiveRaceBeautyMakeupType)makeupType female:(BOOL) isFeMale value:(float) alpha;

#pragma mark - "贴纸相关API"
/**
 * @brief 增加贴纸/贴图，素材统一接口，支持GLTF,TAOPAI,MEDIAAI 类型
 * @param materialPath 要添加的素材的路径
 */
- (void)addMaterialWithPath:(NSString *)materialPath;

/**
 * @brief 删除贴纸/贴图
 * @param materialPath 要删除的素材的路径
 */
- (void)removeMaterialWithPath:(NSString *)materialPath;

@end

NS_ASSUME_NONNULL_END
