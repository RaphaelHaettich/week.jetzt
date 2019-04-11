[@bs.val] external alert : string => unit = "alert";
let component = ReasonReact.statelessComponent("Weeks");
let make = (_children) => {
  ...component,
  render: self =>
    <div className="Weeks">
      {ReasonReact.string(Js.Float.toString(WeekOfYear.getNumberOfWeek(Js.Date.make())))}
    </div>,
};
