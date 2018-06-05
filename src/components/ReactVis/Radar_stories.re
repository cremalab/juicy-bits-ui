open BsStorybook.Main;

type data('a) = {
  .
  "name": string,
  "fields": array(dataField('a)),
}
and dataField('a) = {
  .
  "name": string,
  "value": 'a,
};

type field = {. "name": string};

let id = (x: 'a) : 'a => x;

let _module = [%bs.raw "module"];

let default = () => {
  let myStory =
    createStory(~title="RadarChart", ~decorators=[], ~_module, ());
  myStory.add("example", () => {
    module Styles = {
      let wrapper = Css.(style([height(px(500)), width(px(500))]));
    };
    let data: array(data(int)) = [|
      {
        "name": "Blake",
        "fields": [|
          {"name": "JS", "value": 20},
          {"name": "React", "value": 13},
          {"name": "CSS", "value": 10},
        |],
      },
      {
        "name": "Rob",
        "fields": [|
          {"name": "JS", "value": 20},
          {"name": "React", "value": 15},
          {"name": "CSS", "value": 5},
        |],
      },
    |];
    let fields = [|{"name": "JS"}, {"name": "React"}, {"name": "CSS"}|];
    let domain_of_field =
        (field: field)
        : ReactVis.RadarChart.domain(data(int)) => {
      "name": field##name,
      "domain": [|0.0, 20.0|],
      "getValue": data =>
        Array.fold_left(
          (value, dataField) =>
            dataField##name == field##name ?
              dataField##value |> float_of_int : value,
          0.0,
          data##fields,
        ),
      "tickFormat": x => x |> int_of_float |> string_of_int,
    };
    let domains = fields |> Array.map(domain_of_field);
    <div className=Styles.wrapper>
      <ReactVis.RadarChartFlexible data domains />
    </div>;
  });
};