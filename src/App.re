let component = ReasonReact.statelessComponent("App");

Css.(
  global(
    "html, body, #root",
    [
      margin(px(0)),
      width(pct(100.0)),
      height(pct(100.0)),
      display(flexBox),
    ],
  )
);

let make = _children => {
  ...component,
  render: _self => <LayoutMain header={<TitleBar />} main={<Router />} />,
};