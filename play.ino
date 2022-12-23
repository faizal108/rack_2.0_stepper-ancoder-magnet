void startPlaying() {
  Serial.println("Playing your saved recording.......");
  for (int i = 0 ; i < seq_index; i++) {

    int motor = seq_pointer[i] / 1000;
    Serial.print("Sequence pointer : ");
    Serial.println(seq_pointer[i]);
    Serial.print("Motor NO : ");
    Serial.println(motor);
    switch (motor) {
      case 1:
        {
          int indexM1 = seq_pointer[i] % 1000;
          int m1_value = m1_memory[indexM1];
          Serial.print("Value : ");
          Serial.println(m1_value);
          gotoPosition(m1_value, 1, stepPin1, dirPin1);
          break;
        }
      case 2:
        {
          int indexM2 = seq_pointer[i] % 1000;
          int m2_value = m2_memory[indexM2];
          Serial.print("Value : ");
          Serial.println(m2_value);
          gotoPosition(m2_value, 2, stepPin2, dirPin2);
          break;
        }
      case 3:
        {
          int indexM3 = seq_pointer[i] % 1000;
          int m3_value = m3_memory[indexM3];
          Serial.print("Value : ");
          Serial.println(m3_value);
          gotoPosition(m3_value, 3, stepPin3, dirPin3);
          break;
        }
      case 5:
        {
          Serial.println("Magnet ON");
          int indexMagnet = seq_pointer[i] % 1000;
          int magnet_value = magnet_memory[indexMagnet];
          Serial.print("Value : ");
          Serial.println(magnet_value);
          checkMagnet();
          break;
        }
      default:
        Serial.println("ERR : error while playing Motor not found!!");
        break;
    }
  }
}
