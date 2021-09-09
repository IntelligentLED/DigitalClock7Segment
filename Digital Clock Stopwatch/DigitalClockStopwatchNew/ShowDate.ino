void updateDate() {
  static uint16_t ls1;
  int timeShow = 5000;
  uint16_t tmr1 = millis();
  if ((tmr1 - ls1) < timeShow) cc = 0;
  if (((tmr1 - ls1) > timeShow) && ((tmr1 - ls1) < timeShow + 1500) && sett == 0) cc = 3;
  if (((tmr1 - ls1) > timeShow+1500) && ((tmr1 - ls1) < timeShow + 3000) && sett == 0) cc = 1;
  if (((tmr1 - ls1) > timeShow+3000) && ((tmr1 - ls1) < timeShow + 4000) && sett == 0) cc = 2;

  if ((tmr1 - ls1) > timeShow + 4000) {
    ls1 = tmr1;
    upp = next = 0;
  }

}

void showDate() {

  tgl = RTC.getDay();
  bln = RTC.getMonth();

  if (tgl > 9)
  {
    tgl1 = tgl / 10;
    tgl2 = tgl - (tgl1 * 10);
  }
  else
  {
    tgl1 = 0;
    tgl2 = tgl2;
  }
  if (bln > 9)
  {
    bln1 = bln / 10;
    bln2 = bln - (bln1 * 10);
  }
  else
  {
    bln1 = 0;
    bln2 = bln;
  }
  jam(sett, next, tgl1, tgl2, bln1, bln2);
  digitalWrite(13, 1);
}

