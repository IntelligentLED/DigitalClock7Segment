void dayName(int showset, int k1, int k2, int k3, int k4) {
  static uint16_t ls2;
  uint16_t tmr2 = millis();
  if (showset == 7 ||showset == 9 ) { //kedip saat di masuk set
    if ((tmr2 - ls2) < 500) {
      showdigit(k1);
      digitalWrite(GND1, HIGH);
//      digitalWrite(GND2, LOW);
//      digitalWrite(GND3, LOW);
//      digitalWrite(GND4, LOW);
      delay (1);
      digitalWrite(GND1, LOW);

      showdigit(k2);
      digitalWrite(GND2, HIGH);
      delay (1);
      digitalWrite(GND2, LOW);

      showdigit(k3);
      digitalWrite(GND3, HIGH);
      delay (1);
      digitalWrite(GND3, LOW);

      showdigit(k4);
      digitalWrite(GND4, HIGH);
      delay (1);
      digitalWrite(GND4, LOW);

    }
    if ((tmr2 - ls2) > 1000) ls2 = tmr2;
  }
  else { //jika showset tidak bernilai 1
    showdigit(k1);
    digitalWrite(GND1, HIGH);
    digitalWrite(GND2, LOW);
    digitalWrite(GND3, LOW);
    digitalWrite(GND4, LOW);
    delay (1);

    digitalWrite(GND1, LOW);
    showdigit(k2);
    digitalWrite(GND2, HIGH);
    delay (1);

    digitalWrite(GND2, LOW);
    showdigit(k3);
    digitalWrite(GND3, HIGH);
    delay (1);

    digitalWrite(GND3, LOW);
    showdigit(k4);
    digitalWrite(GND4, HIGH);
    delay (1);
    digitalWrite(GND4, LOW);
  }
}

void jam(int showset, int digitt, int k1, int k2, int k3, int k4) {
  static uint16_t ls2;
  uint16_t tmr2 = millis();
  if (showset == 1 || showset == 3 || showset == 5 ) { //kedip saat di masuk set
    if (digitt == 0) {
      if ((tmr2 - ls2) < 500) {
        showdigit(k1);
        digitalWrite(GND1, HIGH);
        digitalWrite(GND2, LOW);
        digitalWrite(GND3, LOW);
        digitalWrite(GND4, LOW);
      }
      if ((tmr2 - ls2) > 1000) ls2 = tmr2;
    }
    else { //jika digitt tidak bernilai 0 lagi
      showdigit(k1);
      digitalWrite(GND1, HIGH);
      digitalWrite(GND2, LOW);
      digitalWrite(GND3, LOW);
      digitalWrite(GND4, LOW);
    }
    delay (1);
    digitalWrite(GND1, LOW);

    if (digitt == 1) {
      if ((tmr2 - ls2) < 500) {
        showdigit(k2);
        digitalWrite(GND2, HIGH);
      }
      if ((tmr2 - ls2) > 1000) ls2 = tmr2;
    }
    else { //jika digitt tidak bernilai 1 lagi
      showdigit(k2);
      digitalWrite(GND2, HIGH);
    }
    delay (1);
    digitalWrite(GND2, LOW);

    if (digitt == 2) {
      if ((tmr2 - ls2) < 500) {
        showdigit(k3);
        digitalWrite(GND3, HIGH);
      }
      if ((tmr2 - ls2) > 1000) ls2 = tmr2;
    }
    else { //jika digitt tidak bernilai 2 lagi
      showdigit(k3);
      digitalWrite(GND3, HIGH);
    }
    delay (1);
    digitalWrite(GND3, LOW);

    if (digitt == 3) {
      if ((tmr2 - ls2) < 500) {
        showdigit(k4);
        digitalWrite(GND4, HIGH);
      }
      if ((tmr2 - ls2) > 1000) ls2 = tmr2;
    }
    else { //jika digitt tidak bernilai 3 lagi
      showdigit(k4);
      digitalWrite(GND4, HIGH);
    }
    delay (1);
    digitalWrite(GND4, LOW);
  }
  else { //jika showset tidak bernilai 1
    showdigit(k1);
    digitalWrite(GND1, HIGH);
    digitalWrite(GND2, LOW);
    digitalWrite(GND3, LOW);
    digitalWrite(GND4, LOW);
    delay (1);

    digitalWrite(GND1, LOW);
    showdigit(k2);
    digitalWrite(GND2, HIGH);
    delay (1);

    digitalWrite(GND2, LOW);
    showdigit(k3);
    digitalWrite(GND3, HIGH);
    delay (1);

    digitalWrite(GND3, LOW);
    showdigit(k4);
    digitalWrite(GND4, HIGH);
    delay (1);
    digitalWrite(GND4, LOW);
  }
}

void blynk() {
  static uint16_t ls1;
  uint16_t tmr1 = millis();
  if ((tmr1 - ls1) < 500) digitalWrite(13, 0);
  if ((tmr1 - ls1) > 500) digitalWrite(13, 1);
  if ((tmr1 - ls1) > 1000) {
    ls1 = tmr1;
    upp = next = 0;
  }
}

