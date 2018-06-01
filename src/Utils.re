let (@<) = (f, g, x) => f(g(x));
let (>>) = (f, g, x) => g(f(x));
let identity = x => x;
let flip = (f, a, b) => f(b, a);
let const = (a, _b) => a;

module Decorators = {
  module Styles = {
    let padded = (p: Theme.spacing) =>
      Css.(style([padding(Theme.px_of_spacing(p))]));
  };

  let global = s => <div className=Theme.Global.styles> (s()) </div>;

  let padded = (spacing: Theme.spacing, s) =>
    <div className=(Styles.padded(spacing))> (s()) </div>;
};

let elementOfList = ReasonReact.array @< Array.of_list;

let elementOfOption =
    (~wrapper: option('a => 'a)=?, x: option(ReasonReact.reactElement)) =>
  switch (x, wrapper) {
  | (Some(el), Some(fn)) => fn(el)
  | (Some(el), None) => el
  | (None, None) => ReasonReact.null
  | (None, Some(_fn)) => ReasonReact.null
  };