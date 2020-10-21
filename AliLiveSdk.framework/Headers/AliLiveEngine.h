/* Copyright (c) 2018, Alibaba Inc.
 * All rights reserved
 */

/* This header file is part of Alibaba live engine sdk for
 * ios system.
 */

#import <UIKit/UIKit.h>
#import "AliLiveConfig.h"
#import "AliLiveDelegate.h"
#import "AliLiveRaceBeautyManager.h"


/**
 渲染view基类
 */
@interface AliRTCRenderView : UIView

@end

/**
 渲染view
 */
@interface AliLiveRenderView : AliRTCRenderView

@end

#pragma mark - 接口主类

@class AliLiveRaceBeautyManager;

@interface AliLiveEngine : NSObject 

#pragma mark - "Engine的生命周期，工作参数以及频道操作"

/**
 * @brief 获取sdk版本号
 * @return SDK版本号
 * @note 在任何时刻都可以调用
 */
+ (NSString *)getSdkVersion;


/**
 * @brief 创建AliLiveEngine对象
 * @param config 直播推流配置参数
 */
- (instancetype)initWithConfig:(AliLiveConfig*)config;

/**
 * @brief 销毁sdk
 * @note AliLiveEngine 对象置空前记得先调用destorySdk 销毁资源
 */
- (void)destorySdk;

/**
 * @brief 设置RTS推流相关回调
 * @param delegate RTS回调
 */
- (void) setRtsDelegate:(id<AliLiveRtsDelegate>)delegate;

/**
 * @brief 设置推流状态相关回调
 * @param delegate 推流状态回调
*/
- (void) setStatusDelegate:(id<AliLivePushInfoStatusDelegate>)delegate;

/**
 * @brief 设置推流网络状态相关回调
 * @param delegate 推流网络状态回调
*/
- (void) setNetworkDelegate:(id<AliLiveNetworkDelegate>)delegate;

/**
 * @brief 设置SDK日志文件保存路径
 * @param logDirPath 日志文件保存绝对路径
 * @return 0为成功，非0失败
 * @note 如需调用此接口，请在调用所有SDK接口前先进行设置，避免日志出现丢失，同时App必须保证指定的目录已存在且可写入
*/
- (int)setLogDirPath:(NSString *)logDirPath;

/**
 * @brief 设置日志输出级别
 * @param level 日志级别
 */
- (void)setLogLevel:(AliLiveLogLevel) level;

#pragma mark - "NEW APIs - 设置和操作本地的媒体"

/**
 * @brief 启动摄像头预览
 * @param previewView 预览view
 * @return 0:success  非0:failure
*/
- (int)startPreview:(AliLiveRenderView *)previewView;

/**
 * @brief 启动摄像头预览
 * @param previewView 预览view
 * @param rMode 视频渲染方式
 * @param mMode 是否需要镜像
 * @return 0:success  非0:failure
*/
- (int)startPreview:(AliLiveRenderView *)previewView renderMode:(AliLiveRenderMode)rMode mirrorMode:(AliLiveRenderMirrorMode)mMode;

/**
 * @brief  停止摄像头预览
 * @return 0表示Success 非0表示Failure
 */
- (int)stopPreview;

/**
 * @brief 设置设备横竖屏方向
 * @param mode 设备方向
 * @return 0表示Success 非0表示Failure
 * @note 当前只支持固定横竖屏模式，仅允许在推流和预览之前进行设置
 */
- (int)setDeviceOrientationMode:(AliLiveOrientationMode)mode;


/**
 * @brief mute/unmute 本地音频采集
 * @param mute  YES表示本地音频采集空帧；NO表示恢复正常
 * @note mute是指采集和发送静音帧。采集和编码模块仍然在工作
 * @return 0表示成功放入队列，-1表示被拒绝
 */
- (int)setMute:(BOOL)mute;


#pragma mark - "直播推流和订阅相关API"

/**
 * @brief 开始推流
 * @param pushURL 推流URL
 */
- (void)startPushWithURL:(NSString *)pushURL;

/**
 * @brief 停止推流
 */
- (void)stopPush;

/**
 * @brief 暂停摄像头采集并进入垫片推流状态
 * SDK 会暂时停止摄像头采集，并使用 AliLiveConfig.pauseImage 中指定的图片作为替代图像进行推流。
 * 该功能常用于 App 被切到后台场景，在 iOS 系统中，当 App 切到后台以后，系统不允许该 App 继续使用摄像头。
 * 此种场景下可以通过调用 pausePush() 进入垫片状态。
 * @note 需要先调用startPushWithURL 后才可以调用pausePush，否则调用顺序会出错
 */
- (void)pausePush;

/**
 * @brief 恢复摄像头采集并结束垫片推流状态
 * @note 正确的调用顺序startPushWithURL => ( pausePush => resumePush ) => stopPush
 */
