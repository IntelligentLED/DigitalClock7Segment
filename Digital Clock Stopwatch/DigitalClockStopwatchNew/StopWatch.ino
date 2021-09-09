void stopwatch() {
  static uint16_t ls1;
  static uint16_t ls2;
  static uint16_t ls3;
  uint16_t tmr1 = millis();
  uint16_t tmr2 = millis();
  uint16_t tmr3 = millis();
  //  unsigned long tmr1;
  //  unsigned long tmr2;
  //  if (digitalRead(12) == HIGH) {
  //    delay(200);
  //    n++;
  //  }
  if ((digitalRead(11) == HIGH)) {
    if (stateU == LOW) {
      delay(100);
      n++;
      stateU = HIGH;
    }
  } else stateU = LOW;

  if (n == 0) {
    jam(0, next, 0, 0, 0, 0);
    di1 = di2 = di3 = di4 = di5 = dj1 = dj2 = dm1 = dm2 = 0;
  }

  if (n == 1) {
    if ((tmr2 - ls2) > 100) {
      di3++;
      if (di3 > 5) di3 = 0;
      ls2 = tmr2;
    }
    if ((tmr3 - ls3) > 10) {
      di4++;
      if (di4 > 9) {
        di4 = 0;
        di3++;
      }
      ls3 = tmr3;
    }
    if ((tmr1 - ls1) > 1000) {
      l++;
      di1 = l / 10;
      if (di1 < 5) di2 = 0;
      di2 = l - (di1 * 10);
      if (di1 > 5) {
        di1 = 0;
        l = 0;
        dm2++;
        if (dm2 > 9) {
          dm2 = 0;
          dm1++;
          if (dm1 > 5) {
            dm1 = 0;
            dj2++;
            if (dj2 > 9) {
              dj2 = 0;
              dj1++;
              if (dj1 > 5) {
                dj1 = 0;
              }
            }
          }
        }
      }
      ls1 = tmr1;
    }
    if (dj1 + dj2 != 0)    jam(0, next, dj1, dj2, dm1, dm2);
    else if ((dm1 + dm2 != 0) && (dj1 + dj2 == 0))    jam(0, next, dm1, dm2, di1, di2);
    else    jam(0, next, di1, di2, di3, di4);
    blynk();
  }
  if (n == 2) {
    if (dj1 + dj2 != 0)    jam(0, next, dj1, dj2, dm1, dm2);
    else if ((dm1 + dm2 != 0) && (dj1 + dj2 == 0))    jam(0, next, dm1, dm2, di1, di2);
    else    jam(0, next, di1, di2, di3, di4);
    //    if ((dj1 + dj2 == 0) && (dm1 + dm2 == 0))    jam(0, next, di1, di2, di3, di4);
    //    if ((dm1 + dm2 != 0) && (dj1 + dj2 == 0))    jam(0, next, dm1, dm2, di1, di2);
    //    if (dj1 + dj2 != 0)    jam(0, next, dj1, dj2, dm1, dm2);
    digitalWrite(13, 0);
  }
  if (n == 3) {
    jam(0, next, 0, 0, 0, 0);
    n = l = 0;
    digitalWrite(13, 1);
  }
}
