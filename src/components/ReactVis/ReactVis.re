[@bs.module "react-vis"]
external makeVisFlexible : ReasonReact.reactClass => ReasonReact.reactClass =
  "makeVisFlexible";

[@bs.module "react-vis"]
external radarChart : ReasonReact.reactClass = "RadarChart";

module RadarChart = {
  type domain('a) = {
    .
    "name": string,
    "getValue": 'a => float,
    "domain": array(float),
    "tickFormat": float => string,
  };
  let make =
      (
        ~width: option(int)=?,
        ~height: option(int)=?,
        ~data: array('a),
        ~domains: array(domain('a)),
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=radarChart,
      ~props={
        "width": Js.Nullable.fromOption(width),
        "height": Js.Nullable.fromOption(height),
        "data": data,
        "domains": domains,
      },
      children,
    );
};

module RadarChartFlexible = {
  type domain('a, 'b) = {
    .
    "name": string,
    "getValue": 'a => 'b,
    "domain": array(float),
    "tickFormat": float => string,
  };
  let make = (~data: array('a), ~domains: array(domain('a, 'b)), children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=makeVisFlexible(radarChart),
      ~props={"data": data, "domains": domains},
      children,
    );
};

[@bs.module "react-vis"] external xYPlot : ReasonReact.reactClass = "XYPlot";

module XYPlot = {
  let make = (~width: option(int)=?, ~height: option(int)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=xYPlot,
      ~props={
        "width": Js.Nullable.fromOption(width),
        "height": Js.Nullable.fromOption(height),
      },
      children,
    );
};

module XYPlotFlexible = {
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=makeVisFlexible(xYPlot),
      ~props=(),
      children,
    );
};

[@bs.module "react-vis"]
external lineSeries : ReasonReact.reactClass = "LineSeries";

module LineSeries = {
  let make =
      (
        ~data: array('a),
        ~color: option(string)=?,
        ~stroke: option(string)=?,
        ~fill: option(string)=?,
        ~opacity: option(float)=?,
        ~getX: option('a => float)=?,
        ~getY: option('a => float)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=lineSeries,
      ~props={
        "data": data,
        "getX": Js.Nullable.fromOption(getX),
        "getY": Js.Nullable.fromOption(getY),
        "opacity": Js.Nullable.fromOption(opacity),
        "color": Js.Nullable.fromOption(color),
        "stroke": Js.Nullable.fromOption(stroke),
        "fill": Js.Nullable.fromOption(fill),
      },
      children,
    );
};

[@bs.module "react-vis"]
external areaSeries : ReasonReact.reactClass = "AreaSeries";

module AreaSeries = {
  let make =
      (
        ~data: array('a),
        ~color: option(string)=?,
        ~stroke: option(string)=?,
        ~fill: option(string)=?,
        ~opacity: option(float)=?,
        ~getX: option('a => float)=?,
        ~getY: option('a => float)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=areaSeries,
      ~props={
        "data": data,
        "getX": Js.Nullable.fromOption(getX),
        "getY": Js.Nullable.fromOption(getY),
        "opacity": Js.Nullable.fromOption(opacity),
        "color": Js.Nullable.fromOption(color),
        "stroke": Js.Nullable.fromOption(stroke),
        "fill": Js.Nullable.fromOption(fill),
      },
      children,
    );
};

[@bs.module "react-vis"]
external verticalBarSeries : ReasonReact.reactClass = "VerticalBarSeries";

module VerticalBarSeries = {
  let make =
      (
        ~data: array('a),
        ~color: option(string)=?,
        ~stroke: option(string)=?,
        ~fill: option(string)=?,
        ~opacity: option(float)=?,
        ~getX: option('a => float)=?,
        ~getY: option('a => float)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=verticalBarSeries,
      ~props={
        "data": data,
        "getX": Js.Nullable.fromOption(getX),
        "getY": Js.Nullable.fromOption(getY),
        "opacity": Js.Nullable.fromOption(opacity),
        "color": Js.Nullable.fromOption(color),
        "stroke": Js.Nullable.fromOption(stroke),
        "fill": Js.Nullable.fromOption(fill),
      },
      children,
    );
};

[@bs.module "react-vis"]
external horizontalBarSeries : ReasonReact.reactClass = "HorizontalBarSeries";

module HorizontalBarSeries = {
  let make =
      (
        ~data: array('a),
        ~color: option(string)=?,
        ~stroke: option(string)=?,
        ~fill: option(string)=?,
        ~opacity: option(float)=?,
        ~getX: option('a => float)=?,
        ~getY: option('a => float)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=horizontalBarSeries,
      ~props={
        "data": data,
        "getX": Js.Nullable.fromOption(getX),
        "getY": Js.Nullable.fromOption(getY),
        "opacity": Js.Nullable.fromOption(opacity),
        "color": Js.Nullable.fromOption(color),
        "stroke": Js.Nullable.fromOption(stroke),
        "fill": Js.Nullable.fromOption(fill),
      },
      children,
    );
};

[@bs.module "react-vis"]
external horizontalGridLines : ReasonReact.reactClass = "HorizontalGridLines";

module HorizontalGridLines = {
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=horizontalGridLines,
      ~props=(),
      children,
    );
};

[@bs.module "react-vis"]
external verticalGridLines : ReasonReact.reactClass = "VerticalGridLines";

module VerticalGridLines = {
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=verticalGridLines,
      ~props=(),
      children,
    );
};

[@bs.module "react-vis"] external xAxis : ReasonReact.reactClass = "XAxis";

module XAxis = {
  let make = (~title: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=xAxis,
      ~props={"title": Js.Nullable.fromOption(title)},
      children,
    );
};

[@bs.module "react-vis"] external yAxis : ReasonReact.reactClass = "YAxis";

module YAxis = {
  let make = (~title: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=yAxis,
      ~props={"title": Js.Nullable.fromOption(title)},
      children,
    );
};