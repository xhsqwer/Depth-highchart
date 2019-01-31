//
//  DemoChatViewController.m
//  HighFit
//
//  Created by Hongshuo Xiao on 2019/1/30.
//  Copyright © 2019 Highsoft AS. All rights reserved.
//

#import "DemoChatViewController.h"
#import <Highcharts/Highcharts.h>
#import "OptionsProvider.h"
#import "SocketManager.h"
#import "zlib.h"

@interface DemoChatViewController ()
{
        SocketManager *_socketData;
    HIChartView *_chartView;
}
@property (strong, nonatomic) NSMutableArray *sources;
@property (strong, nonatomic) NSArray *data;
@end

@implementation DemoChatViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor=[UIColor whiteColor];

    _chartView = [[HIChartView alloc] initWithFrame:CGRectMake(5.0f, 5.0f, self.view.bounds.size.width-20.0f, 400.0f)];
    
    _chartView.backgroundColor = [UIColor clearColor];
    [self.view addSubview:_chartView];
    
    [self initSocket];
    // Do any additional setup after loading the view.
}

-(void)initSocket{
    _socketData= [SocketManager sharedInsatance];
    
    [_socketData webSocketOpen:@"wss://source.hiex.net:12345/ws" connect:^{
        NSLog(@"成功连接");
            [self sendMessage];
    } receive:^(id message, SocketReceiveType type) {
        if (type == SocketReceiveTypeForMessage) {
            NSError *err;
            NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:[self uncompressZippedData:message]
                                                                options:NSJSONReadingMutableContainers
                                                                  error:&err];
            //
            NSLog(@"接收 类型1-----:%@",[NSJSONSerialization JSONObjectWithData:[self uncompressZippedData:message]
                                                                    options:NSJSONReadingMutableContainers
                                                                      error:&err]);
            
            [self dataWith:dic];
        }
        else if (type == SocketReceiveTypeForPong){
            NSLog(@"接收 类型2--%@",message);
        }
    } failure:^(NSError *error) {
        NSLog(@"连接失败");
    }];
}

-(void)sendMessage{
//    NSNumber *kk= [NSNumber numberWithLong:[@"5000" longLongValue]];
//    NSDictionary * dataDic = [NSDictionary dictionaryWithObjectsAndKeys:@"market.btcusdt.depth.step0",@"sub",@"id10",@"id",kk,@"freq-ms", nil];
//    NSData *data = [NSJSONSerialization dataWithJSONObject:dataDic options:NSJSONWritingPrettyPrinted error:nil];
//
//    [_socketData webSocketSend:[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding]];
    NSDictionary * dataDic = [NSDictionary dictionaryWithObjectsAndKeys:@"market.btcusdt.depth.step0",@"req",@"id10",@"id", nil];
    NSData *data = [NSJSONSerialization dataWithJSONObject:dataDic options:NSJSONWritingPrettyPrinted error:nil];
    
    [_socketData webSocketSend:[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding]];
}

