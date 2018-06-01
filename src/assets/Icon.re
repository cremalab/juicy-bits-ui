module ArrowRight = {
  open Theme;
  let component = ReasonReact.statelessComponent("ArrowRight");

  let make = (~fill: color=`black, ~size: int=24, _chilren) => {
    ...component,
    render: _self =>
      <svg
        fill=(hex_of_color(fill) |> string_of_color)
        xmlns="http://www.w3.org/2000/svg"
        width=(size |> string_of_int)
        height=(size |> string_of_int)
        viewBox="0 0 24 24">
        <path d="M8.59 16.34l4.58-4.59-4.58-4.59L10 5.75l6 6-6 6z" />
      </svg>,
  };
};