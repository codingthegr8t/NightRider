 void f_Booster(){
  
  timer = 5;
  
  for (count=0;count<7; count++) {
    digitalWrite(pinArray[count + 1], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer*2);
  }
  for (count=7;count>0; count--) {
    digitalWrite(pinArray[count - 1], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer*2);
  }
  digitalWrite(pinArray[count], LOW);
}
