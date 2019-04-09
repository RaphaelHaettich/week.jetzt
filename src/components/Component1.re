let component = ReasonReact.statelessComponent("Component1");

let handleClick = (_event, _self) => Js.log(WeekOfYear.getNumberOfWeek(Js.Date.make()));
let make = (~messages, _children) => {
  ...component,
  render: self =>
    <div onClick={self.handle(handleClick)}>
      {ReasonReact.string(messages)}
    </div>,
};
