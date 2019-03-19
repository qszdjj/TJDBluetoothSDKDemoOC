//
//  ViewController.m
//  TJDBluetoothSDKDemoOC
//
//  Created by tjd on 2019/1/3.
//  Copyright © 2019年 tjd. All rights reserved.
//

#import "ViewController.h"
#import <CoreBluetooth/CoreBluetooth.h>
#import "FunctionViewController.h"

@interface ViewController () <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) UITableView *table;
@property (nonatomic, strong) NSMutableArray<SleepModel *> * dataArray;
@property (nonatomic, strong) NSMutableArray<WUBleModel *> * _Nonnull bleModels;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    _dataArray = [NSMutableArray array];
    _bleModels = [NSMutableArray array];
    _table = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    _table.delegate = self;
    _table.dataSource = self;
    [self.view addSubview:_table];
    
    [self setupNotify];
    
    //若手环有过滤条件，请填写相应厂商的过滤条件
    bleSelf.filterString = @"YW";
    [bleSelf setupManager];
    [WUAppManager setIsDebug:true];
}

- (IBAction)pressScan:(UIBarButtonItem *)sender {
    if (bleSelf.isBluetoothOn) {
        [self.bleModels removeAllObjects];
        [bleSelf startFindBleDevices];
    }
    else {
        NSLog(@"未打开蓝牙");
    }
}

- (IBAction)pressStop:(UIBarButtonItem *)sender {
    [bleSelf disconnectBleDevice];
//    [bleSelf stopFindBleDevices];
//    [self.bleModels removeAllObjects];
//    [self.table reloadData];
}

- (void)setupNotify {
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WUBleManagerNotifyKeys.on object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WUBleManagerNotifyKeys.scan object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WUBleManagerNotifyKeys.connected object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WUBleManagerNotifyKeys.disconnected object:nil];
    
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WristbandNotifyKeys.readyToWrite object:nil];
    
    
    //全在子线程里处理，UI请回到主线程
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WristbandNotifyKeys.read_Sport object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WristbandNotifyKeys.read_All_Sport object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WristbandNotifyKeys.read_Sleep object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WristbandNotifyKeys.read_All_Sleep object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WristbandNotifyKeys.sysCeLiang_heart object:nil];
}


