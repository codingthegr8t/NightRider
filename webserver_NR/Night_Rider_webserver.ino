#include <SPI.h>
#include <WiFi.h>
#include "analogWrite.h"

int pinArray[] = {4, 16, 17, 5, 18, 23, 19, 22};
int count = 0;
int timer;

char ssid[] = "Where is Waldo";      //  your network SSID (name)
char pass[] = "";   // your network password
//int keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  for (count=0;count<8;count++) {
  pinMode(pinArray[count], OUTPUT);
  }
//
//  // check for the presence of the shield:
//  if (WiFi.status() == WL_NO_SHIELD) {
//    Serial.println("WiFi shield not present");
//    while (true);       // don't continue
//  }

//  String fv = WiFi.firmwareVersion();
//  if (fv != "1.1.0") {
//    Serial.println("Please upgrade the firmware");
//  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid,pass);
    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();                           // start the web server on port 80
  printWifiStatus();                        // you're connected now, so print out the status
}


void loop() {
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/ALIFE\">here</a> start Nightrider Standaard<br>");
            client.print("Click <a href=\"/LOW\">here</a> Nightrider naar recht<br>");
            client.print("Click <a href=\"/HIGH\">here</a> Nightrider naar links<br>");
            client.print("Click <a href=\"/SPEED\">here</a> Nightrider booster<br>");
            client.print("Click <a href=\"/SLEEP\">here</a> Nightrider chill<br>");
            client.print("Click <a href=\"/WILD\">here</a> Nightrider all out<br>");


            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request is "GET /NameExample":
        if (currentLine.endsWith("GET /ALIFE")) {
          f_ledStandaard();
        }
        if (currentLine.endsWith("GET /LOW")) {
          f_ledRechts();
        }
        if (currentLine.endsWith("GET /HIGH")) {
          f_ledLinks();
        }
        if (currentLine.endsWith("GET /SPEED")) {
          f_Booster();
        }
        if (currentLine.endsWith("GET /SLEEP")) {
          f_Chill();
        }
        if (currentLine.endsWith("GET /WILD")) {
          f_ledStandaard();
          f_ledRechts();
          f_ledLinks();
          f_Booster();
          f_Chill();
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}
