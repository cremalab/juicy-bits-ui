open BsStorybook.Main;

let _module = [%bs.raw "module"];

let default = () => {
  let myStory =
    createStory(
      ~title="CardPreview",
      ~decorators=[Utils.Decorators.global, Utils.Decorators.padded(`six)],
      ~_module,
      (),
    );
  myStory.add("Default", () =>
    <CardPreview
      title="Hello"
      description="This is my description."
      route=Config.Routes.Fields
      content={<div> (ReasonReact.string("Hi")) </div>}
    />
  );
};