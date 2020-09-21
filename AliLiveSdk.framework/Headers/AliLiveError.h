//
//  AliLiveError.h
//  AliLiveSdk
//
//  Created by yujian on 2020/7/7.
//  Copyright © 2020 mt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliLiveConstants.h"

@interface AliLiveError : NSObject

/**
 error module
 */
// @property (nonatomic, assign) NSInteger errorModule;

/**
 error description
 */
@property (nonatomic, strong) NSString* errorDescription;

/**
 error code
 */
@property (nonatomic, assign) AliLiveSdkErrorCode errorCode;

- (instancetype)initWithErrorCode:(AliLiveSdkErrorCode)errCode message:(NSString *)desc;

@end

