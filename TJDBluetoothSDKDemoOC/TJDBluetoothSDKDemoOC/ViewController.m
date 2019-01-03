//
//  ViewController.m
//  TJDBluetoothSDKDemoOC
//
//  Created by tjd on 2019/1/3.
//  Copyright © 2019年 tjd. All rights reserved.
//

#import "ViewController.h"
#import <TJDBluetoothSDK/TJDBluetoothSDK.h>
#import <CoreBluetooth/CoreBluetooth.h>

#define bleSelf [WUBleManager shared]

@interface ViewController () <UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) UITableView *table;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    _table = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    _table.delegate = self;
    _table.dataSource = self;
    [self.view addSubview:_table];
    
    [self setupNotify];
    
    bleSelf.filterString = @"YW";
    [bleSelf setUpManager];
    [WUAppManager setIsDebug:true];
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
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotify:) name:WristbandNotifyKeys.sysCeLiang_heart object:nil];
    
}

- (void)handleNotify:(NSNotification *)notify {
    if (notify.name == WUBleManagerNotifyKeys.on) {
        [bleSelf startFindBleDevices];
    }
    
    if (notify.name == WUBleManagerNotifyKeys.scan) {
        [_table reloadData];
    }
    
    if (notify.name == WUBleManagerNotifyKeys.connected) {
        NSLog(@"WUBleManagerNotifyKeys.connected");
    }
    
    if (notify.name == WUBleManagerNotifyKeys.disconnected) {
        NSLog(@"WUBleManagerNotifyKeys.disconnected");
    }
    
    //准备好之后，先获取设备信息
    if (notify.name == WristbandNotifyKeys.readyToWrite) {
        [bleSelf setLanguageForWristband];
        [bleSelf getBatteryForWristband];
        [bleSelf getDeviceInfoForWristband];
        [bleSelf getUserinfoForWristband];
        [bleSelf setTimeForWristband];
        
        //然后同步手环的数据 。。。。。。
        [bleSelf getStepWith:0];
        NSLog(@"同步数据开始，这里可以开始刷新数据");
    }
    
    if (notify.name == WristbandNotifyKeys.read_Sport) {
        NSLog(@"%ld 步, %ld cal, %ld m", (long)bleSelf.step, bleSelf.cal, bleSelf.distance);
        [bleSelf aloneGetStepWith:0];
    }
    
    if (notify.name == WristbandNotifyKeys.read_All_Sport) {
        StepModel *stepModel = notify.object;
        //这里自己保存数据
        if ((stepModel.indexCount == 0) || (stepModel.indexCount == stepModel.index + 1)) {
            NSLog(@"同步记步完成");
            [bleSelf aloneGetMeasure:WristbandMeasureType.heart];
        }
    }
    
    if (notify.name == WristbandNotifyKeys.sysCeLiang_heart) {
        HeartModel *heartModel = notify.object;
        if ((heartModel.indexCount == 0) || (heartModel.indexCount == heartModel.index)) {
            NSLog(@"同步完成，这里可以结束刷新数据");
            
        }
    }
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return bleSelf.bleModels.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:nil];
    WUBleModel *model = bleSelf.bleModels[indexPath.row];
    cell.textLabel.text = model.name;
    cell.detailTextLabel.text = model.mac;
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:true];
    [bleSelf stopFindBleDevices];
    WUBleModel *model = bleSelf.bleModels[indexPath.row];
    bleSelf.activeModel = model;
    [WUBleModel setModel:model];
    CBPeripheral *peripheral = [bleSelf retrievePeripheralWith:model.uuidString];
    [bleSelf connectBleDevice:peripheral];
    
}


@end
