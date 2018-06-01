let component = ReasonReact.statelessComponent("Items");

type item('a) = 'a => ReasonReact.reactElement;

type items('a) = array('a);

let make = (~item: item('a), ~items: items('a), _children) => {
  ...component,
  render: _self => {
    let xs = Array.map(item, items) |> ReasonReact.array;
    xs;
  },
};