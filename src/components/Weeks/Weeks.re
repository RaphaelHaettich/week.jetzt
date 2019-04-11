[@bs.val] external alert : string => unit = "alert";
let component = ReasonReact.statelessComponent("Weeks");
let handleClick = (_event, _self) => {
  alert(Js.Float.toString(WeekOfYear.getNumberOfWeek(Js.Date.make())));
};
let make = (~messages, _children) => {
  ...component,
  render: self =>
    <div className="Weeks" onClick={self.handle(handleClick)}>
      {ReasonReact.string(messages)}
    </div>,
};
