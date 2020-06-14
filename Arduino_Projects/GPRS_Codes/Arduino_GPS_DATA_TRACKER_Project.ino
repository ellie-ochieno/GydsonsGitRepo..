#include <SD.h>             //loads the SD card library
#include <SPI.h>     //loads the SPI communication library
#include <Adafruit_GPS.h>   //loads the GPS library
#include <SoftwareSerial.h> //loads the SoftwareSerial library

                            /**This(SoftwareSerial.h) creates a new serial port apart from the normal 
                             * arduino serial port to be used by the GPS 
                             */



                //***************PROJECT:  GPS DATA TRACKER*************
                


       /**
        * In this project we'll be using the 'adafruit GPS ultimate' connected to the arduino board micro-controller.
        * It forms an integration to the 'Arduino_and_The_GPS_Tracker_Project' by providing quite embedded devices to
        * help in data manipulation e.g the 'Virtuabotix SD card Reader/Writer.
        * The whole project system will be powered by a 9V recharge Battery Clip which would allow mobility with the device to get more clear
        * GPS information. GPS connection hook up will be as in the preceeding project above and the SD card connection would be as in the 
        * 'Arduino_Pressure_Sensor_and_Saving_to_SD_card_Project' in the arduino projects dir.
        * 
        * Thus, from the 'Arduino_and_The_GPS_Tracker_Project' we have the code as follows with soe slight modification...
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


int chipSelect = 4;          //SD card chipselect variable set to 4 as directed in the guide
File MySensorData;           //variable to work with the SD card file object

              //**********SD card Varialbles************

void setup()
{
  
  Serial.begin(115200);   //turns ON the serial port with high baude rate factor '115200'
  GPS.begin(9600);        //turns ON the GPS module with baude rate factor '9600'
  GPS.sendCommand("$PCGMD,33,0*6D");
                          /**
                           * command send to the GPS h/ware registers commanding it to turn OFF the 
                           * information about the 'antenna update' nuissence data that tends to come 
                           * along with other essential data required from the the GPS.
                           */
   GPS.sendCommand(PMTK_SET_NMEA_UPDATE_10HZ);  //sets GPS update rate to 10HZ(possible to change to 5HZ etc)
   GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);//request for RMC and GGA sentences only from the GPS o/put data
   delay(1000);                                 //delays GPS output printing rate

   pinMode(10, OUTPUT);   //arduino pin 10 functionality defined and specifically RESERVED for 'SD.h' library use
   SD.begin(chipSelect);  //initializes the SD card with the chipselect pin 4

   if(SD.exists("NMEA.txt"))
   {
      SD.remove("NMEA.txt");//deletes the file 'NMEA.txt' if exists
   }         //loop checks if the 'NMEA.txt' file exists and if exists, it deletes the file preparing the card for new data
   
   
   if(SD.exists("GPSData.txt"))
   {
      SD.remove("GPSData.txt");//deletes the file 'GPSData.txt' if exists
   }         //loop checks if the 'GPSData.txt' file exists and if exists, it deletes the file preparing the card for new data.
   
}

void loop() 
{

   readGPS();                                 //calling user customed function

   if(GPS.fix == 1)
   {
       MySensorData = SD.open("NMEA.txt", FILE_WRITE);
                                                  //opens 'NMEA.txt' as a file on the SD card ready to be written to
       MySensorData.println(NMEA1);               //prints the 1st NMEA sentence to the SD card
       MySensorData.println(NMEA2);               //prints the 2nd NMEA sentence to the SD card
       MySensorData.close();                      //closes the 'NMEA.txt' file created on the SD card 
       
       
       MySensorData = SD.open("GPSData.txt", FILE_WRITE);
                                                    //opens 'GPSData.txt' as a file on the SD card ready to be written to
       MySensorData.print(GPS.latitude, 4);          //prints the GPS determined latitude to 4 d.p
       MySensorData.print(GPS.lat);                  //shows the hemisphere either N or S
       MySensorData.print(", ");
       MySensorData.print(GPS.longitude, 4);         //prints the GPS determined longitude to 4 d.p
       MySensorData.print(GPS.lon);                  //shows the hemispheren either E or W
       MySensorData.print(", ");
       MySensorData.println(GPS.altitude);           //prints the altitude(height above sea level)
       MySensorData.close();                         //closes the 'GPSData.txt' file created on the SD card 
                                             
   } //function to open 'NMEA.txt' and 'GPSData.txt' file ONLY IF the GPS connection is well fixed

}

