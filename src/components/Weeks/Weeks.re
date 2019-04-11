let component = ReasonReact.statelessComponent("Weeks");
let make = (_children) => {
  ...component,
  render: _ =>
    <div className="Weeks">
      {ReasonReact.string(Js.Float.toString(WeekOfYear.getNumberOfWeek(Js.Date.make())))}
    </div>,
};
