module Styles = {
  let list =
    Css.(
      style([
        display(flexBox),
        borderWidth(px(1)),
        borderColor(whitesmoke),
        borderStyle(solid),
        borderRadius(px(3)),
        overflow(hidden),
      ])
    );
  let item = (isCurrent: bool) =>
    Css.(
      style([
        cursor(`pointer),
        padding(px(10)),
        backgroundColor(isCurrent ? whitesmoke : white),
        hover([backgroundColor(lightgray)]),
      ])
    );
};

module Item = {
  let component = ReasonReact.statelessComponent("NavigationItem");
  let make = (~path: string, ~currentRoute: string, ~label: string, _children) => {
    ...component,
    render: _self => {
      let isCurrent = path == currentRoute;
      <div
        className=(Styles.item(isCurrent))
        onClick=(_e => ReasonReact.Router.push(path))>
        (ReasonReact.string(label))
      </div>;
    },
  };
};

module List = {
  let component = ReasonReact.statelessComponent("Navigation");
  let make = (~currentRoute: string, _children) => {
    ...component,
    render: _self =>
      <nav className=Styles.list>
        <Item path="/" label="Home" currentRoute />
        <Item path="/fields" label="Fields" currentRoute />
      </nav>,
  };
};

type state = {currentRoute: string};

type action =
  | RouteChange(string);

let component = ReasonReact.reducerComponent("Navigation");

let pathFromUrl = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | [path] => "/" ++ path
  | [path, _] => "/" ++ path
  | [] => "/"
  | _ => "/"
  };

let make = _children => {
  ...component,
  initialState: () => {
    currentRoute: ReasonReact.Router.dangerouslyGetInitialUrl() |> pathFromUrl,
  },
  reducer: (action, _state) =>
    switch (action) {
    | RouteChange(currentRoute) =>
      ReasonReact.Update({currentRoute: currentRoute})
    },
  didMount: self => {
    let watcherId =
      ReasonReact.Router.watchUrl(url =>
        RouteChange(url |> pathFromUrl) |> self.send
      );
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
  },
  render: self => <List currentRoute=self.state.currentRoute />,
};