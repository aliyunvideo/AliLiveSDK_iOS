//
//  AliLiveConstants.h
//  AliLiveSdk
//
//  Created by yujian on 2020/7/7.
//  Copyright © 2020 mt. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 Log级别
 */
typedef NS_ENUM(NSUInteger, AliLiveLogLevel) {
    AliLiveLogLevelDump,
    AliLiveLogLevelDebug,
    AliLiveLogLevelVerbose,
    AliLiveLogLevelInfo,
    AliLiveLogLevelWarn,
    AliLiveLogLevelError,
    AliLiveLogLevelFatal,
    AliLiveLogLevelNone,
};

/**
 渲染模式
 - AliLiveRenderModeAuto: 自动模式
 - AliLiveRenderModeStretch: 延伸
 - AliLiveRenderModeFill: 填充
 - AliLiveRenderModeCrop: 裁剪
 */
typedef NS_ENUM(NSUInteger, AliLiveRenderMode) {
    AliLiveRenderModeAuto    = 0,
    AliLiveRenderModeStretch = 1,
    AliLiveRenderModeFill    = 2,
    AliLiveRenderModeCrop    = 3,
};

/**
Video Push Profile

- AliLiveVideoPushProfile180P: 180P
- AliLiveVideoPushProfile360P: 360P
- AliLiveVideoPushProfile480P: 480P
- AliLiveVideoPushProfile540P: 540P
- AliLiveVideoPushProfile720P: 720P
- AliLiveVideoPushProfile1280P: 1280P
*/

typedef NS_ENUM(NSInteger, AliLiveVideoProfile){
    AliLiveVideoProfile_180P = 0,
    AliLiveVideoProfile_360P,
    AliLiveVideoProfile_480P,
    AliLiveVideoProfile_540P,
    AliLiveVideoProfile_720P,
    AliLiveVideoProfile_1080P,
    AliLiveVideoProfile_Max
};

/**
 推流模式
 - AliLivePushQualityModeResolutionFirst: 清晰度优先模式
 - AliLivePushQualityModeFluencyFirst: 流畅度优先模式
 */
typedef NS_ENUM(NSInteger, AliLivePushQualityMode){
    AliLivePushQualityModeResolutionFirst = 0,
    AliLivePushQualityModeFluencyFirst
};

/**
 关键帧间隔

 - AliLivePushVideoEncodeGOP_1: 1s
 - AliLivePushVideoEncodeGOP_2: 2s
 - AliLivePushVideoEncodeGOP_3: 3s
 - AliLivePushVideoEncodeGOP_4: 4s
 - AliLivePushVideoEncodeGOP_5: 5s
 */
typedef NS_ENUM(NSInteger, AliLivePushVideoEncodeGOP){
    AliLivePushVideoEncodeGOP_1 = 1,
    AliLivePushVideoEncodeGOP_2 = 2,
    AliLivePushVideoEncodeGOP_3 = 3,
    AliLivePushVideoEncodeGOP_4 = 4,
    AliLivePushVideoEncodeGOP_5 = 5,
};

/**
 声道数
 - AliLivePushAudioChannelOne: 单声道
 - AliLivePushAudioChannelTwo: 双声道
 */
typedef NS_ENUM(NSInteger, AliLivePushAudioChannel){
    AliLivePushAudioChannel_1 = 1,
    AliLivePushAudioChannel_2 = 2,
};

/**
 音频采样率
 - AliLivePushAudioSample32000: 32000Hz
 */
typedef NS_ENUM(NSInteger, AliLivePushAudioSampleRate){
    AliLivePushAudioSampleRate16000 = 16000,
    AliLivePushAudioSampleRate32000 = 32000,
    AliLivePushAudioSampleRate44100 = 44100,
    AliLivePushAudioSampleRate48000 = 48000,
};

