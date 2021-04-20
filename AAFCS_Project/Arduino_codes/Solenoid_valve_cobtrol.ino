//    --------------SOLENOID VALVE CONTROL---------------
   /*
    * This controls the irrigation process 
    * Opens and closes the water outlet tap system using the solenoid valve
    * To be actualized mechanically using a switch and as well remotely using a web supported interface 
    * over the phone or on a PC system.
    */

const int valve = 13;
      //control valve object connect pin on arduino

void setup() {
  pinMode(valve, OUTPUT);
        //valve pin functionality dfn

}

void loop() {
  digitalWrite(valve, HIGH);
        //activates the valve object pin
        //opens the solenoid valve
  delay(2000);
        //keeps the valve in open state for 2s

  digitalWrite(valve, LOW);
        //deactivates the valve object pin
        //closes the solenoid valve
  delay(5000);
        //keeps the valve in closed state for 5s

}
