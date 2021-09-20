 void f_ledLinks(){
  
  timer = 20;
  
  for (count=7;count>0; count--) {
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count - 1], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer*2);
  }
  digitalWrite(pinArray[count], LOW);
 }
