let component = ReasonReact.statelessComponent("Weeks");
let make = (_children) => {
  ...component,
  render: _ =>
    <div className="Weeks">
      <div className="Weeks__week-number">
        {ReasonReact.string(Js.Float.toString(WeekOfYear.getNumberOfWeek(Js.Date.make())))}
      </div>
      <div className="Weeks__week-date-time">
        {ReasonReact.string(Js.Date.make()|>Js.Date.toLocaleString)}
      </div>
    </div>,
};
