open BsStorybook.Main;

let _module = [%bs.raw "module"];

let default = () => {
  let myStory =
    createStory(
      ~title="P",
      ~decorators=[Utils.Decorators.global, Utils.Decorators.padded(`six)],
      ~_module,
      (),
    );
  myStory.add("Scale", () =>
    <div>
      <P
        text="Lorem ipsum dolor sit amet, tincidunt lacinia condimentum eu mauris, orci laoreet et cras arcu. Arcu justo eleifend, in libero arcu quis, senectus vitae dolor sit nulla tempor consequat. Sed commodo eget feugiat, nunc ac quis. Sed et vivamus non et ut. Eros fusce sociosqu in penatibus, ut orci. Nullam et mauris taciti aliquet, elementum luctus. Molestie sed aliquet, ut curabitur adipiscing, morbi accumsan in sed, nam rhoncus penatibus condimentum taciti gravida. Eros nibh magna ut. Inventore proin dictum faucibus suscipit dolorem, pellentesque in, posuere odio tellus mi mauris orci, rutrum est nulla nibh vitae eget mattis, posuere sit. Libero tellus purus pede dictum faucibus, eu quis euismod justo tempor volutpat."
      />
      <P
        text="Lorem ipsum dolor sit amet, tincidunt lacinia condimentum eu mauris, orci laoreet et cras arcu. Arcu justo eleifend, in libero arcu quis, senectus vitae dolor sit nulla tempor consequat. Sed commodo eget feugiat, nunc ac quis. Sed et vivamus non et ut. Eros fusce sociosqu in penatibus, ut orci. Nullam et mauris taciti aliquet, elementum luctus. Molestie sed aliquet, ut curabitur adipiscing, morbi accumsan in sed, nam rhoncus penatibus condimentum taciti gravida. Eros nibh magna ut. Inventore proin dictum faucibus suscipit dolorem, pellentesque in, posuere odio tellus mi mauris orci, rutrum est nulla nibh vitae eget mattis, posuere sit. Libero tellus purus pede dictum faucibus, eu quis euismod justo tempor volutpat."
      />
      <P
        text="Lorem ipsum dolor sit amet, tincidunt lacinia condimentum eu mauris, orci laoreet et cras arcu. Arcu justo eleifend, in libero arcu quis, senectus vitae dolor sit nulla tempor consequat. Sed commodo eget feugiat, nunc ac quis. Sed et vivamus non et ut. Eros fusce sociosqu in penatibus, ut orci. Nullam et mauris taciti aliquet, elementum luctus. Molestie sed aliquet, ut curabitur adipiscing, morbi accumsan in sed, nam rhoncus penatibus condimentum taciti gravida. Eros nibh magna ut. Inventore proin dictum faucibus suscipit dolorem, pellentesque in, posuere odio tellus mi mauris orci, rutrum est nulla nibh vitae eget mattis, posuere sit. Libero tellus purus pede dictum faucibus, eu quis euismod justo tempor volutpat."
      />
      <P
        text="Lorem ipsum dolor sit amet, tincidunt lacinia condimentum eu mauris, orci laoreet et cras arcu. Arcu justo eleifend, in libero arcu quis, senectus vitae dolor sit nulla tempor consequat. Sed commodo eget feugiat, nunc ac quis. Sed et vivamus non et ut. Eros fusce sociosqu in penatibus, ut orci. Nullam et mauris taciti aliquet, elementum luctus. Molestie sed aliquet, ut curabitur adipiscing, morbi accumsan in sed, nam rhoncus penatibus condimentum taciti gravida. Eros nibh magna ut. Inventore proin dictum faucibus suscipit dolorem, pellentesque in, posuere odio tellus mi mauris orci, rutrum est nulla nibh vitae eget mattis, posuere sit. Libero tellus purus pede dictum faucibus, eu quis euismod justo tempor volutpat."
      />
      <P
        text="Lorem ipsum dolor sit amet, tincidunt lacinia condimentum eu mauris, orci laoreet et cras arcu. Arcu justo eleifend, in libero arcu quis, senectus vitae dolor sit nulla tempor consequat. Sed commodo eget feugiat, nunc ac quis. Sed et vivamus non et ut. Eros fusce sociosqu in penatibus, ut orci. Nullam et mauris taciti aliquet, elementum luctus. Molestie sed aliquet, ut curabitur adipiscing, morbi accumsan in sed, nam rhoncus penatibus condimentum taciti gravida. Eros nibh magna ut. Inventore proin dictum faucibus suscipit dolorem, pellentesque in, posuere odio tellus mi mauris orci, rutrum est nulla nibh vitae eget mattis, posuere sit. Libero tellus purus pede dictum faucibus, eu quis euismod justo tempor volutpat."
      />
      <P
        text="Lorem ipsum dolor sit amet, tincidunt lacinia condimentum eu mauris, orci laoreet et cras arcu. Arcu justo eleifend, in libero arcu quis, senectus vitae dolor sit nulla tempor consequat. Sed commodo eget feugiat, nunc ac quis. Sed et vivamus non et ut. Eros fusce sociosqu in penatibus, ut orci. Nullam et mauris taciti aliquet, elementum luctus. Molestie sed aliquet, ut curabitur adipiscing, morbi accumsan in sed, nam rhoncus penatibus condimentum taciti gravida. Eros nibh magna ut. Inventore proin dictum faucibus suscipit dolorem, pellentesque in, posuere odio tellus mi mauris orci, rutrum est nulla nibh vitae eget mattis, posuere sit. Libero tellus purus pede dictum faucibus, eu quis euismod justo tempor volutpat."
      />
    </div>
  );
};