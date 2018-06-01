[%bs.raw {|require('../node_modules/react-vis/dist/style.css')|}];

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => <LayoutMain header={<TitleBar />} main={<Router />} />,
};