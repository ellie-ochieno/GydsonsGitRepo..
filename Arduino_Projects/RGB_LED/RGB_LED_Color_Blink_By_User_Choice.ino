

       /**
        * RGB LED PROGRAM TO PROVIDE USER WITH COLOR CHOICES ON WHICH TYPE
        * TO BLINK AN LED WITH
        */

int redLEDpin = 9;               //red LED initialized to pin 9
int greenLEDpin = 10;            //green LED initialized to pin 10
int blueLEDpin = 11;             //blue LED initialized to pin 11


int delayOnTime;                 //to hold user prefered delay ON time
int delayOffTime;                //to hold user prefered delay OFF time
int usrLEDChoice;                //variable to hold user input choice

int rColorStrength;              //to hold red LED brightness intesity
int gColorStrength;              //to hold green LED brightness intesity
int bColorStrength;              //to hold blue LED brightness intesity



void setup() 
 {
     Serial.begin(9600);             //starting the serial port with baude rate factor 9600
     pinMode(redLEDpin, OUTPUT);     //red LED pin action defined for OUTPUT purpose
     pinMode(greenLEDpin, OUTPUT);   //red LED pin action defined for OUTPUT purpose
     pinMode(blueLEDpin, OUTPUT);    //red LED pin action defined for OUTPUT purpose
  
     
  
      Serial.println(" Please choose the type of LED colour to blink using the choices below: ");
      Serial.println(" ");
      Serial.println("        1 for Red  ");
      Serial.println("        2 for Green  ");
      Serial.println("        3 for Blue  ");
      Serial.println("        4 for Cyan  ");
      Serial.println("        5 for Magenta  ");
      Serial.println("        6 for Pink  ");
      Serial.println("        7 for Purple  ");
      Serial.println("        8 for Yellow  ");
      Serial.println("        9 for Orange  ");
      Serial.println("        10 for White  ");
      Serial.println(" ");
                                       //prompt for user choice on type of LED color to blink
                               
      while(Serial.available() == 0)
      {}                               //halts the program execution waiting for user input
      
      usrLEDChoice = Serial.parseInt();
                                       //Reads user input for the user LED choice
                                       
     Serial.println(" ");
     Serial.println(" Enter the ON delay-time for the chosen LED to blink in microseconds  ");
                                     //prompt for user input for LED's ON delay time
     delayOnTime = Serial.parseInt();
                                     //reads the user input
     
     Serial.println(" ");      
     Serial.println(" Enter the OFF delay-time for the chosen LED to blink in microseconds  ");
                                     //prompt for user input for LED's OFF delay time
     delayOffTime = Serial.parseInt();
                                     //reads the user input
}