- (void)handleNotify:(NSNotification *)notify {
    if (notify.name == WUBleManagerNotifyKeys.on) {
        NSLog(@"蓝牙已经打开");
        // 在这里可以进行重连，连接过就会连接上次保存的设备。
        if (bleSelf.activeModel.isBond) {
            [bleSelf reConnectDevice];
        }
    }
    
    if (notify.name == WUBleManagerNotifyKeys.scan) {
        _bleModels = [NSMutableArray arrayWithArray:bleSelf.bleModels];
        [_table reloadData];
    }
    
    if (notify.name == WUBleManagerNotifyKeys.disconnected) {
        NSLog(@"WUBleManagerNotifyKeys.disconnected");
        [self.navigationController popToRootViewControllerAnimated:true];
        //断开后，进行重连
        if (bleSelf.activeModel.isBond) {
            [bleSelf reConnectDevice];
        }
    }
    
    if (notify.name == WUBleManagerNotifyKeys.connected) {
        NSLog(@"WUBleManagerNotifyKeys.connected");
        //连接之后保存连接设备信息
        bleSelf.activeModel.isBond = true;
        [WUBleModel setModel:bleSelf.activeModel];
        FunctionViewController *vc = [[FunctionViewController alloc] init];
        [self.navigationController pushViewController:vc animated:true];
    }
    
    //准备好之后，先获取设备信息
    if (notify.name == WristbandNotifyKeys.readyToWrite) {
        //获取手环的基础信息
        [bleSelf setLanguageForWristband];
        [bleSelf getBatteryForWristband];
        [bleSelf getDeviceInfoForWristband];
        [bleSelf getUserinfoForWristband];
        // 给手环设置时间
        [bleSelf setTimeForWristband];
        
        //然后同步手环的数据 。。。。。。
        //先获取手环当前的记步
        [bleSelf getStepWith:0];
        NSLog(@"同步数据开始，这里可以开始刷新UI动画");
    }
    
    if (notify.name == WristbandNotifyKeys.read_Sport) {
        [WUAppManager testPrint:bleSelf.activeModel];
        NSLog(@"%d 步, %d cal, %d m", (int)bleSelf.step, (int)bleSelf.cal, (int)bleSelf.distance);
        //再获取手环的历史记步
        [bleSelf aloneGetStepWith:0];
    }
    
    if (notify.name == WristbandNotifyKeys.read_All_Sport) {
        StepModel *stepModel = notify.object;
        // 最后一天睡眠
        if (stepModel.day == 6) {
            if ((stepModel.indexCount == 0) || (stepModel.indexCount == stepModel.index + 1)) {
                NSLog(@"同步历史记步完成");
                //再同步当前睡眠
                [bleSelf getSleepWith:0];
            }
        }
        else {
            if ((stepModel.indexCount == 0) || (stepModel.indexCount == stepModel.index + 1)) {
                //再同步昨天的记步
                [bleSelf aloneGetStepWith:stepModel.day + 1];
            }
        }
    }
    
    if (notify.name == WristbandNotifyKeys.read_Sleep) {
        NSLog(@"%d", (int)bleSelf.sleep);
        //再同步历史睡眠
        [bleSelf aloneGetSleepWith:0];
    }
    
    if (notify.name == WristbandNotifyKeys.read_All_Sleep) {
        SleepModel *model = notify.object;
        if (model.day == 6) {
            if (model.indexCount == 0) {
                NSLog(@"没有睡眠数据");
                //再同步历史心率
                [bleSelf aloneGetMeasure:WristbandMeasureType.heart];
            }
            else {
                if (model.index == 0) {
                    [self.dataArray removeAllObjects];
                }
                [self.dataArray addObject:model];
                
                if (model.indexCount == model.index + 1) {
                    NSArray *timeSleepArray = [SleepTimeModel sleepTime:self.dataArray];
                    NSArray *detailSleepArray = [SleepTimeModel detailSleep:timeSleepArray];
                    int wake = [detailSleepArray[0] intValue];
                    int light = [detailSleepArray[1] intValue];
                    int deep = [detailSleepArray[2] intValue];
                    NSLog(@"同步历史睡眠完成：%d , %d , %d, day: %d", wake, light, deep, (int)model.day);
                    //再同步历史心率
                    [bleSelf aloneGetMeasure:WristbandMeasureType.heart];
                }
            }
        }
        else {
            if (model.indexCount == 0) {
                NSLog(@"没有睡眠数据");
                [bleSelf aloneGetSleepWith:model.day + 1];
            }
            else {
                if (model.index == 0) {
                    [self.dataArray removeAllObjects];
                }
                [self.dataArray addObject:model];
                
                if (model.indexCount == model.index + 1) {
                    // 这个是详细睡眠列表
                    NSArray *timeSleepArray = [SleepTimeModel sleepTime:self.dataArray];
                    NSArray *detailSleepArray = [SleepTimeModel detailSleep:timeSleepArray];
                    NSInteger sleepQuality = [SleepTimeModel sleepQuality:detailSleepArray];
                    int wake = [detailSleepArray[0] intValue];
                    int light = [detailSleepArray[1] intValue];
                    int deep = [detailSleepArray[2] intValue];
                    NSLog(@"同步历史睡眠完成：%d , %d , %d, day: %d", wake, light, deep, (int)model.day);
                    [bleSelf aloneGetSleepWith:model.day + 1];
                }
            }
        }
    }
    
    if (notify.name == WristbandNotifyKeys.sysCeLiang_heart) {
        HeartModel *heartModel = notify.object;
        if ((heartModel.indexCount == 0) || (heartModel.indexCount == heartModel.index)) {
            NSLog(@"同步历史心率完成，这里可以结束刷新数据");
        }
    }
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.bleModels.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:nil];
    WUBleModel *model = self.bleModels[indexPath.row];
    cell.textLabel.text = model.name;
    cell.detailTextLabel.text = model.mac;
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 55;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:true];
    [bleSelf stopFindBleDevices];
    WUBleModel *model = self.bleModels[indexPath.row];
    [bleSelf connectBleDeviceWithModel:model];
}


@end
