let component = ReasonReact.statelessComponent("CardOverview");

module Styles = {
  open Theme;
  let header =
    Css.(
      style([
        padding(px_of_spacing(`four)),
        selector("> * + *", [marginTop(px_of_spacing(`three))]),
      ])
    );
  let headerTitle =
    Css.(
      style([
        display(inlineBlock),
        backgroundColor(hex_of_color(`yellow)),
        padding(px_of_spacing(`three)),
        fontSize(fontSize_of_heading(`h4)),
      ])
    );
  let mainSize = Css.(style([position(relative), paddingTop(pct(75.0))]));
  let mainPosition =
    Css.(
      style([
        padding(px_of_spacing(`four)),
        top(px(0)),
        right(px(0)),
        bottom(px(0)),
        left(px(0)),
        position(absolute),
      ])
    );
  let footer =
    Css.(
      style([
        display(flexBox),
        justifyContent(`spaceBetween),
        alignItems(`center),
        cursor(`pointer),
        backgroundColor(hex_of_color(~step=`three, ~mix=Tint, `black)),
        color(hex_of_color(`white)),
        padding(px_of_spacing(`four)),
      ])
    );
};

let make = (~title, ~description, ~content, ~route, _children) => {
  ...component,
  render: _self =>
    <Card
      header={
        <div className=Styles.header>
          <div className=Styles.headerTitle>
            <Heading level=`h4 text=title />
          </div>
          <P text=description />
        </div>
      }
      main={
        <div>
          <div className=Styles.mainSize>
            <div className=Styles.mainPosition> content </div>
          </div>
        </div>
      }
      footer={
        <div
          className=Styles.footer
          onClick=(
            _e => ReasonReact.Router.push(Config.Routes.routeToString(route))
          )>
          (ReasonReact.string("See more"))
          <Icon.ArrowRight fill=`white />
        </div>
      }
    />,
};