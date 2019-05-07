//
//  CellLayout.h
//  zfplayer+ijkplayer+autoframework
//
//  Created by 邹腾蛟 on 2019/5/7.
//  Copyright © 2019 zfplayer+ijkplayer+autoframework. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TableData.h"

NS_ASSUME_NONNULL_BEGIN

@interface CellLayout : NSObject

@property (nonatomic, strong) TableData *data;
@property (nonatomic, readonly) CGRect headerRect;
@property (nonatomic, readonly) CGRect nickNameRect;
@property (nonatomic, readonly) CGRect videoRect;
@property (nonatomic, readonly) CGRect playBtnRect;
@property (nonatomic, readonly) CGRect titleLabelRect;
@property (nonatomic, readonly) CGRect maskViewRect;
@property (nonatomic, readonly) CGFloat height;
@property (nonatomic, readonly) BOOL isVerticalVideo;

- (instancetype)initWithData:(TableData *)data;

@end

NS_ASSUME_NONNULL_END
