void f_ledStandaard (){
  int i;

  timer = 20;
  i = 0;
  while (i < 10){
     for (count=0;count<7; count++) {
        digitalWrite(pinArray[count], HIGH);
        delay(timer);
        digitalWrite(pinArray[count + 1], HIGH);
        delay(timer);
        digitalWrite(pinArray[count], LOW);
        delay(timer*2);
       }
      for (count=7;count>0; count--) {
        digitalWrite(pinArray[count], HIGH);
        delay(timer);
        digitalWrite(pinArray[count - 1], HIGH);
        delay(timer);
        digitalWrite(pinArray[count], LOW);
        delay(timer*2);
        }
      i++;
  }
  digitalWrite(pinArray[count], LOW);
}
