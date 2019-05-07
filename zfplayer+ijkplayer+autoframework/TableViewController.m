//
//  TableViewController.m
//  zfplayer+ijkplayer+autoframework
//
//  Created by 邹腾蛟 on 2019/5/7.
//  Copyright © 2019 zfplayer+ijkplayer+autoframework. All rights reserved.
//

#import "TableViewController.h"
#import "NormalViewController.h"
#import "ListLightViewController.h"

static NSString *kIdentifier = @"kIdentifier";

@interface TableViewController ()

@property (nonatomic, strong) NSArray *titles;
@property (nonatomic, strong) NSArray *viewControllers;

@end

@implementation TableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:kIdentifier];
    self.title = @"ZJPlayer+IJKPlayer Demo";
    self.titles = @[@"普通样式",
                    @"列表明暗播放"];
    
    self.viewControllers = @[@"NormalViewController",
                             @"ListLightViewController"];
}

#pragma mark - Table view data source

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.titles.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kIdentifier];
    cell.textLabel.text = self.titles[indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    NSString *vcString = self.viewControllers[indexPath.row];
    UIViewController *viewController = [[NSClassFromString(vcString) alloc] init];
    viewController.navigationItem.title = self.titles[indexPath.row];
    [self.navigationController pushViewController:viewController animated:YES];
}

@end
