/*
       A
    F     B
       G
    E     C
       D
*/

void digitA() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, HIGH);
  digitalWrite(B, 1);
  digitalWrite(C, 1);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);
}

void digitD() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, 0);
  digitalWrite(B, 1);
  digitalWrite(C, 1);
  digitalWrite(D, 1);
  digitalWrite(E, 2);
  digitalWrite(F, 0);
  digitalWrite(G, 1);
}
void digitE() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, HIGH);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 1);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);
}
void digitF() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, HIGH);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);
}

void digitH() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, 0);
  digitalWrite(B, 1);
  digitalWrite(C, 1);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);
}
void digitI() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
}
void digitM1() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, HIGH);
  digitalWrite(B, 1);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, HIGH);
  digitalWrite(G, 0);
}
void digitM2() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, HIGH);
  digitalWrite(B, 1);
  digitalWrite(C, 1);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 1);
  digitalWrite(G, 0);
}

void digitN() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, HIGH);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 1);
}
void digitR() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 1);
}

void digitS() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, HIGH);
  digitalWrite(B, 0);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, 0);
  digitalWrite(F, HIGH);
  digitalWrite(G, 1);
}
void digitT1() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, HIGH);
  digitalWrite(B, 1);
  digitalWrite(C, 1);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
}

void digitT2() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, HIGH);
  digitalWrite(B, 0);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 0);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
}
void digitU() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, 0);
  digitalWrite(B, 1);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, 1);
  digitalWrite(F, HIGH);
  digitalWrite(G, 0);
}
void digitW1() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, 0);
  digitalWrite(B, 0);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, 1);
  digitalWrite(F, HIGH);
  digitalWrite(G, 0);
}
void digitW2() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, 0);
  digitalWrite(B, 1);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, 1);
  digitalWrite(F, 0);
  digitalWrite(G, 0);
}
void digitSpace() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
void digitP() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, HIGH);
  digitalWrite(B, 1);
  digitalWrite(C, 0);
  digitalWrite(D, 0);
  digitalWrite(E, 1);
  digitalWrite(F, 1);
  digitalWrite(G, 1);
}

void digit0() {
  // for 0 needed to turn ON F A B C D E segments, so:
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  //////////////////////// G segment should be turn OFF
  digitalWrite(G, LOW);
}

void digit1() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void digit2() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void digit3() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void digit4() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void digit5() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void digit6() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void digit7() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void digit8() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void digit9() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

//function to display digit from inputed int

void showdigit (int digit) {
  switch (digit) {
    case 0: digit0 (); break;
    case 1: digit1 (); break;
    case 2: digit2 (); break;
    case 3: digit3 (); break;
    case 4: digit4 (); break;
    case 5: digit5 (); break;
    case 6: digit6 (); break;
    case 7: digit7 (); break;
    case 8: digit8 (); break;
    case 9: digit9 (); break;

    case 11: digitA (); break;
    case 12: digitD (); break;
    case 13: digitE (); break;
    case 14: digitF (); break;
    case 15: digitH (); break;
    case 16: digitI (); break;
    case 17: digitM1 (); break;
    case 18: digitM2 (); break;
    case 19: digitN (); break;
    case 20: digitR (); break;
    case 21: digitS (); break;
    case 22: digitT1 (); break;
    case 23: digitT2 (); break;
    case 24: digitU (); break;
    case 25: digitW1 (); break;
    case 26: digitW2 (); break;
    case 27: digitSpace (); break;

    default: break;
  }
}

