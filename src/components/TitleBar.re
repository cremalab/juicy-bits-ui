let component = ReasonReact.statelessComponent("TitleBar");

module Styles = {
  let container =
    Css.(
      style([display(flexBox), flexGrow(1), justifyContent(spaceAround)])
    );
};

let make = _children => {
  ...component,
  render: _self =>
    <div className=Styles.container>
      <Navigation />
      (ReasonReact.string("Juicy Bits"))
    </div>,
};