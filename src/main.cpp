#include <WiFi.h>

const char* ssid = "WIFI_SSID";
const char* password = "WIFI_PASSWORD";

WiFiServer server(80);
const int ledPin = 2;

void setup() {
  Serial.begin(115200);
  delay(10000);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  digitalWrite(4,HIGH);
  Serial.println("\nConnected to WiFi");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/on") != -1) {
      digitalWrite(ledPin, HIGH);
    } else if (request.indexOf("/off") != -1) {
      digitalWrite(ledPin, LOW);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html; charset=UTF-8");
    client.println("Connection: close\r\n");

    client.println(R"rawliteral(
     <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="Stylesheet" href="styles.css">
    <style>
        body{
    height: 100vh;
    width: 100vw;
    overflow: hidden;
    display: flex;
    justify-content: center;
    align-items: center;
    color: white;
    background-image: url('https://images.unsplash.com/photo-1519681393784-d120267933ba?ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&auto=format&fit=crop&w=1124&q=100');
    background-repeat: no-repeat;
    background-size:cover;
}

.container{
    height:fit-content;
    width:fit-content;
    backdrop-filter: blur(4px) ;
    -webkit-backdrop-filter: blur(4px) ;
    background-color: rgba(17, 25, 40, 0.41);
    border-radius: 35px;
    border: 1px solid rgba(0, 0, 0, 0.125);
    display: flex;
    justify-content: center;
    align-items: center;
    flex-direction: column;
    padding: 0.6em;
    gap:0.5em;
    transition: all 0.5s cubic-bezier(0.075, 0.82, 0.165, 1);
    cursor: pointer;
    box-shadow: rgba(0, 0, 0, 0.779) 3px 3px 15px;
}
.container:hover{
    transform: translateY(-8%);
    scale: 1.1;
    background-color: rgba(17, 25, 40, 0.61);
    box-shadow: rgba(0, 0, 0, 0.779) 10px 10px 15px;
}

.container:active{
    transition: all 0.2s cubic-bezier(0.075, 0.82, 0.165, 1);
    transform: translateY(3%);
    scale: 0.95;
    background-color: rgba(17, 25, 40, 0.61);
    box-shadow: rgba(0, 0, 0, 0.779) 5px 5px 15px;
}

button{
    display: flex;
    justify-content: center;
    align-items: center;
    font-size: 2em;
    font-family:Verdana;
    height: 12vh;
    width: 12vh;
    flex-direction: column;
    -webkit-user-select: none; /* Safari */
    -ms-user-select: none; /* IE 10 and IE 11 */
    user-select: none; /* Standard syntax */
    background-color: rgba(0, 0, 0, 0);
    border: none;
    cursor: pointer;
}


button svg{
    width: 100%;
    aspect-ratio: 1/1;
}

    </style>
</head>
<body>
    <div class="root">
        <div class="container">
            <div class="Button-container">
                <button id="Button" class="light">
                    <svg xmlns="http://www.w3.org/2000/svg" width="56" height="56" viewBox="0 0 56 56" fill="none">
<path d="M28.2422 24.2422C29.7422 24.2422 30.9844 23 30.9844 21.5C30.9844 19.9765 29.7422 18.7578 28.2422 18.7578C26.7188 18.7578 25.5 19.9765 25.5 21.5C25.5 23 26.7188 24.2422 28.2422 24.2422ZM38.1329 28.8671C39.1876 29.9453 40.9219 29.9453 42 28.8671C43.0782 27.7656 43.0782 26.0546 42 25C40.8985 23.9218 39.211 23.8984 38.1329 25C37.0548 26.0546 37.0548 27.789 38.1329 28.8671ZM13.5 28.3675C14.5547 29.4456 16.2891 29.4456 17.3672 28.3675C18.4687 27.2659 18.4687 25.5549 17.3672 24.5003C16.2656 23.4222 14.5781 23.3987 13.5 24.5003C12.4219 25.5549 12.3984 27.2659 13.5 28.3675ZM10.7578 41.43C12.2578 41.43 13.5 40.1878 13.5 38.6878C13.5 37.1643 12.2578 35.9456 10.7578 35.9456C9.23442 35.9456 8.01562 37.1643 8.01562 38.6878C8.01562 40.1878 9.23442 41.43 10.7578 41.43ZM45.5 41.5C47 41.5 48.2423 40.2578 48.2423 38.7578C48.2423 37.2344 47 36.0156 45.5 36.0156C43.9765 36.0156 42.7577 37.2344 42.7577 38.7578C42.7577 40.2578 43.9765 41.5 45.5 41.5ZM20.1016 36.719C19.0235 36.719 18.1095 37.6097 18.1095 38.6878C18.1095 39.7425 19.0235 40.6331 20.1016 40.6331H35.8282C36.9064 40.6331 37.8204 39.7425 37.8204 38.6878C37.8204 37.6097 36.9064 36.719 35.8282 36.719H20.1016Z" fill="white"/>
</svg>
                </button>
            </div>
        </div>
    </div>
    <script>
        const Button = document.getElementById("Button");
let Button_state = false;

Button.addEventListener("click", function(){

    if(Button_state){
        Button_state=false;
        Button.innerHTML=`<svg xmlns="http://www.w3.org/2000/svg" width="56" height="56" viewBox="0 0 56 56" fill="none"><path d="M28.2422 24.2422C29.7422 24.2422 30.9844 23 30.9844 21.5C30.9844 19.9765 29.7422 18.7578 28.2422 18.7578C26.7188 18.7578 25.5 19.9765 25.5 21.5C25.5 23 26.7188 24.2422 28.2422 24.2422ZM38.1329 28.8671C39.1876 29.9453 40.9219 29.9453 42 28.8671C43.0782 27.7656 43.0782 26.0546 42 25C40.8985 23.9218 39.211 23.8984 38.1329 25C37.0548 26.0546 37.0548 27.789 38.1329 28.8671ZM13.5 28.3675C14.5547 29.4456 16.2891 29.4456 17.3672 28.3675C18.4687 27.2659 18.4687 25.5549 17.3672 24.5003C16.2656 23.4222 14.5781 23.3987 13.5 24.5003C12.4219 25.5549 12.3984 27.2659 13.5 28.3675ZM10.7578 41.43C12.2578 41.43 13.5 40.1878 13.5 38.6878C13.5 37.1643 12.2578 35.9456 10.7578 35.9456C9.23442 35.9456 8.01562 37.1643 8.01562 38.6878C8.01562 40.1878 9.23442 41.43 10.7578 41.43ZM45.5 41.5C47 41.5 48.2423 40.2578 48.2423 38.7578C48.2423 37.2344 47 36.0156 45.5 36.0156C43.9765 36.0156 42.7577 37.2344 42.7577 38.7578C42.7577 40.2578 43.9765 41.5 45.5 41.5ZM20.1016 36.719C19.0235 36.719 18.1095 37.6097 18.1095 38.6878C18.1095 39.7425 19.0235 40.6331 20.1016 40.6331H35.8282C36.9064 40.6331 37.8204 39.7425 37.8204 38.6878C37.8204 37.6097 36.9064 36.719 35.8282 36.719H20.1016Z" fill="white"/></svg>`;
        fetch('/off');

      }
    else {
        Button_state = true;
        Button.innerHTML= `<svg fill="#ffffff" viewBox="0 0 56.00 56.00" xmlns="http://www.w3.org/2000/svg" stroke="#ffffff"><g id="SVGRepo_bgCarrier" stroke-width="0"></g><g id="SVGRepo_tracerCarrier" stroke-linecap="round" stroke-linejoin="round"></g><g id="SVGRepo_iconCarrier"><path d="M 30.0392 16.0820 C 30.0392 14.9571 29.1016 14.0195 28.0001 14.0195 C 26.8985 14.0195 25.9610 14.9571 25.9610 16.0820 L 25.9610 22.5976 C 25.9610 23.6992 26.8985 24.6367 28.0001 24.6367 C 29.1016 24.6367 30.0392 23.6992 30.0392 22.5976 Z M 14.1251 28.9492 C 14.8985 29.7461 16.2110 29.7461 16.9845 28.9492 C 17.7813 28.1758 17.7813 26.8633 16.9845 26.0898 L 12.4142 21.4727 C 11.6407 20.6758 10.3282 20.6524 9.5314 21.4492 C 8.7579 22.2227 8.7579 23.5352 9.5314 24.3320 Z M 38.7345 26.3242 C 37.9610 27.0976 37.9610 28.4102 38.7345 29.1836 C 39.5314 29.9805 40.8673 29.9805 41.6407 29.1836 L 46.2577 24.5898 C 47.0550 23.7930 47.0550 22.4571 46.2577 21.6836 C 45.4845 20.8867 44.1720 20.8867 43.3751 21.6836 Z M 51.8593 41.9805 C 52.9609 41.9805 53.8983 41.0430 53.8983 39.9414 C 53.8983 38.8164 52.9609 37.8789 51.8593 37.8789 L 45.3438 37.8789 C 44.2189 37.8789 43.2813 38.8164 43.2813 39.9414 C 43.2813 41.0430 44.2189 41.9805 45.3438 41.9805 Z M 4.1407 37.8789 C 3.0392 37.8789 2.1017 38.8164 2.1017 39.9414 C 2.1017 41.0430 3.0392 41.9805 4.1407 41.9805 L 10.6798 41.9805 C 11.8048 41.9805 12.7423 41.0430 12.7423 39.9414 C 12.7423 38.8164 11.8048 37.8789 10.6798 37.8789 Z M 20.1251 38.0195 C 19.0470 38.0195 18.1329 38.9102 18.1329 39.9883 C 18.1329 41.0430 19.0470 41.9336 20.1251 41.9336 L 35.8516 41.9336 C 36.9298 41.9336 37.8438 41.0430 37.8438 39.9883 C 37.8438 38.9102 36.9298 38.0195 35.8516 38.0195 Z"></path></g></svg>`;
        fetch('/on');
      }
})
    </script>
</body>
</html>
    )rawliteral");
  }
}
