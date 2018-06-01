open Config.Routes;

type state = {currentRoute: route};

type action =
  | Push(route);

let component = ReasonReact.reducerComponent("Router");

let renderByRoute = (route: route) =>
  switch (route) {
  | Home => <Home />
  | Fields => <div> (ReasonReact.string("Fields")) </div>
  | NotFound => <div> (ReasonReact.string("NotFound")) </div>
  };

let routeByUrl = (url: ReasonReact.Router.url) : route =>
  switch (url.path) {
  | ["home"] => Home
  | [] => Home
  | ["fields"] => Fields
  | _ => NotFound
  };

let make = _children => {
  ...component,
  initialState: () => {
    currentRoute: routeByUrl(ReasonReact.Router.dangerouslyGetInitialUrl()),
  },
  reducer: (action, _state) =>
    switch (action) {
    | Push(route) => ReasonReact.Update({currentRoute: route})
    },
  didMount: self => {
    let watcherID =
      ReasonReact.Router.watchUrl(url => self.send(Push(routeByUrl(url))));
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  render: self => renderByRoute(self.state.currentRoute),
};