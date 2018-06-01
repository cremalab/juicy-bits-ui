open BsStorybook.Main;

let _module = [%bs.raw "module"];

let default = () => {
  let myStory =
    createStory(
      ~title="Card",
      ~decorators=[Utils.Decorators.global, Utils.Decorators.padded(`six)],
      ~_module,
      (),
    );
  myStory.add("Default", () =>
    <Card
      header=(ReasonReact.string("Header"))
      main=(ReasonReact.string("Main"))
      footer=(ReasonReact.string("Footer"))
    />
  );
  myStory.add("Without header", () =>
    <Card
      main=(ReasonReact.string("Main"))
      footer=(ReasonReact.string("Footer"))
    />
  );
  myStory.add("Without footer", () =>
    <Card main=(ReasonReact.string("Main")) />
  );
};