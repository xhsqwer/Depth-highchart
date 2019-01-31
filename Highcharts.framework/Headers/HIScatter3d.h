/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"


/**
 A `scatter3d` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `scatter3d` series are defined in `plotOptions.scatter3d`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        scatter3d: {
            // shared options for all scatter3d series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'scatter3d'
    }]
 });
 <pre>
 */
@interface HIScatter3d: HISeries


-(NSDictionary *)getParams;

@end
