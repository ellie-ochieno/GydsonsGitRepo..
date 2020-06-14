#include <Adafruit_GPS.h>   //loads the GPS library
#include <SoftwareSerial.h> //loads the SoftwareSerial library

                            /**This(SoftwareSerial.h) creates a new serial port apart from the normal 
                             * arduino serial port to be used by the GPS 
                             */

                //***************PROJECT: USING ARDUINO AND THE GPS TRACKER*************
                


             /**
              * GPS - Global Positioning System
              * We'll be using the 'Adafruit Ultimate GPS module' which is quite excellecnt and affordable and far more, works well 
              * at extreme elevations, making it ideal for our Edge of Space/High Altitude Balloon work. The circuit connection for the
              * project is as shown in 'arduino-gps.jpg' photograph in arduino projects dir. GPS connection table guide is also provided
              * in 'Arduino-gps-connection-guide.png' photograph in the dir.
              * The goal in this lesson is to get the GPS connected, and get it reading NMEA sentences. NMEA is a data format used by GPS 
              * and mapping devices and software to keep track of position coordinates. There are lots of different NMEA sentences, but the 
              * two that contain the most useful information are the $GPRMC and $GPGGA sentences. Two only sample out these two spcified 
              * piece of information, we'll be required program/modify the GPS module. 
              * To get full NMEA sentences information, the whole project setup with the mdule needs to be placed in a clear open spaced 
              * place.
              * 
              * 
              *      ******ADVANCED*******
              *       
              *       #NMEA(National Marine Electronics Association) data.
              *        -This data includes the complete PVT (position, velocity, time) solution computed by 
              *         the GPS receiver. The idea of NMEA is to send a line of data called a sentence that 
              *         is totally self contained and independent from other sentences.
              *         
              *       #$GPRMC data
              *        -GPS specific information. Platform: OEM719, OEM729, OEM7700, OEM7720, PwrPak7. 
              *        -This log contains time, date, position, track made good and speed data provided 
              *         by the GPS navigation receiver.
              *         
              *       #$GPGGA data
              *        -The GPGGA log outputs these messages without waiting for a valid almanac. Instead, 
              *         it uses a UTC(Coordinated Universal Time) time, calculated with default parameters. In this case, the UTC time 
              *         status (see the TIME log) is set to WARNING since it may not be one hundred percent 
              *         accurate. When a valid almanac is available, the receiver uses the real ...
              *         
              * 
              * Our interest is in creating a location tracker for our High Altitude Balloon work, and the $GPRMC and $GPGGA sentences contain 
              * all the information and data we would need for that work. These sentences contain the lattitude, longitude, time, altitude, 
              * and velocity.
              * The GPS modules are pretty easy to work with. When you apply power to the GPS, it immediately starts spitting out NMEA sentences 
              * to its serial port. Our job on the arduino side is to simply read these data strings, and then parse them into useful data. 
              *  The thing that is a challenge is that they constantly spit out data, whether you want it, or whether you are ready for it or not. 
              *  In developing the software, we have to be mindful the the data is always spewing out of the GPS. Typically, we will have other 
              *  components on our package, like temperature, pressure and inertial sensors. While our arduino is out making measurements on 
              *  these other sensors, data continues to stream in from the GPS, likely overflowing our serial buffer. When we return to make 
              *  a GPS measurement, it is very likely that the serial buffer will have old or corrupt GPS data in it. Hence,  we must be 
              *  mindful to deal with this issue in developing our software.
              * 
                *     #NOTE:
                *         -Most GPS trackers in ballooning high altitude systems would stop working 
                *          at approximately 60,000 ft for they are turned OFF if the manufacturers
                *          misread the government regulations and never complied.
                *         -For complied manufacturers, the slow moving GPS installed trackers would 
                *          successifuly fly above the 60,000 ft at high altitudes e.g those from the
                *          above recommended manufacturers 'Adafruit Ultimate GPS module'.
                *          
                *          
                *          
                *In order for this software to work, you need to download and install the 'Adafruit GPS Library'.
                *To install this we follow the procedure below:
                *      1. Go to the site and download the 'Adafruit GPS Library' zipped file.
                *      2. Open the zip folder and move the folder inside it to the Desktop and
                *         rename it e.g adafruit-gps
                *      3. Then finally, move this new named folder (adafruit-gps) to the arduino 
                *         sketchbook library. 
                *        -Thus we now have the library loaded. To view it from the arduino IDE, we
                *         have to restart it so that it could load the library ready to use.
                *        #NOTE:
                *              -This is the procedure for installing libraries to the arduino IDE
                *               s/ware
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



void setup()
{
  Serial.begin(115200);   //turns ON the serial port with high baude rate factor '115200'
  GPS.begin(9600);        //turns ON the GPS module with baude rate factor '9600'
  GPS.sendCommand("$PCGMD,33,0*6D");
                          /**
                           * command send to the GPS h/ware rgisters commanding it to turn OFF the 
                           * information about the 'antenna update' nuissence data that tends to come 
                           * along with other essential data required from the the GPS.
                           */
   GPS.sendCommand(PMTK_SET_NMEA_UPDATE_10HZ);  //sets GPS update rate to 10HZ(possible to change to 5HZ etc)
   GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);//request for RMC and GGA sentences only
   delay(1000);                                 //delays GPS output printing rate
}

void loop() 
{
  readGPS();             //calling user customed function
  delay(12);             //GPS data reading delay to allow time for reading temp and pressure data( if available)
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
            */
