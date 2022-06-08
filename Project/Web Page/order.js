 /*var request = new XMLHttpRequest();


request.onreadystatechange = function() {
  jsontext = request.responseText;
    if(jsontext.length > 0) {
        data = jsontext;
        
        console.log(jsontext);
    }
    

  //alert(jsontext);
}

request.open("GET", "https://api.thingspeak.com/channels/1338874/fields/1.json?api_key=LT3CGD9ASCQ1NZRP&results=2", true);

request.send();


var data = request.responseText;
var text;
if(data > 0) text = data;

console.log("type = " + typeof text); 






var request = new XMLHttpRequest();
request.open("GET", "https://api.thingspeak.com/update?api_key=IOJ3PZBVM9E7IOQI&field1=333", true);
request.send();
console.log(request);


request.onreadystatechange = function() {
  jsontext = request.responseText;
    
    

  alert(jsontext);
}


*/

request = new XMLHttpRequest();

request.onreadystatechange = function() {
  jsontext = request.responseText;
}

var random = Math.floor(Math.random() * 1000000);
var link = "https://api.thingspeak.com/update?api_key=IOJ3PZBVM9E7IOQI&field1=" + random;

request.open("GET", link, true);
request.send();