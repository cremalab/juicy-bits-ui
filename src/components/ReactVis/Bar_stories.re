open BsStorybook.Main;

let _module = [%bs.raw "module"];

let default = () => {
  let myStory = createStory(~title="Bar Chart", ~decorators=[], ~_module, ());
  myStory.add("horizontal", () => {
    let data = [|{"x": 0, "y": 0}, {"x": 1, "y": 4}, {"x": 2, "y": 10}|];
    ReactVis.(
      <XYPlot height=500 width=500>
        <HorizontalGridLines />
        <HorizontalBarSeries stroke="black" data />
        <XAxis title="Hello" />
        <YAxis title="World" />
      </XYPlot>
    );
  });
  myStory.add("vertical", () => {
    let data = [|{"x": 0, "y": 0}, {"x": 1, "y": 4}, {"x": 2, "y": 10}|];
    ReactVis.(
      <XYPlot height=500 width=500>
        <HorizontalGridLines />
        <VerticalBarSeries stroke="black" data />
        <XAxis title="Hello" />
        <YAxis title="World" />
      </XYPlot>
    );
  });
};