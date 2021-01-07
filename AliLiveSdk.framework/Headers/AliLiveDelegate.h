//
//  AliLiveDelegate.h
//  AliLiveSdk
//
//  Created by yujian on 2020/7/27.
//  Copyright © 2020 aliyun. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "AliLiveConstants.h"
#import "AliLiveError.h"

/**
 实时数据
 */
@interface AliLiveStats : NSObject
@property (nonatomic, assign) int64_t sentKbitrate;       // 总发送码率(kb)
@property (nonatomic, assign) int64_t rcvdKbitrate;       // 总接收码率(kb)
@property (nonatomic, assign) int64_t sentBytes;          // 总发送数据量(bytes)
@property (nonatomic, assign) int64_t rcvdBytes;          // 总接收数据量(bytes)
@property (nonatomic, assign) int64_t videoRcvdKbitrate;  // 视频接收码率(kb)
@property (nonatomic, assign) int64_t videoSentKbitrate;  // 视频发送码率(kb)
@property (nonatomic, assign) uint64_t callDuration;      // 通话时长(s)
@property (nonatomic, assign) float cpuUsage;             // CPU使用量(%)
@end


/**
 本地视频统计信息
 */
@interface AliLiveLocalVideoStats : NSObject

@property (nonatomic, assign) AliLiveVideoTrack track; // 视频流track类型
@property (nonatomic, assign) uint32_t sentBitrate;    // 发送码率
@property (nonatomic, assign) uint32_t sentFps;        // 发送帧率
@property (nonatomic, assign) uint32_t encodeFps;      // 编码帧率

@end

/**
 远端视频统计信息
 */
@interface AliLiveRemoteVideoStats : NSObject

@property (nonatomic, copy) NSString *userId;            // 远端用户userID
@property (nonatomic, assign) AliLiveVideoTrack track;   // 视频流track类型
@property (nonatomic, assign) uint32_t width;            // width
@property (nonatomic, assign) uint32_t height;           // height
@property (nonatomic, assign) uint32_t decodeFps;        // 解码帧率
@property (nonatomic, assign) uint32_t renderFps;        // 渲染帧率
@property (nonatomic, assign) uint32_t frozenTimes;      // 卡顿次数

@end

/**
 远端视频统计信息
 */
@interface AliLiveRemoteAudioStats : NSObject

@property (nonatomic, copy) NSString *userId;            // 远端用户userID
@property (nonatomic, assign) AliLiveAudioTrack track;   // 视频流track类型
@property (nonatomic, assign) uint32_t audioLossRate;    // 回调周期内的音频丢帧率
@property (nonatomic, assign) uint32_t rcvdBitrate;      // 接收流的瞬时码率（Kbps）
@property (nonatomic, assign) uint32_t totalFrozenTimes; // 远端用户加入频道后音频卡顿的累计时长 (ms)。

@end

/**
 *  状态回调
 */
@interface AliLiveResult : NSObject

@property (nonatomic, assign) AliLiveResultStatusType statusCode;
@property (nonatomic, strong) AliLiveError *error;

@end

@class AliLiveEngine;

@protocol AliLiveRtsDelegate <NSObject>

@optional
/**
 * @brief 订阅状态回调
 * @param result 订阅状态，成功或者失败
 * @param url 订阅成员的唯一标识
 */
- (void)onSubscribe:(AliLiveEngine *)publisher result:(AliLiveResult *)result url:(NSString *)url;
/**
 * @brief 取消订阅状态回调
 * @param result 取消订阅状态，成功或者失败
 * @param url 取消订阅成员的唯一标识
 */
- (void)onUnSubscribe:(AliLiveEngine *)publisher result:(AliLiveResult *)result url:(NSString *)url;
/**
 * @brief 首包数据接收成功
 * @param url  接收成功第一个包的成员标示
 * @note 接收到首桢数据后即可以展示媒体流
 */
- (void)onFirstPacketReceived:(AliLiveEngine *)publisher url:(NSString *)url;

/**
 * @brief remote user的第一帧视频帧显示时触发这个消息
 * @param url   User ID。从App server分配的唯一标示符
*/
- (void)onFirstRemoteVideoFrameDrawn:(AliLiveEngine *)publisher url:(NSString *)url;

@end

#pragma mark - AliLiveDataStatsDelegate 回调
@protocol AliLiveDataStatsDelegate <NSObject>

//统计媒体流相关信息
/**
 * @brief 实时数据回调(2s触发一次)
 * @param stats stats
 */
- (void)onLiveTotalStats:(AliLiveEngine *)publisher stats:(AliLiveStats *)stats;

/**
 * @brief 本地视频统计信息(2s触发一次)
 * @param localVideoStats 本地视频统计信息
 * @note SDK每两秒触发一次此统计信息回调
 */
- (void)onLiveLocalVideoStats:(AliLiveEngine *)publisher stats:(AliLiveLocalVideoStats *)localVideoStats;