void readGPS()
{

  clearGPS();              //calling a GPS clear function
  
  while(!GPS.newNMEAreceived())
  {
    gps_output_character = GPS.read();   //reads the GPS output character
  }                      //program to loop through this until good NMEA sentences data is recieved

    GPS.parse(GPS.lastNMEA()); //parse last good NMEA sentence
    NMEA1 = GPS.lastNMEA();  //variable initialization to NMEA 1st sentence data
    
                             //**************READING 1ST NMEA SENTENCE DATA**************
    
  while(!GPS.newNMEAreceived())
  {
    gps_output_character = GPS.read();
  }                          //program to loop through this until good NMEA sentences data is recieved

    GPS.parse(GPS.lastNMEA()); //parse last good NMEA sentence
    NMEA2 = GPS.lastNMEA();  //variable initialization to NMEA 2nd sentence data
    
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
    gps_output_character = GPS.read();   //reads the GPS output character
  }                      //program to loop through this until good NMEA sentences data is recieved

    GPS.parse(GPS.lastNMEA()); //parse last good NMEA sentence
    
                               //1st piece of information to be cleared
    
  while(!GPS.newNMEAreceived())
  {
    gps_output_character = GPS.read();   //reads the GPS output character
  }                      //program to loop through this until good NMEA sentences data is recieved

    GPS.parse(GPS.lastNMEA()); //parse last good NMEA sentence
    
                               //2nd piece of information to be cleared
    
  while(!GPS.newNMEAreceived())
  {
    gps_output_character = GPS.read();   //reads the GPS output character
  }                      //program to loop through this until good NMEA sentences data is recieved

    GPS.parse(GPS.lastNMEA()); //parse last good NMEA sentence
    
                               //3rd piece of information to be cleared
}
                             //user customed function to clear the GPS old and corrupted data sentences 
                             //clears 3 pieces of information at a go



           /**
            * APPLICATION:
            *              -This forms an essential and fundamental portion of a GPS tracker project in High altitude Ballooning Systems
            *              -With the data retrieved from the 'GPSData.txt' file we can clearly detect our location when
            *               this data is entered into the Google Search Earth web app search bar. For instance the detected data 
            *               could be in the form:
            *               
            *                         3051.7937N,10036.0273W,771.40
            *               
            *               This means we're at
            *                
            *                         latitude 30 degrees 51.7937 minutes NORTH 
            *                         longitude 100 degrees 36.0273 minutes WEST
            *                         altitude 771.40 m 
            *                         
            *                   #NOTE:
            *                         Minutes are read fro the 2nd digit to the left of the decimal place(d.p)
            *                         
            *               Thus, to search this on Google Search Earth engine we enter the data as
            *               
            *                        30 51.7937N,100 36.0273W
            *               
            *               
            *               
            * $GPRMC and the $GPGGA among other data not requested in this project are collectively called NMEA sentences.
            * If the working GPS module has the option to turn OFF other sentences, then we can simplify the GPS o/put to get only 
            * the data we're interested in. Otherwise if not possible we could focus only on the NMEA sentences of interest as the ones
            * determined above.
            * 
            * 
            *       ************MMEA SENTENCES EXPLANATION*****************
            * 
            *        1. $GPSRMC data
            *        
            *           -for instance assume to have the NMEA sentence as:
            *           
            *            $GPSRMC,194530.000,A,3051.8007,N,10033.9989,W,1.49,111.67,310714...A
            *            
            *            -'$GPSRMC' simply tells the type of NMEA sentence is on the line.
            *            -The long number proceeding it is the Coordinated Universal Time(UTC). Where, 194530.000
            *             means 19.45 and 30.000 seconds in UTC. Thus from this we can simply convert into our various 
            *             local time. 
            *             
            *            -The next letter defines the state of the signal i.e whether Active(A) or Void(V). 'A' means the
            *             signal is bieng recieved and everything is working properly. A 'V' menas no signal is bieng 
            *             recieved.
            *             
            *            -Next, 3051.8007,N, refers to the latitude rad as
            *             30 degrees, 51.8007 minutes in Northern (N) hemisphere
            *             
            *            -Following this is the longitude 10033.9989,W, read as
            *             100 degrees, 33.9989 minutes in Western (W) hemisphere
            *             
            *            -Preceeding the above number is 1.49.
            *             This is the velocity(speed) in knots
            *             
            *            -Next 111.67 refers to the track angle.
            *            
            *            -Finally 310714 refers to the date in 'dd/mm/yy format i.e
            *             31/07/2014
            *             
            *
            *The challenge however is that if you want to log data from your GPS and then show a track of where you have been, you will have to create 
            *a KML or KMZ file. These files are even more particular about the format of the coordinate data. These files want both latitude and longitude 
            *as decimal numbers, so we must convert degrees, minutes to decimal degrees. You can do this simply by realizing that there are sixty minutes 
            *in a degree. So, for the case above, 51.8007 Minutes = 51.8007/60 degrees = .86335 degrees. So, to make a KML file that Google Earth will like, 
            *30 51.8007N should be converted to 30.86335. We still have to deal with the N and W. KML files do not know what to do with the N, S, E, W. So, 
            *you must do the conversion. On Latitude, if you have a N, leave Latitude positive, if you have a S make your Latitude negative. On Longitude, 
            *if you have an E leave your number positive. If you have a W make your Longitude negative. Following these rules:
            *               
            *                         3051.8007,N,10035.9989,W
            *Should become: 
            *
            *                         30.8633, -100.5999
            *                         
            *Those numbers will not only display properly in a KML file, they will also work if directly typed into the search bar on Google Earth.
            *      
            *      #NOTE:
            *          -In the KML file, you should put Longitude first, followed by Latitude. 
            *           Opposite of how you put the numbers in Google earth, 
            *           which wants latitude followed by longitude.
            *      
            *      
            * 
            *     2. $GPGGA data
            *     
            *        -This has a couple of nuggets of info we need, particularly if we are doing High Altitude Ballooning/Edge of Space work. 
            *         Lets look at the $GPGGA sentence:
            *         
            *                   $GPGGA,194530.000,3051.8007,N,10035.9989,W,1,4,2.18,746.4,M,-22.2,M,,*6B
            *                   
            *        i) -Again, the first number represents the time.
            *        
            *            194530.000 would be 19:45 and 30.000 seconds, UTC
            *         
            *        ii) The next numbers represent Latitude and Longitude, just as in the $GPRMC sentence above.
            *         
            *        iii)-Now the next number, '1' above, is the fix quality. a '1' means you have a fix and a '0' means you do not have a fix. 
            *             If there is a different number it is more details on the type of fix you have. 
            *         
            *        iv) -Next number is how many satellites you are tracking. For us, '4'. The larger number here the better.
            *        
            *        v)  -Next up, '2.18' is the horizontal dilution of position. 
            *        
            *        vi) -Next one is an important one . . . '746.4' is the altitude in meters above mean seal level. 
            *             This is hugely important for projects like high altitude ballooning. 
            *             It is a direct indication of your altitude.
            *             
            *        vii) -Next number is the altitude of mean sea level where you are. This is something you do not need to worry about 
            *              in most applications but is related to a geometric approximation of the earth as an ellipsoid. 
            *              
            *              *****************ADVANCED*********************************
            *              
            *              *******WGS84 Ellipsoid********
            *              
            *              -The World Geodetic System (WGS) is a standard for use in cartography, geodesy, and navigation including GPS.
            *               It comprises a standard coordinate system for the Earth, a standard spheroidal reference surface (the datum 
            *               or reference ellipsoid) for raw altitude data, and a gravitational equipotential surface (the geoid) 
            *               that defines the nominal sea level.
            *               
            *               ******KML File******
            *               
            *              -Keyhole Markup Language(KML) is a file format used to display geographic data in an Earth browser such as Google Earth.
            *               You can create KML files to pinpoint locations, add image overlays , and expose rich data in new 
            *               ways. KML is an international standard maintained by the Open Geospatial Consortium, Inc. (OGC).
            *               
            *               ***HORIZONTAL DILLUTION OF POSITION (DOP)******
            *               
            *               -Dilution of precision (DOP), or geometric dilution of precision (GDOP), is a term used in satellite navigation 
            *                and geomatics engineering to specify the additional multiplicative effect of navigation satellite geometry on 
            *                positional measurement precision.
            *               
            *              **********************************************************
            *              
            *              
            *   **********SUMMARY**********
            *
            *    -sing the  $GPRMC and $GPGGA NMEA sentences, we can get our latitude and longitude coordinates, and convert them to numbers 
            *     that can be recognized by Google Earth, or put into a KML file. We also have our speed in knots, and our altitude. 
            *     These are all the things we would want for projects like unmanned aerial drones, or high altitude balloons.
            *          
            *   ***************************
            *         
            */




            
