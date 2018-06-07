open Utils;
let component = ReasonReact.statelessComponent("Card");

module Styles = {
  let container =
    Css.(
      style([
        backgroundColor(white),
        borderRadius(Theme.px_of_spacing(`three)),
        boxShadow(~y=px(1), ~blur=px(5), rgba(0, 0, 0, 0.3)),
        overflow(hidden),
      ])
    );
};

let section = elementOfOption(~wrapper=el => <div> el </div>);

let make =
    (
      ~header: option(ReasonReact.reactElement)=?,
      ~main: ReasonReact.reactElement,
      ~footer: option(ReasonReact.reactElement)=?,
      _children,
    ) => {
  ...component,
  render: _self =>
    <div className=Styles.container>
      (section(header))
      <div> main </div>
      (section(footer))
    </div>,
};