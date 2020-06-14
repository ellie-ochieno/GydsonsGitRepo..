




                //***************PROJECT: TO MEASURE THE SPEED OF SOUND IN DRY AIR USING ARDUINO AND ULTRASONIC SENSOR**************




                  /**
                   * In dry air the speed of sound is approximately 
                   *                            = 331.4 + 0.6Tc
                   *                            where Tc denotes temperature in degrees celcius 
                   *                    
                   * Meaning at RTP(Room Temperature and Pressure) where Tc = 25 degrees C
                   *                            
                   *              speed of sound = 331.4 + (25*.6) = 346.4 m/s
                   *              
                   *              
                   *The ultrasonic sensor works by sending out a ping signal when commanded and waits for the reflected signal of its 
                   *ping. In the process the sensor is able to calibrate the transit time taken by the signal.
                   *Knowing the distance between the sensor and the reflecting body, we can determine the speed of the sent ping
                   *signal. Thus if the ping signal is of ultrasound wave then we can definately determine its speed
                   *
                   *The sensor has four external leads: 
                   *     1. VCC 
                   *            -connects to arduino power source 5V
                   *     2. TIRG(Trigger pin)
                   *            -Is the one through which the command to send out the ping signal is sent
                   *     3. Echo pin
                   *            -Reports back the information about the sent ping signal
                   *     4. Ground
                   *            -Connnected to the round of the arduino
                   *            
                   *Having all tehse in place, we can have the project's program code as shown below
                   */




int trigrPin = 13;            //sensor trigger pin variable connected to arduino pin 13
int echoPin = 11;             //sensor echo pin variable connected to arduino pin 11
float pingTime;               //variable to hold ping signal transit time
float speedOfSound;           //variable to hold the value for speed of sound to be computed
float targetDistance = 6.0;   //variable holds the value for signal's target distance assume 6m



void setup()
{
    Serial.begin(9600);               //sets the serial port ON
    pinMode(trigrPin, OUTPUT);        //arduino pin 13 action defined for OUTPUT purpose
    pinMode(echoPin, OUTPUT);         //arduino pin 11 action defined for OUTPUT purpose
}
void loop()
{ 
    digitalWrite(trigrPin, LOW);       //sets the trigger pulse LOW
    delayMicroseconds(2000);           //delays the trigger pulse in LOW state
    digitalWrite(trigrPin, HIGH);      //sets the trigger pulse HIGH
    delayMicroseconds(10);             //delays the trigger pulse in HIGH state in a short time
    digitalWrite(trigrPin, LOW);       //finish the trigger pulse by setting it LOW

    pingTime = pulseIn(echoPin, HIGH); //reads the ping signal transit time in ms

    pingTime /= 1000000;               //converts the pingTime from microseconds to seconds 

    speedOfSound = (targetDistance * 2) / pingTime;
                                       //computes speed of sound in m/s

    Serial.println(" ");
    Serial.println(" The speed of sound in dry air at RTP is ");
    Serial.print("    ");
    Serial.println(speedOfSound);
    Serial.println(" meter per second");
                                        //prints out the computed speed of sound signal.
    delay(2000);                         //delay the output printing rate in ms
}















