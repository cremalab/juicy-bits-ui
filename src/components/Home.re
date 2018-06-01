let component = ReasonReact.statelessComponent("Home");

module Style = {
  let container = Css.(style([flex(1)]));
};

let data0 = [|
  {"x": 1, "y": 3},
  {"x": 2, "y": 4},
  {"x": 3, "y": 6},
  {"x": 4, "y": 10},
|];

let data1 = [|
  {"x": 1, "y": 6},
  {"x": 2, "y": 4},
  {"x": 3, "y": 8},
  {"x": 4, "y": 15},
|];

let make = _children => {
  ...component,
  render: _self =>
    <div className=Style.container>
      <CardPreview
        title="Team Overview"
        description="Vivamus eget nulla vitae felis bibendum iaculis sed vitae quam. Phasellus condimentum facilisis turpis quis molestie. Integer bibendum, lectus a hendrerit condimentum, nulla dui mattis nulla, ultrices sollicitudin."
        route=Config.Routes.Fields
        content=ReactVis.(
                  <XYPlotFlexible>
                    <HorizontalGridLines />
                    <AreaSeries data=data1 color="#8884d8" opacity=0.7 />
                    <AreaSeries data=data0 color="#82ca9d" opacity=0.7 />
                    <XAxis />
                    <YAxis />
                  </XYPlotFlexible>
                )
      />
    </div>,
};