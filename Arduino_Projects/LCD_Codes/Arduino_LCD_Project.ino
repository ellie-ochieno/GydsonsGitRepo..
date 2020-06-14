  #include<LiquidCrystal.h>       //reference to the LCD library 




                //***************PROJECT: CREATING A DISPLAY COUNTER USING Sparkfun Inventor Kit LCD, ARDUINO AND ULTRASONIC SENSOR**************


         /**
          * LCD->Liduid Crystall Display
          * Sparkfun Inventor Kit LCD is connected as shown in 'Arduino_LCD_Display_Cct.png' and 'Arduino_LCD_Display_Clear_Cct.png'
          * photographs available in arduino projects dir. Following the orientation of the LCD as in 'Arduino_LCD_Display_Cct.png', pin one
          * is the 1st pin on the left top corner followed by other 15 pins fo it has 16 pins in number
          * Its connected as per the connection table guides given in photographs'Sparkfun Inventor Kip LCD_Connection_Table01.png' 
          * and 'Sparkfun Inventor Kip LCD_Connection_Table02.png'. ALWAYS refer to the spec sheet to confirm correct connection of the LCD.
          * Going on to the project's program, we first import the LCD lidrary files from the arduino s/ware. Here, we use the 
          * command;
          *                  #include <LiquidCrystal.h>
          *                          
          *Within the code, we also create an LCD object through which we tell the arduino how ts connected to it.
          *e.g
          *                  LiquidCrystal MyLCDdisplay(10, 9, 5, 4, 3, 2);
          *                  
          *Where,we're telling the arduino that:
          *                  LCD pin RS is hooked to pin 10
          *                  LCD pin is hooked to pin 9
          *                  LCD pins DB4 to DB7 are hooked to pins 5 to 2
          *                  
          *To send the msgs to the LCD, we start by telling the arduino where on the LCD to begin the msg. For t always atsrt 
          *with column first then row and it starts with '0'. Thus, the upper left character would be column '0' row '0' or(0,0). 
          *to set the cursor to the upper left corner we would send the command
          *                   
          *                  MyLCDdisplay setCursor(0,0);
          *                  
          *NOTE: 
          *      -The COLUMN-ROW definition oder for the LCD is the inverse of the mathematical reference
          *       ROW-COLUMN
          */


  LiquidCrystal MyLCDdisplay(10, 9, 5, 4, 3, 2);   //creates an LCD object named 'MyLCDdisplay' with pins defined
  int myCounter = 0;                               //to hold the number ot counts
  
void setup() {
  MyLCDdisplay.begin(16, 2);   //turning ON the LCD and defining its size
                               //'16' refers to columns and '2' refers to the number of rows
  MyLCDdisplay setCursor(0,0); //sets the cursor position at the top left corner of the display
  MyLCDdisplay.print("My timer: "); 
                               //prints 'My timer' to the LCD display
}

void loop() {
  for(myCounter = 1; myCounter <= 10; myCounter++)
  {
     MyLCDdisplay setCursor(0,1); //sets the cursor at the 1st column 2nd row of the display
     MyLCDdisplay.print("                ");        
                                            //clears the screen by the 16 white spaces given btn the quotes
                                            //This solves the problem of a virtual character displayed when the counter hits the two digit value
     
     MyLCDdisplay setCursor(0,1); //sets the cursor at the 1st column(column 0) and 2nd row(row 1) of the display
     MyLCDdisplay.print(myCounter);
                                  //prints out 'myCounter' value on the display
     MyLCDdisplay.print(" seconds");
                                  //prints 'myCounter' units
     delay(1000);                 //delays display rate
  }
                                  //loop displays counts from 1-10
             

  for(myCounter = 10; myCounter >= 0; myCounter--)
  {
     MyLCDdisplay setCursor(0,1); //sets the cursor at the 1st column 2nd row of the display
     MyLCDdisplay.print("                ");        
                                            //clears the screen by the 16 white spaces
                                            //This solves a problem of a virtually added character when the counter hits the two digit value
                                            
     MyLCDdisplay setCursor(0,1); //sets the cursor at the 1st column(column 0) and 2nd row(row 1) of the display
     MyLCDdisplay.print(myCounter);
                                  //prints out 'myCounter' value on the display
     MyLCDdisplay.print(" seconds");
                                  //prints 'myCounter' units
     delay(1000);                 //delays display rate
  }
                                  //loop displays counts from 10-0
}
