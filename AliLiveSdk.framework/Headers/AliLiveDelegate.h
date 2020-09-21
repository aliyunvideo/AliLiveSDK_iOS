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
@property (nonatomic, assign) int64_t sent_kbitrate;      // 总发送码率(kb)
@property (nonatomic, assign) int64_t rcvd_kbitrate;      // 总接收码率(kb)
@property (nonatomic, assign) int64_t sent_bytes;        // 总发送数据量(bytes)
@property (nonatomic, assign) int64_t rcvd_bytes;        // 总接收数据量(bytes)
@property (nonatomic, assign) int64_t video_rcvd_kbitrate;  // 视频接收码率(kb)
@property (nonatomic, assign) int64_t video_sent_kbitrate;  // 视频发送码率(kb)
@property (nonatomic, assign) uint64_t call_duration;      // 通话时长(s)
@property (nonatomic, assign) float cpu_usage;            // CPU使用量(%)
@end


/**
 本地视频统计信息
 */
@interface AliLiveLocalVideoStats : NSObject

@property (nonatomic, assign) AliLiveVideoTrack track; // 视频流track类型
@property (nonatomic, assign) uint32_t sent_bitrate;  // 发送码率
@property (nonatomic, assign) uint32_t sent_fps;      // 发送帧率
@property (nonatomic, assign) uint32_t encode_fps;    // 编码帧率

@end

/**
 远端视频统计信息
 */
@interface AliLiveRemoteVideoStats : NSObject

@property (nonatomic, copy) NSString *userId;           // 远端用户userID
@property (nonatomic, assign) AliLiveVideoTrack track;   // 视频流track类型
@property (nonatomic, assign) uint32_t width;           // width
@property (nonatomic, assign) uint32_t height;          // height
@property (nonatomic, assign) uint32_t decode_fps;      // 解码帧率
@property (nonatomic, assign) uint32_t render_fps;      // 渲染帧率
@property (nonatomic, assign) uint32_t frozen_times;    // 卡顿次数

@end

/**
 远端视频统计信息
 */
@interface AliLiveRemoteAudioStats : NSObject

@property (nonatomic, copy) NSString *userId;           // 远端用户userID
@property (nonatomic, assign) AliLiveAudioTrack track;   // 视频流track类型
//@property (nonatomic, assign) uint32_t quality;         // 远端用户发送的音频流质量, 具体类型参看AliLiveTranportAudioQuality
@property (nonatomic, assign) uint32_t audio_loss_rate; // 回调周期内的音频丢帧率
@property (nonatomic, assign) uint32_t rcvd_bitrate;    // 接收流的瞬时码率（Kbps）
@property (nonatomic, assign) uint32_t total_frozen_times; // 远端用户加入频道后音频卡顿的累计时长 (ms)。

@end

/**
 *  状态回调
 */
@interface AliLiveResult : NSObject

@property (nonatomic, assign) AliLiveResultStatusType statusCode;
@property (nonatomic, strong) AliLiveError *error;

@end

@class AliLiveEngine;

#pragma mark - AliLiveRtsDelegate 回调
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


//统计媒体流相关信息
/**
 * @brief 实时数据回调(2s触发一次)
 * @param stats stats
 */
- (void)onRtsStats:(AliLiveEngine *)publisher stats:(AliLiveStats *)stats;

/**
 * @brief 本地视频统计信息(2s触发一次)
 * @param localVideoStats 本地视频统计信息
 * @note SDK每两秒触发一次此统计信息回调
 */
- (void)onRtsLocalVideoStats:(AliLiveEngine *)publisher stats:(AliLiveLocalVideoStats *)localVideoStats;

/**
 * @brief 远端视频统计信息(2s触发一次)
 * @param remoteVideoStats 远端视频统计信息
 */
- (void)onRtsRemoteVideoStats:(AliLiveEngine *)publisher stats:(AliLiveRemoteVideoStats *)remoteVideoStats;

/**
 * @brief 远端音频统计信息(2s触发一次)
 * @param remoteAudioStats 远端视频统计信息
 */
- (void)onRtsRemoteAudioStats:(AliLiveEngine *)publisher stats:(AliLiveRemoteAudioStats *)remoteAudioStats;

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
 * @brief 重连开始回调
 * @param publisher 推流实例对象
*/
- (void)onReconnectStart:(AliLiveEngine *)publisher;

/**
 * @brief 网络连接重连成功
 * @param publisher 推流实例对象
 */
- (void)onReconnectSuccess:(AliLiveEngine *)publisher;

/**
 * @brief 连接被断开
 * @param publisher 推流实例对象
*/
- (void)onConnectionLost:(AliLiveEngine *)publisher;

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


@end
