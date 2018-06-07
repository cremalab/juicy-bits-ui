open BsStorybook.Main;

let _module = [%bs.raw "module"];

let default = () => {
  let myStory =
    createStory(
      ~title="Heading",
      ~decorators=[Utils.Decorators.global, Utils.Decorators.padded(`six)],
      ~_module,
      (),
    );
  myStory.add("Scale", () =>
    <div>
      <Heading level=`h1 text="Hello" />
      <Heading level=`h2 text="Hello" />
      <Heading level=`h3 text="Hello" />
      <Heading level=`h4 text="Hello" />
      <Heading level=`h5 text="Hello" />
      <Heading level=`h6 text="Hello" />
    </div>
  );
};