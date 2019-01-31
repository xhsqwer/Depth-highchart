//
//  OptionsProvider.h
//  HighFit
//
//  License: www.highcharts.com/license
//  Copyright © 2018 Highsoft AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Highcharts/Highcharts.h>

@interface OptionsProvider : NSObject

+ (HIOptions*)provideOptionsForChartseriesOne:(NSArray*)seriesOne seriesTwo:(NSArray*)seriesTwo;

@end
