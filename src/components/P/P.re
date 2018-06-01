let component = ReasonReact.statelessComponent("P");

module Style = {
  open Theme;
  let p = level =>
    Css.(
      style([
        fontSize(fontSize_of_heading(level)),
        lineHeight(1.3),
        marginBottom(px(0)),
      ])
    );
};

let make = (~level: Theme.heading=`h6, ~text: string, _children) => {
  ...component,
  render: _self => {
    let content = ReasonReact.string(text);
    <p className=(Style.p(level))> content </p>;
  },
};