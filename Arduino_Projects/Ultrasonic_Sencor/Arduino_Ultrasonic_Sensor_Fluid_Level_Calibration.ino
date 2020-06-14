



                //***************PROJECT: TO CALIBRATE WATER LEVELS IN THE TANK USING ARDUINO AND ULTRASONIC SENSOR**************




int trigrPin = 10;            //sensor trigger pin variable connected to arduino pin 13
int echoPin = 11;             //sensor echo pin variable connected to arduino pin 11
float pingTime;               //variable to hold ping signal transit time
float speedOfSound;           //variable to hold the value for speed of sound to be computed
float targetDistance;         //variable holds the value for signal's target distance
float tnkCapacity;            //tank volume in metre cubed



void setup() {
  Serial.begin(9600);          //serial port turned ON
  pinMode(trigrPin, OUTPUT);
  pinMode(echoPin, OUTPUT);
                                //pin actions defined for output purposes

  Serial.println(" ");
  Serial.println(" ************FLUID LEVEL CALIBRATION SYSTEM***************");

  
  Serial.println(" ");
  Serial.println(" Enter the following tank dimensional properties:");
  Serial.println(" ");
  Serial.println("     1. Shape:");
  Serial.println("        Enter");
  Serial.println("             1 for Cylindrical");
  Serial.println("             2 for Cuboid");
  Serial.println("             3 for Cubed");
  Serial.println(" ");
  
  while(Serial.available() == 0)
  {}                             
                                 //halts pogram execution waiting for user input
  int tnkshape = Serial.parseInt(); //reads user input
  

  if (tnkshape == 1)
  {
    float tnkDiameter, tnkHeight1, tnkCrosxnArea;
                                   //tank property variables
    Serial.println(" ");
    Serial.println("  Tank shape: Cylindrical");
    Serial.println(" ");
    Serial.println("     2. The height of the tank in metres?");
    Serial.print("       =  ");    //prompt for user input
    
    while(Serial.available() == 0)
    {}                             
                                   //halts pogram execution waiting for user input
    tnkHeight1 = Serial.parseFloat();
                                   //reads user input
                                   
    Serial.println(" ");
    Serial.println("     3. The diameter of the tank in metres?");
    Serial.print("       =  ");     //prompt for user input
    
    while(Serial.available() == 0)
    {}                             
                                    //halts pogram execution waiting for user input
    tnkDiameter = Serial.parseFloat(); 
                                    //reads user input
    
    float pi = 3.141592654;     
    float tnkR =  tnkDiameter / 2;  //tank radius 
  
    tnkCrosxnArea = pi * tnkR * tnkR;
                                    //computes the cross-sectional area of the tank
    tnkCapacity = tnkCrosxnArea * tnkHeight1;
                                    //computes tank volume
                                    
    Serial.println(" ");
    Serial.print(" Tank Volume = ");
    Serial.print(tnkCapacity);
    Serial.println(" m3");
    Serial.println(" ");
    Serial.println(" *************Done*************");
    Serial.println(" ");
  }
                          //CYLINDRICAL SHAPED TANK
  else if (tnkshape == 2)
  {
    float tnkLength, tnkWidth, tnkHeight2;
                                   //tank property variables
    Serial.println(" ");
    Serial.println("  Tank shape: Cuboid");
    Serial.println(" ");
    Serial.println("     2. The height of the tank in metres?");
    Serial.print("       =  ");    //prompt for user input
    
    while(Serial.available() == 0)
    {}                             
                                   //halts pogram execution waiting for user input
    tnkHeight2 = Serial.parseFloat();
                                   //reads user input
                                   
    Serial.println(" ");
    Serial.println("     3. The width of the tank in metres?");
    Serial.print("       =  ");     //prompt for user input
    
    while(Serial.available() == 0)
    {}                             
                                    //halts pogram execution waiting for user input
    tnkWidth = Serial.parseFloat(); 
                                    //reads user input
        
    tnkCapacity = tnkLength * tnkWidth * tnkHeight2;
                                    //computes tank volume
                                    
    Serial.println(" ");
    Serial.print(" Tank Volume = ");
    Serial.print(tnkCapacity);
    Serial.println(" m3");
    Serial.println(" ");
    Serial.println(" *************Done*************");
    Serial.println(" ");
  }
                          //CUBOID SHAPED TANK
  else if (tnkshape == 3)
  {
    float tnkSideLength;
                                   //tank property variable
    Serial.println(" ");
    Serial.println("  Tank shape: Cubed");
    Serial.println(" ");
    Serial.println("     2. The side length of the tank in metres?");
    Serial.print("       =  ");    //prompt for user input
    
    while(Serial.available() == 0)
    {}                             
                                   //halts pogram execution waiting for user input
    tnkSideLength = Serial.parseFloat();
                                   //reads user input
                                   
    tnkCapacity = tnkSideLength * tnkSideLength * tnkSideLength;
                                    //computes tank volume
                                    
    Serial.println(" ");
    Serial.print(" Tank Volume = ");
    Serial.print(tnkCapacity);
    Serial.println(" m3");
    Serial.println(" ");
    Serial.println(" *************Done*************");
    Serial.println(" ");
  }
                          //CUBE SHAPED TANK
  else
  {
    Serial.println(" ");
    Serial.println("  Error! Undefined choice for tank shape");
    Serial.println("  Please restart the program and enter either 1, 2 or 3 ");
    Serial.println("  Program ending ...");
    Serial.println(" ");
  }
                          //EXCEPTION
}

void loop() 
{
  
}
