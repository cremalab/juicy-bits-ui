open BsStorybook.Main;

let _module = [%bs.raw "module"];

let default = () => {
  let myStory =
    createStory(~title="Area Chart", ~decorators=[], ~_module, ());
  myStory.add("example", () => {
    let data = [|{"x": 0, "y": 0}, {"x": 1, "y": 4}, {"x": 2, "y": 10}|];
    ReactVis.(
      <XYPlot height=500 width=500>
        <HorizontalGridLines />
        <AreaSeries stroke="black" fill="#999" data />
        <XAxis title="Hello" />
        <YAxis title="World" />
      </XYPlot>
    );
  });
};