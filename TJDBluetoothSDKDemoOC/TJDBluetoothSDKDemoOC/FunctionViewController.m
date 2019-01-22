//
//  FunctionViewController.m
//  TJDBluetoothSDKDemoOC
//
//  Created by tjd on 2019/1/8.
//  Copyright © 2019年 tjd. All rights reserved.
//

#import "FunctionViewController.h"
#import "SwitchViewController.h"

@interface FunctionViewController () <UITableViewDelegate, UITableViewDataSource, WristbandSetDelegate> {
    NSArray *titleArray_;
}
@property (nonatomic, strong) UITableView *table;
@property (nonatomic, strong) NSMutableArray<SleepModel *> * dataArray;
@property (nonatomic, strong) HeartModel *heartModel;
@property (nonatomic, strong) BloodModel *bloodModel;

@end

@implementation FunctionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self setupNotify];
    titleArray_ = @[@"设备相关功能开关", @"心率测量（点击测量）", @"血压测量（点击测量）", @"修改用户信息"];
    
    _table = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    _table.delegate = self;
    _table.dataSource = self;
    [self.view addSubview:_table];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    bleSelf.wristbandDelegate = self;
}

- (void)didSetWristbandWithUserinfo:(BOOL)isSuccess {
    if (isSuccess) {
        NSLog(@"修改用户信息成功");
    }
    else {
        NSLog(@"修改用户信息失败");
    }
}

- (void)setupNotify {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WristbandNotifyKeys.devSendCeLiang_heart object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WristbandNotifyKeys.devSendCeLiang_blood object:nil];
}


- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)handleNotify:(NSNotification *)notify {
    
    // 测量心率实时发送数据返回
    if (notify.name == WristbandNotifyKeys.devSendCeLiang_heart) {
        HeartModel *model = notify.object;
        _heartModel = model;
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.table reloadData];
        });
    }
    
    // 测量血压实时发送数据返回
    if (notify.name == WristbandNotifyKeys.devSendCeLiang_blood) {
        BloodModel *model = notify.object;
        _bloodModel = model;
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.table reloadData];
        });
    }
}


- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return titleArray_.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:nil];
    cell.textLabel.text = titleArray_[indexPath.row];
    cell.accessoryType = UITableViewCellAccessoryNone;
    if (indexPath.row == 0 || indexPath.row == 1) {
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    }
    
    if (indexPath.row == 1) {
        cell.detailTextLabel.text = @(_heartModel.heart).stringValue;
    }
    
    if (indexPath.row == 2) {
        cell.detailTextLabel.text = [NSString stringWithFormat:@"%d/%d", (int)_bloodModel.max, (int)_bloodModel.min];
    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:true];
    if (indexPath.row == 0) {
        SwitchViewController *vc = [[SwitchViewController alloc] init];
        [self.navigationController pushViewController:vc animated:true];
    }
    
    if (indexPath.row == 1) {
        self.title = @"正在测量心率";
        [bleSelf startMeasure:WristbandMeasureType.heart];
    }
    
    if (indexPath.row == 2) {
        self.title = @"正在测量血压";
        [bleSelf startMeasure:WristbandMeasureType.blood];
    }
    
    if (indexPath.row == 3) {
        // 调试用来查看信息,该方法与功能无关
        [WUAppManager testPrint:bleSelf.userInfo];
        WUUserInfo *model = bleSelf.userInfo;
        model.sex = 1;
        // 修改用户信息 然后发送给蓝牙设备
        [bleSelf setUserinfoForWristband:model];
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 55;
}

@end
