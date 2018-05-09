let component = ReasonReact.statelessComponent("Home");

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

let make = _children => {
  ...component,
  render: _self =>
    <Recharts.FlexContainer>
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
    </Recharts.FlexContainer>,
};