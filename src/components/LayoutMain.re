let component = ReasonReact.statelessComponent("LayoutMain");

module Styles = {
  let container =
    Css.(style([flexGrow(1), flexDirection(column), display(flexBox)]));
  let header = Css.(style([display(flexBox), flexGrow(0)]));
  let main = Css.(style([display(flexBox), flexGrow(1)]));
};

let make =
    (
      ~header: ReasonReact.reactElement,
      ~main: ReasonReact.reactElement,
      _children,
    ) => {
  ...component,
  render: _self =>
    <div className=Styles.container>
      <header className=Styles.header> header </header>
      <main className=Styles.main> main </main>
    </div>,
};