#include <SD.h>             //loads the SD card library
#include <SPI.h>     //loads the SPI communication library
#include <Adafruit_GPS.h>   //loads the GPS library
#include <SoftwareSerial.h> //loads the SoftwareSerial library

                            /**This(SoftwareSerial.h) creates a new serial port apart from the normal 
                             * arduino serial port to be used by the GPS 
                             */


                //***************PROJECT:  DISPLAYING GPS DATA AS A TRACK ON GOOGLE EARTH*************
                
       /**
        * This will include takin the data we're loging from the GPS and displayn ti properly on Google Earth. This project 
        * involves a build up from the other previous GPS related projects.
        * We will start with the software that we used in that we used in 'GPS DATA TRACKER' project. This software correctly reads 
        * data from the GPS and then logs the data into two data files on the SD card. The problem, though, we did not really do 
        * any fine tuning of the data file we were creating.
        * In this lesson we want to create a data file that we can display as a track in Google Earth. In order for this to work, 
        * we have to save the data in the manner a KML file wants to see. We have to save the data as:
        *  
        *                     Decimal Longitude, Decimal latitude, Altitude
        *                     
        *Do not use a line ending, but put a single white space after the Altitude.  That is, delimit with commas as shown above, 
        *but then use one white space to delimit between successive lines of data.
        *For is that the Arduino is very poor at parsing strings, we are going to try and parse the data using numbers and math, 
        *not strings.
        *To actualize this for instance, the latitude data we get from the parsed data from the Adafruit GPS looks like this:
        *
        *            3051.8007
        *            
        *This represents 30 degrees and 51.8007 minutes. In order to parse this in Arduino using just numbers I do the following. 
        *First create three variables 'deg', 'degWhole', and 'degDec'. The variable deg will hold the final answer, degWhole holds the 
        *whole part of the number, and degDec whole part of the number to the right of the decimal. Adding degWhole to degDec gives you deg, 
        *your final answer. So, lets assume x = 3051.8007, our Latitude from the GPS.
        *
        *            degWhole = float(int(x/100));
        *            
        *            e.g for x = 3051.8007
        *            
        *                int(x/100) = int no. = 30
        *                
        *                float(int(x/100)) = float no. =30.0
        *             
        *            
        *Thus, from the value of 'x' given above it turns it into 30.0, the whole number part of degrees.
        *Now to get the fractional part, we need to take minutes and divide by 60. This will always be a number less than one
        *To get fractional part of the latitude in degrees, we do the following:
        *
        *            degDec = (x - degWhole * 100) / 60;
        *            
        *            e.g for x = 3051.8007 and degWhole = 30.0
        *            
        *            degWhole * 100 = 30.0 * 100 = 3000.0
        *            
        *            (x - degWhole * 100) / 60 = (x - 3000.0) / 60 = (3051.8007 - 3000.0) / 60 = 51.8007 / 60
        *            
        *We divide by 60 and we have converted minutes to a fraction of a degree.
        *We now have the whole part and the fractional part of the answer, so we just add those together to get the 
        *decimal number, 'deg', which is the decimal representation of our Latitude.
        *
        *             deg = degWhole + degDec;
        *             
        *Next, for we'll not be dealing with the N or S representations for the hemispheres, if the GPS is reporting ‘N’, 
        *leave the number positive. If the GPS is reporting ‘S’ (that we are in the Southern Hemisphere),  you need to 
        *make your latitude number negative. 
        *Ansd similarly, when you are doing your longitude, you need to make the longitude negative if you are in the 
        *Western Hemisphere as the one for "E' is left positive.
        *To write the KML file, Google Earth would require us to store the data as 
        *
        *              Longitude, Latitude, altitude
        *              
        *       #NOTE:
        *             -This is the reverse from what you would do if you were entering coordinates into the Google Earth 
        *              search bar. That wants Latitude first.
        *              
        *              
        *Thus, with the parsing and formatting described above, you can create a file that is almost ready to read into Google Earth.
        *The code below will create our coordinates in the correct format for KML, which Google Earth will read. It is
        *an advancement of the previous'GPS DATA TRACKER' project with some appeciable modifications.
        *
        */


SoftwareSerial myNewserial(3, 2);
                             
                              /**
                               * Creates a SoftwareSerial object named 'myNewserial'.
                               * Guided to create the new serial port at pins 3 and 
                               * 2 of the arduino which references to pins TX and RX
                               * respectively on the GPS module as per the connection
                               * table guide of 'Arduino-gps-connection-guide.png'
                               * photograph.
                               */

