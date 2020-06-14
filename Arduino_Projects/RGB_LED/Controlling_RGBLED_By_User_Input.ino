
             

        //************14. CONTROLLING RGB LED'S COLOR BLINKS USING USER INPUT CHOICE*******************



           /**
                -We can enable user to choose the type of color in RGB LED to blink
                -Consider the program below: 
           **/

        int redLEDpin = 9;            //variable for red LED pin of the RGB LED
        int greenLEDpin = 11;         //variable for green LED pin of the RGB LED
        int blueLEDpin = 13;          //variable for blue LED pin of the RGB LED
        
        int redLEDOnTime = 250;       
        int greenLEDOnTime = 250;
        int blueLEDOnTime = 250;
                                      //LEDs ON time
        
        int redLEDOffTime = 100;  
        int greenLEDOffTime = 100; 
        int blueLEDOffTime = 100; 
                                      //LEDs OFF time
                                      
        int numOfBlinks;
        int brightnessIntensity = 153;         
                                      //brightness intensity on 'analogWrite()' scale(0-255)
         
        int usrclrChoice;               //user choice variable
           
                                      //variables declaration
                                 
        void setup()
        { 
            Serial.begin(9600);             //turns ON the arduino board serial port
            pinMode(redLEDpin, OUTPUT);     //red LED pin action defined for output purpose
            pinMode(greenLEDpin, OUTPUT);   //green LED pin action defined for output purpose
            pinMode(blueLEDpin, OUTPUT);    //blue LED pin action defined for output purpose
            
            
            Serial.println(" How many times should an RGB LED blink?  ");
            Serial.print(" Enter your choice in number form e.g 3,5 etc  ");
                                            //user prompt for number of blinks
            while(Serial.available() == 0)
            {}                              //halts the program waiting user input
            numOfBlinks = Serial.parseInt();
                                            //reads the user input
        }

        void loop()
        {
            int count;
                                              //blinking counter
            
            Serial.println(" Please choose the type of LED colour to blink using the choices below: ");
            Serial.println(" ");
            Serial.println("        1 for Red  ");
            Serial.println("        2 for Green  ");
            Serial.println("        3 for Blue  ");
            Serial.println(" ");
                                           //prompt for user choice on type of LED to blink
                             
            while(Serial.available() == 0)
            {}                             //halts the program flow waiting for user input
            usrclrChoice = Serial.parseInt();
                                           //Reads user input
                                           
                                           
            if(usrclrChoice == 1)
            {
                 Serial.println(" Red LED blinking.   ");           
                                                        //validates blinking LED
                 for(count == 1; count <= numOfBlinks; count++)
                 {
                      analogWrite(redLEDpin, brightnessIntensity);     
                                                        //red LED pin powered ON by 3V signal
                      delay(redLEDOnTime);              //waiting time ON
                      analogWrite(redLEDpin, 0);        //red LED pin powered OFF by 0V signal
                      delay(redLEDOffTime);             //waiting time OFF 
                 }                        
                                                        //Red LED blinking  
            }else if(usrclrChoice == 2)
            {
                 Serial.println(" Green LED blinking.   ");           
                                                        //validates blinking LED
                 for(count == 1; count <= numOfBlinks; count++)
                 {
                      analogWrite(greenLEDpin, brightnessIntensity);    
                                                        //red LED pin powered ON by 3V signal
                      delay(greenLEDOnTime);            //waiting time ON
                      analogWrite(redLEDpin, 0);        //red LED pin powered OFF by 0V signal
                      delay(greenLEDOffTime);           //waiting time OFF
                 }
                                                        //Green LED blinkingw
            }else if(usrclrChoice == 3)
            {
                 Serial.println(" Blue LED blinking.   ");           
                                                        //validates blinking LED
                 for(count == 1; count <= numOfBlinks; count++)
                 {
                      analogWrite(blueLEDpin, brightnessIntensity);    
                                                        //red LED pin powered ON by 3V signal
                      delay(blueLEDOnTime);             //waiting time ON
                      analogWrite(redLEDpin, 0);        //red LED pin powered OFF by 0V signal
                      delay(blueLEDOffTime);            //waiting time OFF
                 }
                                                        //Blue LED blinking
            }else
            {
                  Serial.print(" Oops!! ");
                  Serial.print(usrclrChoice);
                  Serial.println(" is an invalid choice. ");
                  Serial.println(" Please review the given choices above and enter the correct choice.");
            }
             
            
        }
        
        
