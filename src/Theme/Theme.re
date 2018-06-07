module Color = {
  let blue = Css.hsl(210, 97);
  let yellow = Css.hsl(46, 97);
};

type step = [ | `zero | `one | `two | `three | `four | `five | `six | `seven];

type spacing = step;

type heading = [ | `h1 | `h2 | `h3 | `h4 | `h5 | `h6];

type colorStep = [ | `zero | `one | `two | `three];

type colorMix =
  | Shade
  | Tint;

type color = [ | `black | `white | `yellow | `blue];

let join = (separator, strings) => {
  let rec run = (acc, strings) =>
    switch (strings) {
    | [] => acc
    | [x] => acc ++ x
    | [x, ...xs] => run(acc ++ x ++ separator, xs)
    };
  run("", strings);
};

let string_of_color =
  fun
  | `rgb(r, g, b) =>
    "rgb("
    ++ join(", ", [string_of_int(r), string_of_int(g), string_of_int(b)])
    ++ ")"
  | `rgba(r, g, b, a) =>
    "rgba("
    ++ join(
         ", ",
         [
           string_of_int(r),
           string_of_int(g),
           string_of_int(b),
           string_of_float(a),
         ],
       )
    ++ ")"
  | `hsl(h, s, l) =>
    "hsl("
    ++ join(
         ", ",
         [
           string_of_int(h),
           string_of_int(s) ++ "%",
           string_of_int(l) ++ "%",
         ],
       )
    ++ ")"
  | `hsla(h, s, l, a) =>
    "hsla("
    ++ join(
         ", ",
         [
           string_of_int(h),
           string_of_int(s) ++ "%",
           string_of_int(l) ++ "%",
           string_of_float(a),
         ],
       )
    ++ ")"
  | `hex(s) => "#" ++ s
  | `transparent => "transparent"
  | `currentColor => "currentColor";

let int_of_colorStep = (step: colorStep, mix: colorMix) =>
  switch (step, mix) {
  | (`zero, Shade) => 0
  | (`zero, Tint) => 0
  | (`one, Shade) => 1
  | (`one, Tint) => 1
  | (`two, Shade) => 2
  | (`two, Tint) => 2
  | (`three, Shade) => 3
  | (`three, Tint) => 3
  };

let px_of_spacing = (s: spacing) =>
  switch (s) {
  | `zero => Css.px(0)
  | `one => Css.px(1)
  | `two => Css.px(2)
  | `three => Css.px(4)
  | `four => Css.px(8)
  | `five => Css.px(10)
  | `six => Css.px(16)
  | `seven => Css.px(20)
  };

let fontSize_of_heading = (s: heading) =>
  switch (s) {
  | `h1 => Css.px(28)
  | `h2 => Css.px(24)
  | `h3 => Css.px(20)
  | `h4 => Css.px(18)
  | `h5 => Css.px(16)
  | `h6 => Css.px(14)
  };

let hex_of_black = (step: colorStep, mix: colorMix) : Css.color =>
  switch (step, mix) {
  | (`three, Tint) => Css.hsl(210, 10, 20)
  | (`two, Tint) => Css.hsl(210, 10, 15)
  | (`one, Tint) => Css.hsl(210, 10, 10)
  | (`zero, Tint)
  | (_, Shade) => Css.hsl(210, 10, 0)
  };

let hex_of_white = (step: colorStep, mix: colorMix) : Css.color =>
  switch (step, mix) {
  | (_, Tint)
  | (`zero, Shade) => Css.hsl(210, 10, 100)
  | (`one, Shade) => Css.hsl(210, 10, 95)
  | (`two, Shade) => Css.hsl(210, 10, 90)
  | (`three, Shade) => Css.hsl(210, 10, 85)
  };

let hex_of_yellow = (step: colorStep, mix: colorMix) : Css.color => {
  let baseColor = Color.yellow;
  switch (step, mix) {
  | (`three, Tint) => baseColor(80)
  | (`two, Tint) => baseColor(75)
  | (`one, Tint) => baseColor(70)
  | (`zero, Shade | Tint) => baseColor(65)
  | (`one, Shade) => baseColor(60)
  | (`two, Shade) => baseColor(55)
  | (`three, Shade) => baseColor(50)
  };
};

let hex_of_blue = (step: colorStep, mix: colorMix) : Css.color => {
  let baseColor = Color.blue;
  switch (step, mix) {
  | (`three, Tint) => baseColor(80)
  | (`two, Tint) => baseColor(75)
  | (`one, Tint) => baseColor(70)
  | (`zero, Shade | Tint) => baseColor(65)
  | (`one, Shade) => baseColor(60)
  | (`two, Shade) => baseColor(55)
  | (`three, Shade) => baseColor(50)
  };
};

let hex_of_color =
    (~step: colorStep=`zero, ~mix: colorMix=Shade, color: [> color]) =>
  switch (color) {
  | `black => hex_of_black(step, mix)
  | `white => hex_of_white(step, mix)
  | `yellow => hex_of_yellow(step, mix)
  | `blue => hex_of_blue(step, mix)
  };

module Global = {
  open Css;
  let base = [
    margin(px(0)),
    width(pct(100.0)),
    height(pct(100.0)),
    fontFamily("Helvetica"),
  ];
  let styles = style(base);
  global("html, body, #root", base);
};