Adafruit_GPS GPS(&myNewserial); 
                                /**
                                 * creates 'Adafruit_GPS' module object named 'GPS' with
                                 * the new serial port created in inclusion hence the 
                                 * command '&myNewserial' in the bracket
                                 */

String NMEA1;                      //variable to hold 1st NMEA sentence
String NMEA2;                      //variable to hold 2nd NMEA sentence
                                  /**
                                   * These are the '$GPRMC data' and '$GPGGA data'
                                   */
char gps_output_character;                //to hold GPS related characters

float deg;                   //variable to hold the final latitude's degree value
float degDec;                //variable to hold the latitude's degree whole part number to the right of the decimal
float degWhole;              //variable to hold the latitude's degree whole part number of the value
                             //essential variables for creating the KML file

int chipSelect = 4;          //SD card chipselect variable set to 4 as directed in the guide
File MySensorData;           //variable to work with the SD card file object
                             //**********SD card Varialbles************

void setup()
{
  
  Serial.begin(115200);      //turns ON the serial port with high baude rate factor '115200'
  GPS.begin(9600);           //turns ON the GPS module with baude rate factor '9600'
  GPS.sendCommand("$PCGMD,33,0*6D");
                          /**
                           * command send to the GPS h/ware registers commanding it to turn OFF the 
                           * information about the 'antenna update' nuissence data that tends to come 
                           * along with other essential data required from the the GPS.
                           */
   GPS.sendCommand(PMTK_SET_NMEA_UPDATE_10HZ);  //sets GPS update rate to 10HZ(possible to change to 5HZ etc)
   GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);//request for RMC and GGA sentences only from the GPS o/put data
   delay(1000);                                 //delays GPS output printing rate

   pinMode(10, OUTPUT);        //arduino pin 10 functionality defined and specifically RESERVED for 'SD.h' library use
   SD.begin(chipSelect);       //initializes the SD card with the chipselect pin 4

   if(SD.exists("NMEA.txt"))
   {
      SD.remove("NMEA.txt");    //deletes the file 'NMEA.txt' if exists
   }                            //loop checks if the 'NMEA.txt' file exists and if exists, it deletes the file preparing the card for new data
   
   
   if(SD.exists("GPSData.txt"))
   {
      SD.remove("GPSData.txt");  //deletes the file 'GPSData.txt' if exists
   }                             //loop checks if the 'GPSData.txt' file exists and if exists, it deletes the file preparing the card for new data.
   
}

void loop() 
{

   readGPS();                       //calling user customed function

   if(GPS.fix == 1)
   {
       MySensorData = SD.open("NMEA.txt", FILE_WRITE);
                                     //opens 'NMEA.txt' as a file on the SD card ready to be written to
       MySensorData.println(NMEA1);  //prints the 1st NMEA sentence to the SD card
       MySensorData.println(NMEA2);  //prints the 2nd NMEA sentence to the SD card
       MySensorData.close();         //closes the 'NMEA.txt' file created on the SD card 
       
       
       MySensorData = SD.open("GPSData.txt", FILE_WRITE);
                                  //opens 'GPSData.txt' as a file on the SD card ready to be written to

       degWhole = float(int(((GPS.longitude) / 100))); 
                                  //gives the whole degree part of the longitude
       degDec = ((GPS.longitude) - (degWhole * 100)) / 60; 
                                  //gives the whole decimal part degree of the longitude
                                  //converts the minutes to degrees
       deg = degWhole + degDec;   //gives the complete degree value of the longitude with its fractionals part

       if(GPS.lon == "W")
       {
          deg *= -1;              
       }                           //checks whether in western hemisphere and make the logitude's complete degree value negative
       MySensorData.print(deg, 4); //prints logitude's degree value to the GPSData.txt file on the SD card
                                   //'4' denotes to 4 d.p
       MySensorData.print(", ");   //longitude, latitude seperator comma

       
       degWhole = float(int(((GPS.latitude) / 100))); //gives the whole degree part of the latitude
       degDec = ((GPS.latitude) - (degWhole * 100)) / 60; 
                                    //gives the whole decimal part degree of the latitude
                                    //converts the minutes to degrees
       deg = degWhole + degDec;     //gives the complete degree value of the latitude with its fractionals part
       
       if(GPS.lat == "S")         
       {
          deg *= -1;                 
       }                             //checks whether in southern hemisphere and make the latitude's complete degree value negative
       MySensorData.print(deg, 4);   //prints latitude's degree value to the GPSData.txt file on the SD card
                                     //'4' denotes to 4 d.p
       MySensorData.print(", ");     //latitude altitude seperator comma
       MySensorData.print(GPS.altitude); 
                                     //prints the altitude(mean height above sea level)
       MySensorData.print(" ");      //formated one line space to delimit data sets
       MySensorData.close();         //closes the 'GPSData.txt' file created on the SD card
     
   }  //function to open 'NMEA.txt' and 'GPSData.txt' file ONLY IF the GPS connection is well fixed

}

