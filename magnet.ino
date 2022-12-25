void checkMagnet() {
  //for magnet
  if (magnetBtnState == HIGH) {
    Serial.println("Magnet ON");
    digitalWrite(magnetLedPin, HIGH);
//    magnet_prevState = 1;
  } else {
    digitalWrite(magnetLedPin, LOW);
//    magnet_prevState = 0;
  }
}

void setMagnet(int state) {
  magnetState = state;
  if (magnetState == HIGH || magnetState == 1) {
    Serial.println("Magnet ON");
    digitalWrite(magnetLedPin, HIGH);
  }
  else {
    Serial.println("Magnet OFF");
    digitalWrite(magnetLedPin, LOW);
  }
}
