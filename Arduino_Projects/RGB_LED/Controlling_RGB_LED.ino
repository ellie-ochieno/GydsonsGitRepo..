
             
             

        //************13. CONTROLLING RGB LED*******************



          /**
               -This is a special type of LED that has 3 independent LEDs: Red, Green and Blue(thus RGB).
               -Each can be blinked independently from their specific pins as connected on the bread board.
               -It can also be blinked as an independent LED from the individual pins
          **/




  //Blinking ALL the LEDs at same intensity one after the other starting from Red, Green to Bllue
  


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
        int brightnessIntensity = 153;         //brightness intensity on 'analogWrite()' scale(0-255)
         
                                      //variables declaration
                                 
                                 
                                 
        void setup()
        { 
            Serial.begin(9600);             //turns ON the arduino board serial port
            pinMode(redLEDpin, OUTPUT);     //red LED pin action defined for output purpose
            pinMode(greenLEDpin, OUTPUT);   //green LED pin action defined for output purpose
            pinMode(blueLEDpin, OUTPUT);    //blue LED pin action defined for output purpose
            
            
            Serial.print(" How many times should every RGB LED colors blink?  ");
                                            //user prompt for number of blinks
            while(Serial.available() == 0)
            {}                              //halts the program waiting user input
            numOfBlinks = Serial.parseInt();
                                            //reads the input
        }

        void loop()
        {
            int count;
                                              //blinking counter
            for(count == 1; count <= numOfBlinks; count++)
            {
                 analogWrite(redLEDpin, brightnessIntensity);      //red LED pin powered ON by 3V signal
                 delay(redLEDOnTime);              //waiting time ON
                 analogWrite(redLEDpin, 0);        //red LED pin powered OFF by 0V signal
                 delay(redLEDOffTime);             //waiting time OFF 
            }                        
                                                   //Red LED blinking  
             
            for(count == 1; count <= numOfBlinks; count++)
            {
                 analogWrite(greenLEDpin, brightnessIntensity);    //red LED pin powered ON by 3V signal
                 delay(greenLEDOnTime);            //waiting time ON
                 analogWrite(redLEDpin, 0);        //red LED pin powered OFF by 0V signal
                 delay(greenLEDOffTime);           //waiting time OFF
            }
                                                   //Green LED blinking
            
            for(count == 1; count <= numOfBlinks; count++)
            {
                 analogWrite(blueLEDpin, brightnessIntensity);     //red LED pin powered ON by 3V signal
                 delay(blueLEDOnTime);             //waiting time ON
                 analogWrite(redLEDpin, 0);        //red LED pin powered OFF by 0V signal
                 delay(blueLEDOffTime);            //waiting time OFF
            }
                                                   //Blue LED blinking
        }
  
  