/**
 音频编码格式

 - AliLiveAudioEncoderProfile_AAC_LC: AAC_LC
 - AliLiveAudioEncoderProfile_HE_AAC: HE_AAC
 - AliLiveAudioEncoderProfile_HE_AAC_V2: HE_AAC_V2
 - AliLiveAudioEncoderProfile_AAC_LD: AAC_LD
 */
typedef NS_ENUM(NSInteger, AliLiveAudioEncoderProfile){
    AliLiveAudioEncoderProfile_AAC_LC = 2,
    AliLiveAudioEncoderProfile_HE_AAC = 5,
    AliLiveAudioEncoderProfile_HE_AAC_V2 = 29
};

typedef NS_ENUM(NSInteger, AliLiveCameraPosition){
    AliLiveCameraPositionBack = 0,
    AliLiveCameraPositionFront = 1,
};

/**
 视频流类型

 - AliLiveVideoTrackNo: 无摄像头和屏幕共享
 - AliLiveVideoTrackCamera: 摄像头
 - AliLiveVideoTrackScreen: 屏幕共享
 - AliLiveVideoTrackBoth: 摄像头+屏幕共享
 */
typedef NS_ENUM(NSUInteger, AliLiveVideoTrack) {
    AliLiveVideoTrackNo     = 0,
    AliLiveVideoTrackCamera = 1,
    AliLiveVideoTrackScreen = 2,
    AliLiveVideoTrackBoth   = 3,
};

/**
 音频流类型

 - AliLiveAudioTrackNo: 无麦克风
 - AliLiveAudioTrackMic: 麦克风
 */
typedef NS_ENUM(NSUInteger, AliLiveAudioTrack) {
    AliLiveAudioTrackNo   = 0,
    AliLiveAudioTrackMic  = 1,
};


/**
 设备方向
 
 - AliLiveOrientationModePortrait: 固定竖屏模式
 - AliLiveOrientationModeLandscape: 固定横屏模式
 - AliLiveOrientationModeAuto: 自适应
 */
typedef NS_ENUM(NSInteger, AliLiveOrientationMode) {
    AliLiveOrientationModePortrait = 0,
    AliLiveOrientationModeLandscapeLeft = 1,
    AliLiveOrientationModeLandscapeRight = 2,
    AliLiveOrientationModeAuto = 3,
};

/**
 SDK对Audio Session的控制权限
 
 AliLiveAudioSessionOperationRestrictionNone: 没有限制，SDK完全控制AVAudioSession
 AliLiveAudioSessionOperationRestrictionSetCategory: SDK不能修改AVAudioSession的Category
 AliLiveAudioSessionOperationRestrictionConfigureSession: SDK不能修改AVAudioSession的配置，包括Category，Mode，CategoryOptions
 AliLiveAudioSessionOperationRestrictionDeactivateSession: SDK不能关闭AVAudioSession的活动状态，离开频道时，AVAudioSession依然处于活动状态
 */
typedef NS_ENUM(NSInteger, AliLiveAudioSessionOperationRestriction) {
    AliLiveAudioSessionOperationRestrictionNone = 0,
    AliLiveAudioSessionOperationRestrictionSetCategory = 1,
    AliLiveAudioSessionOperationRestrictionConfigureSession = 2,
    AliLiveAudioSessionOperationRestrictionDeactivateSession = 3
};

/**
 视频裸数据源类型

 - AliLiveVideosourceCameraLargeType: 大分辨率视频流
 - AliLiveVideosourceCameraSmallType: 小分辨率视频流
 - AliLiveVideosourceScreenShareType: 屏幕共享流
 - AliLiveVideosourceTypeMax: 占位符，无意义
 */
typedef NS_ENUM(NSInteger, AliLiveVideoSource) {
    AliLiveVideosourceCameraLargeType = 0,
    AliLiveVideosourceCameraSmallType = 1,
    AliLiveVideosourceScreenShareType = 2,
    AliLiveVideosourceTypeMax,
};

