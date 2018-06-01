let component = ReasonReact.statelessComponent("Heading");

module Style = {
  open Theme;
  let heading = level =>
    Css.(
      style([
        fontSize(fontSize_of_heading(level)),
        lineHeight(1.2),
        margin(px(0)),
        fontWeight(400),
      ])
    );
};

let make = (~level: Theme.heading, ~text: string, _children) => {
  ...component,
  render: _self => {
    let content = ReasonReact.string(text);
    switch (level) {
    | `h1 => <h1 className=(Style.heading(`h1))> content </h1>
    | `h2 => <h2 className=(Style.heading(`h2))> content </h2>
    | `h3 => <h3 className=(Style.heading(`h3))> content </h3>
    | `h4 => <h4 className=(Style.heading(`h4))> content </h4>
    | `h5 => <h5 className=(Style.heading(`h5))> content </h5>
    | `h6 => <h6 className=(Style.heading(`h6))> content </h6>
    };
  },
};