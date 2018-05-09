let component = ReasonReact.statelessComponent("TitleBar");

let make = _children => {
  ...component,
  render: _self => <div> (ReasonReact.string("Juicy Bits")) </div>,
};