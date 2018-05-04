let component = ReasonReact.statelessComponent("App");

type dataItem = {
  .
  name: string,
  value: int,
};

let data = [|
  {"name": "Rob", "value": 12},
  {"name": "Blake", "value": 39},
  {"name": "Ross", "value": 20},
  {"name": "Deric", "value": 40},
  {"name": "Chris", "value": 150},
  {"name": "Micheal", "value": 20},
|];

let items = [|"one", "two"|];

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <Items item=(i => <div key=i> (ReasonReact.string(i)) </div>) items />
      <Recharts.LineChart width=800 height=400 data>
        <Recharts.Line lineType="monotone" dataKey="value" stroke="#8884d8" />
        <Recharts.XAxis dataKey="name" />
        <Recharts.YAxis dataKey="value" />
      </Recharts.LineChart>
    </div>,
};