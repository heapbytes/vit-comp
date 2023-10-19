//3600 seconds
const REQUESTSPERHOUR = 10000000;
let timeForOneRequest = 50; 
let count = 0;
console.log(`time interval for every req:${timeForOneRequest}ms`);
let interval = setInterval(async () => {
  try {
    console.log("sending request number:", count + 1);
    const resp = await fetch("http://192.168.85.151:5000/");
    const data = await resp.json();
    console.log(data);
  } catch (err) {
    console.log(err);
  }
  if (count == REQUESTSPERHOUR) {
    clearInterval(interval);
  }
  count++;
}, timeForOneRequest);
