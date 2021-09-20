int pinArray[] = {2, 3, 4, 5, 6, 7, 8, 9};
int count = 0;
int timer;

unsigned long delaytime = 100;
int sensorValue = 0; // value read from the pot
int outputValue = 0; // value output to the PWM (analog out)
const int analogInPin = A0;
 
int sensorValue1 = 0; // value read from the pot
int outputValue1 = 0; // value output to the PWM (analog out)
const int analogInPin1 = A1;
 
int sensorValue2 = 0; // value read from the pot
int outputValue2 = 0; // value output to the PWM (analog out)
//const int digitalInPin1 = A2;
const int digitalInPin2 = A2;

void setup()  {
  for (count=0;count<8;count++) {
  pinMode(pinArray[count], OUTPUT);
  }
  pinMode(A2, INPUT_PULLUP);
  // Zet het display uit voor het geval dat hij aan stond:
//  lc.shutdown(0, false);
//  // Zet de helderheid op gemiddeld:
//  lc.setIntensity(0, 4);
//  // Maak het scherm leeg:
//  lc.clearDisplay(0);
}

void loop() {
  
   sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
 
  sensorValue1 = analogRead(analogInPin1);
  // map it to the range of the analog out:
  outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
 
  sensorValue2 = digitalRead(digitalInPin2);
  // map it to the range of the digital out:
  outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
  outputValue2 = sensorValue2;

  if (outputValue1 < 100) {
    f_ledStandaard();
  }
  
  if (outputValue1 > 150) {
    f_Booster();
  }
  
  if (outputValue < 100 ) {
    f_ledLinks();  
  }
  
  if (outputValue > 150 ) {
    f_ledRechts();
  }
  
  if (outputValue2 == 0 ) {
    f_ledStandaard();
    f_Booster();
    f_ledLinks();
    f_ledRechts();
  }
}