-(void)dataWith:(NSDictionary *)dicModel
{
    if ([dicModel objectForKey:@"ping"] != nil) {
        NSNumber *kk= [NSNumber numberWithLong:[[dicModel objectForKey:@"ping"] longLongValue]];
        NSDictionary * dataDic = [NSDictionary dictionaryWithObjectsAndKeys:kk,@"pong", nil];
        
        NSData *data = [NSJSONSerialization dataWithJSONObject:dataDic options:NSJSONWritingPrettyPrinted error:nil];
        
        [_socketData webSocketSend:[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding]];
        
    }else if ([dicModel objectForKey:@"data"] != nil){
        NSMutableArray *arrBidDone=[NSMutableArray new];
        NSMutableArray *arrAsksDone=[NSMutableArray new];
        
        NSArray *arrBids=[NSArray arrayWithArray:[[dicModel objectForKey:@"data"] objectForKey:@"bids"]];
        NSArray *arrAsks=[NSArray arrayWithArray:[[dicModel objectForKey:@"data"] objectForKey:@"asks"]];
        
        for (int i = 0; i<arrBids.count ; i++) {
            NSMutableArray *arrB=[NSMutableArray new];
            [arrB addObject:arrBids[i][0]];
            NSMutableArray *arrSum=[NSMutableArray new];
            for (int j = 0; j < i+1; j++) {
                [arrSum addObject:arrBids[j][1]];
            }
            NSNumber *sum = [arrSum valueForKeyPath:@"@sum.self"];
            [arrB addObject:sum];
            [arrBidDone addObject:arrB];
        }
        
        for (int i = 0; i<arrAsks.count ; i++) {
            NSMutableArray *arrA=[NSMutableArray new];
            [arrA addObject:arrAsks[i][0]];
            NSMutableArray *arrSum1=[NSMutableArray new];
            for (int j = 0; j < i+1; j++) {
                [arrSum1 addObject:arrAsks[j][1]];
            }
            NSNumber *sum1 = [arrSum1 valueForKeyPath:@"@sum.self"];
            [arrA addObject:sum1];
            [arrAsksDone addObject:arrA];
        }
        _chartView.options = [OptionsProvider provideOptionsForChartseriesOne:arrBidDone seriesTwo:arrAsksDone];
    }

    else if ([dicModel objectForKey:@"tick"] != nil){
        NSMutableArray *arrBidDone=[NSMutableArray new];
        NSMutableArray *arrAsksDone=[NSMutableArray new];
        
        NSMutableArray *arrBidDoneAll=[NSMutableArray new];

        NSArray *arrBids=[NSArray arrayWithArray:[[dicModel objectForKey:@"tick"] objectForKey:@"bids"]];
        NSArray *arrAsks=[NSArray arrayWithArray:[[dicModel objectForKey:@"tick"] objectForKey:@"asks"]];
        
        for (int i = 0; i<arrBids.count ; i++) {
            NSMutableArray *arrB=[NSMutableArray new];
            [arrB addObject:arrBids[i][0]];
            NSMutableArray *arrSum=[NSMutableArray new];
            for (int j = 0; j < i+1; j++) {
                [arrSum addObject:arrBids[j][1]];
            }
            NSNumber *sum = [arrSum valueForKeyPath:@"@sum.self"];
            [arrB addObject:sum];
            [arrBidDone addObject:arrB];
        }
        
        [arrBidDone enumerateObjectsWithOptions:NSEnumerationReverse usingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [arrBidDoneAll addObject:obj];
        }];
        
        for (int i = 0; i<arrAsks.count ; i++) {
            NSMutableArray *arrA=[NSMutableArray new];
            [arrA addObject:arrAsks[i][0]];
            NSMutableArray *arrSum1=[NSMutableArray new];
            for (int j = 0; j < i+1; j++) {
                [arrSum1 addObject:arrAsks[j][1]];
            }
            NSNumber *sum1 = [arrSum1 valueForKeyPath:@"@sum.self"];
            [arrA addObject:sum1];
            [arrAsksDone addObject:arrA];
        }
            _chartView.options = [OptionsProvider provideOptionsForChartseriesOne:arrBidDoneAll seriesTwo:arrAsksDone];
    }
}

-(NSData *)uncompressZippedData:(NSData *)compressedData
{
    if ([compressedData length] == 0) return compressedData;
    
    unsigned full_length = [compressedData length];
    
    unsigned half_length = [compressedData length] / 2;
    NSMutableData *decompressed = [NSMutableData dataWithLength: full_length + half_length];
    BOOL done = NO;
    int status;
    z_stream strm;
    strm.next_in = (Bytef *)[compressedData bytes];
    strm.avail_in = [compressedData length];
    strm.total_out = 0;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    if (inflateInit2(&strm, (15+32)) != Z_OK) return nil;
    while (!done) {
        // Make sure we have enough room and reset the lengths.
        if (strm.total_out >= [decompressed length]) {
            [decompressed increaseLengthBy: half_length];
        }
        // chadeltu 加了(Bytef *)
        strm.next_out = (Bytef *)[decompressed mutableBytes] + strm.total_out;
        strm.avail_out = [decompressed length] - strm.total_out;
        // Inflate another chunk.
        status = inflate (&strm, Z_SYNC_FLUSH);
        if (status == Z_STREAM_END) {
            done = YES;
        } else if (status != Z_OK) {
            break;
        }
        
    }
    if (inflateEnd (&strm) != Z_OK) return nil;
    // Set real length.
    if (done) {
        [decompressed setLength: strm.total_out];
        return [NSData dataWithData: decompressed];
    } else {
        return nil;
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
