[@bs.module "recharts"]
external responsiveContainer : ReasonReact.reactClass = "ResponsiveContainer";

module ResponsiveContainer = {
  let make = (~width: option(string)=?, ~height: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=responsiveContainer,
      ~props={
        "width": Js.Nullable.fromOption(width),
        "height": Js.Nullable.fromOption(height),
      },
      children,
    );
};

[@bs.module "recharts"]
external areaChart : ReasonReact.reactClass = "AreaChart";

module AreaChart = {
  let make =
      (~width: option(int)=?, ~height: option(int)=?, ~data, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=areaChart,
      ~props={
        "width": Js.Nullable.fromOption(width),
        "height": Js.Nullable.fromOption(height),
        "data": data,
      },
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

[@bs.module "recharts"] external line : ReasonReact.reactClass = "Line";

module Line = {
  let make = (~lineType: string, ~dataKey: string, ~stroke: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=line,
      ~props={"type": lineType, "dataKey": dataKey, "stroke": stroke},
      children,
    );
};

[@bs.module "recharts"] external area : ReasonReact.reactClass = "Area";

module Area = {
  let make =
      (
        ~stackId: string,
        ~lineType: string,
        ~dataKey: string,
        ~stroke: option(string)=?,
        ~fill: option(string)=?,
        ~fillOpacity: float=1.0,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=area,
      ~props={
        "stackId": stackId,
        "type": lineType,
        "dataKey": dataKey,
        "stroke": Js.Nullable.fromOption(stroke),
        "fill": Js.Nullable.fromOption(fill),
        "fillOpacity": fillOpacity,
      },
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

type optionalDataKey = option(string);

module YAxis = {
  let make = (~dataKey: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=yAxis,
      ~props={"dataKey": Js.Nullable.fromOption(dataKey)},
      children,
    );
};

[@bs.module "recharts"] external legend : ReasonReact.reactClass = "Legend";

module Legend = {
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass=legend, ~props=(), children);
};