void readGPS()
{

  clearGPS();                         //calling a GPS clear function
  while(!GPS.newNMEAreceived())
  {
    gps_output_character = GPS.read();//reads the GPS output character
  }                                   //program to loop through this until good NMEA sentences data is recieved

    GPS.parse(GPS.lastNMEA());        //parse last good NMEA sentence
    NMEA1 = GPS.lastNMEA();           //variable initialization to NMEA 1st sentence data
                                      //**************READING 1ST NMEA SENTENCE DATA**************
    
  while(!GPS.newNMEAreceived())
  {
    gps_output_character = GPS.read();
  }                                   //program to loop through this until good NMEA sentences data is recieved

    GPS.parse(GPS.lastNMEA());        //parse last good NMEA sentence
    NMEA2 = GPS.lastNMEA();           //variable initialization to NMEA 2nd sentence data
                                      //**************READING 2ND NMEA SENTENCE DATA**************

     Serial.println(NMEA1);
     Serial.println(NMEA2);
     Serial.println(" ");
                                     //prints out GPS read data sentences
}        
                                     //user customed function to read GPS data sentences

void clearGPS()
{
  while(!GPS.newNMEAreceived())
  {
    gps_output_character = GPS.read();//reads the GPS output character
  }                                   //program to loop through this until good NMEA sentences data is recieved

    GPS.parse(GPS.lastNMEA());        //parse last good NMEA sentence
                                      //1st piece of information to be cleared
    
  while(!GPS.newNMEAreceived())
  {
    gps_output_character = GPS.read();//reads the GPS output character
  }                                   //program to loop through this until good NMEA sentences data is recieved

    GPS.parse(GPS.lastNMEA());        //parse last good NMEA sentence
                                      //2nd piece of information to be cleared
    
  while(!GPS.newNMEAreceived())
  {
    gps_output_character = GPS.read();//reads the GPS output character
  }                                   //program to loop through this until good NMEA sentences data is recieved

    GPS.parse(GPS.lastNMEA());        //parse last good NMEA sentence
                                      //3rd piece of information to be cleared
}
                                      //user customed function to clear the GPS old and corrupted data sentences 
                                      //clears 3 pieces of information at a go




    /**
     * ******NOTE******
     * The final thing we have to do is to put a “wrapper” around the coordinates to turn the coordinates into a 
     * .kml file Google Earth will like. 
     * This is done manually as follows, open the text file(GPSData.txt) on the SD card created by the code above,
     * and then just paste it into this KML wrapper, and save the file with a .kml extension. 
     * The KML wrapper is as follows:
     * 
     * 
           * <?xml version="1.0" encoding="UTF-8"?>
            <kml xmlns="http://www.opengis.net/kml/2.2">
            <Document>
            <Style id="yellowPoly">
            <LineStyle>
            <color>7f00ffff</color>
            <width>4</width>
            </LineStyle>
            <PolyStyle>
            <color>7f00ff00</color>
            </PolyStyle>
            </Style>
            <Placemark><styleUrl>#yellowPoly</styleUrl>
            <LineString>
            <extrude>1</extrude>
            <tesselate>1</tesselate>
            <altitudeMode>absolute</altitudeMode>
            <coordinates>
            
            
            
            
            </coordinates>
            </LineString></Placemark>
            
            </Document></kml>
      *
      *
      *Then with the 'GPSData.txt' on saved by the arduino on the SD card, 
      *   1. copy the KML wrapper code above, open notepad or any editor and paste it in.
      *   2. open the saved 'GPSData.txt' file and copy the whole data.
      *   3. In the opened new notepad file, paste the above copied 'GPSData.txt' content 
      *      between the <coordinates></coordinates> tags in the space provided.
      *   4. Then save the file as .kml file with the file type selected as 'ALL'
      *   5, Then finally open the above saved .kml file with the Google Earth to view 
      *      the track(assuming we took a walk with the above system intactly working)
      *       
      *       #NOTE:
      *             -The result track in this project appears with some 
      *              noise effects which makes it to appear quite stugger..
      *             -We can modify this system into a useful instrument of
      *              application by fabricating it into a smaller knit board
      *              with arduino uno replaced with a quite small sized version 
      *              called arduino nano which has equal functionality.
      *
     */