void loop()
{
    if(usrLEDChoice == 1)
    {
        
        Serial.println(" "); 
        Serial.println("  LED Blinking Red Color ");    
        Serial.println(" ");    
        
        rColorStrength = 255;      //red LED brightness intesity set to 255 
        gColorStrength = 0;        //green LED brightness intesity set to 0
        bColorStrength = 0;        //blue LED brightness intesity set to 0

                                   //RGB LED's brightness intensities(color strengths) to achieve red color 

        
        analogWrite(redLEDpin, rColorStrength);     //red LED pin powered to the defined potential
        analogWrite(greenLEDpin, gColorStrength);   //green LED pin powered to the defined potential
        analogWrite(blueLEDpin, bColorStrength);    //blue LED pin powered to the defined potential
        delay(delayOnTime);                         //LED ON time delay
   
        analogWrite(redLEDpin, 0);                  //red LED pin powered LOW
        analogWrite(greenLEDpin, 0);                //green LED pin powered LOW
        analogWrite(blueLEDpin, 0);                 //blue LED pin powered LOW
        delay(delayOffTime);                        //LED OFF time delay

                                                    //RGB LED BLINKING IN RED COLOR
    }
    else if(usrLEDChoice == 2)
    {
        
        Serial.println(" "); 
        Serial.println("  LED Blinking Green Color ");    
        Serial.println(" ");    
        
        rColorStrength = 0;        //red LED brightness intesity set to 0 
        gColorStrength = 128;      //green LED brightness intesity set to 128
        bColorStrength = 0;        //blue LED brightness intesity set to 0

                                   //RGB LED's brightness intensities(color strengths) to achieve green color 

        
        analogWrite(redLEDpin, rColorStrength);     //red LED pin powered to the defined potential
        analogWrite(greenLEDpin, gColorStrength);   //green LED pin powered to the defined potential
        analogWrite(blueLEDpin, bColorStrength);    //blue LED pin powered to the defined potential
        delay(delayOnTime);                         //LED ON time delay
   
        analogWrite(redLEDpin, 0);                  //red LED pin powered LOW
        analogWrite(greenLEDpin, 0);                //green LED pin powered LOW
        analogWrite(blueLEDpin, 0);                 //blue LED pin powered LOW
        delay(delayOffTime);                        //LED OFF time delay

                                                    //RGB LED BLINKING IN GREEN COLOR
    }
    else if(usrLEDChoice == 3)
    {
        
        Serial.println(" "); 
        Serial.println("  LED Blinking Blue Color ");    
        Serial.println(" ");    
        
        rColorStrength = 0;        //red LED brightness intesity set to 0 
        gColorStrength = 0;        //green LED brightness intesity set to 0
        bColorStrength = 255;      //blue LED brightness intesity set to 255

                                   //RGB LED's brightness intensities(color strengths) to achieve blue color 

        
        analogWrite(redLEDpin, rColorStrength);     //red LED pin powered to the defined potential
        analogWrite(greenLEDpin, gColorStrength);   //green LED pin powered to the defined potential
        analogWrite(blueLEDpin, bColorStrength);    //blue LED pin powered to the defined potential
        delay(delayOnTime);                         //LED ON time delay
   
        analogWrite(redLEDpin, 0);                  //red LED pin powered LOW
        analogWrite(greenLEDpin, 0);                //green LED pin powered LOW
        analogWrite(blueLEDpin, 0);                 //blue LED pin powered LOW
        delay(delayOffTime);                        //LED OFF time delay

                                                    //RGB LED BLINKING IN BLUE COLOR
    }
    else if(usrLEDChoice == 4)
    {
        
        Serial.println(" "); 
        Serial.println("   LED Blinking Cyan Color ");    
        Serial.println(" ");    
        
        rColorStrength = 0;        //red LED brightness intesity set to 0 
        gColorStrength = 255;      //green LED brightness intesity set to 255
        bColorStrength = 255;      //blue LED brightness intesity set to 255

                                   //RGB LED's brightness intensities(color strengths) to achieve cyan color 

        
        analogWrite(redLEDpin, rColorStrength);     //red LED pin powered to the defined potential
        analogWrite(greenLEDpin, gColorStrength);   //green LED pin powered to the defined potential
        analogWrite(blueLEDpin, bColorStrength);    //blue LED pin powered to the defined potential
        delay(delayOnTime);                         //LED ON time delay
   
        analogWrite(redLEDpin, 0);                  //red LED pin powered LOW
        analogWrite(greenLEDpin, 0);                //green LED pin powered LOW
        analogWrite(blueLEDpin, 0);                 //blue LED pin powered LOW
        delay(delayOffTime);                        //LED OFF time delay

                                                    //RGB LED BLINKING IN CYAN COLOR
    }
    else if(usrLEDChoice == 5)
    {
        
        Serial.println(" "); 
        Serial.println("  LED Blinking Magenta Color ");    
        Serial.println(" ");    
        
        rColorStrength = 255;        //red LED brightness intesity set to 255 
        gColorStrength = 0;          //green LED brightness intesity set to 0
        bColorStrength = 255;        //blue LED brightness intesity set to 255

                                     //RGB LED's brightness intensities(color strengths) to achieve magenta color 

        
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
    else if(usrLEDChoice == 6)
    {
        
        Serial.println(" "); 
        Serial.println("  LED Blinking Pink Color ");    
        Serial.println(" ");    
        
        rColorStrength = 255;        //red LED brightness intesity set to 255 
        gColorStrength = 192;        //green LED brightness intesity set to 192
        bColorStrength = 203;        //blue LED brightness intesity set to 203

                                     //RGB LED's brightness intensities(color strengths) to achieve pink color 

        
        analogWrite(redLEDpin, rColorStrength);     //red LED pin powered to the defined potential
        analogWrite(greenLEDpin, gColorStrength);   //green LED pin powered to the defined potential
        analogWrite(blueLEDpin, bColorStrength);    //blue LED pin powered to the defined potential
        delay(delayOnTime);                         //LED ON time delay
   
        analogWrite(redLEDpin, 0);                  //red LED pin powered LOW
        analogWrite(greenLEDpin, 0);                //green LED pin powered LOW
        analogWrite(blueLEDpin, 0);                 //blue LED pin powered LOW
        delay(delayOffTime);                        //LED OFF time delay

                                                    //RGB LED BLINKING IN PINK COLOR
    }
    else if(usrLEDChoice == 7)
    {
        
        Serial.println(" "); 
        Serial.println("  LED Blinking Purple Color ");    
        Serial.println(" ");    
        
        rColorStrength = 128;        //red LED brightness intesity set to 128 
        gColorStrength = 0;          //green LED brightness intesity set to 0
        bColorStrength = 128;        //blue LED brightness intesity set to 128

                                     //RGB LED's brightness intensities(color strengths) to achieve purple color 

        
        analogWrite(redLEDpin, rColorStrength);     //red LED pin powered to the defined potential
        analogWrite(greenLEDpin, gColorStrength);   //green LED pin powered to the defined potential
        analogWrite(blueLEDpin, bColorStrength);    //blue LED pin powered to the defined potential
        delay(delayOnTime);                         //LED ON time delay
   
        analogWrite(redLEDpin, 0);                  //red LED pin powered LOW
        analogWrite(greenLEDpin, 0);                //green LED pin powered LOW
        analogWrite(blueLEDpin, 0);                 //blue LED pin powered LOW
        delay(delayOffTime);                        //LED OFF time delay

                                                    //RGB LED BLINKING IN PURPLE COLOR
    }
    else if(usrLEDChoice == 8)
    {
        
        Serial.println(" "); 
        Serial.println("  LED Blinking Yellow Color ");    
        Serial.println(" ");    
        
        rColorStrength = 255;        //red LED brightness intesity set to 255 
        gColorStrength = 255;        //green LED brightness intesity set to 255
        bColorStrength = 0;          //blue LED brightness intesity set to 0

                                     //RGB LED's brightness intensities(color strengths) to achieve yellow color 

        
        analogWrite(redLEDpin, rColorStrength);     //red LED pin powered to the defined potential
        analogWrite(greenLEDpin, gColorStrength);   //green LED pin powered to the defined potential
        analogWrite(blueLEDpin, bColorStrength);    //blue LED pin powered to the defined potential
        delay(delayOnTime);                         //LED ON time delay
   
        analogWrite(redLEDpin, 0);                  //red LED pin powered LOW
        analogWrite(greenLEDpin, 0);                //green LED pin powered LOW
        analogWrite(blueLEDpin, 0);                 //blue LED pin powered LOW
        delay(delayOffTime);                        //LED OFF time delay

                                                    //RGB LED BLINKING IN YELLOW COLOR
    }
    else if(usrLEDChoice == 9)
    {
        
        Serial.println(" "); 
        Serial.println("  LED Blinking Orange Color ");    
        Serial.println(" ");    
        
        rColorStrength = 255;        //red LED brightness intesity set to 255 
        gColorStrength = 165;        //green LED brightness intesity set to 165
        bColorStrength = 0;          //blue LED brightness intesity set to 0

                                     //RGB LED's brightness intensities(color strengths) to achieve orange color 

        
        analogWrite(redLEDpin, rColorStrength);     //red LED pin powered to the defined potential
        analogWrite(greenLEDpin, gColorStrength);   //green LED pin powered to the defined potential
        analogWrite(blueLEDpin, bColorStrength);    //blue LED pin powered to the defined potential
        delay(delayOnTime);                         //LED ON time delay
   
        analogWrite(redLEDpin, 0);                  //red LED pin powered LOW
        analogWrite(greenLEDpin, 0);                //green LED pin powered LOW
        analogWrite(blueLEDpin, 0);                 //blue LED pin powered LOW
        delay(delayOffTime);                        //LED OFF time delay

                                                    //RGB LED BLINKING IN ORANGE COLOR
    }
    else if(usrLEDChoice == 10)
    {
        
        Serial.println(" "); 
        Serial.println("  LED Blinking White Color ");    
        Serial.println(" ");    
        
        rColorStrength = 255;        //red LED brightness intesity set to 255 
        gColorStrength = 255;        //green LED brightness intesity set to 255
        bColorStrength = 255;          //blue LED brightness intesity set to 255

                                     //RGB LED's brightness intensities(color strengths) to achieve white color 

        
        analogWrite(redLEDpin, rColorStrength);     //red LED pin powered to the defined potential
        analogWrite(greenLEDpin, gColorStrength);   //green LED pin powered to the defined potential
        analogWrite(blueLEDpin, bColorStrength);    //blue LED pin powered to the defined potential
        delay(delayOnTime);                         //LED ON time delay
   
        analogWrite(redLEDpin, 0);                  //red LED pin powered LOW
        analogWrite(greenLEDpin, 0);                //green LED pin powered LOW
        analogWrite(blueLEDpin, 0);                 //blue LED pin powered LOW
        delay(delayOffTime);                        //LED OFF time delay

                                                    //RGB LED BLINKING IN WHITE COLOR
    }
    else
    {
        Serial.println(" --------------------------------------------------------------");
        Serial.println(" ");
        Serial.println(" Ooops!!! Error detected.");
        Serial.println(" ");
        Serial.print(usrLEDChoice);
        Serial.println(" is an INVALID choice!");
        Serial.println(" Please restart the program and enter a correct choice.");
        Serial.println(" ");
        Serial.println(" --------------------------------------------------------------");
    }
}

