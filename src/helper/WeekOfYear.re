let getNumberOfWeek = (date : Js.Date.t) => {
    let firstDayOfYear : Js.Date.t = Js.Date.makeWithYMD(~year = Js.Date.getFullYear(date), ~month = 0.0, ~date = 1.0, ());
  	let pastDaysOfYear : float = (Js.Date.getTime(date) -. Js.Date.getTime(firstDayOfYear)) /. 86400000.0;
 	ceil((pastDaysOfYear +. Js.Date.getDay(firstDayOfYear) +. 1.0) /. 7.0);
}