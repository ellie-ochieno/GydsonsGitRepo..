




        //*****************16. COLOR SENSOR READING MIXTURE OF COLORS FROM COLOR-CARDS USING THE RGB LED******************
        


        
               /**
                      -BLINKING THE LED WITH A MIXTURE OF AMPLIFIED COLOR STRENGTH AS READ BY THE SENSOR
                      -WE MAKE USE OF THE CONDITIONAL LOOPS
                      -PLACING A COLOR CARD INFRONT OF THE SENSOR AND AMPLIFYING THE STRONGEST COLOR TO 255 AND 
                       ATTENUATING THE WEAKEST COLOR TO 0 AND INITIALIZING THE LESS STRONGEST COLOR TO HALF ITS VALUE.
                       THE LED BLINKS WITH THE RESULTANT OF THE AMPLIFIED COLOR STRENGTHS.
                       
                       CONSIDER THE PROGRAM CODE BELOW
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





              
               if((rColorStrength > gColorStrength) && (gColorStrength > bColorStrength))
               {
                     rColorStrength = 255;
                     gColorStrength /= 2;                //initializes the read color strength to its half
                     bColorStrength = 0;
                                                          //color strengths amplified
                                                          
               }
               if((rColorStrength > bColorStrength) && (bColorStrength > gColorStrength))
               {
                     rColorStrength = 255;
                     bColorStrength /= 2;                //initializes the read color strength to its half
                     gColorStrength = 0;
                                                          //color strengths amplified
               }

               if((gColorStrength > rColorStrength) && (rColorStrength > bColorStrength))
               {
                     gColorStrength = 255;
                     rColorStrength /= 2;                //initializes the read color strength to its half
                     bColorStrength = 0;
                                                          //color strengths amplified
                                                                                                           
               }
               if((gColorStrength > bColorStrength) && (bColorStrength > rColorStrength))
               {
                     gColorStrength = 255;
                     bColorStrength /= 2;                //initializes the read color strength to its half
                     rColorStrength = 0;
                                                          //color strengths amplified
                                                                                                           
               }

               if((bColorStrength > rColorStrength) && (rColorStrength > gColorStrength))
               {
                     bColorStrength = 255;
                     rColorStrength /= 2;                //initializes the read color strength to its half
                     gColorStrength = 0;
                                                          //color strengths amplified
               }
               if((bColorStrength > gColorStrength) && (gColorStrength > rColorStrength))
               {
                     bColorStrength = 255;
                     gColorStrength /= 2;                //initializes the read color strength to its half
                     rColorStrength = 0;
                                                          //color strengths amplified
               }
               
                               
                     bColorStrength *= .5;                           //blue color strength amplified to much lower value
                     gColorStrength *= .7;                           //green color strength also  amplified to lower value                                               
                     analogWrite(redLEDpin, rColorStrength);        //powers the RED LED pin to the defined potential
                     analogWrite(greenLEDpin, gColorStrength);      //powers the GREEN LED pin to the defined potential
                     analogWrite(blueLEDpin, bColorStrength);       //powers the BLUE LED pin to the defined potential

         }




