let component = ReasonReact.statelessComponent("App");

Css.(
  global(
    "html, body, #root",
    [width(pct(100.0)), height(pct(100.0)), display(flexBox)],
  )
);

let make = _children => {
  ...component,
  render: _self => <LayoutMain header={<TitleBar />} main={<Router />} />,
};