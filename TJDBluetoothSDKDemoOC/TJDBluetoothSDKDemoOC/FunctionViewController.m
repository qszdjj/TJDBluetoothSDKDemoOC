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

@property (nonatomic, strong) NSData *localData;
@property (nonatomic, assign) int location;
@property (nonatomic, assign) int count;
@property (nonatomic, strong) NSTimer *otaTimer;
@property (nonatomic, strong) NSString *filePath;
@property (nonatomic, assign) BOOL isStartOTA;
@property (nonatomic, assign) float progress;

@end

@implementation FunctionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self setupNotify];
    titleArray_ = @[@"设备相关功能开关", @"心率测量（点击测量）", @"血压测量（点击测量）", @"修改用户信息", @"OTA升级\n（固件请从相关服务器\n或供应商处获取）", @"查找手环"];
    
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
    
    if (indexPath.row == 4) {
        cell.detailTextLabel.text = [NSString stringWithFormat:@"%f", _progress];
        cell.textLabel.numberOfLines = 3;
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
    
    if (indexPath.row == 4) {
        NSString *path = [[NSBundle mainBundle] pathForResource:@"SmartBand2.0" ofType:@"bin"];
        [self startOTA:path];
    }
    
    if (indexPath.row == 5) {
        [bleSelf findDeviceForWristband];
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 4) {
        return 100;
    }
    return 55;
}

//MARK: ota

- (void)startOTA:(NSString *)path {
    NSData *data = [[NSData alloc] initWithContentsOfFile:path];
    if (data.length <= 0) {
        return;
    }
    
    [bleSelf beginOTA];
    bleSelf.otaPackIndex = 0;
    _localData = data;
//    NSLog(@"%@", _localData);
    
    if (self.localData.length%16) {
        self.count = (int)self.localData.length/16 + 1;
    }
    else {
        self.count = (int)self.localData.length/16;
    }
    self.isStartOTA = true;
    [self performSelector:@selector(sendDataPack) withObject:nil afterDelay:1];
}

- (void)sendDataPack {
    [self.otaTimer invalidate];
    self.otaTimer = nil;
    
    if (!bleSelf.isConnected) {
        return;
    }
    
    //包的位置
    int packLoction = 0;
    int packLength = 0;
    if (bleSelf.otaPackIndex < self.count) {
        if (bleSelf.otaPackIndex == self.count - 1) {
            packLength = (int)(self.localData.length - bleSelf.otaPackIndex * 16);
        }
        else {
            packLength = 16;
        }
        packLoction = (int)bleSelf.otaPackIndex*16;
        NSRange range = NSMakeRange(packLoction, packLength);
        NSData *sendData = [self.localData subdataWithRange:range];
        [bleSelf sendOta:sendData];
        _progress = (float)bleSelf.otaPackIndex/self.count;
        [self.table reloadData];
    }
    else if (bleSelf.otaPackIndex == self.count) {
        [bleSelf endOTA];
        packLength = 0;
        self.count = 0;
        self.location = 0;
        _progress = 1;
        self.isStartOTA = false;
        [self.table reloadData];
        return;
    }
    
    if (self.isStartOTA) {
        self.otaTimer = [NSTimer scheduledTimerWithTimeInterval:0.02 target:self selector:@selector(sendDataPack) userInfo:nil repeats:true];
    }
}

@end
