let component = ReasonReact.statelessComponent("App");
let make = (_children) => {
  ...component,
  render: _ =>
    <>
      <Weeks />
      <Footer />
    </>,
};
