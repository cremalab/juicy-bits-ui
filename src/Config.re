module Routes = {
  type route =
    | Home
    | Fields
    | NotFound;

  let routeToString = (route: route) =>
    switch (route) {
    | Home => "/home"
    | Fields => "/fields"
    | NotFound => "/404"
    };
};