- (void)resumePush;

/**
 * @brief 订阅RTS 方式连麦的成员媒体流
 * @param url 需要被订阅的连麦成员的唯一url标示
 * @param master 是否是订阅主流(RTS 流存在大小两路流可被订阅)
 */
- (void)subscribeStream:(NSString *)url preferMaster:(BOOL)master;

/**
 * @brief 取消订阅RTC 方式的连麦成员媒体流
 * @param url 需要取消订阅的连麦成员的唯一url标示
 */
- (void)unSubscribeStream:(NSString *)url;

/**
 * @brief 为连麦成员视频流设置渲染窗口
 * @param renderView 需要将视频流渲染上的窗口
 * @param url 连麦成员的唯一标示
 */
- (void)renderRemoteStreamWithView:(AliLiveRenderView *)renderView url:(NSString *)url;

/**
 * @brief 为连麦成员视频流设置渲染窗口以及绘制参数
 * @param renderView 需要将视频流渲染上的窗口
 * @param url 连麦成员的唯一标示
 * @param rMode 视频渲染方式
 * @param mMode 是否需要镜像
 */
- (void)renderRemoteStreamWithView:(AliLiveRenderView *)renderView url:(NSString *)url enderMode:(AliLiveRenderMode)rMode mirrorMode:(AliLiveRenderMirrorMode)mMode;

/**
 * @brief 查询是否正在推流
 * @return YES： 推流中；NO：没有在推流
 */
- (BOOL)isPublishing;

/**
 * @brief 获取当前推流地址
 */
@property (nonatomic, readonly) NSString *livePushURL;


#pragma mark - "设备管理"
/**
 * @brief 检查camera是否打开
 * @return YES表示摄像头已打开；NO表示摄像头没有打开
 */
- (BOOL)isCameraOn;

/**
 * @brief 查询是否audio only
 * @return YES表示audio Only  NO表示非audio Only
 */
- (BOOL)isAudioOnly;

/**
 * @brief 切换前后摄像头
 * @return 0表示Success 非0表示Failure
 * @note 只有iOS和android提供这个接口
 */
- (int)switchCamera;

/**
 * @brief 设置音频输出为听筒还是扬声器
 * @param enable YES:扬声器模式；NO:听筒模式(默认听筒)
 * @return 0表示Success 非0表示Failure
 */
- (int)enableSpeakerphone:(BOOL)enable;

/**
 * @brief 获取当前音频输出为听筒还是扬声器
 * @return YES:扬声器模式；NO:听筒模式
 */
- (BOOL)isEnableSpeakerphone;

/**
 * @brief 设置采集音量
 * @param volume   [0 400],0:静音，>100:放大音量，<100:减小音量
 * @return 0表示Success 非0表示Failure
 */
- (int)setRecordingVolume:(NSInteger)volume;

/**
 * @brief 设置播放音量
 * @param volume   [0 400],0:静音，>100:放大音量，<100:减小音量
 * @return 0表示Success 非0表示Failure
 */
- (int)setPlayoutVolume:(NSInteger)volume;

/**
 * 设置SDK对AVAudioSession的控制权限
 */
- (int)setAudioSessionOperationRestriction:(AliLiveAudioSessionOperationRestriction)restriction;

/**
 * @brief 设置摄像头参数
 * @param zoom   zoom的级别
 * @param flash  是否允许闪光灯
 * @return 0表示Success 非0表示Failure
 * @note 在将来版本中统一通过setParameters设置
 */
 - (int)setCameraZoom:(float)zoom flash:(BOOL)flash;

/**
 * @brief 摄像头是否支持手动聚焦
 * @return YES表示支持 NO表示不支持
 */
- (BOOL)isCameraFocusPointSupported;

/**
 * @brief 摄像头是否支持设置曝光区域
 * @return YES表示支持 NO表示不支持
 */
- (BOOL)isCameraExposurePointSupported;

/**
 * @brief 设置摄像头手动聚焦
 * @param point   聚焦点
 * @return 0表示Success 非0表示Failure
 */
- (int)setCameraFocusPoint:(CGPoint)point;

/**
 * @brief 设置摄像头曝光点
 * @param point   曝光点
 * @return 0表示Success 非0表示Failure
 */
- (int)setCameraExposurePoint:(CGPoint)point;


#pragma mark - "美颜管理和控制"
/**
 * @brief 设置美颜
 * @return 获取美颜管理对象
*/
- (AliLiveRaceBeautyManager *)getRaceBeautyManager;

/**
 * @brief 打开或者关闭美颜，美颜开关打开后，可以获取getRaceBeautyManager 函数开获取AliLiveRaceBeautyManager对象，调用该对象的api设置美颜效果
 * @param enable 美颜开关
*/
- (void)setBeautyEffect:(BOOL)enable;

@end