/**
 音频裸数据源类型
 
 - AliLiveAudiosourcePub: 推流音频数据
 - AliLiveAudiosourceSub: 拉流音频数据
 - AliLiveAudiosourceRawData: 采集音频裸数据
 - AliLiveAudiosourceVolume: 音量
 */
typedef NS_ENUM(NSInteger, AliLiveAudioSource) {
    AliLiveAudiosourcePub = 0,
    AliLiveAudiosourceSub = 1,
    AliLiveAudiosourceRawData = 2,
    AliLiveAudiosourceVolume = 3,
};

/**
 纹理类型
 */
typedef NS_ENUM(NSInteger, AliLiveVideoTextureType) {
    AliLiveVideoTextureTypeUnknown = -1,
    AliLiveVideoTextureTypePre = 0,
    AliLiveVideoTextureTypePost = 1,
};

/**
 视频数据格式
 */
typedef NS_ENUM(NSInteger, AliLiveVideoFormat) {
    AliLiveVideoFormat_UNKNOW = -1,
    AliLiveVideoFormat_BGRA = 0,
    AliLiveVideoFormat_I420,
    AliLiveVideoFormat_NV21,
    AliLiveVideoFormat_NV12,
};


/**
 视频数据类型

 - AliLiveBufferType_Raw_Data: YUV裸数据
 - AliLiveBufferType_CVPixelBuffer: CVPixelBuffer数据
 - AliLiveBufferType_Texture: 纹理数据
 */
typedef NS_ENUM(NSInteger, AliLiveBufferType) {
    AliLiveBufferType_Raw_Data = 0,
    AliLiveBufferType_CVPixelBuffer,
    AliLiveBufferType_Texture,
};

/**
 音频声道数

 - AliLiveMonoAudio: 单声道
 - AliLiveStereoAudio: 双声道
 */
typedef NS_ENUM(NSInteger, AliLiveAudioNumChannel) {
    AliLiveMonoAudio = 1,
    AliLiveStereoAudio = 2,
};

/**
 镜像模式

 - AliLiveRenderMirrorModeOnlyFrontCameraPreviewEnabled: 只有前置摄像头预览镜像，其余不镜像
 - AliLiveRenderMirrorModeAllEnabled: 全部镜像
 - AliLiveRenderMirrorModeAllDisabled: 全部不镜像
 */
typedef NS_ENUM(NSInteger, AliLiveRenderMirrorMode) {
    AliLiveRenderMirrorModeOnlyFrontCameraPreviewEnabled = 0,
    AliLiveRenderMirrorModeAllEnabled = 1,
    AliLiveRenderMirrorModeAllDisabled = 2,
};

/**
 录制音频采样率
*/
typedef NS_ENUM(NSInteger, AliLiveAudioSampleRate) {
    AliLiveAudioSampleRate_8000 = 0,
    AliLiveAudioSampleRate_11025 = 1,
    AliLiveAudioSampleRate_16000 = 2,
    AliLiveAudioSampleRate_22050 = 3,
    AliLiveAudioSampleRate_32000 = 4,
    AliLiveAudioSampleRate_44100 = 5,
    AliLiveAudioSampleRate_48000 = 6,
};

