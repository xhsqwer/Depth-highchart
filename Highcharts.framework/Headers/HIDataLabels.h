/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIFilter.h"
#import "HIColor.h"
#import "HIFunction.h"
#import "HICSSObject.h"


/**
Options for the series data labels, appearing next to each data point. Since v6.2.0, multiple data labels can be applied to each single point by defining them as an array of configs. In styled mode, the data labels can be styled with the `.highcharts-data-label-box` and `.highcharts-data-label` class names ([see example](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-datalabels)).

**Try it**

* [Data labels enabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-enabled)
* [Multiple data labels on a bar series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-multiple)
*/
@interface HIDataLabels: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSNumber /* Bool */ *defer;
@property(nonatomic, readwrite) NSNumber /* Bool */ *inside;
@property(nonatomic, readwrite) HIFunction *formatter;
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
@property(nonatomic, readwrite) NSString *verticalAlign;
@property(nonatomic, readwrite) NSNumber /* Bool */ *crop;
@property(nonatomic, readwrite) NSNumber *padding;
@property(nonatomic, readwrite) NSNumber /* Bool */ *overflow;
/**
The x position of the data label relative to the data point.

**Defaults to** `5`.

**Try it**

* [Data labels inside the bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bar-datalabels-align-inside-bar/)
*/
@property(nonatomic, readwrite) NSNumber *x;
/**
Alignment of the data label relative to the data point.

**Defaults to** `left`.

**Try it**

* [Data labels inside the bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/bar-datalabels-align-inside-bar/)
*/
@property(nonatomic, readwrite) NSString *align;
@property(nonatomic, readwrite) NSNumber *y;
/**
Y offset of the higher data labels relative to the point value.

**Try it**

* [Data labels on range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-datalabels/)
*/
@property(nonatomic, readwrite) NSNumber *yHigh;
/**
X offset of the higher data labels relative to the point value.

**Try it**

* [Data labels on range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-datalabels/)
*/
@property(nonatomic, readwrite) NSNumber *xHigh;
/**
X offset of the lower data labels relative to the point value.

**Try it**

* [Data labels on range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-datalabels/)
*/
@property(nonatomic, readwrite) NSNumber *xLow;
/**
Y offset of the lower data labels relative to the point value.

**Try it**

* [Data labels on range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/arearange-datalabels/)
*/
@property(nonatomic, readwrite) NSNumber *yLow;
/**
The border radius in pixels for the data label.

**Defaults to** `0`.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) NSNumber *borderRadius;
/**
The name of a symbol to use for the border around the label. Symbols are predefined functions on the Renderer object.

**Defaults to** `square`.

**Try it**

* [A callout for annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-shape/)
*/
@property(nonatomic, readwrite) NSString *shape;
/**
Whether to [use HTML](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting#html) to render the labels.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *useHTML;
/**
The border color for the data label. Defaults to `undefined`.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) HIColor *borderColor;
/**
A declarative filter for which data labels to display. The declarative filter is designed for use when callback functions are not available, like when the chart options require a pure JSON structure or for use with graphical editors. For programmatic control, use the `formatter` instead, and return `undefined` to disable a single data label.

**Try it**

* [Data labels filtered by percentage](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/demo/pie-monochrome)
*/
@property(nonatomic, readwrite) HIFilter *filter;
/**
Styles for the label. The default `color` setting is `"contrast"`, which is a pseudo color that Highcharts picks up and applies the maximum contrast to the underlying point item, for example the bar in a bar chart. The `textOutline` is a pseudo property that applies an outline of the given width with the given color, which by default is the maximum contrast to the text. So a bright text color will result in a black text outline for maximum readability on a mixed background. In some cases, especially with grayscale text, the text outline doesn't work well, in which cases it can be disabled by setting it to `"none"`. When `useHTML` is true, the `textOutline` will not be picked up. In this, case, the same effect can be acheived through the `text-shadow` CSS property. For some series types, where each point has an extent, like for example tree maps, the data label may overflow the point. There are two strategies for handling overflow. By default, the text will wrap to multiple lines. The other strategy is to set `style.textOverflow` to `ellipsis`, which will keep the text on one line plus it will break inside long words.

**Defaults to** `{"color": "contrast", "fontSize": "11px", "fontWeight": "bold", "textOutline": "1px contrast" }`.

**Try it**

* [Bold labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-style/)
*/
@property(nonatomic, readwrite) HICSSObject *style;
/**
The text color for the data labels. Defaults to `undefined`. For certain series types, like column or map, the data labels can be drawn inside the points. In this case the data label will be drawn with maximum contrast by default. Additionally, it will be given a `text-outline` style with the opposite color, to further increase the contrast. This can be overridden by setting the `text-outline` style to `none` in the `dataLabels.style` option.

**Try it**

* [Red data labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-color/)
*/
@property(nonatomic, readwrite) HIColor *color;
/**
The background color or gradient for the data label.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) HIColor *backgroundColor;
/**
Whether to allow data labels to overlap. To make the labels less sensitive for overlapping, the `dataLabels.padding` can be set to 0.

**Defaults to** `false`.

**Try it**

* [Don't allow overlap](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-allowoverlap-false/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *allowOverlap;
/**
The shadow of the box. Works best with `borderWidth` or `backgroundColor`. Since 2.3 the shadow can be an object configuration containing `color`, `offsetX`, `offsetY`, `opacity` and `width`.

**Defaults to** `false`.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *shadow;
/**
A [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) for the data label. Available variables are the same as for `formatter`.

**Defaults to** `{y}`.

**Try it**

* [Add a unit](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-format/)
*/
@property(nonatomic, readwrite) NSString *format;
/**
Text rotation in degrees. Note that due to a more complex structure, backgrounds, borders and padding will be lost on a rotated data label.

**Defaults to** `0`.

**Try it**

* [Vertical labels](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-rotation/)
*/
@property(nonatomic, readwrite) NSNumber *rotation;
/**
The Z index of the data labels. The default Z index puts it above the series. Use a Z index of 2 to display it behind the series.

**Defaults to** `6`.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
A class name for the data label. Particularly in styled mode, this can be used to give each series' or point's data label unique styling. In addition to this option, a default color class name is added so that we can give the labels a [contrast text shadow](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/data-label-contrast/).

**Try it**

* [Styling by CSS](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/series-datalabels/)
*/
@property(nonatomic, readwrite) NSString *className;
/**
The border width in pixels for the data label.

**Defaults to** `0`.

**Try it**

* [Data labels box options](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/series-datalabels-box/)
*/
@property(nonatomic, readwrite) NSNumber *borderWidth;
/**
Decides how the data label will be rotated relative to the perimeter of the sunburst. Valid values are `auto`, `parallel` and `perpendicular`. When `auto`, the best fit will be computed for the point. The `series.rotation` option takes precedence over `rotationMode`.

**Accepted values:** `["auto", "perpendicular", "parallel"]`.
*/
@property(nonatomic, readwrite) NSString *rotationMode;
/**
Callback to format data labels for _nodes_ in the sankey diagram. The `nodeFormat` option takes precedence over the `nodeFormatter`.
*/
@property(nonatomic, readwrite) HIFunction *nodeFormatter;
/**
The [format string](https://www.highcharts.com/docs/chart-concepts/labels-and-string-formatting) specifying what to show for _nodes_ in the sankey diagram. By default the `nodeFormatter` returns `{point.name}`.
*/
@property(nonatomic, readwrite) NSString *nodeFormat;
/**
The color of the line connecting the data label to the pie slice. The default color is the same as the point's color. In styled mode, the connector stroke is given in the `.highcharts-data-label-connector` class.

**Try it**

* [Blue connectors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorcolor/)
* [Styled connectors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/pie-point/)
*/
@property(nonatomic, readwrite) HIColor *connectorColor;
/**
Alignment method for data labels. Possible values are: `'toPlotEdges'` (each label touches the nearest vertical edge of the plot area) or `'connectors'` (connectors have the same x position and the widest label of each half (left & right) touches the nearest vertical edge of the plot area).

**Defaults to** `undefined`.

**Try it**

* [alignTo: connectors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-alignto-connectors/)
* [alignTo: plotEdges](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-alignto-plotedges/)
*/
@property(nonatomic, readwrite) NSString *alignTo;
/**
The width of the line connecting the data label to the pie slice. In styled mode, the connector stroke width is given in the `.highcharts-data-label-connector` class.

**Defaults to** `1`.

**Try it**

* [Disable the connector](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorwidth-disabled/)
* [Styled connectors](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/pie-point/)
*/
@property(nonatomic, readwrite) NSNumber *connectorWidth;
/**
Whether to render the connector as a soft arc or a line with sharp break. Works only if `connectorShape` equals to `fixedOffset`.

**Try it**

* [Soft](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-softconnector-true/)
* [Non soft](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-softconnector-false/)
*/
@property(nonatomic, readwrite) NSNumber *softConnector;
/**
The distance from the data label to the connector. Note that data labels also have a default `padding`, so in order for the connector to touch the text, the `padding` must also be 0.

**Try it**

* [No padding](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorpadding/)
*/
@property(nonatomic, readwrite) NSNumber *connectorPadding;
/**
Specifies the method that is used to generate the connector path. Highcharts provides 3 built-in connector shapes: `'fixedOffset'` (default), `'straight'` and `'crookedLine'`. Using `'crookedLine'` has the most sense (in most of the cases) when `'alignTo'` is set. Users can provide their own method by passing a function instead of a String. 3 arguments are passed to the callback:    Object that holds the information about the coordinates of the  label (`x` & `y` properties) and how the label is located in  relation to the pie (`alignment` property). `alignment` can by one  of the following:  `'left'` (pie on the left side of the data label),  `'right'` (pie on the right side of the data label) or  `'center'` (data label overlaps the pie).    Object that holds the information about the position of the  connector. Its `touchingSliceAt` porperty tells the position of  the place where the connector touches the slice.    Data label options   The function has to return an SVG path definition in array form (see the example).

**Try it**

* [connectorShape is a String](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorshape-string/)
* [connectorShape is a function](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-connectorshape-function/)
*/
@property(nonatomic, readwrite) NSString *connectorShape;
/**
Works only if `connectorShape` is `'crookedLine'`. It defines how far from the vertical plot edge the coonnector path should be crooked.

**Try it**

* [crookDistance set to 90%](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-crookdistance/)
*/
@property(nonatomic, readwrite) NSString *crookDistance;
/**
The distance of the data label from the pie's edge. Negative numbers put the data label on top of the pie slices. Connectors are only shown for data labels outside the pie.

**Try it**

* [Data labels on top of the pie](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/pie-datalabels-distance/)
*/
@property(nonatomic, readwrite) NSNumber *distance;

-(NSDictionary *)getParams;

@end
