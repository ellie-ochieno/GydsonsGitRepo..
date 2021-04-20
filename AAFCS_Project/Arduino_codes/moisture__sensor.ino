//        -------------------SOIL MOISTURE SENSOR-----------------

#include <LiquidCrystal.h>

LiquidCrystal LCD_display(12, 11, 5, 4, 3, 2);
int sensor_pin = A0;                    //sensor module1
int sensor_pin1 = A1;                    //sensor module2
int output_value ;
int output_value2 ;
int average_reading;

void setup() {
   LCD_display.begin(16, 2);   //sets ON the LCD and defines its size, '16' columns '2' rows 
   Serial.begin(9600);
                                        //sets host communication rate
   Serial.println("Reading From the Sensor ...");
   delay(2000);

   LCD_display.clear();
   LCD_display.setCursor(0,0);
   LCD_display.print("Average moisture");
   }

void loop() {
   delay(1000);
   output_value= analogRead(sensor_pin);
   output_value2= analogRead(sensor_pin1);
                                          //reads info data from analog sensor pin
   output_value = map(output_value,550,0,0,100);
   output_value2 = map(output_value2,550,0,0,100);
//     output_value = (output_value);
//     output_value2 = (output_value2);
                                          //maps analog values spread across(0-1024) on (0-100%) scale
   average_reading = (output_value + output_value2) / 2;
                                          //gets average reading
   Serial.print("Mositure sesnsor 1: ");
   Serial.print(output_value);
   Serial.println("%");
                                          //sensor 1 reading
   Serial.print("Mositure sesnsor 2: ");
   Serial.print(output_value2);
   Serial.println("%");             
                                          //sensor 2 reading
   Serial.print("Average moisture level: ");
   Serial.print(average_reading);
   Serial.println("%"); 
   Serial.println();                          //average reading
   
   LCD_display.setCursor(0,1);
   LCD_display.print("Level: ");
   LCD_display.setCursor(7,1);
   LCD_display.print(average_reading);
   LCD_display.print("%       ");           
   delay(1000);                           //delay btn iterations
   }
    /*
     * ////////////////ARDUINO-FC-28 MOISTURE SENSOR CONNECTION//////////////////////////
     *    Arduino         FC-28 Sensor
     *    -------         ------------
     *      3V/5V     -->       VCC
     *      GND       -->       GND
     *      A0        -->       A0 
     *      
     *      
     *    Average Soil Moisture Content
     *    ------------------------------
     *    
     *    Soil Type       |  No Irrigation Needed  |  Irrigation to Be Applied  |  Dangerously Low Soil Moisture
     *    ------------       --------------------     ------------------------     -----------------------------
     *    Fine Clay               80-100                      60-80                         Below 60
     *    
     *    Medium(Loamy)           88-100                      70-88                         Below 70
     *    
     *    Coarse (Sandy)          90-100                      80-90                         Below 80
     *      
     *    --------------     --------------------     ------------------------     -----------------------------
     *    Overal average          86-100                      70-86                         Below 70
     *    --------------     --------------------     ------------------------     -----------------------------
     *    
     *    Crop             Maximum moisture value     Maximum moisture value              Average
     *    --------------     --------------------     ------------------------     -----------------------------
     *    Wheat                   100                       60                            80
     *    
     */
