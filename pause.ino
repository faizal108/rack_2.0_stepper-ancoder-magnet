void checkPause() {
  //  for pause
  pauseBtnState = digitalRead(pauseBtnPin);
  if (pauseBtnState == HIGH) {
    digitalWrite(pauseLedPin, HIGH);
    while (pauseBtnState != LOW) {
      Serial.println("Running Pause");
      pauseBtnState = digitalRead(pauseBtnPin);
    }
  } else {
    digitalWrite(pauseLedPin, LOW);
  }

}
