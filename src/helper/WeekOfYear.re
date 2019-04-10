let getNumberOfWeek = (date) => {
    let firstDayOfYear = Js.Date.makeWithYMD(~year = Js.Date.getFullYear(date), ~month = 0.0, ~date = 1.0, ());
  	let pastDaysOfYearFloat = (Js.Date.getTime(date) -. Js.Date.getTime(firstDayOfYear)) /. 86400000.0;
 	ceil((pastDaysOfYearFloat +. Js.Date.getDay(firstDayOfYear) +. 1.0) /. 7.0);
}