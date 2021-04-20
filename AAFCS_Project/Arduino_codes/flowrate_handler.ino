    //flowrate sensor control
int flowSnsrPin = 2;
    //sensor pin dfn
double flowRate;
volatile int count;
    //control variables dfn

void setup() {
  pinMode(flowSnsrPin, INPUT);
  attachInterrupt(0, Flow, RISING);
  Serial.begin(9600);
    //control settings
}

void loop() {
  count = 0;
  interrupts();
  delay(1000);
  noInterrupts();
  flowRate = (count / 7.75);
     //flow rate calibration
  Serial.println(String(flowRate)+" L/min");
}

void Flow()
{
  count++
      //increments counter by 1  
}
