/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Holds a pattern definition.
*/
@interface HIPatternObject: HIChartsJSONSerializable

/**
Animation options for the image pattern loading.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *animation;
/**
Pattern options
*/
@property(nonatomic, readwrite) id pattern;

-(NSDictionary *)getParams;

@end
