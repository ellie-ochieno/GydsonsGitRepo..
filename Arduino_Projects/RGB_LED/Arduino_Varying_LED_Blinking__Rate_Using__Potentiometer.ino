

                /**
                     PUZZLE
                     =========
                     
                    1.  Set the LED blinking rate based on the position of the potentiometer knob(i.e blink rate increases when the knob is turned to the 
                        right)
                      
                    #. Tip:
                     
                        >Use the co-relation graph to actualize the relation btn the blinking time and the signal potential
                         for the 0-1023 scale.
                        >Let the 0-1023 scale lie on x-axis while the blinking time(1-.01 second) on y-axis.
                      )
                **/
                


                  //**************PROJECT: VARYING THE BLINKING RATE OF AN LED USING THE POTENTIOMETER******************




               /**
                * This project involves using an LED together with a potentiometer.
                * The teleoperations are to be in analogwrite mode. Meaning the potentiometer voltage values are to quantified on a stadard
                * scale of range(0-1023). 
                * LED blinking rate on the other hand is to be calibrated in seconds in the range of(1-0.01 seconds)
                * To achieve this, we'll co-relate these two scales on a graph where the potentiometer reading scale(0-1023) will be 
                * positioned on x-axis while the blink-rate scale(1-0.01 seconds) on y-axis.
                * Thus, at the origin of the graph we have (0, .01) and at the highest point on the graph we have (1023, 1)
                * 
                *                   Hence the slope of the graph
                *                                                m = (change in Y) / (change in X)
                *                                                  = (Y2 - Y1) / (X2 - X1)
                *                                                  = (1 - .01) / (1023 - 0)
                *                                                  = .99 / 1023
                *                                                  
                *                   and from point slope formular of the line
                *                   
                *                                                (Y - Y1) = m(X - X1)
                *                                                (Y - .01) = (.99 / 1023)(X - 0)
                *                                                
                *                                                 for Y1 = .01, X1 = 0 and m = .99 / 1023 from the above working
                *                                                 
                *                    therefore: 
                *                    
                *                                                Y = ((.99 / 1023) * X ) + .01
                *                                             
                *                    where
                *                    
                *                                                Y = blink-rate
                *                                                X = potreading
                *                                                
                *                     thus;
                *                     
                *                                               blink-rate =  ((.99 / 1023) * potreading ) + .01 in seconds
                *                                                          
                *                                                          =  ((99 / 1023) * potreading ) + 10 in ms
                *                                               
                *                                               
                *Thus the program appears as follows:
                */




int LEDpin = 9;      //LED pin number variable specified from the arduino board
int potPin = A0;      //potPin variable for potentiometer pin
int readValue;       //variable declared to read the potentiomter
float blinkRate;    //variable for the LED to define the ON and OFF time delay
             
                     //vaiables declaration and initialization
                    

void setup()
{
   Serial.begin(9600);          //serial port turned ON with 9600 as the baude rate factor
   pinMode(potPin, INPUT);      //pin action defined as for input purpose
   pinMode(LEDpin, OUTPUT);     //pin action for the LED defined as for output purpose
}

void loop()
{
   readValue = analogRead(potPin);     //reading the potentiometer value
   blinkRate = ((99. / 1023.) * readValue ) + 10;
                                       //computes the blinkRate value
                                       //the dots(.) validates the result as a float rather than taking it zero(0)

   analogWrite(LEDpin, 255);           //LED defined pin powered HIGH
   delay(blinkRate);                   //LED ON delay time 
   analogWrite(LEDpin, 0);             //LED defined pin powered LOW
   delay(blinkRate);                   //LED FF delay time 



   /**
    * The LED blinking rate is to increase upon the turning turning the potentiometer knob clockwise 
    * and the vicevers is to be true
    */
}


