

        //************12. VARIABLES MANIPULATION AND USER INPUTS*******************




          /**
                -Just like in other coding languages, in arduino we can have programs that 
                 take different properties from the user and print its out on the screen.
                -consider the sample project below:
          **/


 
             String usrName;    //variable to hold user name
             int age;           //variable to hold user age
             float height;      //variable to hold user height
                                //variables declaration
             
             void setup()
             {
                  Serial.begin(9600);    //serial port turned ON
                  
                  Serial.print(" Enter your name :  ");   //prompt for user input
                  while(Serial.available() == 0)
                  {}                                      //puts the program to halt waiting for
                                                          //user input
                  usrName = Serial.readString();          //read user input assigning it to the 
                                                          //declared variable
                  
                  
                  Serial.print(" Enter your age :  ");    //prompt for user input
                  while(Serial.available() == 0)
                  {}                                      //puts the program to halt waiting for user input
                  age = Serial.parseInt();                //read user input assigning it to the declared variable
                  
                  
                  Serial.print(" Enter your height :  "); //prompt for user input
                  while(Serial.available() == 0) 
                  {}                                      //puts the program to halt waiting for user input
                  height = Serial.parseFloat();           //read user input assigning it to the declared variable
                  
                  
                  
                  Serial.println(" ");
                  Serial.println(" ");
                  Serial.print("Thank you ");
                  Serial.println(usrName);            
                                                          //prints out username
                  Serial.print("You are ");
                  Serial.print(age);    
                  Serial.println(" years old ");           
                                                          //prints out age
                  Serial.print("You are ");
                  Serial.print(height);     
                  Serial.println(" ft ");          
                                                          //prints out height
             }
             
             void loop()
             {
             
             }
             
