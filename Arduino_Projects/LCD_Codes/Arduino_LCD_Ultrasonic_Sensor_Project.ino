 #include<LiquidCrystal.h>    //reference to the LCD library





                //***************PROJECT: MEASURING OBJECT DISTANCE USING ULTRASONIC SENSOR AND DISPLAYING THE 
                //                        RESULTS ON AN Sparkfun Inventor Kit LCD USING ARDUINO**************
                
        /**
         * In thiis project we'll use the Sparkfun Inventor Kit LCD, Arduino, an Ultrasonic sensor.and a target object.
         * The sensor will be used to calibrate the distance of the target object and the result displayed on an LCD display.
         * The sensor's max accurate measuring distance is approximately 15" = 38.1cm
         * Following the ultrasonic sensor and the LCD projects on arduino board we can wrap up all these together and achieve
         * our main goal in this project.
         * For 
         *                 speed of sound V = 331.4 + 0.6Tc m/s
         *                                                //where Tc denotes temp in degrees C
         *                 thus, at RTP where Tc approx = 25 degrees C
         *                                 
         *                                 V = 331.4 + (0.6 * 25) m/s
         *                                 V = 346.4 m/s
         *                                 
         * For project's cct connection, refer to the 'Arduino_LCD_Ultrasonic_Sensor_Clear_Cct2.png' photograph 
         * in arduino projects dir
         * The potentiometer is involved in the cct to be used as an LCD display light intensity variable i.e making the \
         * dimmer and brighter etc
         */



int trggrPin = 12;          //sensor trigger pin variable assigned to pin 12
int echoPin = 13;           //sensor echo pin variable assigned to pin 13
float pingTime;             //ping signal transit time variable
float trgtDistance;         //to hold object/target distance value from the sensor
float pingSpeed = 346.4;    //ping signal speed in m/s taken as an ultrasound sound wave at RTP

                      //************ULTRASONIC SENSOR PROPERTIES**************

LiquidCrystal MyLCDdisplay(10, 9, 5, 4, 3, 2);   //creates an LCD object 'MyLCDdisplay' with the LCD pins connected to arduino defined

                     //************LCD PROPERTIES**************
                     
void setup() 
{
  
  Serial.begin(9600);             //starting the serial port with baude rate set to '9600'
  pinMode(trggrPin, OUTPUT);      //trigger pin action defined for o/p purpose
  pinMode(echoPin, OUTPUT);       //echo pin action defined for o/p purpose

  MyLCDdisplay.begin(16,2);       //sets ON the LCD and defines its size, '16' columns '2' rows 
  MyLCDdisplay.setCursor(0,0);    //LCD display cursor set to the top left corner column 1 row 1 of the display 
  MyLCDdisplay.print("Target Distance:"); //output on the LCD dispay

}

void loop() 
{
  
  digitalWrite(trggrPin, LOW);    //sets the pulse LOW
  delayMicroseconds(2000);        //pulse LOW state delay
  digitalWrite(trggrPin, HIGH);   //sets the pulse HIGH
  delayMicroseconds(10);          //pulse HIGH state delay
  digitalWrite(trggrPin, LOW);    //sets the pulse LOW
  
  pingTime = pulseIn(echoPin, HIGH);   //reads ping signal transit time from the echo pin

  pingTime /= 1000000.;                 //converts 'pingTime' time units to seconds from microseconds

  trgtDistance = pingTime * pingSpeed; //target distance computed in metres

              /**
               * For
               *         1 inch = 2.54 cm
               * then
               *         1 inch = .0254 m
               *         
               * Hence target distance in inches
               */

   trgtDistance /= .0254;               //Converts target distance from metres to inches
                                        //devides 'trgtDistance' by .0254 and returns the to itself
               /**
                * For the ping signal travelled a 'to' and 'fro'fro' jny in its transit time,
                * Then to get the actual distance to the target we devide the whole 
                * ping signal distance by '2'
                * 
                * Thus,
                */

   trgtDistance /= 2;                   //actual target distance

   MyLCDdisplay.setCursor(0, 1);        //sets the cursor at 1st column 2nd row
   MyLCDdisplay.print("                ");
                                        //clears out virtual character
   MyLCDdisplay.print(trgtDistance);    //prints on the LCD display computed target distance
   MyLCDdisplay.print(" inches");       //prints target distance units 'inches,
   delay(250);                          //delays the o/p by 250 ms


   /**
    * TIP:   
    *     -This project can be used as an integrative extension to an 'object avoiding robot' project.
    *     -This is possible as we can define the safe distance of proximity for a robot vehicle using the 
    *      ultrasonic sensor device.
    *    2-The project can also be used in security systems as we can define 'target' motions and movement
    */
}