/**
 * @brief 远端视频统计信息(2s触发一次)
 * @param remoteVideoStats 远端视频统计信息
 */
- (void)onLiveRemoteVideoStats:(AliLiveEngine *)publisher stats:(AliLiveRemoteVideoStats *)remoteVideoStats;

/**
 * @brief 远端音频统计信息(2s触发一次)
 * @param remoteAudioStats 远端视频统计信息
 */
- (void)onLiveRemoteAudioStats:(AliLiveEngine *)publisher stats:(AliLiveRemoteAudioStats *)remoteAudioStats;

@end

#pragma mark - AliLiveNetworkDelegate 回调
@protocol AliLiveNetworkDelegate <NSObject>

@required

/**
 * @brief 网络状态变化回调
 * @param publisher 推流实例对象
 * @param netStatus  AliLiveNetworkStatus
*/
- (void)onNetworkStatusChange:(AliLiveEngine *)publisher status:(AliLiveNetworkStatus)netStatus;

/**
 * @brief 网络差回调
 * @param publisher 推流实例对象
 */
- (void)onNetworkPoor:(AliLiveEngine *)publisher;


/**
 * @brief 网络恢复
 * @param publisher 推流实例对象
*/
- (void)onNetworkRecovery:(AliLiveEngine *)publisher;

/**
 * @brief 网络连接断开
 * @param publisher 推流实例对象
*/
- (void)onConnectionLost:(AliLiveEngine *)publisher;

/**
 * @brief 网络重连开始
 * @param publisher 推流实例对象
*/
- (void)onReconnectStart:(AliLiveEngine *)publisher;

/**
 * @brief 网络重连状态
 * @param publisher 推流实例对象
 * @param success 是否重连成功 YES成功 NO失败
 */
- (void)onReconnectStatus:(AliLiveEngine *)publisher success:(BOOL)success;

@end


#pragma mark - AliLiveStatusDelegate 回调
@protocol AliLivePushInfoStatusDelegate <NSObject>

/**
 * @brief 如果engine出现error，通过这个回调通知app
 * @param publisher 推流实例对象
 * @param error  Error type
 */
- (void)onLiveSdkError:(AliLiveEngine *)publisher error:(AliLiveError *)error;

/**
 * @brief 如果engine出现warning，通过这个回调通知app
 * @param warn  Warning type
 */
- (void)onLiveSdkWarning:(AliLiveEngine *)publisher warning:(int)warn;


/**
 * @brief 开始预览回调
 * @param publisher 推流实例对象
*/
- (void)onPreviewStarted:(AliLiveEngine *)publisher;

/**
 * @brief 停止预览回调
 * @param publisher 推流实例对象
 */
- (void)onPreviewStoped:(AliLiveEngine *)publisher;

/**
 * @brief 渲染第一帧视频回调
 * @param publisher 推流实例对象
 */
- (void)onFirstVideoFramePreviewed:(AliLiveEngine *)publisher;

/**
 * @brief 推流成功回调，表示开始推流
 * @param publisher 推流实例对象
*/
- (void)onLivePushStarted:(AliLiveEngine *)publisher;

/**
 * @brief 推流停止回调，表示停止推流
 * @param publisher 推流实例对象
*/
- (void)onLivePushStoped:(AliLiveEngine *)publisher;

/**
 * @brief 伴奏播放状态回调
 * @param playState 当前播放状态
 * @param errorCode 播放错误码
 */
- (void)onBGMStateChanged:(AliLiveEngine *)publisher
                playState:(AliLiveAudioPlayingStateCode)playState
                errorCode:(AliLiveAudioPlayingErrorCode)errorCode;
@end

#pragma mark - AliLiveVideoPreProcessDelegate 回调
@protocol AliLiveVidePreProcessDelegate <NSObject>
@optional

/**
 * 在OpenGL线程中回调，在这里可以进行采集图像的二次处理,  如美颜
 * @param texture    纹理ID
 * @param width      纹理的宽度
 * @param height     纹理的高度
 * @param rotate  纹理的角度
 * @return  返回给SDK的纹理
 * 说明：SDK回调出来的纹理类型是GL_TEXTURE_2D，接口返回给SDK的纹理类型也必须是GL_TEXTURE_2D; 该回调在SDK美颜之后. 纹理格式为GL_RGBA
 */
- (int)onTexture:(int)texture width:(int)width height:(int)height rotate:(int)rotate;

/**
 * 在OpenGL线程中回调，可以在这里释放创建的OpenGL资源
 */
- (void)onTextureDestoryed;

/**
 * 视频采集对象回调，进行采集图像的二次处理
 * @param pixelBuffer   采集图像
 * @return 返回给SDK的处理的图像
 * @note 若实现了该回调请回调有效的图像，若回调图像为nil，sdk会直接显示原采集图像
 */
- (CVPixelBufferRef)onVideoPixelBuffer:(CVPixelBufferRef)pixelBuffer;

@end
