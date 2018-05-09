let component = ReasonReact.statelessComponent("App");

Css.(
  global("html, body, #root", [width(pct(100.0)), height(pct(100.0))])
);

type dataItem = {
  .
  name: string,
  react: int,
  testing: int,
};

let data = [|
  {"name": "Week 1", "react": 3, "testing": 6},
  {"name": "Week 2", "react": 4, "testing": 2},
  {"name": "Week 3", "react": 6, "testing": 1},
  {"name": "Week 4", "react": 10, "testing": 15},
|];

let items = [|"one", "two"|];

let make = _children => {
  ...component,
  render: _self =>
    <Recharts.ResponsiveContainer width="100%" height="100%">
      <Recharts.AreaChart data>
        <Recharts.Area
          stackId="1"
          lineType="monotone"
          dataKey="react"
          stroke="transparent"
          fill="#8884d8"
          fillOpacity=0.5
        />
        <Recharts.Area
          stackId="1"
          lineType="monotone"
          dataKey="testing"
          stroke="transparent"
          fill="#82ca9ddd"
          fillOpacity=0.5
        />
        <Recharts.XAxis dataKey="name" />
        <Recharts.YAxis />
        <Recharts.Legend />
      </Recharts.AreaChart>
    </Recharts.ResponsiveContainer>,
};