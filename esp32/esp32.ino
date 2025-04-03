/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/
// Load Wi-Fi library
#include <WiFi.h>
// Replace with your network credentials
const char* ssid = "realme"; // tên wifi
const char* password = "hieu1234"; // password của wifi
// Set web server port number to 80
WiFiServer server(80);
// Variable to store the HTTP request
String header;
// Auxiliar variables to store the current output state
String output33State = "off";
String output25State = "off";
String output26State = "off";
String output27State = "off";
// Assign output variables to GPIO pins
const int output33 = 33;
const int output25 = 25;
const int output26 = 26;
const int output27 = 27;
// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;
void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output33, OUTPUT);
  pinMode(output25, OUTPUT);
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output33, HIGH);
  digitalWrite(output25, HIGH);
  digitalWrite(output26, HIGH);
  digitalWrite(output27, HIGH);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}
void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients
  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            // turns the GPIOs on and off
            if (header.indexOf("GET /33/on") >= 0) {
              Serial.println("GPIO 33 on");
              output33State = "on";
              digitalWrite(output33, LOW);
              delay(1000);
              digitalWrite(output33, HIGH);
            } 
            else if (header.indexOf("GET /25/on") >= 0) {
              Serial.println("GPIO 25 on");
              output25State = "on";
              digitalWrite(output25, LOW);
              delay(1000);
              digitalWrite(output25, HIGH);
            } 
            else if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output26, LOW);
              delay(500);
              digitalWrite(output26, HIGH);
            } 
            else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output27, LOW);
              delay(500);
              digitalWrite(output27, HIGH);
            } 
            // HTML content
            client.println("<!DOCTYPE html>");
client.println("<html lang=\"en\">");
client.println("<head>");
client.println("    <meta charset=\"UTF-8\">");
client.println("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
client.println("    <style>");
client.println("        body {");
client.println("            background-color: white;");
client.println("            font-family: Arial, sans-serif;");
client.println("        }");
client.println("        #wrapper {");
client.println("            max-width: 960px;");
client.println("            margin: 0 auto;");
client.println("            text-align: center;");
client.println("        }");
client.println("        #header {");
client.println("            padding: 20px;");
client.println("            color: black;");
client.println("        }");
client.println("        .button {");
client.println("            border: 2px solid #4CAF50;");
client.println("            padding: 15px 30px;");
client.println("            color: #4CAF50;");
client.println("            font-size: 16px;");
client.println("            background-color: white;");
client.println("            border-radius: 8px;");
client.println("            text-decoration: none;");
client.println("            margin: 10px;");
client.println("            transition: all 0.3s;");
client.println("        }");
client.println("        .button:hover {");
client.println("            background-color: #4CAF50;");
client.println("            color: white;");
client.println("        }");
client.println("    </style>");
client.println("    <title>Traffic Light Project</title>");
client.println("</head>");
client.println("<body>");
client.println("    <div id=\"wrapper\">");
client.println("        <div id=\"header\">");
client.println("            <h1>TRAFFIC LIGHT PROJECT</h1>");
client.println("        </div>");
client.println("        <div id=\"button\">");
client.println("            <a href=\"/33/on\" class=\"button\">BUTTON 0</a>");
client.println("            <a href=\"/25/on\" class=\"button\">BUTTON 1</a>");
client.println("            <a href=\"/26/on\" class=\"button\">BUTTON 2</a>");
client.println("            <a href=\"/27/on\" class=\"button\">BUTTON 3</a>");
client.println("        </div>");
client.println("    </div>");
client.println("</body>");
client.println("</html>");

            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection

    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}