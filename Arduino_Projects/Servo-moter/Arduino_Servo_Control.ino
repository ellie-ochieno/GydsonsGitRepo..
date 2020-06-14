#include <Servo.h>    //servo header file referencing to the servo library




        //*****************17. CONTROLLING A SERVO DEVICE WITH ARDUINO WITH THE HELP OF APOTENTIOMETER******************
        


            /**
                 -A servo is an electronic device with movable parts that can be electrically rotated up to 180 degrees from 0 degrees using commands
                 -It has external connection codes for communication with three main lines:
                 
                    1. Red cable line
                       -Is the power line for positive terminal usually connected to the power source
                    2. Black cable line 
                       -Is the power line for negative terminal usually connected to ground
                    3. White cable line
                       -This is the control line through which the commands are sent to the servo
                       -Its the main communication line for the servo.
                       
                 -Because some other high rated power servos draws much current when in operation which could be beyond the safe rates for the arduino, we can have the servo power line 
                  connected to an external power source(set to supply safe power to the device) and the controll line connected to the arduino. In this case ensure the grounds for the involved
                  components are hooked up together for their safety of operation.
                 
                 #.NOTE
                       -In normal operation the servos DO NOT mit the 180 degrees span of rotation as they are intended to(e.g could span between 15-170 degrees).
                        So its essential to first test for each servo its safe positions of rotation before putting it in application. For rotating it beyond its 
                        safe limits causes it to strain in vibration hence drawing more current which could burn out the arduino if the power line is connected to it.
                       -Servo pointer is only made to be rotated electronically. So DO NOT spin the pointer mechanically either by hand as this 
                       damage the device.
                       
                 -The circuit connection for all this involves a slight modification of that in 'PotentiometerProject10Cct.png' provided in arduino projects directory.
                 -The modification involves appending the servo to the circuit where:
                    >Servo control line is connected to pin 9(one of the squiggling line pins which can serve both analogWrite and digitalWrite functionalities)
                    >Servo power line is connected to the 5V power line on arduino board.
                    >Servo ground line is connected to teh arduino ground line.

  
                  -The program code for this project therefore appears as follows:
            **/

/**

                //***************17a. TESTER PROGRAM TO SET THE SERVO AT SAFE LIMITS OF SPAN**************



int postn = 0;        //servo position variable initialized to 0
int servoPin = 9;     //servo connection variable actualized to pin 9
int servoDelay = 25;  //delay time variable initialized to 25ms

Servo myPointer;       //servo object declaration


void setup() 
{
    Serial.begin(9600);                //serial port set ON with baude rate value of 9600
    myPointer.attach(servoPin);        //defines pin of servo attachment to arduino board
}
void loop() 
{
    Serial.println(" Enter the position you wish to set the servo to:");
                                       //prompt for user input
    while(Serial.available() == 0 )
    {}                                 //halts the program execution waitin for user input
    postn = Serial.parseInt();         //reads the user input

    myPointer.write(postn);            //writing(communicating) position to the servo


    /**
     * Compiling and running this program we're able to communicate to the servo and test its safe limits of span on the 
     * 180 degrees scale. From the samllest range we can set it to 20 degrees and determine its capability to reach the point 
     * and check its behaviour when at that point. When ok we enter another lower value e.g 15 degrees and determine the behaviour
     * again till we achieve its safe position of span. 
     * We repeat the same for the highest position of span for the servo.
     */
     /**
}
  **/



/**


                //***************17b. PROGRAM TO SPIN THE SERVO BETWEEN THE SAFE LIMITS OF SPAN(e.g 15-170 degrees)**************





int postn = 0;        //servo position variable initialized to 0
int servoPin = 9;     //servo connection variable actualized to pin 9
int servoDelay = 25;  //delay time variable initialized to 25ms

Servo myPointer;       //servo object declaration


void setup() 
{
    Serial.begin(9600);                //serial port set ON with baude rate value of 9600
    myPointer.attach(servoPin);        //defines pin of servo attachment to arduino board
}
void loop() 
{
    for(postn = 15; postn <= 170; postn++)
    {
        myPointer.write(postn);         //writing(communicating) to the servo
        delay(servoDelay);              //delays the spin
    }                                   
                                        //spins the servo in clockwise direction
    for(postn = 170; postn >= 15; postn--)
    {
        myPointer.write(postn);         //writing(communicating) position to the servo
        delay(servoDelay);              //delays the spin
    }
                                        //spins the servo in counterclockwise direction


   /**
    * We can manipulate the speed of spin in either sweeps by changing the factors of incrementing or 
    * decrementing the 'postn' variable within the for loop
    *//**
}
**/









                //***************17c. PROGRAM TO CONTROL SERVO POSITION USING THE POTENTIOMETER WITHIN LIMITS OF SPAN(e.g 15-170 degrees)**************



               /**
                * For this case we'll be using the analogWrite() standard voltage range (0-1023) in calibrating with the help of a 
                * potentiomter. And on the other hand the servo positions are to be within its safe limits of span on 0-180 degrees scale
                * which varies between the servos. for this case let's use the above sevo range(15-170 degrees).
                * To have these two scales(voltage scale(0-1023) and the servo position scale(15-170 degrees)) in application, we'll have to
                * co-relate them as follows:
                * 
                * Let the position scale(15-170 degrees) lie on the y-axis and the voltage scale(0-1023) on x-axis.
                * Thus, at the origin of this co-relation graph we've(0,15) and at the far position in the graph(1023,170). This means, when 
                * the potentiometer value reads 0, the servo will at position 15 degrees. 
                * To get more values;
                *       
                *          slope of the graph is
                *                            m = (change in Y) / (change in X)
                *                              = (Y2 - Y1) / (X2 - X1)
                *                              = (170 - 15) / (1023 - 0)
                *                              = 155 / 1023
                *                              
                *          and from point slope formula of the line
                *                            (Y - 15) = m(X - 0)
                *                                   Y = m(X) + 15      
                *                                                  for Y1 = 15 and X1 = 0 from the graph
                *                                                  
                *                                   Y = ((155 / 1023)(X)) + 15
                *                                   
                *          and for
                *                             Y = servo position
                *                             X = potentiometer voltage value
                *          Thus,
                *               
                *                             servo position = 0.151515152(X) + 15
                * 
                * 
                * Thus, with this in place, we can have our program as follows:
                */





int postn = 0;        //servo position variable initialized to 0
int servoPin = 9;     //servo connection variable actualized to pin 9
int servoDelay = 25;  //delay time variable initialized to 25ms
int potPin = A0;      //potentiometer connected to pin A0
int potReading;       //variable to hold potentiometer reading

Servo myPointer;       //servo object declaration


void setup() 
{
  
    Serial.begin(9600);                //serial port set ON with baude rate value of 9600
    myPointer.attach(servoPin);        //defines pin of servo attachment to arduino board
    
}
void loop() 
{
     potReading = analogRead(potPin);   //reading value fro the potentiometer pin
     postn = (0.151515152  * potReading) + 15;
                                        //computes servo position from the above co-relation graph for the two scales 
     myPointer.write(postn);            //writing position to the servo



     /**
      * Compiling and uplading this program to the arduino board with the potentiometer at 0 position, the servo is positioned at
      * 15degrees. Turning the potentiometer knob clockwise, gradually turns the servo in that same direction and vicebersa
      */
}
