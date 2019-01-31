//
//  OptionsProvider.m
//  HighFit
//
//  License: www.highcharts.com/license
//  Copyright © 2016 Highsoft AS. All rights reserved.
//

#import "OptionsProvider.h"
#import <UIKit/UIKit.h>

@implementation OptionsProvider

//@[@0, @"rgb(98, 104, 166)"],
//@[@1, @"rgb(244, 153, 82)"]

+ (HIOptions*)provideOptionsForChartseriesOne:(NSArray*)seriesOne seriesTwo:(NSArray*)seriesTwo
{
    NSArray *categories = nil;
    
    id step = [NSNull null];
    
        categories = @[@214, @900, @1400];

    
        
        HIOptions *hioptions = [[HIOptions alloc]init];
        
        HIChart *chart = [[HIChart alloc]init];
        chart.backgroundColor = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:1];
        chart.borderRadius = @1;
        chart.type = @"area";
        hioptions.chart = chart;
    
//    HILegend *Legend=[[HILegend alloc]init];;
//    Legend.layout = @"vertical";
//    Legend.align =@"left";
//    Legend.floating = @NO;
//    Legend.verticalAlign =@ "top";
//    Legend.x =@150;
//    Legend.y = @100;
//    Legend.borderWidth =@1;
//    hioptions.legend=Legend;
    
//        HIExporting *exporting = [[HIExporting alloc]init];
//        exporting.enabled = false;
//        hioptions.exporting = exporting;
    
//        HIPlotOptions *plotOptions = [[HIPlotOptions alloc]init];
//        plotOptions.area = [[HIArea alloc]init];
//        plotOptions.area.fillColor = [[HIColor alloc]initWithLinearGradient:@{ @"x1": @0, @"x2": @0, @"y1": @0, @"y2": @150 } stops:@[
//                                                                                                                                      @[@0, @"rgba(5,193,134, 0.75)"],
//                                                                                                                                      @[@1, @"rgba(240,99,67, 0.02)"]
//                                                                                                                                      ]];
//        hioptions.plotOptions = plotOptions;
    
        HINavigation *btn=[[HINavigation alloc]init];
        hioptions.navigation = btn;
    
        HICredits *credits = [[HICredits alloc]init];
        credits.enabled = @NO;
        hioptions.credits = credits;
        
        HITitle *title = [[HITitle alloc]init];
        title.text = @"";
//        title.align = @"left";
//        title.style = [[HICSSObject alloc] init];
//        title.style.fontFamily = @"Arial";
//        title.style.fontSize = @"14px";
//        title.style.color = @"rgba(255, 255, 255, 0.6)";
//        title.y = @16;
        hioptions.title = title;
    
        HISubtitle *subtitle = [[HISubtitle alloc]init];
        subtitle.text = @"";
        if ([subtitle.text length] > 0) {
            subtitle.text = [subtitle.text stringByAppendingString:@" total"];
        }
        subtitle.align = @"right";
        subtitle.style = [[HICSSObject alloc] init];
        subtitle.style.fontFamily = @"Arial";
        subtitle.style.fontSize = @"10px";
        subtitle.style.color = @"rgba(0, 0, 0, 0.6)";
        subtitle.y = @13;
    subtitle.verticalAlign=@"bottom";
        subtitle.widthAdjust=@-44;
        hioptions.subtitle = subtitle;
    
        HITooltip *tooltip = [[HITooltip alloc]init];
        tooltip.headerFormat = @"";
    tooltip.enabled=@YES;
    tooltip.animation=@YES;
        hioptions.tooltip = tooltip;
        
        HIXAxis *xaxis = [[HIXAxis alloc]init];
        xaxis.tickColor = [[HIColor alloc]initWithRGBA:0 green:0 blue:0 alpha:0.0];
        xaxis.lineColor = [[HIColor alloc]initWithRGBA:0 green:0 blue:0 alpha:0.3];
        xaxis.type=@"category";
//        xaxis.labels = [[HILabels alloc]init];
//        xaxis.labels.style = [[HICSSObject alloc] init];
//        xaxis.labels.style.textOutline = @"10px Arial";
//        xaxis.labels.style.color = @"rgb(255, 255, 255)";
//    xaxis.index=@0;
//    xaxis.isX=@true;
//        xaxis.labels.step = step;
        xaxis.categories = [categories copy];
    xaxis.minTickInterval=@10;
        hioptions.xAxis = @[xaxis];
        
        HIYAxis *yaxis = [[HIYAxis alloc]init];
        yaxis.lineColor = [[HIColor alloc]initWithRGBA:0 green:0 blue:0 alpha:0.3];
        yaxis.lineWidth = @1;
        yaxis.gridLineWidth = @0;
        yaxis.labels = [[HILabels alloc]init];
        yaxis.labels.style = [[HICSSObject alloc] init];
        yaxis.labels.style.textOutline = @"10px Arial";
        yaxis.labels.style.color = @"rgb(0, 0, 0)";
        yaxis.labels.x = @-5;
        yaxis.title = [[HITitle alloc]init];
        yaxis.title.text = @"";
        hioptions.yAxis = @[yaxis];
    
        HIArea *area = [[HIArea alloc]init];
        area.tooltip = [[HITooltip alloc]init];
        area.tooltip.headerFormat = @"";
        area.tooltip.valueSuffix = @"";
        area.showInLegend = @YES;
        area.data = [seriesOne copy];
        area.color = [[HIColor alloc]initWithRGB:5 green:193 blue:134];
        area.name = @"买";
        area.fillColor=[[HIColor alloc]initWithRGBA:5 green:193 blue:134 alpha:0.6];
    
    HIArea *area1 = [[HIArea alloc]init];
    area1.tooltip = [[HITooltip alloc]init];
    area1.tooltip.headerFormat = @"";
    area1.tooltip.valueSuffix = @"";
    area1.showInLegend = @YES;
    area1.data = [seriesTwo copy];
    area1.color = [[HIColor alloc]initWithRGB:240 green:99 blue:67];
    area1.name = @"卖";
    area1.fillColor=[[HIColor alloc]initWithRGBA:240 green:99 blue:67 alpha:0.6];
        hioptions.series = @[area,area1];
        
        return hioptions;
}

@end
