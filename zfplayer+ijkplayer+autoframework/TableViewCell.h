//
//  TableViewCell.h
//  zfplayer+ijkplayer+autoframework
//
//  Created by 邹腾蛟 on 2019/5/7.
//  Copyright © 2019 zfplayer+ijkplayer+autoframework. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TableData.h"
#import "CellLayout.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZFTableViewCellDelegate <NSObject>

- (void)zf_playTheVideoAtIndexPath:(NSIndexPath *)indexPath;

@end

@interface TableViewCell : UITableViewCell

@property (nonatomic, strong) CellLayout *layout;

@property (nonatomic, copy) void(^playCallback)(void);

- (void)setDelegate:(id<ZFTableViewCellDelegate>)delegate withIndexPath:(NSIndexPath *)indexPath;

- (void)showMaskView;

- (void)hideMaskView;

- (void)setNormalMode;

@end

NS_ASSUME_NONNULL_END
