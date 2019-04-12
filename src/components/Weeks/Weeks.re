type state = {
    time: string,
    timerId: ref(option(Js.Global.intervalId)),
};

type action = Update;

let component = ReasonReact.reducerComponent("Weeks");
let make = (_children) => {
    ...component,

    initialState: () => {
        time: Js.Date.make() |> Js.Date.toLocaleString,
        timerId: ref(None),
    },

    reducer: (action, state) =>
        switch(action) {
        | Update => ReasonReact.Update({...state, time: Js.Date.make() |> Js.Date.toLocaleString})
        },

    didMount: (self) => {
        self.state.timerId := Some(Js.Global.setInterval(() => {
            self.send(Update);
        }, 1000));
    },

    willUnmount: (self) => 
        switch(self.state.timerId^) {
        | Some(id) => Js.Global.clearInterval(id);
        | None => Js.log("Error clearing interval");
    },

    render: (self) =>
        <div className="Weeks">
            <div className="Weeks__week-number">
                {ReasonReact.string(Js.Float.toString(WeekOfYear.getNumberOfWeek(Js.Date.make())))}
            </div>
            <div className="Weeks__week-date-time">
                {ReasonReact.string(self.state.time)}
            </div>
        </div>,
};