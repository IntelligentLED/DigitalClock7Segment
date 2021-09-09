void updateread() {
  static uint16_t ls1;
  uint16_t tmr1 = millis();
  if ((tmr1 - ls1) >= 100) {
    //    dt = RTC.getDateTime();
    btnStateSet = digitalRead(12);
    btnStateUp = digitalRead(11);
    btnStateNext = digitalRead(10);
    ls1 = tmr1;
  }
  if ((btnStateSet == HIGH) && (Nmode == 0)) {
    if (stateS == LOW) {
      sett++;
      stateS = HIGH;
    }
  }
  if (btnStateSet == LOW)stateS = LOW;

  if ((btnStateUp == HIGH) && (Nmode == 0)) {
    if (sett == 1 || sett == 3|| sett == 5|| sett == 7) {
      upp = 0;
      if (stateU == LOW) {
        upp = 1;
        stateU = HIGH;
      }
    }
  }
  if (btnStateUp == LOW) {
    upp = 0;
    stateU = LOW;
  }

  if ((btnStateNext == HIGH) && (sett == 0)) {
    if (stateN == LOW) {
      Nmode++;
      stateN = HIGH;
    }
  }
  if (btnStateNext == LOW) stateN = LOW;

  switch (Nmode) {
    case 0 :
      jamDigital();
      break;
    case 1 :
      stopwatch();
      break;
    default:
      Nmode = 0;
      break;
  }
}

