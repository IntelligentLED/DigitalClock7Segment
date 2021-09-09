
void jamDigital() {
  if (sett == 0) {
    updateDate();
    har = RTC.getWeek();
    //    hm = RTC.getHourMode();
    hour = RTC.getHours();
    if (hm == 1) {
      jamm = hour - 12;
    }
    else     jamm = hour;
    //kalkulasi jam
    if (jamm > 9) {
      jam1 = jamm / 10;
      jam2 = jamm - (jam1 * 10);
    } else {
      jam1 = 0;
      jam2 = jamm;
    }

    if (RTC.getMinutes() > 9) {
      min1 = RTC.getMinutes() / 10;
      min2 = RTC.getMinutes() - (min1 * 10);
    } else {
      min1 = 0;
      min2 = RTC.getMinutes();
    }
    if (cc == 0) blynk();
    //kalkulasi tanggal
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
      tgl2 = tgl;
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

    thn = RTC.getYear();

    thn1 = thn / 1000;
    thn2 = (thn - (thn1 * 1000)) / 100;
    thn3 = (thn - (thn2 * 100) - (thn1 * 1000)) / 10;
    thn4 = (thn - (thn3 * 10) - (thn2 * 100) - (thn1 * 1000));
  }

  if (sett == 1) {
    cc = 0;
    if (btnStateNext == HIGH) {
      if (stateN == LOW) {
        next++;
        if (next > 3 ) next = 0;
        stateN = HIGH;
      }
    }
    else stateN = LOW;
    if (next == 0 && upp == HIGH) {
      jam1++;
      if (jam1 > 2 - hm) jam1 = 0;
    }
    if (next == 1 && upp == HIGH) {
      jam2++;
      if (jam2 > 9) jam2 = 0;
    }
    if (next == 2 && upp == HIGH) {
      min1++;
      if (min1 > 5) min1 = 0;
    }
    if (next == 3 && upp == HIGH) {
      min2++;
      if (min2 > 9) min2 = 0;
    }
    //    int totjam = (jam1 * 10) + jam2;
    //    int totmin = (min1 * 10) + min2;
    digitalWrite(13, 1);
  }
  if (sett == 2) {
    if (hm == 1) {
      //      jamm = hour - 12;
      hour = (jam1 * 10) + jam2 + 12;
    }
    else hour = (jam1 * 10) + jam2;
    RTC.setDay(RTC.getDay());
    RTC.setMonth(RTC.getMonth());
    RTC.setYear(RTC.getYear());
    RTC.setWeek(RTC.getWeek());
    RTC.setHourMode(RTC.getHourMode());
    RTC.setHours(hour);
    RTC.setMinutes((min1 * 10) + min2);
    RTC.setSeconds(RTC.getSeconds());
    Serial.print(RTC.getHours());
    Serial.print(" : ");
    Serial.print(RTC.getMinutes());
    if (RTC.getHourMode() == CLOCK_H12)
    {
      switch (RTC.getMeridiem()) {
        case HOUR_AM:
          Serial.print(" AM");
          break;
        case HOUR_PM:
          Serial.print(" PM");
          break;
      }
    }
    Serial.println("");
    Serial.println("Setting is finish");
    sett = 3; next = 0;
  }

  if (sett == 3) {
    cc = 1;
    if (btnStateNext == HIGH) {
      if (stateN == LOW) {
        next++;
        if (next > 3 ) next = 0;
        stateN = HIGH;
      }
    }
    else stateN = LOW;

    if (next == 0 && upp == HIGH) {
      tgl1++;
      if (tgl1 > 3) tgl1 = 0;
    }
    if (next == 1 && upp == HIGH) {
      tgl2++;
      if (tgl2 > 9) tgl2 = 0;
    }
    if (next == 2 && upp == HIGH) {
      bln1++;
      if (bln1 > 1) bln1 = 0;
    }
    if (next == 3 && upp == HIGH) {
      bln2++;
      if (bln2 > 9) bln2 = 0;
    }
    digitalWrite(13, 1);
  }

  if (sett == 4) {
    RTC.setDay((tgl1 * 10) + tgl2);
    RTC.setMonth((bln1 * 10) + bln2);
    RTC.setYear(RTC.getYear());
    RTC.setWeek(RTC.getWeek());
    RTC.setHourMode(RTC.getHourMode());

    Serial.print(RTC.getDay());
    Serial.print(" - ");
    Serial.println(RTC.getMonth());
    Serial.println("Setting is finish");
    sett = 5; next = 0;
    cc = 0;
  }
  if (sett == 5) {
    cc = 2;
    if (btnStateNext == HIGH) {
      if (stateN == LOW) {
        next++;
        if (next > 3 ) next = 0;
        stateN = HIGH;
      }
    }
    else stateN = LOW;

    if (next == 0 && upp == HIGH) {
      thn1++;
      if (thn1 > 9) thn1 = 0;
    }
    if (next == 1 && upp == HIGH) {
      thn2++;
      if (thn2 > 9) thn2 = 0;
    }
    if (next == 2 && upp == HIGH) {
      thn3++;
      if (thn3 > 9) thn3 = 0;
    }
    if (next == 3 && upp == HIGH) {
      thn4++;
      if (thn4 > 9) thn4 = 0;
    }
    digitalWrite(13, 1);
  }
  if (sett == 6) {
    thn = (thn4 + (thn3 * 10) + (thn2 * 100) + (thn1 * 1000));

    RTC.setDay(RTC.getDay());
    RTC.setMonth(RTC.getMonth());
    RTC.setYear(thn);
    RTC.setWeek(RTC.getWeek());
    RTC.setHourMode(RTC.getHourMode());

    Serial.println(RTC.getYear());
    Serial.println("  Setting is finish");
    sett = 7; next = 0;
    cc = 0;
  }
  if (sett == 7) {
    cc = 3;
    if (btnStateNext == HIGH) {
      if (stateN == LOW) {
        har++;
        if (har > 6 ) har = 0;
        stateN = HIGH;
      }
    }
    else stateN = LOW;
    if (upp == HIGH) {
      har--;
      if (har < 0) har = 6;
    }
    digitalWrite(13, 1);
  }
  if (sett == 8) {
    RTC.setWeek(har);
    RTC.setHourMode(RTC.getHourMode());

    Serial.println(RTC.getWeek());
    Serial.println("Setting is finish");
    sett = 9; next = 0;
    cc = 0;
  }
  if (sett == 9) {
    cc = 4;
    if (btnStateNext == HIGH) {
      if (stateN == LOW) {
        if (hm == 0 ) hm = 1;
        else hm = 0;
        stateN = HIGH;
      }
    }
    else stateN = LOW;
    digitalWrite(13, 1);
  }
  if (sett == 10) {
    RTC.setDay(RTC.getDay());
    RTC.setMonth(RTC.getMonth());
    RTC.setYear(RTC.getYear());
    RTC.setWeek(RTC.getWeek());
    //    RTC.setHourMode(hm);
    EEPROM.write(1, hm);

    Serial.println(hm);
    Serial.print(RTC.getHours());
    Serial.print(" : ");
    Serial.print(RTC.getMinutes());
    if (hm == CLOCK_H12)
    {
      switch (RTC.getMeridiem()) {
        case HOUR_AM:
          Serial.print(" AM");
          break;
        case HOUR_PM:
          Serial.print(" PM");
          break;
      }
    }
    Serial.println("");
    Serial.println("  Setting is finish");
    sett = 0; next = 0;
    cc = 0;
  }

  if (hm == 0) {
    hm1 = 2;//
    hm2 = 4;//
    hm3 = 15;//
    hm4 = 20;//
  }
  if (hm == 1) {
    hm1 = 1;//
    hm2 = 2;//
    hm3 = 15;//
    hm4 = 20;//
  }

  if (har == 0) {
    har1 = 21;//S
    har2 = 24;//U
    har3 = 19;//n
    har4 = 27;//off
  }
  if (har == 1) {
    har1 = 17;//M1
    har2 = 18;//M2
    har3 = 0;//0
    har4 = 19;//N
  }
  if (har == 2) {
    har1 = 22;//T1
    har2 = 23;//T2
    har3 = 24;//U
    har4 = 13;//E
  }
  if (har == 3) {
    har1 = 25;//W1
    har2 = 26;//W2
    har3 = 13;//E
    har4 = 12;//d
  }
  if (har == 4) {
    har1 = 22;//T1
    har2 = 23;//T2
    har3 = 15;//h
    har4 = 24;//U
  }
  if (har == 5) {
    har1 = 14;//F
    har2 = 20;//r
    har3 = 16;//I
    har4 = 27;//Space
  }
  if (har == 6) {
    har1 = 21;//S
    har2 = 11;//A
    har3 = 22;//T1
    har4 = 23;//T2
  }
  if (cc == 0) jam(sett, next, jam1, jam2, min1, min2);
  if (cc == 1) {
    digitalWrite(13, 0);
    //    jam(sett, next, thn1, thn2, thn3, thn4);
    jam(sett, next, tgl1, tgl2, bln1, bln2);
  }
  if (cc == 2) {
    digitalWrite(13, 1);
    jam(sett, next, thn1, thn2, thn3, thn4);
  }
  if (cc == 3) {
    digitalWrite(13, 1);
    dayName(sett, har1, har2, har3, har4);
  }
  if (cc == 4) {
    digitalWrite(13, 1);
    dayName(sett, hm1, hm2, hm3, hm4);
  }

}

