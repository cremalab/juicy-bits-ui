[@bs.module "recharts"] external line : ReasonReact.reactClass = "Line";

module Line = {
  let make = (~lineType: string, ~dataKey: string, ~stroke: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=line,
      ~props={"type": lineType, "dataKey": dataKey, "stroke": stroke},
      children,
    );
};

[@bs.module "recharts"]
external lineChart : ReasonReact.reactClass = "LineChart";

module LineChart = {
  let make = (~width: int, ~height: int, ~data, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=lineChart,
      ~props={"width": width, "height": height, "data": data},
      children,
    );
};

[@bs.module "recharts"] external xAxis : ReasonReact.reactClass = "XAxis";

module XAxis = {
  let make = (~dataKey: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=xAxis,
      ~props={"dataKey": dataKey},
      children,
    );
};

[@bs.module "recharts"] external yAxis : ReasonReact.reactClass = "YAxis";

module YAxis = {
  let make = (~dataKey: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=yAxis,
      ~props={"dataKey": dataKey},
      children,
    );
};