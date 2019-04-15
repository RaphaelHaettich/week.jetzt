let component = ReasonReact.statelessComponent("Footer");
let make = (_children) => {
  ...component,
  render: _ =>
    <div className="Footer">
        {ReasonReact.string("Photo from ")}
        <a className="Footer__link" href="https://unsplash.com/collections/4643953/">
            {ReasonReact.string("Unsplash")}
        </a>
    </div>,
};
