void gotoPosition(int gotoPos, int motor, int stepPin, int dirPin) {

  switch (motor) {
    case 1:
      Serial.println("Motor 1 Running");
      break;
    case 2:
      Serial.println("Motor 2 Running");
      break;
    case 3:
      Serial.println("Motor 3 Running");
      break;
    default:
      Serial.println("ERR : Motor Not Found!!");
      break;
  }

  if (motor == 1) {
    if (gotoPos < 0) {
      if (m1_currentPos < gotoPos) {
        digitalWrite(dirPin, HIGH);
        for (int x = m1_currentPos; x < gotoPos; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          m1_steps++;
        }
        //          Serial.print("Value of m1_steps : ");
        //          Serial.print(m1_steps);
        //          Serial.print("\t");
        //          Serial.print("Counter : ");
        //          Serial.print(counter1);
        //          Serial.print("\t");
        m1_currentPos = m1_steps;
        //          Serial.print("Current pos : ");
        //          Serial.println(m1_currentPos);
      }
      else {
        digitalWrite(dirPin, LOW);
        for (int x = m1_currentPos; x > gotoPos; x--) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          m1_steps--;
        }
      }
      //        Serial.print("Value of m1_steps : ");
      //        Serial.print(m1_steps);
      //        Serial.print("\t");
      //        Serial.print("Counter : ");
      //        Serial.print(counter1);
      //        Serial.print("\t");
      m1_currentPos = m1_steps;
      //        Serial.print("Current pos : ");
      //        Serial.println(m1_currentPos);
    }
    else if (gotoPos > 0) {
      if (m1_currentPos < gotoPos) {
        digitalWrite(dirPin, HIGH);
        for (int x = m1_currentPos; x < gotoPos; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m1_steps++;
        }
      }
      else {
        digitalWrite(dirPin, LOW);
        for (int x = m1_currentPos; x > gotoPos; x--) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m1_steps--;
        }
      }
      m1_currentPos = m1_steps;
    }
    else {
      if (m1_currentPos < 0) {
        digitalWrite(dirPin, HIGH);
        for (int x = m1_currentPos; x < 0; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m1_steps++;
        }
      }
      else {
        digitalWrite(dirPin, LOW);
        for (int x = m1_currentPos; x > 0; x--) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m1_steps--;
        }
      }
      m1_currentPos = m1_steps;
      counter1 = 0;
      //        Serial.print("Value of m1_steps : ");
      //        Serial.print(m1_steps);
      //        Serial.print("Current Position : ");
      //        Serial.print(m1_currentPos);
      //        Serial.print("\t");
      //        Serial.print("Counter : ");
      //        Serial.println(counter1);
    }
  }
  else if (motor == 2) {
    if (gotoPos < 0) {
      if (m2_currentPos < gotoPos) {
        digitalWrite(dirPin, HIGH);
        for (int x = m2_currentPos; x < gotoPos; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          m2_steps++;
        }
        //          Serial.print("Value of m2_steps : ");
        //          Serial.print(m2_steps);
        //          Serial.print("\t");
        //          Serial.print("Counter : ");
        //          Serial.print(counter2);
        //          Serial.print("\t");
        m2_currentPos = m2_steps;
        //          Serial.print("Current pos : ");
        //          Serial.println(m2_currentPos);
      }
      else {
        digitalWrite(dirPin, LOW);
        for (int x = m2_currentPos; x > gotoPos; x--) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          m2_steps--;
        }
      }
      //        Serial.print("Value of m2_steps : ");
      //        Serial.print(m2_steps);
      //        Serial.print("\t");
      //        Serial.print("Counter : ");
      //        Serial.print(counter2);
      //        Serial.print("\t");
      m2_currentPos = m2_steps;
      //        Serial.print("Current pos : ");
      //        Serial.println(m2_currentPos);
    }
    else if (gotoPos > 0) {
      if (m2_currentPos < gotoPos) {
        digitalWrite(dirPin, HIGH);
        for (int x = m2_currentPos; x < gotoPos; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m2_steps++;
        }
      }
      else {
        digitalWrite(dirPin, LOW);
        for (int x = m2_currentPos; x > gotoPos; x--) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m2_steps--;
        }
      }
      m2_currentPos = m2_steps;
    }
    else {
      if (m2_currentPos < 0) {
        digitalWrite(dirPin, HIGH);
        for (int x = m2_currentPos; x < 0; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m2_steps++;
        }
      }
      else {
        digitalWrite(dirPin, LOW);
        for (int x = m2_currentPos; x > 0; x--) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m2_steps--;
        }
      }
      m2_currentPos = m2_steps;
      counter2 = 0;
      //        Serial.print("Value of m2_steps : ");
      //        Serial.print(m2_steps);
      //        Serial.print("Current Position : ");
      //        Serial.print(m2_currentPos);
      //        Serial.print("\t");
      //        Serial.print("Counter : ");
      //        Serial.println(counter2);
    }
  }
  else if (motor == 3) {
    if (gotoPos < 0) {
      if (m3_currentPos < gotoPos) {
        digitalWrite(dirPin, HIGH);
        for (int x = m3_currentPos; x < gotoPos; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          m3_steps++;
        }
        //          Serial.print("Value of m3_steps : ");
        //          Serial.print(m3_steps);
        //          Serial.print("\t");
        //          Serial.print("Counter : ");
        //          Serial.print(counter3);
        //          Serial.print("\t");
        m3_currentPos = m3_steps;
        //          Serial.print("Current pos : ");
        //          Serial.println(m3_currentPos);
      }
      else {
        digitalWrite(dirPin, LOW);
        for (int x = m3_currentPos; x > gotoPos; x--) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(2000);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(2000);
          m3_steps--;
        }
      }
      //        Serial.print("Value of m3_steps : ");
      //        Serial.print(m3_steps);
      //        Serial.print("\t");
      //        Serial.print("Counter : ");
      //        Serial.print(counter3);
      //        Serial.print("\t");
      m3_currentPos = m3_steps;
      //        Serial.print("Current pos : ");
      //        Serial.println(m3_currentPos);
    }
    else if (gotoPos > 0) {
      if (m3_currentPos < gotoPos) {
        digitalWrite(dirPin, HIGH);
        for (int x = m3_currentPos; x < gotoPos; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m3_steps++;
        }
      }
      else {
        digitalWrite(dirPin, LOW);
        for (int x = m3_currentPos; x > gotoPos; x--) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m3_steps--;
        }
      }
      m3_currentPos = m3_steps;
    }
    else {
      if (m3_currentPos < 0) {
        digitalWrite(dirPin, HIGH);
        for (int x = m3_currentPos; x < 0; x++) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m3_steps++;
        }
      }
      else {
        digitalWrite(dirPin, LOW);
        for (int x = m3_currentPos; x > 0; x--) {
          digitalWrite(stepPin, HIGH);
          delayMicroseconds(500);
          digitalWrite(stepPin, LOW);
          delayMicroseconds(500);
          m3_steps--;
        }
      }
      m3_currentPos = m3_steps;
      counter3 = 0;
      //        Serial.print("Value of m3_steps : ");
      //        Serial.print(m3_steps);
      //        Serial.print("Current Position : ");
      //        Serial.print(m3_currentPos);
      //        Serial.print("\t");
      //        Serial.print("Counter : ");
      //        Serial.println(counter3);
    }
  }

}
