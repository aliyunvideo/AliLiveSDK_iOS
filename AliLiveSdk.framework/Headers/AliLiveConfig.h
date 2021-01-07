//
//  AliLiveConfig.h
//  AliLiveSdk
//
//  Created by yujian on 2020/7/7.
//  Copyright © 2020 mt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliLiveConstants.h"

#define CUSTOM_MODE_VIDEO_PREPROCESS                0X001   ///> 客户自定义视频前处理
#define CUSTOM_MODE_AUDIO_PREPROCESS                0X002   ///> 客户自定义音频前处理 (暂不支持)

@interface AliLiveConfig : NSObject

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                             常规设置
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* @brief 连麦域名httpdns解析account id
* @note 连麦场景必须传入
*/
@property(nonatomic, strong) NSString* accountID;

/**
 * @brief 前后置摄像头
 * @note 默认 : 前置摄像头
 */
@property(nonatomic, assign) AliLiveCameraPosition cameraPosition;

/**
 * @brief 美颜开关
 * @note 默认 : YES
 */
@property(nonatomic, assign) BOOL beautyOn;

/**
 * @brief 纯音频连麦 （ rtmp里面需要实现）
 * @note 默认：NO
 */
@property (nonatomic, assign) BOOL enablePureAudioPush; // 需要添加

/**
 * @brief 是否支持自动对焦
 * @note 默认NO
 */
@property (nonatomic, assign) BOOL autoFocus;

/**
 * @brief 可以设置推流一张图片，此时观众只能看到推的这张图片，常用在App 切换至后台
 * 设置后调用paushPush进入推送图片 暂时仅RTMP推流支持
 */
@property(nonatomic, strong) UIImage *pauseImage;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                   音视频编解码设置
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief video  profile
 * 视频推流分辨率
 * 默认 : AliLiveVideoProfile_540P
 */
@property(nonatomic, assign) AliLiveVideoProfile videoProfile;


///【字段含义】视频帧率，默认值：20FPS。
@property(nonatomic, assign) NSUInteger videoFPS;


/**
   是否开启高清预览
 * 默认 : NO
 */
@property (nonatomic, assign) BOOL enableHighDefPreview;

/**
  视频硬编码 （功能特性，需要保留）
 * 默认 : YES
 */
@property (nonatomic, assign) BOOL enableVideoHWAcceleration;


/**
 * 视频硬解码
 * 默认 : YES，赋值NO则采用软解
*/
@property (nonatomic, assign) BOOL enableVideoDecodeHWAcceleration;

/**
 video GOP size
 视频编码GOP size，单位s秒
 * 默认 : 2秒
 */
@property (nonatomic, assign)AliLivePushVideoEncodeGOP videoGopSize;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RTMP方式推流特有参数 （以下参数仅在RTMP推流模式下设置，RTS推流设置以下参数无效）
//  推流地址以rtmp:// 开头的推流是RTMP推流
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 rtmp 音频硬编码
 * 默认 : NO
 */
@property (nonatomic, assign) BOOL enableAudioHWAcceleration;

/**
 rtmp video init bitrate
 视频编码初始编码码率，单位kbps （初始码率）
 * 默认 : 1000kbps
 */
@property (nonatomic, assign)NSUInteger videoInitBitrate;

/**
 rtmp video target bitrate
 视频编码目标编码码率，单位kbps （最大码率）
 * 默认 : 1500kbps
 */
@property (nonatomic, assign)NSUInteger videoTargetBitrate;

/**
 rtmp video min bitrate
 视频编码最小编码码率，单位kbps （最低码率）
 * 默认 : 600kbps
 */
@property (nonatomic, assign)NSUInteger videoMinBitrate;

/**
 rtmp audio channel
 音频声道数 （声音采集）（RTC只支持单声道）
 * 默认 : 单声道
 */
@property (nonatomic, assign)AliLivePushAudioChannel audioChannel;

/**
 rtmp audio sample rate （RTC可支持的采样率很少，无法和rtmp保持一致）
 音频采样率
 * 默认 : AliLivePushAudioSampleRate44100
 */
@property (nonatomic, assign) AliLivePushAudioSampleRate audioSampleRate;

/**
 rtmp 音频编码格式
 * 默认 : AliLiveAudioEncoderProfile_AAC_LC （RTC 无音频编码配置，是opus编码）
 */
@property (nonatomic, assign) AliLiveAudioEncoderProfile audioEncoderProfile;

/**
 rtmp push auto reconnect retry count
 推流自动重连次数
 * 默认 : 5
 */
@property (nonatomic, assign) NSUInteger autoReconnectRetryCount;

/**
 rtmp push auto reconnect retry interval time
 推流自动重连间隔，单位毫秒
 * 默认 : 1000毫秒
 */
@property (nonatomic, assign) NSUInteger autoReconnectRetryInterval;


/////////////////////////////////////////////////////////////////////////////////
//
//                      自定义前处理
//
/////////////////////////////////////////////////////////////////////////////////

/**
 * 自定义前处理开关
 * 默认：关闭
 * 【特别说明】该字段需要使用与运算符进行级联操作:
 *      开启自定义视频前处理：_config.customPreProcessMode |= CUSTOM_MODE_VIDEO_PREPROCESS；
 *                              典型场景是外接美颜，该功能开启之后内置美颜关闭
 *      开启自定义音频前处理：_config.customPreProcessMode |= CUSTOM_MODE_AUDIO_PREPROCESS；
 *                              暂不支持音频前处理
 */
@property(nonatomic, assign) int customPreProcessMode;

/**
 * 该字段为辅助字段，用户可以传入直播成员唯一标示，用于sdk问题的日志排查
 */
@property(nonatomic, strong) NSString *extra;

@end
