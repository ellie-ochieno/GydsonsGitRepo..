const int pingPin = 8; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 7; // Echo Pin of Ultrasonic Sensor

float duration, inches, cm, ft;
  
float overflow_lvl, full_lvl, half_lvl, low_lvl, empty_lvl, tank_height, calibrator_unit;
  //level control variables
tank_height = 8.0;
  //tank height dfn
   
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   ft = microsecondsToCentimeters(duration) * 0.0328084;
   Serial.print(inches, 2);
   Serial.print("in, ");
   Serial.print(cm, 2);
   Serial.print("cm, ");
   Serial.print(ft, 2);
   Serial.print("ft");
   Serial.println();
   delay(1000);
}

float microsecondsToInches(float microseconds) {
   return microseconds / 74 / 2;
}

float microsecondsToCentimeters(float microseconds) {
   return microseconds / 29 / 2;
}


void level_calibrate(){
  
    float overflow_lvl, full_lvl, half_lvl, low_lvl, empty_lvl, tank_height;
      //level control variables
    tank_height = 8.0;
      //tank height dfn
      
    overflow_lvl = 2.4;
    full_lvl     = 3.6;
    half_lvl     = 4.8;
    low_lvl      = 6.0;
    empty_lvl    = 7.2;
     if (cm>=2.4)//max possible water level
     {
       {
         lcd.setCursor(1, 0);     //sets LCD cursor ready for display
         lcd.print("  OVERFLOW   ");
                                  //display info
       }
      if (cm>=3.6)
      {
       {
         lcd.setCursor(1, 0);     //sets LCD cursor ready for display
         lcd.print("  TANK FULL  ");
                                  //display info
       }
      if (cm>=4.8)
     {
      {
       lcd.setCursor(1, 0);     //sets LCD cursor ready for display
       lcd.print("  HALF FILLED  ");
                                //display info
      }
     if (cm>=6)
     {
      {
       lcd.setCursor(1, 0);     //sets LCD cursor ready for display
       lcd.print("    FILLING    ");
                                //display info
      }
     if(cm>7.2)
     {
      {
       lcd.setCursor(1, 0);     //sets LCD cursor ready for display
       lcd.print("  TANK EMPTY   ");
                                //display info
      }
       }}}}}
  }
