/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Animation setting for hovering the graph in line-type series.
*/
@interface HIAnimation: HIChartsJSONSerializable

/**
The duration of the hover animation in milliseconds. By default the hover state animates quickly in, and slowly back to normal.
*/
@property(nonatomic, readwrite) NSNumber *duration;

-(NSDictionary *)getParams;

@end
