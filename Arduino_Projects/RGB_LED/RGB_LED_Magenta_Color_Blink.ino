


     /**
        PROGRAM TO BLINK THE RGB LED IN MAGENTA/FUCHSIA COLOR MAKING USE OF THE 
        analogwrite() scale (0-255)
     **/



int redLEDpin = 9;               //red LED initialized to pin 9
int greenLEDpin = 10;            //green LED initialized to pin 10
int blueLEDpin = 11;             //blue LED initialized to pin 11

int rColorStrength = 255;        //red LED brightness intesity set to 255 
int gColorStrength = 0;          //green LED brightness intesity set to 0
int bColorStrength = 255;        //blue LED brightness intesity set to 255

                                 //RGB LED's brightness intensities(color strengths) to achieve magenta color 
                                 

int delayOnTime;                 //to hold user prefered delay ON time
int delayOffTime;                //to hold user prefered delay OFF time


void setup() 
{
   Serial.begin(9600);             //starting the serial port with baude rate factor 9600
   pinMode(redLEDpin, OUTPUT);     //red LED pin action defined for OUTPUT purpose
   pinMode(greenLEDpin, OUTPUT);   //red LED pin action defined for OUTPUT purpose
   pinMode(blueLEDpin, OUTPUT);    //red LED pin action defined for OUTPUT purpose

   Serial.println(" ");
   Serial.println(" Enter the blinking LED ON delay-time in microseconds  ");
                                   //prompt for user input for LED's ON delay time
   delayOnTime = Serial.parseInt();
                                   //reads the user input
   
   Serial.println(" ");      
   Serial.println(" Enter the blinking LED OFF delay-time in microseconds  ");
                                   //prompt for user input for LED's OFF delay time
   delayOffTime = Serial.parseInt();
                                   //reads the user input
}

void loop() 
{          
   analogWrite(redLEDpin, rColorStrength);     //red LED pin powered to the defined potential
   analogWrite(greenLEDpin, gColorStrength);   //green LED pin powered to the defined potential
   analogWrite(blueLEDpin, bColorStrength);    //blue LED pin powered to the defined potential
   delay(delayOnTime);                         //LED ON time delay
   
   analogWrite(redLEDpin, 0);                  //red LED pin powered LOW
   analogWrite(greenLEDpin, 0);                //green LED pin powered LOW
   analogWrite(blueLEDpin, 0);                 //blue LED pin powered LOW
   delay(delayOffTime);                        //LED OFF time delay

                                               //RGB LED BLINKING IN MAGENTA COLOR
}







