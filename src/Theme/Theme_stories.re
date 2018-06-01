open BsStorybook.Main;
open Utils;

let _module = [%bs.raw "module"];
module Style = {
  open Theme;
  let swatchPadding = Css.padding(px_of_spacing(`five));
  let container = Css.(style([display(flexBox)]));
  let swatch = Css.(style([flexBasis(px(100))]));
  let color = (col: color, mix: colorMix, step: colorStep) =>
    Css.(
      style([
        backgroundColor(hex_of_color(~step, ~mix, col)),
        swatchPadding,
      ])
    );
};

let stepsOrderedByMix =
  Theme.(
    (m: colorMix, ss) =>
      switch (m) {
      | Tint => ss |> List.rev
      | Shade => ss
      }
  );

type mix =
  | Mix(Theme.color, Theme.colorMix, Theme.colorStep);

type swatch =
  | Swatch(Theme.color, list(mix));

let generateSwatches =
    (
      colors: list(Theme.color),
      mixes: list(Theme.colorMix),
      steps: list(Theme.colorStep),
    )
    : list(swatch) =>
  colors
  |> List.map(c =>
       Swatch(
         c,
         mixes
         |> List.map(m =>
              steps |> stepsOrderedByMix(m) |> List.map(s => Mix(c, m, s))
            )
         |> List.concat,
       )
     );

let mixToColor = mix =>
  switch (mix) {
  | Mix(color, mix, step) =>
    <div className=(Style.color(color, mix, step)) />
  };

let swatchToElement = swatch =>
  switch (swatch) {
  | Swatch(_, mixes) =>
    <div className=Style.swatch>
      (mixes |> List.map(mixToColor) |> elementOfList)
    </div>
  };

let default = () => {
  let myStory =
    createStory(
      ~title="Theme",
      ~decorators=[Utils.Decorators.global, Utils.Decorators.padded(`six)],
      ~_module,
      (),
    );
  myStory.add("Colors", () => {
    open Theme;
    let colors = [`black, `white, `yellow, `blue];
    let mixes = [Tint, Shade];
    let steps = [`zero, `one, `two, `three];

    let swatches: list(swatch) = generateSwatches(colors, mixes, steps);

    <div className=Style.container>
      (swatches |> List.map(swatchToElement) |> elementOfList)
    </div>;
  });
};