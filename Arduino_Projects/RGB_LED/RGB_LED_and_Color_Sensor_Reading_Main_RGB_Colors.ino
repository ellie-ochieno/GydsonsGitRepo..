


             

        //************15. COLOUR SENSOR PROJECT*******************



                  
          /**
              -This project involves using an arduino micro-controller and a colour sensor 
               to read the various colour card types
               brought in its vicinity at specific proximity distance.
               
              #Note:
                    -The colour sensor in use here is the 'Virtuobotix Colour Sensor'
                    -Use Male/Female connecting wires to help hook up the sensor
                    
              -With this project instead of having the desired colours entered by the user through 
               the serial port, we'll set the LED colour by having it match the coloured cards 
               placed at the front of the sensor.
              -Hooking up the sensor to the arduino board we'll follow the given directive 
               connecting table guide as provided in 'Project15Cct.png' 
              -The sensor will make three different readings indicating the relative 'strength' 
               of the three primary colors Red, Green and Blue.
              -The colour read depends on the voltages you write to the S2 and S3 pins, according
               to the provided table in Project15a.png by the  digitalWrite approach.
              -The color strengths are read on the sensor OUTpin which is connected to Arduino pin4.
               To make the measurements we need to make a pulsein  measurement at pin4 on Arduino.
              -'Pulsein measurement' is an arduino command that looks at the pin specified and looks 
                for the pulse and returns a number representing the lenght in microseconds of the 
                pulse seen at the pin specified.
              -For instance consider the sample code below:
              
                 int outPin = 4;             //arduino output pin assigned a variable
                 unsigned int pulseWidth;    //to hold pulse width time in ms
                 
                      -With the pinMode of the outPin as INPUT, for we're reading from the pin.
                      -The followin code will allow us to measure the pulseWidth at the outPin
                        
                 pulseWidth = pulseIn(outPin, LOW);  //measure length of a LOW pulse

                       -This measurement would return a value btn 0 and 102,400. Thus the pulseWidth
                        variable needs to be defined as the unsigned int which only takes positive 
                        numbers up to 4,294,967,295. Normal integers hold numbers up to +/- 32,768
                       -For the value returned to the variable pulseWidth is interpreted as:
                           >The larger the number, the weaker the color read and the lower the
                            number the stronger the color read. 

                       -We'll have to make the pulseWidth value more meaningful by converting
                        the range 0 to 102,400 to a quite standard scale of 0 to 255.

                       -For
                                102,400 / 400 = 256
                      
                           then this makes it near 255 as the greater value of the above scale.

                       -Thus, the strength of the components R, G and B can be quantified on  
                        standard scale 0 to 255 e.g for the R component:
                                  
                                 rColorstrength = (pulseWidth / 400) - 1;

                       -To fix and make larger pulseWidth value mean strong color read and lower 
                        pulseWidth value mean weak color read then we adopt the following
                        formula
                         
                                  rColorstrength = 255 - rColorstrength;
                                                     //color strength value for the red LED

                       -For Green and Blue LEDs we'll follow the same format         

                                  gColorstrength = 255 - gColorstrength;
                                                     //color strength value for the green LED

                                  bColorstrength = 255 - bColorstrength;
                                                     //color strength value for the blue LED


          **/

   
           /**

               -------------------------------------------------------------------------------------

                          #. CONSIDER THE PROGRAM CODE BELOW TO ACCOMPLISH THE ABOVE PROJECT

           **/




               /**
                      -BLINKING THE LED WITH THE STRONGEST COLOR STRENGTH AS READ BY THE SENSOR
                      -WE MAKE USE OF THE CONDITIONAL LOOPS
                      -PLACING A COLOR CARD INFRONT OF THE SENSOR THE LED BLINKS LIGHTS WITH 
                       THAT COLOR
               **/




        int redLEDpin = 9;            //variable for red LED pin of the RGB LED
        int greenLEDpin = 11;         //variable for green LED pin of the RGB LED
        int blueLEDpin = 13;          //variable for blue LED pin of the RGB LED
                                      
         int S2 = 7;                  //color sensor pin S2 to arduino pin 7
         int S3 = 8;                  //color sensor pin S2 to arduino pin 8

         int outPin =4;               //color sensor OUT to arduino pin 4

         unsigned int pulseWidth;     //to hold pulse width time in ms

         int rColorStrength;
         int gColorStrength;
         int bColorStrength; 
                                       //variables to hold defined LEDs color strengths

         void setup()
         {
               Serial.begin(9600);   
                                      //serial port turned ON with baude rate set as 9600
               pinMode(redLEDpin, OUTPUT);
                                      //red LED pin action defined as output
               pinMode(greenLEDpin, OUTPUT);
                                      //green LED pin action defined as output
               pinMode(blueLEDpin, OUTPUT);
                                      //blue LED pin action defined as output

               
               pinMode(S2, OUTPUT);
                                      //S2 sensor pin action defined as output
               pinMode(S3, OUTPUT);
                                      //S3 sensor pin action defined as output
               pinMode(outPin, INPUT);
                                      //S3 sensor out pin action defined as input
         }

         void loop()
         {
                                      //reading external color components using the sensor
                                      //set pins S2 and S3 using the table provided in ProjectCct15a.png

                                      //Reading the RED component of the color
                                      //S2 and S3 pins powered LOW
               digitalWrite(S2, LOW);
               digitalWrite(S3, LOW);  
                                       //This combination lights up the red LED
               pulseWidth = pulseIn(outPin, LOW);
                                       //measures the length of a pulse in ms

               rColorStrength = (pulseWidth / 400) - 1;
                                       //scaling down pulse width read value to more std scale 0-255
               rColorStrength = 255 - rColorStrength;
                                       //color strength value for the red LED in fixed format
                                       //large value denotes a stronger color


                                      //Reading the GREEN component of the color
                                      //S2 and S3 pins powered HIGH
               digitalWrite(S2, HIGH);
               digitalWrite(S3, HIGH);  
                                       //This combination lights up the GREEN LED
               pulseWidth = pulseIn(outPin, LOW);
                                       //measures the length of a pulse in ms

               gColorStrength = (pulseWidth / 400) - 1;
                                       //scaling down pulse width read value to more std scale 0-255
               gColorStrength = 255 - gColorStrength;
                                       //color strength value for the GREEN LED in fixed format
                                       //large value denotes a stronger color


                                      //Reading the BLUE component of the color
                                      //S2 and S3 pins powered LOW and HIGH respectively
               digitalWrite(S2, LOW);
               digitalWrite(S3, HIGH);  
                                       //This combination lights up the BLUE LED
               pulseWidth = pulseIn(outPin, LOW);
                                       //measures the length of a pulse in ms

               bColorStrength = (pulseWidth / 400) - 1;
                                       //scaling down pulse width read value to more std scale 0-255
               bColorStrength = 255 - bColorStrength;
                                       //color strength value for the BLUE LED in fixed format
                                       //large value denotes a stronger color


               Serial.print(rColorStrength);
               Serial.print(" , ");
               Serial.print(gColorStrength);
               Serial.print(" , ");
               Serial.println(bColorStrength);
               Serial.print(" ");
                                        //prints out the color strengths
       
               delay(250);              //delays the printing process by 250 ms 



              
               if((rColorStrength > gColorStrength) && (rColorStrength > bColorStrength))
               {
                     digitalWrite(redLEDpin, HIGH);       //powers ON the RED LED
                     digitalWrite(greenLEDpin, LOW);      //powers OFF the GREEN LED
                     digitalWrite(blueLEDpin, LOW);       //powers OFF the BLUE LED
               }
                                                         //Lights the RED LED

               if((gColorStrength > rColorStrength) && (gColorStrength > bColorStrength))
               {
                     digitalWrite(redLEDpin, LOW);        //powers OFF the RED LED
                     digitalWrite(greenLEDpin, HIGH);     //powers ON the GREEN LED
                     digitalWrite(blueLEDpin, LOW);       //powers OFF the BLUE LED
               }
                                                          //Lights the GREEN LED

               if((bColorStrength > rColorStrength) && (bColorStrength > gColorStrength))
               {
                     digitalWrite(redLEDpin, LOW);        //powers ON the RED LED
                     digitalWrite(greenLEDpin, LOW);      //powers OFF the GREEN LED
                     digitalWrite(blueLEDpin, HIGH);      //powers OFF the BLUE LED
               }
                                                          //Lights the BLUE LED

         }


