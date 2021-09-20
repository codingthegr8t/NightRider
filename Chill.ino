 void f_Chill (){
  int i;
  
  i = 0;
  timer = 5;
  while ( i < 10) {
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
      i++;
      timer+=10;
    }
    digitalWrite(pinArray[count], LOW);
 }
