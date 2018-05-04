let component = ReasonReact.statelessComponent("Items");

module Styles = {
  open Css;
  let container = color => style([background(color)]);
  let heading = style([background(red), padding(em(2.0))]);
  let content = style([padding(em(2.0))]);
};

type item('a) = 'a => ReasonReact.reactElement;

type items('a) = array('a);

let make = (~item: item('a), ~items: items('a), _children) => {
  ...component,
  render: _self => {
    let xs = Array.map(item, items) |> ReasonReact.array;
    <div className=(Styles.container(Css.teal))>
      <div className=Styles.heading> (ReasonReact.string("Heading")) </div>
      <div className=Styles.content> xs </div>
    </div>;
  },
};