typedef NS_ENUM(NSInteger, AliLiveSdkErrorCode) {
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //   基本错误码
    //   NOTE: 通过回调函数 AliLivePushInfoStatusDelegate##onLiveSdkError 通知
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AliLiveSdkErrorCodeNone                           = 0,     ///< 无错误
    AliLiveSdkErrorCodeInvalidState                   = 10000,  ///< sdk状态错误
    AliLiveSdkErrorCodeNotInitState                   = 10001,  /// <sdk未初始化
    AliLiveSdkErrorCodeNoPauseImage                   = 10002,  /// <未设置推流图片
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //   设备（摄像头、麦克风、扬声器）相关错误码
    //   NOTE: 通过回调函数 AliLivePushInfoStatusDelegate##onLiveSdkError 通知
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AliLiveSdkErrorCodeMicOpenFail                   = 11000,     ///< 麦克风设备初始化失败
    AliLiveSdkErrorCodeMicAuthFail                   = 11001,     ///<麦克风设备未授权
    AliLiveSdkErrorCodeMicNotAvailable               = 11002,     ///<无可用的音频采集设备
    AliLiveSdkErrorCodeMicException                  = 11003,     ///<麦克风设备采集过程中出现异常
    AliLiveSdkErrorCodeMicInterrupt                  = 11004,     ///<麦克风设备采集过程中出现被中断，被其他应用(例如电话)中断，不能再采集声音
    AliLiveSdkErrorCodeCameraOpenFail                = 11005,     ///< 摄像头设备初始化失败
    AliLiveSdkErrorCodeCameraException               = 11006,     ///<摄像头设备采集过程中出现异常
    AliLiveSdkErrorCodeSpeakerOpenFail               = 11007,     ///<播放设备初始化失败
    AliLiveSdkErrorCodeSpeakerNotAvailable           = 11008,     ///<无可用的音频播放设备
    AliLiveSdkErrorCodeSpeakerException              = 11009,     ///<播放过程中出现异常
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //   推流相关错误码
    //   NOTE: 通过回调函数 AliLivePushInfoStatusDelegate##onLiveSdkError 通知
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AliLiveSdkErrorCodePushInvalidAddress            = 12000,    ///<无效的推流地址
    AliLiveSdkErrorCodePushNoNetwork                 = 12001,    ///<无网络
    AliLiveSdkErrorCodeConnectionLost                = 12002,    ///<RTMP推流数据发送超时
    AliLiveSdkErrorCodePushServerRefuse              = 12003,    ///<服务器拒绝连接请求
    AliLiveSdkErrorCodePullInvalidAddress            = 12004,    ///<无效的拉流地址
    AliLiveSdkErrorCodeRtmpPushSetUpUrlError         = 12005,    ///<RTMP推流下特有错误
    AliLiveSdkErrorCodeRtmpPushConnectError          = 12006,    ///<RTMP推流下连接错误
    AliLiveSdkErrorCodeRtmpPushStreamError           = 12007,    ///<RTMP推流下流错误
    AliLiveSdkErrorCodeRtmpPushDataTimeout           = 12008,    ///<RTMP推流数据发送超时
    AliLiveSdkErrorCodePushError                     = 12009,    /// < 推流错误
    AliLiveSdkErrorCodeStopPushError                 = 12010,    /// <取消 推流错误
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //   连麦拉流相关错误
    //   NOTE: 通过回调函数 AliLivePushInfoStatusDelegate##onLiveSdkError 通知
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AliLiveSdkErrorCodeRemotePushStreamStop               = 13000,   ///<连麦推流端已停止推流
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //   视频渲染相关错误码
    //   NOTE: 通过回调函数 AliLivePushInfoStatusDelegate##onLiveSdkError 通知
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AliLiveSdkErrorCodeRenderViewInvalid             = 14000,   ///<渲染视频的view不是AliLiveRenderView对象

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //   其他错误
    //   NOTE: 通过回调函数 AliLivePushInfoStatusDelegate##onLiveSdkError 通知
    //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AliLiveSdkErrorCodeInner                         = -1      ///<其他内部错误
};


typedef NS_ENUM(NSInteger, AliLiveResultStatusType) {
    AliLiveResultStatusTypeFailed          = 0,
    AliLiveResultStatusTypeSuccess         = 1
};

typedef NS_ENUM(NSInteger, AliLiveNetworkStatus) {
    AliLiveNetworkStatusNoNetwork          = 0,
    AliLiveNetworkStatusWiFi               = 1,
    AliLiveNetworkStatusWWAN               = 2,//蜂窝数据
};

