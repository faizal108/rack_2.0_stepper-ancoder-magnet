void checkMagnet() {
  //for magnet
  if (magnetBtnState == HIGH) {
    digitalWrite(magnetLedPin, HIGH);
    magnet_prevState = 1;
  } else {
    digitalWrite(magnetLedPin, LOW);
    magnet_prevState = 0;
  }
}
