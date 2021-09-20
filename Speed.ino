 void f_Booster (){
  int i;
  
  i = 0;
  timer = 50;
  while ( i < 15) {
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
      timer-=5;
        if ( timer < 10){
        timer = 5;
        }
    }
    digitalWrite(pinArray[count], LOW);
 }
